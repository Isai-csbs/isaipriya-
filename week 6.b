#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function prototypes
void insertAtBeginning(struct Node** headRef, int newData);
void insertAtEnd(struct Node** headRef, int newData);
void deleteFromBeginning(struct Node** headRef);
void deleteFromEnd(struct Node** headRef);
struct Node* search(struct Node* head, int key);
void displayList(struct Node* head);
void printMenu();

int main() {
    struct Node* head = NULL;
    int choice, data, key;
    struct Node* foundNode = NULL;
    
    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                deleteFromBeginning(&head);
                break;
            case 4:
                deleteFromEnd(&head);
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &key);
                foundNode = search(head, key);
                if (foundNode != NULL) {
                    printf("Element %d found in the list.\n", key);
                } else {
                    printf("Element %d not found in the list.\n", key);
                }
                break;
            case 6:
                displayList(head);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }
    
    return 0;
}

// Function definitions

// Print menu function
void printMenu() {
    printf("\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Delete from beginning\n");
    printf("4. Delete from end\n");
    printf("5. Search\n");
    printf("6. Display\n");
    printf("7. Exit\n");
    printf("\n");
}

// Insert a node at the beginning of the list
void insertAtBeginning(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = *headRef;
    
    if (*headRef != NULL) {
        (*headRef)->prev = newNode;
    }
    
    *headRef = newNode;
    
    printf("Node inserted at the beginning successfully.\n");
}

// Insert a node at the end of the list
void insertAtEnd(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = newData;
    newNode->next = NULL;
    
    if (*headRef == NULL) {
        newNode->prev = NULL;
        *headRef = newNode;
    } else {
        struct Node* last = *headRef;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    }
    printf("Node inserted at the end successfully.\n");
}

// Delete a node from the beginning of the list
void deleteFromBeginning(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty. Cannot delete from beginning.\n");
        return;
    }
    struct Node* temp = *headRef;
    *headRef = (*headRef)->next;
    
    if (*headRef != NULL) {
        (*headRef)->prev = NULL;
    }
    
    free(temp);
    printf("Node deleted from the beginning successfully.\n");
}

// Delete a node from the end of the list
void deleteFromEnd(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty. Cannot delete from end.\n");
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *headRef = NULL;
    }
    
    free(temp);
    printf("Node deleted from the end successfully.\n");
}

// Search for an element in the list
struct Node* search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Display the doubly linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("Doubly linked list: NULL\n");
        return;
    }
    printf("Doubly linked list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

