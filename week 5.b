#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

// Stack structure
struct Stack {
    int top;
    int items[MAX_DISKS];
};

// Initialize stack
void initStack(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_DISKS - 1;
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

// Function to move disks between pegs
void displayMove(char source, char destination) {
    printf("Move disk from %c to %c\n", source, destination);
}

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int numDisks, char source, char auxiliary, char destination) {
    struct Stack pegs[3]; // Create three stacks, one for each peg
    char pegNames[] = {'A', 'B', 'C'};
    
    for (int i = 0; i < 3; ++i) {
        initStack(&pegs[i]);
    }
    
    // Push disks onto the source peg initially
    for (int i = numDisks; i >= 1; --i) {
        push(&pegs[source - 'A'], i);
    }
    
    // Function to move disks recursively
    void moveDisks(int disks, int from, int to, int using) {
        if (disks > 0) {
            moveDisks(disks - 1, from, using, to); // Move top disks-1 from 'from' to 'using'
            
            int disk = pop(&pegs[from]);
            push(&pegs[to], disk);
            displayMove(pegNames[from], pegNames[to]);
            
            moveDisks(disks - 1, using, to, from); // Move remaining disks-1 from 'using' to 'to'
        }
    }
    
    printf("Moves to solve the Tower of Hanoi with %d disks:\n", numDisks);
    moveDisks(numDisks, source - 'A', destination - 'A', auxiliary - 'A');
}

int main() {
    int numDisks;
    
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);
    
    if (numDisks <= 0 || numDisks > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }
    
    towerOfHanoi(numDisks, 'A', 'B', 'C');
    
    return 0;
}
