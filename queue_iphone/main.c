#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10

//cau truc nguoi mua: Gom ten, tuoi
typedef struct BUYER
{
    char name[20];
    int age;
} buyer_t;

/*
Cau truc hang:
Gom vi tri dau tien (front): Nguoi mua den som nhat dang o vi tri nay
vi  tri cuoi cung (rear): Tong so luong nguoi mua
va so luu tru con tro tro den thong tin nguoi mua (Buyer_t):
(buyer_t items[SIZE])
*/
typedef struct QUEUE
{
    int front;      //
    int rear;
    buyer_t *items[SIZE];
} queue_t;

/*
Ham khoi tao queue:
Khoi tao queue de bat dau xep hang.
Set default vi tri con tro front va rear = -1.
*/
void init_queue(queue_t *q)
{
    q->front = -1;
    q->rear = -1;
}

/*
Ham queue is_empty:
Luc nay con tro front se tro ve = -1;
*/
bool is_empty(queue_t *q)
{
    return q->front == -1;
}
/*
Ham queue is_full:
Full du SIZE (so luong nguoi), khi nay return
con tro rear = so luong nguoi -1.
*/
bool is_full(queue_t *q)
{
    return q->rear == SIZE -1;
}

/*
Ham in queue:
In ra thanh phan trong queue, muc dich de biet
con tro front rear dang o dau, va dang den buyer nao.
*/
void print_queue(queue_t *q)
{
    if (!is_empty(q))
    {
        printf("Queue: [Front: %d, Rear: %d, Items: \n", q->front, q->rear);
        for (int i = q->front; i < q->rear; i++)
        {
            printf("%d", *(q->items[i]));
            if (i != q->rear)
            {
                printf(" , ");
            }
        }
        printf("].\n");
    }
}

/*
TODO: Viet ham buyer info, ham enqueue, dequeue, ham main
*/

void buyer_info (queue_t *q)

int main()
{
    return 0;
}
