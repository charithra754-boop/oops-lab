#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* insert(Node* root, int val) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

Node* search(Node* root, int val) {
    if (root == NULL || root->data == val) return root;
    if (val < root->data) return search(root->left, val);
    return search(root->right, val);
}

Node* findMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int val) {
    if (root == NULL) return root;
    
    if (val < root->data) root->left = deleteNode(root->left, val);
    else if (val > root->data) root->right = deleteNode(root->right, val);
    else {
        // Node found
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Two children: Get inorder successor (min in right subtree)
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, val;
    
    while(1) {
        printf("\nBST Menu: 1.Insert 2.Search 3.Delete 4.Inorder 5.Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
                printf("Value: "); scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Search Value: "); scanf("%d", &val);
                if (search(root, val)) printf("Found\n");
                else printf("Not Found\n");
                break;
            case 3:
                printf("Delete Value: "); scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 4:
                printf("Tree: "); inorder(root); printf("\n");
                break;
            case 5: exit(0);
        }
    }
    return 0;
}