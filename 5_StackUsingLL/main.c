#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int x;
    struct list *next;
} l;

void push();
void pop();
void view();

l *head=NULL;

void main()
{
    int choice;
    while(1)
    {
        printf("\n\n\n1.PUSH an element into the Stack\n2.POP an element from the Stack\n3.View the elements of the Stack\n4.Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(head);
            break;
        case 2:
            pop(head);
            break;
        case 3:
            view(head);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Incorrent Choice. Try again.");
        }
    }
}

void push(l *ptr)
{
    if(head==NULL)
    {
        head = (l*)malloc(sizeof(l));
        printf("Enter the value: ");
        scanf("%d", &head->x);
        head->next=NULL;
    }
    else
    {
        l *new = (l *)malloc(sizeof(l));
        printf("Enter the value: ");
        scanf("%d", &new->x);
        new->next=NULL;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
}
void pop(l *preptr)
{
    if(head==NULL)
    {
        printf("Stack Underflow. Nothing to delete. ");
    }
    else if((head->next==NULL)&&(head!=NULL))
    {
        free(head);
        head = NULL;
    }
    else
    {
        l *ptr = preptr->next, *node;
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next=NULL;
        node = ptr;
        free(node);
    }
}

void view(l *ptr)
{
    if(head==NULL)
    {
        printf("Stack Undeflow. Nothing to print.");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d->", ptr->x);
            ptr = ptr->next;
        }
    }
}