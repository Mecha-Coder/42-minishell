#include "header.h"

// function reads the input and converts it into tokens.
// The input expression is first broken down into tokens (numbers, operators, parentheses).

void next_token() 
{
    while (isspace(*input))
        input++;
    if (isdigit(*input))
    {
        current_token.type = TOKEN_NUMBER;
        current_token.value = strtol(input, (char**)&input, 10);
    }
    else 
    {
        switch (*input) 
        {
            case '+': current_token.type = TOKEN_PLUS; break;
            case '-': current_token.type = TOKEN_MINUS; break;
            case '*': current_token.type = TOKEN_MULTIPLY; break;
            case '/': current_token.type = TOKEN_DIVIDE; break;
            case '(': current_token.type = TOKEN_LPAREN; break;
            case ')': current_token.type = TOKEN_RPAREN; break;
            case '\0': current_token.type = TOKEN_END; break;
            default: fprintf(stderr, "Unknown character: %c\n", *input); exit(1);
        }
        input++;
    }
}