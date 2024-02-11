#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(char item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to determine the precedence of operators
int precedence(char op) {
    switch(op) {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1; // for operands
    }
}

// Function to convert infix expression to postfix
void infixToPostfix(char infix[]) {
    int i = 0;
    char symbol;
    push('#'); // Push sentinel character '#'

    while ((symbol = infix[i++]) != '\0') {
        if (isalnum(symbol)) { // Operand
            printf("%c", symbol);
        } else if (symbol == '(') { // Opening parenthesis
            push(symbol);
        } else if (symbol == ')') { // Closing parenthesis
            while (stack[top] != '(') {
                printf("%c", pop());
            }
            pop(); // Discard the '('
        } else { // Operator
            while (precedence(symbol) <= precedence(stack[top])) {
                printf("%c", pop());
            }
            push(symbol);
        }
    }

    // Pop and output remaining operators from the stack
    while (stack[top] != '#') {
        printf("%c", pop());
    }
}

int main() {
    char infix[100];
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    printf("Postfix expression: ");
    infixToPostfix(infix);

    return 0;
}
