/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture04/linked_list_inclass.c
*/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node * next;
};

struct node* insert_at_end(struct node* head, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = new_node;
    return head;
}

void print_list(struct node *head) {
    while (head != NULL) {
        printf("|%d|%p| -> ", head->data, head->next);
        head = head->next;
    }
    printf("\n");
}

void delete_at_begin(struct node **phead) {
    struct node *first = *phead;
    *phead = (*phead)->next;
    free(first);
}

void addOne(int *pn) {
    *pn = *pn + 1;
}

int main() {
    int n = 100;
    addOne(&n);
    printf("n = %d\n", n);

    struct node * head = NULL;
    head = insert_at_end(head, 10);
    print_list(head);
    head = insert_at_end(head, 20);
    print_list(head);
    head = insert_at_end(head, 30);
    print_list(head);
    delete_at_begin(&head);
    print_list(head);
    delete_at_begin(&head);
    print_list(head);
    delete_at_begin(&head);
    print_list(head);
    return 0;
}
