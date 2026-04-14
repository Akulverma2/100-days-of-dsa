#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* deleteKey(struct Node* head, int key) {
    struct Node *temp = head, *prev = NULL;
    if(temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        return head;
    }
    prev->next = temp->next;
    free(temp);

    return head;
}
int main() {
    int n;
    scanf("%d", &n);
    struct Node *head = NULL, *temp = NULL, *newNode;
    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    int key;
    scanf("%d", &key);
    head = deleteKey(head, key);
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}