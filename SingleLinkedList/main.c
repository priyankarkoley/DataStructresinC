#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct list {
	int roll;
	struct list* next;
}l;
l* head;
int count = 0;

// Function to PUSH a node
void PUSH()
{
    l* temp;
    if (count==0){
        head=(l*)malloc(sizeof(l));//first node created and address stored in head
        temp=head;
        //Filling Up Values
        printf("Enter Roll No: ");
        scanf("%d", &temp->roll);
        temp->next=NULL;
        count++;
    }
    else{
        temp->next=(l*)malloc(sizeof(l));
        temp=temp->next;
        //Filling Up Values
        printf("Enter Roll No: ");
        scanf("%d", &temp->roll);
        temp->next=NULL;
        count++;
    }
}

// Function to POP last node
void POP()
{
	l *temp, *prevnode;
	if (count==0)
		printf("\nList is Empty\n");
	else {
		temp = head;
		while (temp->next != NULL) {
			prevnode = temp;
			temp = temp->next;
		}
		printf("Deleted Value is: %d", temp->roll);
		free(temp);
		prevnode->next = NULL;
		count--;
	}
}

// Function to VIEW the list
void VIEW()
{
	l* temp;

	// List is empty
	if (count==0)
		printf("\nList is empty\n");

	// Else print the LL
	else {
		temp = head;
		while (temp != NULL) {
			printf("Roll = %d\n", temp->roll);
			temp = temp->next;
		}
	}
}


// Function to REVERSE the list
void REV()
{
	l *t1, *t2, *temp;
	t1 = t2 = NULL;

	if (count==0)
		printf("List is empty\n");
	else {
		while (head != NULL) {

			// reversing of points
			t2 = head->next;
			head->next = t1;
			t1 = head;
			head = t2;
		}
		head = t1;
		// New head Node
		temp = head;

		printf("Reversed list is : ");
		// Print the LL
		while (temp != NULL) {
			printf("%d ", temp->roll);
			temp = temp->next;
		}
	}
}
void main()
{
	int choice;
	while(1) {
        //clrscr();
		printf("\n\tPress 1 To see list\n");
		printf("\tPress 2 For insert node\n");
		printf("\tPress 3 For delete node\n");
		printf("\tPress 4 To reverse the list\n");
		printf("\tPress 5 To show number of elements\n");
		printf("\tPress 6 To exit\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			VIEW();
			break;
		case 2:
			PUSH();
			break;
		case 3:
			POP();
			break;
		case 4:
			REV();
			break;
        case 5:
            printf("There are %d elements in the list!",count);
            break;
		case 6:
			exit(0);
			break;
		default:
			printf("Incorrect Choice\n");
		}
	}
}
