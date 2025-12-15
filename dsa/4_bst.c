#include <stdio.h>
#include <stdlib.h>

/*
 * BINARY SEARCH TREE
 * 
 * It's a tree, but organized! Like a library, but with numbers.
 * Left is smaller, Right is bigger. It's the law of the land.
 */

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int search(struct Node* root, int key) {
    if (root == NULL) return 0;
    if (root->key == key) return 1;
    if (root->key < key) return search(root->right, key);
    return search(root->left, key);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, val;
    printf("--- Binary Search Tree (Not a literal tree) ---\n");
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display (Inorder)\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("Enter value to plant: "); scanf("%d", &val); 
                root = insert(root, val); 
                printf("Planted %d.\n", val);
                break;
            case 2: 
                printf("Enter value to chop: "); scanf("%d", &val); 
                root = deleteNode(root, val); 
                printf("Timber! (If it was there)\n");
                break;
            case 3: 
                printf("Enter value to find: "); scanf("%d", &val);
                if (search(root, val)) printf("Found it! It was hiding behind a leaf.\n");
                else printf("404: Node not found.\n");
                break;
            case 4: 
                printf("Tree contents: "); inorder(root); printf("\n"); 
                break;
            case 5: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
