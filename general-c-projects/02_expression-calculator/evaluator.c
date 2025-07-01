#include "evaluator.h"
#include <stdlib.h>
#include <stdio.h>

int evaluate_postfix(Token postfix[], int count, float *result){
    float stack[MAX_TOKENS];
    int top= -1;

    for(int i=0; i <  count; ++i){
        if(postfix[i].type == TOKEN_NUMBER){
            stack[++top] = atof(postfix[i].value);
        }

        else if(postfix[i].type == TOKEN_OPERATOR){
            if(top<1){
                return -1;
            }

            float b = stack[top--];
            float a = stack[top--];
            char op = postfix[i].value[0];

            switch(op){
                case '+': stack[++top]= a + b; break;
                case '-': stack[++top]= a - b; break;
                case '*': stack[++top]= a * b; break;
                case '/': 
                    if(b == 0){
                        return -2; // division by zero error return
                    }
                    stack[++top]= a / b; break;
                default: return -3; //unknown operator error return
            }
        }
    }

    if(top != 0){
        return -4;
    }

    *result = stack[0];
    return 0;
}