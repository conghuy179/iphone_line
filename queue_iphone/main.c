#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 5

typedef struct buyer_info
{
    char name[100];
    int age;
    char gender[2];
    int number;
} buyer;

typedef struct QUEUE
{
    int front;
    int rear;
    int *items[SIZE];
} queue;

void init_queue (queue *q)
{
    q->front = -1;
    q->rear = -1;
}

bool is_empty (queue *q)
{
   return q->front == -1;
}

bool is_full (queue *q)
{
    return q->rear == SIZE - 1;
}

void print_queue(queue *q)
{
    if (!is_empty(q))
    {
        printf("There are people in line: [Front: %d. Rear: %d. Items=[", q->front, q->rear);
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d", *(q->items[i]));
            if (i != q->rear)
            {
                printf(", ");
            }
        }
        printf("]]\n");

    }
    else
    {
        printf("There are %d people waiting in line", q->rear);
    }
}

// buyer_ptr is the pointer to buyer that will be enqueued
void enqueue (queue *q, int *buyer_ptr)
{
    if (!is_full(q))
    {
        if (is_empty(q))
        {
            q->front = 0;
        }
        else
        {
            q->rear++;
            q->items[q->rear]= buyer_ptr;
            printf("DEBUG: Enqueue: Inserted person number %d to pos. %d people in queue.\n", *buyer_ptr, q->rear + 1);
        }
    }
    else
    {
        printf("The queue is full.\n");
        print_queue(q);
    }
}

int dequeue (queue *q)
{
    if (!is_empty(q))
    {
        // get the first buyer
        int ip_buyer = q->items[q->front];
        q->front++;

        if (q->front > q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        return ip_buyer;
    }
    else
    {
        printf("Queue is empty.\n");
        return NULL;
    }
}
int main()
{
    queue *q;
    init_queue(&q);

   struct buyer_info b1, b2, b3, b4, b5;

    enqueue(&q, &b1);
    enqueue(&q, &b2);
    enqueue(&q, &b3);
    enqueue(&q, &b4);
    enqueue(&q, &b5);

    print_queue(&q);

    int *ip_buyer = dequeue(&q);

    while (ip_buyer != NULL)
    {
        printf("\nDequeued: elem = %d.\n", *ip_buyer);
        print_queue(&q);
        ip_buyer = dequeue(&q);
    }

    return 0;
}
