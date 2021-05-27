//Insert at the Nth position

#include<stdlib.h>
#include<stdio.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* head;

void insertAtTheNthPosition(int data,int n)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node -> data = data;
	new_node -> next = NULL;
	if(n==1)
	{
		new_node -> next = head;
		head = new_node;
		return;
	}
	struct Node* temp = head;
	for(int i=0;i<n-2;i++)
	{
		temp = temp -> next;
	}
	new_node -> next = temp -> next;
	temp -> next = new_node;
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

int main()
{
	head = NULL;         //empty list
	printf("How many numbers to be inserted?\n");
	int n,i,x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the number and its position :\n");
		scanf("%d %d",&x,&y);
		insertAtTheNthPosition(x,y);
		print();
	}
}
