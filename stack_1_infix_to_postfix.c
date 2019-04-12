#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_TC     100
#define MAX_STACK_SIZE 20
#define MAX_EXPR_SIZE  30

char stack_op[MAX_STACK_SIZE];
int top = -1;

int precedence(char op) 
{
    int prec = 0;
    
    switch (op) {
        case '(':
            prec = 0;
        break;
        
        case '+':
        case '-':
            prec = 1;
        break;
        
        case '*':
        case '/':
            prec = 2;
        break;
        
        case '^':
            prec = 3;
        break;
        
        default:
            prec = 0;
        break;
    }
    return (prec);
}

void push(char operator)
{
    if (top < (MAX_STACK_SIZE - 1)) {
        top++;
        stack_op[top] = operator;
    } else {
        printf("Error: Stack full!\n");
    }
}

int is_empty()
{
	return ((top == -1)?1:0);
}

char pop(void)
{
    char op;
    if (top == -1) {
        printf("Error: Stack empty!\n");
        return (0xFF);
    } else {
        op = stack_op[top--];
        return (op);
    }
}

int main() {
	//code
	int num_tc, i, j = 0;
	char *expr[MAX_NUM_TC] = {NULL};

	scanf("%d", &num_tc);
    for (i = 0; i < num_tc; i++) {
        expr[i] = (char *)malloc((MAX_EXPR_SIZE + 1));
	    scanf("%s", expr[i]);
	}
	for (i = 0; i < num_tc; i++) {
	    for (j = 0; j < MAX_EXPR_SIZE && expr[i][j] != '\0'; j++) {
	        switch(expr[i][j]) {
	            case '(':
	                push(expr[i][j]);
                    break;
	            case '+':
	            case '-':
	            case '*':
	            case '/':
	            case '^':
	                while (!is_empty() && (precedence(stack_op[top]) >= precedence(expr[i][j]))) {
	                    printf("%c", pop());
	                }
	                push(expr[i][j]);
	            break;
	            
	            case ')':
	                while (!is_empty() && stack_op[top] != '(') {
	                    printf("%c", pop());
	                }
	                if (!is_empty()) {
	                    pop();
	                }
	            break;
	            
	            default:
	                printf("%c", expr[i][j]);
	            break;
	        }
	    }
		while (!is_empty()) {
			printf("%c", pop());
		}
	    printf("\n");
	}
	return 0;
}
