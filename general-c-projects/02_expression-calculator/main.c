#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "evaluator.h"

int main(){

    char input[256];
    Token infix[MAX_TOKENS], postfix[MAX_TOKENS];

    printf("-----------------------\n|EXPRESSION CALCULATOR|\n-----------------------\n\n");
    printf("(Type 'exit' to exit program)");

    while(1){
        printf("\nEnter expression: ");
        fgets(input, sizeof(input), stdin);

        if (strncmp(input, "exit", 4) == 0)
            break;

        int tokenCount = tokenize(input, infix,  MAX_TOKENS);
        if(tokenCount<0){
            printf("\nTokenization error.\n");
            continue;
        }

        int postfixCount = to_postfix(infix, tokenCount, postfix, MAX_TOKENS);
        if(postfixCount<0){
            printf("\nPostfix conversion error.\n");
            continue;
        }

        /*printf("Infix Tokens:\n");
        for(int i=0; i<tokenCount; i++){
            printf("[%d] Type: %d, Value: %s\n", i, infix[i].type, infix[i].value);
        }

        printf("Postfix Tokens:\n");
        for(int i=0; i<tokenCount; i++){
            printf("[%d] Type: %d, Value: %s\n", i, postfix[i].type, postfix[i].value);
        }*/

        float result;
        int status = evaluate_postfix(postfix, postfixCount, &result);

        if(status == -2){
            printf("Error: Division by zero.\n");
        }
        else if(status != 0){
            printf( "Error: Evaluation error.\n");
        }
        else{
            printf("Result: %.2f\n", result);
        }
    }
    return 0;
}