#include "parser.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int tokenize(const char *expr, Token tokens[], int maxTokens){
    int count=0;
    
    while(*expr && count < maxTokens){
        if(isspace(*expr)){
            expr++;
        }

        else if(isdigit(*expr)){
            int len=0;
            while((isdigit(*expr) || *expr == '.') && len< MAX_TOKEN_LEN -1){
                tokens[count].value[len++] =*expr++;
            }
            tokens[count].value[len] = '\0';
            tokens[count].type = TOKEN_NUMBER;
            count++;
        }

        else if(*expr == '+' || *expr == '-' || *expr == '*' || *expr == '/'){
            tokens[count].type = TOKEN_OPERATOR;
            tokens[count].value[0] = *expr++;
            tokens[count].value[1] = '\0';
            count++;
        }

        else if(*expr == '('){
            tokens[count].type = TOKEN_PAREN_LEFT;
            tokens[count].value[0] = *expr++;
            tokens[count].value[1] = '\0';
            count++;
        }

        else if(*expr == ')'){
            tokens[count].type = TOKEN_PAREN_RIGHT;
            tokens[count].value[0] = *expr++;
            tokens[count].value[1] = '\0';
            count++;
        }

        else{
            printf("\nUnexpected character: %c\n", *expr);
            return -1;
        }
    }

    return count;
}

int precedence(char op){
    switch(op){
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default: return 0;
    }
}

int to_postfix(Token infix[], int infixCount, Token postfix[], int maxTokens){
    Token stack[MAX_TOKENS];
    int stackTop= -1;
    int outCount= 0;

    for(int i=0; i<infixCount; ++i){
        Token token = infix[i];
        
        if(token.type == TOKEN_NUMBER){
            postfix[outCount++] = token;
        }

        else if(token.type == TOKEN_OPERATOR){
            while(stackTop>=0 && 
                stack[stackTop].type == TOKEN_OPERATOR && 
                precedence(stack[stackTop].value[0]) >= precedence(token.value[0])){
                postfix[outCount++] = stack[stackTop--];
            }
            stack[++stackTop] =  token;
        }

        else if(token.type == TOKEN_PAREN_LEFT){
            stack[++stackTop] = token;
        }

        else if(token.type == TOKEN_PAREN_RIGHT){
            while(stackTop>=0 && stack[stackTop].type != TOKEN_PAREN_LEFT){
                postfix[outCount++] = stack[stackTop--];
            }
            
            if(stackTop>=0 && stack[stackTop].type == TOKEN_PAREN_LEFT){
                stackTop--;
            }

            else{
                return -1;
            }
        }
    }


    while(stackTop>=0){
        if(stack[stackTop].type == TOKEN_PAREN_LEFT){
            return -1;
        }

        postfix[outCount++] =stack[stackTop--];
    }


    return outCount;
}