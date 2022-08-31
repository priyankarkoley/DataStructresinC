#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void view();

int *a, max, top=-1;

void main()
{
    int choice;
    printf("Enter the size of Stack: ");
    scanf("%d", &max);
    a = (int *)malloc(max * sizeof(int));
    while(1)
    {
        printf("\n\n\n1.PUSH an element into the stack\n2.POP an element from the stack\n3.View the elements of the stack\n4. Exit");
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
    if(top==max-1)
    {
        printf("Can not PUSH. Stack Overflow.");
    }
    else
    {
        top++;
        printf("Enter the element to PUSH: ");
        scanf("%d", &a[top]);
    }
}

void pop()
{
    if(top==-1)
    {
        printf("Can not POP. Stack Underflow");
    }
    else
    {
        top--;
    }
}

void view()
{
    if(top==-1)
    {
        printf("Nothing to display. Stack Underflow.");
    }
    else
    {
        int i;
        for(i=0; i<=top; i++)
            printf("%d->", a[i]);
    }
}