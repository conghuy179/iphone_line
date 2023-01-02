#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

/*
Define a struct to represent a person
*/
typedef struct PERSON
{
  char name[20];
  int age;
} person_t;

typedef struct QUEUE
{
  person_t *items[SIZE]; // items is an array holding pointers to actual values
  int rear;              // rear is the position of the last element
  int front;             // front is the position of the first element
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
A queue is empty if it does not contain any elelments, which means q->front is -1.
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

void print_person(person_t *p)
{
  printf("PERSON[name=%s, age=%d]\n", p->name, p->age);
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
      print_person(q->items[i]);
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
void enqueue(queue_t *q, person_t *value_ptr)
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

    printf("DEBUG: enqueue: inserted to pos. %d in queue; value = ", q->rear + 1);
    print_person(value_ptr);
  }
  else
  {
    // if queue is full, just print out the queue
    printf("DEBUG: enqueue: queue is full.\n");
    print_queue(q);
  }
}

person_t *dequeue(queue_t *q)
{
  if (is_empty(q))
  {
    // if queue is empty, just print out a message and return a NULL pointer
    printf("DEBUG: dequeue: queue is empty.\n");
    return NULL;
  }
  else
  {

    person_t *elem = q->items[q->front]; // get the front element
    q->front++;                          // increment the front position
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

  // two men are waiting for buying iPhone
  person_t p1 = {.name = "Huy", .age = 28};
  person_t p2 = {.name = "Huyen", .age = 28};

  // p1 enters the queue first
  enqueue(&q, &p1);
  // then p2 enter the queue
  enqueue(&q, &p2);

  print_queue(&q);

  // now the store opens and serves one by one
  person_t *elem = dequeue(&q);

  while (elem != NULL)
  {
    printf("dequeue: ");
    print_person(elem);
    print_queue(&q);
    elem = dequeue(&q);
  }

  return 0;
}
