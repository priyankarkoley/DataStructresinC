/**

This is a program developed by Priyankar Koley.
It's a menu-driven program. In this program user can
1. Create a Double Linked List
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
    struct list* prev;
    struct list* next;
} dll;

char ch;
dll* head;

void create(dll*);
void insert(dll*);
    void insertAtBeginning(dll*);
    void insertAtEnd(dll*);
    void insertAfterAnyPos(dll*);
void delete_(dll*);
    void deleteAtBeginning(dll*);
    void deleteAtEnd(dll*);
    void deleteAtAnyPos(dll*);
void view(dll*);


void main()
{
	int choice;
	head =(dll*)malloc(sizeof(dll));
	head->prev = NULL;
	while(1)
    {
        printf("\n\n\n\n1. Create a Double Linked List\n2. Insert a NODE \n3. Delete a NODE\n4. View the list\n5. Exit");
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


void create(dll* ptr)
{
    printf("Enter the value: ");
    scanf("%d", &ptr->x);
    ptr->next=NULL;
    printf("Do you want to continue?");
    scanf(" %c", &ch);
    while(ch=='y'||ch=='Y')
    {
        ptr->next=(dll*)malloc(sizeof(dll));
        ptr->next->prev = ptr;
        ptr=ptr->next;
        create(ptr);
    }
}

void view(dll* ptr)
{
    while(ptr->next!=NULL)
    {
        printf("\n%d", ptr->x);
        ptr=ptr->next;
    }
    while(ptr!=NULL)
    {
        printf("\n%d", ptr->x);
        ptr=ptr->prev;
    }
}

void insert(dll*ptr)
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

void insertAtBeginning(dll* ptr)
{
    dll* new = (dll*)malloc(sizeof(dll));
    printf("Enter the value: ");
    scanf("%d", &new->x);
    new->prev = head->prev;
    head->prev = new;
    head = new;
}

void insertAtEnd(dll* ptr)
{
    dll* new = (dll*)malloc(sizeof(dll));
    printf("Enter the value: ");
    scanf("%d", &new->x);
    while(ptr->next!=NULL)
        ptr = ptr->next;
    new->next = ptr->next;
    new->prev = ptr;
    ptr->next = new;
}

void insertAfterAnyPos(dll* ptr)
{
    int ele;
    printf("Enter the element to insert after: ");
    scanf("%d", &ele);
    while(ptr->next!=head)
    {
        if(ptr->x == ele)
        {
            dll* new = (dll*)malloc(sizeof(dll));
            printf("Enter the value: ");
            scanf("%d", &new->x);
            new->next = ptr->next;
        }
        ptr = ptr->next;
    }
}

void delete_(dll* ptr)
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

void deleteAtBeginning(dll* ptr)
{
    dll* node = ptr;
    head = ptr->next;
    head->prev = NULL;
    free(node);
}

void deleteAtEnd(dll* ptr)
{
    dll* preptr;
    dll* node;
    while(ptr!=NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    node = ptr;
    free(node);
}

void deleteAtAnyPos(dll* ptr)
{
    int ele;
    dll* node;
    dll* preptr;
    printf("Enter the value to be deleted: ");
    scanf("%d", &ele);
    while(ptr!=NULL)
    {
        if(ptr->x == ele)
        {
            preptr->next = ptr->next;
            ptr->next->prev = ptr->prev;
            node = ptr;
            free(ptr);
        }
    }
}
