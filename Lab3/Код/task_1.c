#include <stdio.h>
#include <stdbool.h>
 
#define SIZE 10 // 10 символів вибрано свідомо, так простіше для тестів і не міняє суть програми, а 50+ символів було б важко вводити

// Реалізація кільцевого буфера на масиві 
typedef struct {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
} Queue;
 
void init_queue(Queue *q) {
    q->head = 0;
    q->tail = 0;
    q->count = 0;
}
 
bool is_empty(Queue *q) {
    return q->count == 0;
}
 
bool is_full(Queue *q) {
    return q->count == SIZE;
}
 
bool enqueue(Queue *q, char value) {
    if (is_full(q)) {
        return false;
    }
    q->buffer[q->tail] = value;
    q->tail = (q->tail + 1) % SIZE;
    q->count++;
    return true;
}
 
bool dequeue(Queue *q, char *result) {
    if (is_empty(q)) {
        return false;
    }
    *result = q->buffer[q->head];
    q->head = (q->head + 1) % SIZE;
    q->count--;
    return true;
}
 
bool peek_front(Queue *q, char *result) {
    if (is_empty(q)) {
        return false;
    }
    *result = q->buffer[q->head];
    return true;
}
 
void print_queue(Queue *q) {
    int i, index;
    printf("Buffer [%d/%d]: ", q->count, SIZE);
    for (i = 0; i < q->count; i++) {
        index = (q->head + i) % SIZE;
        printf("%c ", q->buffer[index]);
    }
    printf("\n");
}
 
// Симуляція буфера клавіатури 

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
