#include "header.h"

// function recursively parses expressions based on operator precedence
// It uses a recursive descent approach to build the parse tree, climbing up the tree as it processes operators of increasing precedence.
int parse_expression(int precedence) 
{
    int left = parse_primary();

    while (get_precedence(current_token.type) > precedence) 
    {
        TokenType op = current_token.type;
        next_token();
        int right = parse_expression(get_precedence(op));
        switch (op) {
            case TOKEN_PLUS: left += right; break;
            case TOKEN_MINUS: left -= right; break;
            case TOKEN_MULTIPLY: left *= right; break;
            case TOKEN_DIVIDE: left /= right; break;
            default: break;
        }
    }
    return left;
}