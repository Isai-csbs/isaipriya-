#include <stdio.h>
#include <stdbool.h> // for boolean type

#define MAX_SIZE 100 // Maximum size of the queue

// Define queue structure
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
    int size;
};

// Initialize queue
void initQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

// Function to check if queue is full
bool isFull(struct Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// Function to check if queue is empty
bool isEmpty(struct Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to add an element to the queue
void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow - cannot enqueue element %d\n", value);
    } else {
        if (isEmpty(queue)) {
            queue->front = 0; // Set front to 0 when inserting the first element
        }
        queue->rear++;
        queue->items[queue->rear] = value;
        queue->size++;
        printf("Enqueued element: %d\n", value);
    }
}

// Function to remove and return an element from the queue
int dequeue(struct Queue *queue) {
    int dequeued;
    if (isEmpty(queue)) {
        printf("Queue Underflow - cannot dequeue from empty queue\n");
        return -1; // Return -1 indicating error
    } else {
        dequeued = queue->items[queue->front];
        if (queue->front == queue->rear) {
            // Reset queue to empty state after removing last element
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front++;
        }
        queue->size--;
        return dequeued;
    }
}

// Function to peek the front element of the queue
int peek(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty - cannot peek\n");
        return -1; // Return -1 indicating error
    } else {
        return queue->items[queue->front];
    }
}

int main() {
    struct Queue queue;
    initQueue(&queue); // Initialize the queue

    // Example usage
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    int dequeuedElement = dequeue(&queue);
    if (dequeuedElement != -1) {
        printf("Dequeued element: %d\n", dequeuedElement);
    }

    dequeuedElement = dequeue(&queue);
    if (dequeuedElement != -1) {
        printf("Dequeued element: %d\n", dequeuedElement);
    }

    printf("Front element: %d\n", peek(&queue));

    return 0;
}
