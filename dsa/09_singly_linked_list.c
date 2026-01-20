#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;
Node *head = NULL;

Node* createNode(int d) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = d; n->next = NULL;
    return n;
}

void ins_beg() {
    int d; printf("Val: "); scanf("%d", &d);
    Node *n = createNode(d);
    n->next = head; head = n;
}

void ins_end() {
    int d; printf("Val: "); scanf("%d", &d);
    Node *n = createNode(d);
    if (!head) head = n;
    else {
        Node *t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
}

void ins_pos() {
    int k, d, i; printf("Pos & Val: "); scanf("%d%d", &k, &d);
    if (k == 1) { Node *n = createNode(d); n->next = head; head = n; return; }
    Node *t = head;
    for (i = 1; i < k - 1 && t; i++) t = t->next;
    if (t) {
        Node *n = createNode(d);
        n->next = t->next; t->next = n;
    } else printf("Invalid pos\n");
}

void del_beg() {
    if (!head) { printf("Empty\n"); return; }
    Node *t = head; head = head->next;
    printf("Del: %d\n", t->data); free(t);
}

void del_end() {
    if (!head) { printf("Empty\n"); return; }
    if (!head->next) { printf("Del: %d\n", head->data); free(head); head = NULL; return; }
    Node *t = head;
    while (t->next->next) t = t->next;
    printf("Del: %d\n", t->next->data); free(t->next); t->next = NULL;
}

void del_pos() {
    int k, i; printf("Pos: "); scanf("%d", &k);
    if (!head) return;
    if (k == 1) { del_beg(); return; }
    Node *t = head;
    for (i = 1; i < k - 1 && t->next; i++) t = t->next;
    if (t->next) {
        Node *d = t->next; t->next = d->next;
        printf("Del: %d\n", d->data); free(d);
    } else printf("Invalid pos\n");
}

void show() {
    Node *t = head; printf("List: ");
    while (t) { printf("%d -> ", t->data); t = t->next; }
    printf("NULL\n");
}

int main() {
    int c;
    while (1) {
        printf("\n1.InBeg 2.InEnd 3.InPos 4.DelBeg 5.DelEnd 6.DelPos 7.Show 8.Exit: ");
        scanf("%d", &c);
        switch(c) {
            case 1: ins_beg(); break;
            case 2: ins_end(); break;
            case 3: ins_pos(); break;
            case 4: del_beg(); break;
            case 5: del_end(); break;
            case 6: del_pos(); break;
            case 7: show(); break;
            case 8: exit(0);
            default: printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}