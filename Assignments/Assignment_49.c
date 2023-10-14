#include <stdio.h>
#include <stdlib.h>

#define INVALID_QUEUE_STATE 1
#define OVERFLOW 2
#define UNDERFLOW 3

struct Queue {
    int capacity;
    int front, rear;
    int *ptr;
};

void initQueue(struct Queue *q, int cap);
// void copyQueue(struct Queue *dest, const struct Queue *src);
// void assignQueue(struct Queue *dest, const struct Queue *src);
void insert(struct Queue *q, int data);
int isFull(const struct Queue *q);
int isEmpty(const struct Queue *q);
int getFront(const struct Queue *q);
int getRear(const struct Queue *q);
void del(struct Queue *q);
int count(const struct Queue *q);
// void destroyQueue(struct Queue *q);

int main() {
    struct Queue myQueue;
    initQueue(&myQueue, 5);

    // Example usage
    insert(&myQueue, 1);
    insert(&myQueue, 2);
    insert(&myQueue, 3);

    printf("Front: %d\n", getFront(&myQueue));
    printf("Rear: %d\n", getRear(&myQueue));

    del(&myQueue);

    printf("Front after deletion: %d\n", getFront(&myQueue));
    printf("Count: %d\n", count(&myQueue));

    destroyQueue(&myQueue);

    return 0;
}

void initQueue(struct Queue *q, int cap) {
    q->capacity = cap;
    q->front = -1;
    q->rear = -1;
    if (cap > 0)
        q->ptr = (int *)malloc(cap * sizeof(int));
    else
        q->ptr = NULL;
}

// void copyQueue(struct Queue *dest, const struct Queue *src) {
//     dest->capacity = src->capacity;
//     dest->front = src->front;
//     dest->rear = src->rear;
//     dest->ptr = (int *)malloc(dest->capacity * sizeof(int));
//     for (int i = 0; i < dest->capacity; i++)
//         dest->ptr[i] = src->ptr[i];
// }

// void assignQueue(struct Queue *dest, const struct Queue *src) {
//     if (dest->ptr != NULL)
//         free(dest->ptr);
//     copyQueue(dest, src);
// }

void insert(struct Queue *q, int data) {
    if (q->capacity <= 0)
        exit(INVALID_QUEUE_STATE);

    if (isFull(q))
        exit(OVERFLOW);

    if (q->rear == -1) {
        q->rear = q->front = 0;
        q->ptr[q->rear] = data;
    } 
    else if (q->rear == q->capacity - 1) {
        q->rear = 0;
        q->ptr[q->rear] = data;
    } else {
        q->rear++;
        q->ptr[q->rear] = data;
    }
}

int isFull(const struct Queue *q) {
    return (q->front == 0 && q->rear == q->capacity - 1) || (q->rear + 1 == q->front);
}

int isEmpty(const struct Queue *q) {
    return q->front == -1;
}

int getFront(const struct Queue *q) {
    if (isEmpty(q))
        exit(UNDERFLOW);
    return q->ptr[q->front];
}

int getRear(const struct Queue *q) {
    if (isEmpty(q))
        exit(UNDERFLOW);
    return q->ptr[q->rear];
}

void del(struct Queue *q) {
    if (isEmpty(q))
        exit(UNDERFLOW);

    if (q->rear == q->front) {
        q->front = q->rear = -1;
    } else if (q->front == q->capacity - 1)
        q->front = 0;
    else
        q->front++;
}

int count(const struct Queue *q) {
    if (q->front == -1)
        return 0;
    if (q->front == q->rear)
        return 1;
    if (q->rear > q->front)
        return q->rear - q->front + 1;
    else
        return q->capacity - q->front + q->rear + 1;
}

void destroyQueue(struct Queue *q) {
    free(q->ptr);
    q->ptr = NULL;
}
