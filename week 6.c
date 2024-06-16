#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void insertAtBeginning(struct Node** headRef, int newData);
void insertAtEnd(struct Node** headRef, int newData);
void insertAfter(struct Node* prevNode, int newData);
void deleteFromBeginning(struct Node** headRef);
void deleteFromEnd(struct Node** headRef);
void deleteAfter(struct Node* prevNode);
struct Node* search(struct Node* head, int key);
void displayList(struct Node* head);
void printMenu();

int main() {
    struct Node* head = NULL;
    int choice, data, key;
    struct Node* foundNode = NULL;
    struct Node* tempNode = NULL;
    
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
                printf("Enter data to insert after: ");
                scanf("%d", &data);
                printf("Enter value after which to insert: ");
                scanf("%d", &key);
                tempNode = search(head, key);
                if (tempNode != NULL) {
                    insertAfter(tempNode, data);
                } else {
                    printf("Element %d not found in the list.\n", key);
                }
                break;
            case 4:
                deleteFromBeginning(&head);
                break;
            case 5:
                deleteFromEnd(&head);
                break;
            case 6:
                printf("Enter value after which to delete: ");
                scanf("%d", &key);
                tempNode = search(head, key);
                if (tempNode != NULL && tempNode->next != NULL) {
                    deleteAfter(tempNode);
                } else {
                    printf("Element %d not found or no element after it to delete.\n", key);
                }
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &key);
                foundNode = search(head, key);
                if (foundNode != NULL) {
                    printf("Element %d found in the list.\n", key);
                } else {
                    printf("Element %d not found in the list.\n", key);
                }
                break;
            case 8:
                displayList(head);
                break;
            case 9:
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
    printf("3. Insert after a specific node\n");
    printf("4. Delete from beginning\n");
    printf("5. Delete from end\n");
    printf("6. Delete after a specific node\n");
    printf("7. Search for an element\n");
    printf("8. Display the circular list\n");
    printf("9. Exit\n");
    printf("\n");
}

// Insert a node at the beginning of the circular list
void insertAtBeginning(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = newData;
    newNode->next = newNode; // Initialize next of new node to itself
    
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct Node* temp = *headRef;
        while (temp->next != *headRef) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *headRef;
        *headRef = newNode;
    }
    
    printf("Node inserted at the beginning successfully.\n");
}

// Insert a node at the end of the circular list
void insertAtEnd(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = newData;
    newNode->next = newNode; // Initialize next of new node to itself
    
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct Node* temp = *headRef;
        while (temp->next != *headRef) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *headRef;
    }
    
    printf("Node inserted at the end successfully.\n");
}

// Insert a node after a specific node in the circular list
void insertAfter(struct Node* prevNode, int newData) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    
    printf("Node inserted after the specific node successfully.\n");
}

// Delete a node from the beginning of the circular list
void deleteFromBeginning(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty. Cannot delete from beginning.\n");
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != *headRef) {
        temp = temp->next;
    }
    
    if (*headRef == temp) {
        *headRef = NULL;
    } else {
        *headRef = (*headRef)->next;
        temp->next = *headRef;
    }
    
    free(temp);
    printf("Node deleted from the beginning successfully.\n");
}

// Delete a node from the end of the circular list
void deleteFromEnd(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty. Cannot delete from end.\n");
        return;
    }
    struct Node* temp = *headRef;
    struct Node* prev = NULL;
    
    while (temp->next != *headRef) {
        prev = temp;
        temp = temp->next;
    }
    
    if (prev != NULL) {
        prev->next = *headRef;
    } else {
        *headRef = NULL;
    }
    
    free(temp);
    printf("Node deleted from the end successfully.\n");
}

// Delete a node after a specific node in the circular list
void deleteAfter(struct Node* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) {
        printf("Previous node cannot be NULL or there is no node after it to delete.\n");
        return;
    }
    struct Node* temp = prevNode->next;
    prevNode->next = temp->next;
    free(temp);
    printf("Node deleted after the specific node successfully.\n");
}

// Search for an element in the circular list
struct Node* search(struct Node* head, int key) {
    struct Node* current = head;
    if (current == NULL) {
        return NULL;
    }
    do {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    } while (current != head);
    
    return NULL;
}

// Display the circular list
void displayList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("Circular linked list: NULL\n");
        return;
    }
    printf("Circular linked list: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}
