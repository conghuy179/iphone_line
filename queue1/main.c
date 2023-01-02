#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

typedef struct QUEUE
{
    int *items[SIZE]; // items is an array holding pointers to actual values
    int rear;         // rear is the position of the last element
    int front;        // front is the position of the first element
} queue_t;

/*
Initialize a queue by setting its rear and front to -1.
Parameters:
  q is the pointer to the queue
*/
void init_queue(queue_t *q)
{
    q->rear = -1;
    q->front = -1;
}

/*
A queue is empty if it does not contain any elements, which means q->front is -1.
Parameters:
  q is the pointer to the queue
*/
bool is_empty(queue_t *q)
{
    return q->front == -1;
}

/*
A queue is full if it does not contain any empty slot, which means it is at its full capacity (i.e. q->rear == SIZE - 1)
*/
bool is_full(queue_t *q)
{
    return q->rear == SIZE - 1;
}

/*
Display all elements in a queue.
Parameters:
  q is the pointer to the queue
*/
void print_queue(queue_t *q)
{
    if (!is_empty(q))
    {
        printf("queue [front=%d, rear=%d, items=[", q->front, q->rear);
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
        printf("the queue is empty [front=%d, rear=%d].\n", q->front, q->rear);
    }
}

/*
Add an element to a queue.
Parameters:
  q is the pointer to the queue
  value_ptr is the pointer to the element to add.
*/
void enqueue(queue_t *q, int *value_ptr)
{
    if (!is_full(q))
    {
        // if the queue is not full, we can add the element
        if (is_empty(q))
        {
            // queue is empty, we set the front position to 0
            q->front = 0;
        }
        q->rear++;                     // increment the rear position
        q->items[q->rear] = value_ptr; // point the item at rear position to the value

        printf("DEBUG: enqueue: inserted %d to pos. %d in queue.\n", *value_ptr, q->rear + 1);
    }
    else
    {
        // if queue is full, just print out the queue
        printf("DEBUG: enqueue: queue is full.\n");
        print_queue(q);
    }
}

int *dequeue(queue_t *q)
{
    if (is_empty(q))
    {
        // if queue is empty, just print out a message and return a NULL pointer
        printf("DEBUG: dequeue: queue is empty.\n");
        return NULL;
    }
    else
    {

        int *elem = q->items[q->front]; // get the front elelemnt
        q->front++;                     // increment the front position
        if (q->front > q->rear)
        {
            // reset if we read the end of queue
            q->front = -1;
            q->rear = -1;
        }

        // return the pointer to the element
        return elem;
    }
}

int main()
{
    queue_t q;
    init_queue(&q);

    int arr[] = {7, 8, 9};

    enqueue(&q, &arr[0]);
    enqueue(&q, &arr[1]);
    enqueue(&q, &arr[2]);

    print_queue(&q);

    int *elem = dequeue(&q);

    while (elem != NULL)
    {
        printf("\ndequeued: elem = %d.\n", *elem);
        print_queue(&q);
        elem = dequeue(&q);
    }

    return 0;
}
