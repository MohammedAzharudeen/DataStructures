//Doubly Linked List Implementation.

#include<stdlib.h>
#include<stdio.h>

struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node * head;                   //global variable - pointer to head node

struct Node * getNewNode(int x)       //to remove duplication of code we created a function
{
	struct Node * new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node -> data = x;
	new_node -> next = NULL;
	new_node -> prev = NULL;
	return new_node;
}

void insertAtBeginning(int x)
{
	struct Node * new_node = getNewNode(x);
	if(head == NULL)
	{
		head = new_node;
		return;
	}
	head -> prev = new_node;
	new_node -> next = head;
	head = new_node;
}

void insertAtEnd(int x)
{
	struct Node * temp = head;
	struct Node * new_node = getNewNode(x);
	if(head == NULL)
	{
		head = new_node;
		return;
	}
	while(temp -> next != NULL) temp = temp -> next;             //go to last node
	temp -> next = new_node;
	new_node -> prev = temp;
}

void print()
{
	struct Node* temp = head;
	printf("List is : ");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void reversePrint()
{
	struct Node * temp = head;
	if(temp == NULL) return;            //empty list, exit
	//going to last node
	while(temp -> next != NULL)
	{
		temp = temp -> next;
	}
	//traversing backward using prev pointer
	printf("Reverse : ");
	while(temp != NULL)
	{
		printf("%d ",temp -> data);
		temp = temp -> prev;
	}
	printf("\n");
}

int main()
{
	head = NULL;                          //empty list
	insertAtBeginning(2); print(); reversePrint();
	insertAtBeginning(4); print(); reversePrint();
	insertAtBeginning(6); print(); reversePrint();
	insertAtBeginning(8); print(); reversePrint();
	insertAtEnd(10); print(); reversePrint();
	insertAtEnd(12); print(); reversePrint();
}
