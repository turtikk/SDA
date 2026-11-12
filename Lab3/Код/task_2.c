#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
 
#define SIZE 10 // 10 символів вибрано свідомо, так простіше для тестів і не міняє суть програми, а 50+ символів було б важко вводити
 
//Реалізація черги на однозв'язному списку»
typedef struct Node {
    char value;
    struct Node *next;
} Node;
 
typedef struct {
    Node *head;
    Node *tail;
    int count;
} Queue;
 
void init_queue(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
    q->count = 0;
}
 
bool is_empty(Queue *q) {
    return q->count == 0;
}
 
bool is_full(Queue *q) {
    return q->count == SIZE;
}
 
bool enqueue(Queue *q, char value) {
    Node *node;
    if (is_full(q)) {
        return false;
    }
    node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        return false;
    }
    node->value = value;
    node->next = NULL;
    if (q->tail == NULL) {
        q->head = node;
    } else {
        q->tail->next = node;
    }
    q->tail = node;
    q->count++;
    return true;
}
 
bool dequeue(Queue *q, char *result) {
    Node *old;
    if (is_empty(q)) {
        return false;
    }
    old = q->head;
    *result = old->value;
    q->head = old->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(old);
    q->count--;
    return true;
}
 
bool peek_front(Queue *q, char *result) {
    if (is_empty(q)) {
        return false;
    }
    *result = q->head->value;
    return true;
}

// Симуляція буфера клавіатури  
void print_queue(Queue *q) {
    Node *current = q->head;
    printf("Buffer [%d/%d]: ", q->count, SIZE);
    while (current != NULL) {
        printf("%c ", current->value);
        current = current->next;
    }
    printf("\n");
}
 
void clear_input() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}
 
int main() {
    Queue q;
    char choice, symbol;
 
    init_queue(&q);
 
    do {
        printf("\n1-add 2-read 3-peek 4-print 0-exit: ");
        scanf(" %c", &choice);
        clear_input();
 
        if (choice == '1') {
            printf("Enter a symbol: ");
            scanf(" %c", &symbol);
            clear_input();
            if (enqueue(&q, symbol)) {
                printf("Added '%c'\n", symbol);
            } else {
                printf("Buffer is full! Symbol '%c' rejected\n", symbol);
            }
        } else if (choice == '2') {
            if (dequeue(&q, &symbol)) {
                printf("Read '%c'\n", symbol);
            } else {
                printf("Buffer is empty!\n");
            }
        } else if (choice == '3') {
            if (peek_front(&q, &symbol)) {
                printf("Oldest: '%c'\n", symbol);
            } else {
                printf("Buffer is empty!\n");
            }
        } else if (choice == '4') {
            print_queue(&q);
        } else if (choice != '0') {
            printf("Unknown option\n");
        }
    } while (choice != '0');
 
    print_queue(&q);
    while (dequeue(&q, &symbol)) {}
    return 0;
}
