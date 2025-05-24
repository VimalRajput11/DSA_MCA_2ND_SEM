#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int top;
    unsigned capacity;
    int *array;
};
struct stack *createstack(unsigned capacity);
int isempty(struct stack *stack);
int pop(struct stack *stack);
void push(struct stack *stack, int op);
int evaluatePostfix(char *exp);



int main(){
    char exp[100];
    printf("Enter a postfix expression: ");
    scanf("%s", exp);
    printf("Postfix evaluation: %d\n", evaluatePostfix(exp));
    return 0;
}

struct stack *createstack(unsigned capacity)
{
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isempty(struct stack *stack){
    return stack->top == -1;
}

int pop(struct stack *stack){
    if (!isempty(stack))
        return stack->array[stack->top--];
    return -1; 
}

void push(struct stack *stack, int op){
    stack->array[++stack->top] = op;
}

int evaluatePostfix(char *exp){
    struct stack *stack = createstack(strlen(exp));
    if (!stack) return -1;

    for (int i = 0; exp[i]; ++i){
        if (isdigit(exp[i])){
            push(stack, exp[i] - '0');
        } else {
            int val1 = pop(stack);
            int val2 = pop(stack);
            printf("nTop two values are %d %d\n", val1, val2);
            switch (exp[i]){
                case '+': push(stack, val2 + val1); break;
                case '-': push(stack, val2 - val1); break;
                case '*': push(stack, val2 * val1); break;
                case '/': push(stack, val2 / val1); break;
            }
        }
    }
    return pop(stack);
}