/**

This is a program developed by Priyankar Koley.
It's a menu-driven program. In this program user can
1. Create a Circular Linked List
2. Insert a NODE at the beginning
3. Insert a NODE at the end
4. Insert a NODE after any element
5. Delete a NODE at the beginning
6. Delete a NODE at the end
7. Delete any NODE
8. View the list
9. Sort the list
10. Reverse the list
11. Search in the list
OR, 12. EXIT

**/

#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int x;
    struct list* next;
} cl;

char ch;
cl* head;

void create(cl*);
void insert(cl*);
    void insertAtBeginning(cl*);
    void insertAtEnd(cl*);
    void insertAfterAnyPos(cl*);
void delete_(cl*);
    void deleteAtBeginning(cl*);
    void deleteAtEnd(cl*);
    void deleteAtAnyPos(cl*);
void view(cl*);


void main()
{
	int choice;
	head =(cl*)malloc(sizeof(cl));
	while(1)
    {
        printf("\n\n\n\n1. Create a Circular Linked List\n2. Insert a NODE \n3. Delete a NODE\n4. View the list\n5. Exit");
        printf("\n\nEnter Choice :");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			create(head);
			break;
		case 2:
			insert(head);
			break;
		case 3:
			delete_(head);
            break;
        case 4:
            view(head);
            break;
        case 5:
            exit(0);
            break;
		default:
			printf("Incorrect Choice\n");
		}
	}
}


void create(cl* ptr)
{
    printf("Enter the value: ");
    scanf("%d", &ptr->x);
    ptr->next=head;
    printf("Do you want to continue?");
    scanf(" %c", &ch);
    while(ch=='y'||ch=='Y')
    {
        ptr->next=(cl*)malloc(sizeof(cl));
        ptr=ptr->next;
        create(ptr);
    }
}

void view(cl* ptr)
{
    do{
            printf("\n%d", ptr->x);
            ptr=ptr->next;
    }while(ptr!=head);
}

void insert(cl*ptr)
{
    int choice;
    printf("\n\n1. Insert a NODE at the beginning\n2. Insert a NODE at the end\n3. Insert a NODE after any element");
    printf("\n\nEnter Choice :");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			create(ptr);
			break;
		case 2:
			insertAtBeginning(ptr);
			break;
		case 3:
			insertAtEnd(ptr);
			break;
        default:
			printf("Incorrect Choice\n");

    }
}

void insertAtBeginning(cl* ptr)
{
    while(ptr->next!=head)
        ptr = ptr->next;
    cl* new = (cl*)malloc(sizeof(cl));
    printf("Enter the value: ");
    scanf("%d", &new->x);
    new->next = head;
    head = new;
    ptr->next = new;
}

void insertAtEnd(cl* ptr)
{
    cl* new = (cl*)malloc(sizeof(cl));
    printf("Enter the value: ");
    scanf("%d", &new->x);
    while(ptr->next!=head)
        ptr = ptr->next;
    new->next = ptr->next;
    ptr->next = new;
}

void insertAfterAnyPos(cl* ptr)
{
    int ele;
    printf("Enter the element to insert after: ");
    scanf("%d", &ele);
    while(ptr->next!=head)
    {
        if(ptr->x == ele)
        {
            cl* new = (cl*)malloc(sizeof(cl));
            printf("Enter the value: ");
            scanf("%d", &new->x);
            new->next = ptr->next;
        }
        ptr = ptr->next;
    }
}

void delete_(cl* ptr)
{
    int choice;
    printf("\n\n1. Delete a NODE at the beginning\n2. Delete a NODE at the end\n3. Delete any element");
    printf("\n\nEnter Choice :");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        deleteAtBeginning(ptr);
        break;
    case 2:
        deleteAtEnd(ptr);
        break;
    case 3:
        deleteAtAnyPos(ptr);
        break;
    default:
        printf("Incorrect Choice\n");
    }
}

void deleteAtBeginning(cl* ptr)
{
    while(ptr->next!=head)
        ptr = ptr->next;
    ptr->next = head->next;
    cl* node = head;
    head = ptr->next;
    free(node);
}

void deleteAtEnd(cl* ptr)
{
    cl* preptr;
    cl* node;
    while(ptr->next!=head)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = head;
    node = ptr;
    free(node);
}

void deleteAtAnyPos(cl* ptr)
{
    int ele;
    cl* node;
    cl* preptr;
    printf("Enter the value to be deleted: ");
    scanf("%d", &ele);
    while(ptr->next!=head)
    {
        if(ptr->x == ele)
        {
            preptr->next = ptr->next;
            node = ptr;
            free(ptr);
        }
    }
}
