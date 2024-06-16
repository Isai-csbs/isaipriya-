#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isdigit

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int top;
    int items[MAX_SIZE];
};

// Initialize stack
void initStack(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to check if stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to push element onto stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = value;
}

// Function to pop element from stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Function to get precedence of operators
int precedence(char operator) {
    switch (operator) {
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

// Function to apply operator to operands
int applyOperator(int operand1, char operator, int operand2) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Division by zero error\n");
                exit(EXIT_FAILURE);
            }
            return operand1 / operand2;
        default:
            return 0;
    }
}

// Function to evaluate infix expression
int evaluateInfix(char* expression) {
    struct Stack operandStack, operatorStack;
    initStack(&operandStack);
    initStack(&operatorStack);
    
    int i = 0;
    while (expression[i] != '\0') {
        // If current character is a whitespace, skip it
        if (expression[i] == ' ') {
            i++;
            continue;
        }
        // If current character is a digit, parse entire number
        else if (isdigit(expression[i])) {
            int operand = 0;
            while (isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            push(&operandStack, operand);
    
