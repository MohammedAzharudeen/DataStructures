//delete a node at the Nth position

#include<stdlib.h>
#include<stdio.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* head;

void insert(int data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node -> data = data;
	new_node -> next = NULL;
	if(head==NULL) 
		head = new_node;
	else
		new_node -> next = head;
		head = new_node;
}

void print()
{
	struct Node* temp = head;
	printf("List is : ");
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void Delete(int n)
{
	struct Node* temp = head;
	if(n==1)
	{
		head = temp -> next;      //head now points to second node.
		free(temp);
		return;
	}
	int i;
	for(i=0;i<n-2;i++)
	{
		temp = temp -> next;
		//temp points to (n-1)th Node
	}
	struct Node* temp1 = temp -> next;    //Nth Node
	temp->next = temp1 -> next;           //(n+1)th Node
	free(temp1);                          //delete temp1
}

int main()
{
	head = NULL;    //empty list
	insert(2);	
	insert(4);
	insert(6);
	insert(5);      //List : 2,4,6,5
	print();
	int n;
	printf("Enter a position : \n");
	scanf("%d",&n);
	Delete(n);
	print();
}
