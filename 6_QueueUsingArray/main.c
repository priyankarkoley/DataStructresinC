#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void view();

int *a, max, front=-1, rear=-1;

void main()
{
    int choice;
    printf("Enter the size of Queue: ");
    scanf("%d", &max);
    a = (int *)malloc(max * sizeof(int));
    while(1)
    {
        printf("\n\n\n1.PUSH an element into the Queue\n2.POP an element from the Queue\n3.View the elements of the Queue\n4. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            view();
            break;
        case 4:
            exit(0);
            break;
        }
    }
}

void push()
{
    if(rear==max-1)
    {
        printf("Can not PUSH. Queue Overflow.");
    }
    else if(rear==-1)
    {
        rear = 0;
        front = 0;
        printf("Enter the element to PUSH: ");
        scanf("%d", &a[rear]);
    }
    else
    {
        rear++;
        printf("Enter the element to PUSH: ");
        scanf("%d", &a[rear]);
    }
    view();
}

void pop()
{
    if(rear==-1)
    {
        printf("Can not POP. Queue Underflow");
    }
    else if(front==rear)
    {
        rear = -1;
        front = -1;
    }
    else
    {
        front++;
    }
    view();
}

void view()
{
    printf("\n");
    if(rear==-1)
    {
        printf("Nothing to display. Queue Underflow.");
    }
    else
    {
        int i;
        for(i=front; i<=rear; i++)
            printf("%d->", a[i]);
    }
    //printf("\nFront = %d\n Rear = %d", front, rear);
}