#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int top = -1;
char stack[25];

void push_char (char ch)
{
    stack[++top] = ch;
}

char pop_char ()
{
    return(stack[top--]);
}

bool is_symbol(char  ch)
{
    switch (ch) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
        case ')':
            return 1;
        default:
            return 0;
    }
}

int precedence(char symbol)
{
    switch(symbol) {
        case '(':
        case ')':
        case '#':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        case '^':
            return 4;
        default:
            return 1;
    }
}

void convert_infix_postfix(char *infix, char *postfix)
{
    int i, j = 0;
    int len = strlen(infix);
    char ch;
    
    push_char('#');
    
    for (i = 0; i < len; i++) {
        ch = infix[i];
        if (!is_symbol(ch)) {
            postfix[j++] = ch;
        } else {
            if (ch == '(') {
                push_char(ch);
            } else {
                if (ch == ')') {
                    while (stack[top] != '(') {
                        postfix[j++] = pop_char();
                    }
                    pop_char();
                } else {
                    if (precedence(ch) > precedence(stack[top])) {
                        push_char(ch);
                    } else {
                        while (precedence(ch) <= precedence(stack[top])) {
                            postfix[j++] = pop_char();
                        }
                        push_char(ch);
                    }
                }
            }
        }
    }
    
    while (stack[top] != '#') {
        postfix[j++] = pop_char();
    }
    postfix[j] = '\0';
}

int top_int = -1;
int stack_int[25];

void push_int(int n)
{
    stack_int[++top_int] = n;
}

int pop_int()
{
    return (stack_int[top_int--]);
}

int evaluate_postfix(char *postfix)
{
    int len = strlen(postfix);
    int i, operand1, operand2, result;
    char ch;
    
    for (i = 0; i < len; i++) {
        ch = postfix[i];
        if (isdigit(ch)) {
            push_int(ch - '0');
        } else {
            operand2 = pop_int();
            operand1 = pop_int();
            
            switch(ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    break;
            }
            push_int(result);
        }
    }
    result = pop_int();
    return (result);
}

int main()
{
    int i, size = 0, result;
    char infix[30], postfix[30];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    convert_infix_postfix(infix, postfix);
    printf("Postfix expression: %s", postfix);
    
    result = evaluate_postfix(postfix);
    printf("\nEvalution result: %d", result);

    return 0;
}
