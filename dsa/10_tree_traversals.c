#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    // Hardcoded tree for demo:
    //      1
    //     / \
    //    2   3
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    printf("Tree Traversals:\n");
    
    printf("Inorder (Left-Root-Right): ");
    inorder(root);
    printf("\n");

    printf("Preorder (Root-Left-Right): ");
    preorder(root);
    printf("\n");

    printf("Postorder (Left-Right-Root): ");
    postorder(root);
    printf("\n");

    return 0;
}