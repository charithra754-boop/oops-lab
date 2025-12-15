#include <stdio.h>
#include <stdlib.h>

/*
 * TREE TRAVERSAL
 * 
 * Getting lost in the woods, the algorithmic way.
 * 
 * Fun Fact: Trees in CS are upside down. The root is at the top.
 * Gravity does not apply here.
 */

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Just a simple BST insert helper to build a tree easily
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return createNode(data);
    if (data < node->data) node->left = insert(node->left, data);
    else if (data > node->data) node->right = insert(node->right, data);
    return node;
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root = NULL;
    int choice, val;
    printf("--- Tree Traversals (A Walk in the Park) ---\n");
    
    // Let's pre-populate or allow user to build? Let's allow build.
    
    while(1) {
        printf("\n1. Insert Element\n2. Inorder (L-Root-R)\n3. Preorder (Root-L-R)\n4. Postorder (L-R-Root)\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Value: "); scanf("%d", &val);
                root = insert(root, val);
                printf("Inserted %d. The tree grows strong.\n", val);
                break;
            case 2:
                printf("Inorder: "); inorder(root); printf("\n");
                break;
            case 3:
                printf("Preorder: "); preorder(root); printf("\n");
                break;
            case 4:
                printf("Postorder: "); postorder(root); printf("\n");
                break;
            case 5: exit(0);
            default: printf("Try again.\n");
        }
    }
    return 0;
}
