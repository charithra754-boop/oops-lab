#include <stdio.h>
#include <stdlib.h>

// --- TOPIC 11: BINARY SEARCH TREE (BST) ---
// Organized Chaos! Left is smaller, Right is bigger.
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* create_tree_node(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) return create_tree_node(data);
    
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    
    return root;
}

// --- TOPIC 10: TRAVERSALS ---
// Different ways to walk through the forest.

void inorder(TreeNode* root) { // Left -> Root -> Right (Sorted!)
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(TreeNode* root) { // Root -> Left -> Right
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode* root) { // Left -> Right -> Root
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    printf("\n=== BST & TRAVERSALS PLAYGROUND ===\n");
    TreeNode* root = NULL;
    
    // Building the tree
    int values[] = {50, 30, 20, 40, 70, 60, 80};
    for(int i=0; i<7; i++) root = insert(root, values[i]);
    
    printf("Tree built! (50, 30, 20, 40, 70, 60, 80)\n");

    printf("Inorder (Sorted): ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    return 0;
}
