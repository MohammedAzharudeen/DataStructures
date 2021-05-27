//Inserting a node at beginning.

#include<stdlib.h>
#include<stdio.h>

struct Node
{
	int data;
	struct Node* next;
};


struct Node* head;           //global variable, can be accessed anywhere.

void insertAtTheBeginning(int x)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node -> data = x;
	new_node -> next = NULL;
	if(head==NULL)
	{
		head = new_node;
	}
	else
	{
		new_node -> next = head;
		head = new_node;
	}
}

void print(){
	struct Node* temp = head;
	printf("List is : ");
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	head = NULL;            //empty list
	printf("How many numbers to be inserted?\n");
	int n,i,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the number :\n");
		scanf("%d",&x);
		insertAtTheBeginning(x);
		print();
	}
}
