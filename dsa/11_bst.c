#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

struct Node* search(struct Node* root, int val) {
    if (root == NULL || root->data == val) return root;
    if (val < root->data) return search(root->left, val);
    return search(root->right, val);
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, int val) {
    if (root == NULL) return root;
    if (val < root->data) root->left = deleteNode(root->left, val);
    else if (val > root->data) root->right = deleteNode(root->right, val);
    else {
        // Node with one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get inorder successor (smallest in right subtree)
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, val;
    
    while(1) {
        printf("\nBST Menu:\n1. Insert\n2. Search\n3. Delete\n4. Display (Inorder)\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val) != NULL) printf("Found %d\n", val);
                else printf("Not Found\n");
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 4:
                printf("BST Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 5: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
