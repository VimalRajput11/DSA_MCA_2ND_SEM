#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100

int top = -1;
char stack[SIZE];

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

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Infix to Postfix logic (used inside Infix to Prefix)
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char symbol;
    while (infix[i] != '\0') {
        symbol = infix[i];
        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        } else if (symbol == '(') {
            push(symbol);
        } else if (symbol == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        } else if (isOperator(symbol)) {
            while (top != -1 && precedenceValue(stack[top]) > precedenceValue(symbol)) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
        i++;
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void infixToPrefix(char infix[], char prefix[]) {
    char revInfix[SIZE], revPostfix[SIZE];
    strcpy(revInfix, infix);
    reverse(revInfix);

    for (int i = 0; revInfix[i] != '\0'; i++) {
        if (revInfix[i] == '(')
            revInfix[i] = ')';
        else if (revInfix[i] == ')')
            revInfix[i] = '(';
    }
    infixToPostfix(revInfix, revPostfix);
    reverse(revPostfix);
    strcpy(prefix, revPostfix);
}

int main() {
    char infix[SIZE], prefix[SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
