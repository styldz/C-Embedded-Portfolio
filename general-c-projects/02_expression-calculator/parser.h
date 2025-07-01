#ifndef PARSER_H
#define PARSER_H

 #define MAX_TOKENS 100
 #define MAX_TOKEN_LEN 32

 typedef enum{
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_PAREN_LEFT,
    TOKEN_PAREN_RIGHT,
 } TokenType;

typedef struct{
    TokenType type;
    char value[MAX_TOKEN_LEN];

} Token;

int tokenize(const char *expr, Token tokens[], int maxTokens);
int precedence(char op);
int to_postfix(Token infix[], int infixCount, Token postfix[], int maxTokens);

#endif