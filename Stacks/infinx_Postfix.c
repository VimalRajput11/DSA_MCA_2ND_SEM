#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 100
int precedenceValue(char symbol);
int isOperator(char symbol);
void push(char symbol);
char pop();
void infixToPostfix(char infix[], char result[]);
int top = -1;
char stack[SIZE];

int main() {
    char infix[SIZE], result[SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, result);
    printf("Postfix expression: %s\n", result);
    return 0;
}

int precedenceValue(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^');
}

void push(char symbol) {
    if (top == SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = symbol;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

void infixToPostfix(char infix[], char result[]) {
    int i = 0, j = 0;
    char symbol;
    while (infix[i] != '\0') {
        symbol = infix[i];
        if (isalnum(symbol)) {
            result[j++] = symbol;
        } else if (symbol == '(') {
            push(symbol);
        } else if (symbol == ')') {
            while (top != -1 && stack[top] != '(') {
                result[j++] = pop();
            }
            pop(); 
        } else if (isOperator(symbol)) {
            while (top != -1 && precedenceValue(stack[top]) >= precedenceValue(symbol)) {
                result[j++] = pop();
            }
            push(symbol);
        }
        i++;
    }
    while (top != -1) {
        result[j++] = pop();
    }
    result[j] = '\0';
}
