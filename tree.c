#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* right;
    struct Node* left;
};

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

int findLargest(struct Node* root) {
    struct Node* current = root;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current->data;
}

int findSmallest(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

void deleteTree(struct Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

void insert(struct Node* root, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    struct Node* current = root;
    struct Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        } else if (value > current->data) {
            current = current->right;
        } else {
            // Value already exists, no need to insert again.
            printf("Value already exists in the tree.\n");
            free(newNode);
            return;
        }
    }

    if (value < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

int main() {
    printf("Done by Roll.No 2330196.\n");

    // Creating the root node manually.
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 12;
    root->left = NULL;
    root->right = NULL;

    // Manually creating some initial child nodes for the root.
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = 14;
    temp->left = NULL;
    temp->right = NULL;
    root->left = temp;

    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = 23;
    temp->left = NULL;
    temp->right = NULL;
    root->right = temp;

    int choice, value;
    while (1) {
        printf("\n1. Insert\n");
        printf("2. In Order Traversal\n");
        printf("3. Post Order Traversal\n");
        printf("4. Pre Order Traversal\n");
        printf("5. Search\n");
        printf("6. Find Largest\n");
        printf("7. Print Smallest\n");
        printf("8. Delete Tree\n");
        printf("9. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Value: ");
                scanf("%d", &value);
                insert(root, value);
                break;

            case 2:
                inOrderTraversal(root);
                printf("\n");
                break;

            case 3:
                postOrderTraversal(root);
                printf("\n");
                break;

            case 4:
                preOrderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* found = search(root, value);
                if (found) {
                    printf("Element %d found in the tree.\n", value);
                } else {
                    printf("Element %d not found in the tree.\n", value);
                }
                break;

            case 6:
                if (root != NULL) {
                    printf("Largest element: %d\n", findLargest(root));
                } else {
                    printf("Tree is empty.\n");
                }
                break;

            case 7:
                if (root != NULL) {
                    printf("Smallest element: %d\n", findSmallest(root));
                } else {
                    printf("Tree is empty.\n");
                }
                break;

            case 8:
                deleteTree(root);
                root = NULL;
                printf("Tree deleted.\n");
                break;

            case 9:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
