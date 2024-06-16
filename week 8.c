#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the AVL tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    int height;
};

// Function prototypes
struct TreeNode* createNode(int data);
int getHeight(struct TreeNode* node);
int getBalance(struct TreeNode* node);
struct TreeNode* rightRotate(struct TreeNode* y);
struct TreeNode* leftRotate(struct TreeNode* x);
struct TreeNode* insertNode(struct TreeNode* root, int data);
struct TreeNode* minValueNode(struct TreeNode* node);
struct TreeNode* deleteNode(struct TreeNode* root, int data);
void inorderTraversal(struct TreeNode* root);
void deleteTree(struct TreeNode* root);

// Main function
int main() {
    struct TreeNode* root = NULL;
    int choice, data;

    while (1) {
        printf("\nAVL Tree Operations\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display (Inorder Traversal)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("AVL Tree (Inorder Traversal): ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                deleteTree(root); // Free memory before exit
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // New node is initially added at leaf level
    return newNode;
}

// Function to get the height of a node
int getHeight(struct TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Function to get the balance factor of a node
int getBalance(struct TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Function to perform a right rotation
struct TreeNode* rightRotate(struct TreeNode* y) {
    struct TreeNode* x = y->left;
    struct TreeNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + fmax(getHeight(y->left), getHeight(y->right));
    x->height = 1 + fmax(getHeight(x->left), getHeight(x->right));

    return x;
}

// Function to perform a left rotation
struct TreeNode* leftRotate(struct TreeNode* x) {
    struct TreeNode* y = x->right;
    struct TreeNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + fmax(getHeight(x->left), getHeight(x->right));
    y->height = 1 + fmax(getHeight(y->left), getHeight(y->right));

    return y;
}

// Function to insert a node into the AVL tree
struct TreeNode* insertNode(struct TreeNode* root, int data) {
    // Perform standard BST insertion
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    } else { // Equal keys are not allowed in AVL tree
        return root;
    }

    // Update height of this ancestor node
    root->height = 1 + fmax(getHeight(root->left), getHeight(root->right));

    // Get the balance factor of this ancestor node to check if it became unbalanced
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && data < root->left->data) {
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && data > root->right->data) {
        return leftRotate(root);
    }

    // Left Right Case
    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Return the (unchanged) node pointer
    return root;
}

// Function to find the node with minimum value in a subtree
struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the AVL tree
struct TreeNode* deleteNode(struct TreeNode* root, int data) {
    // Perform standard BST delete
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else { // Node to be deleted found

        // Node with only one child or no child
        if (root->left == NULL || root->right == NULL) {
            struct TreeNode* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else { // One child case
                *root = *temp; // Copy the contents of the non-empty child
            }
            free(temp);
        } else { // Node with two children: Get the inorder successor (smallest in the right subtree)
            struct TreeNode* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // If the tree had only one node then return
    if (root == NULL) {
        return root;
    }

    // Update height of the current node
    root->height = 1 + fmax(getHeight(root->left), getHeight(root->right));

    // Get the balance factor of this node to check whether it became unbalanced
    int balance = getBalance(root);

 
