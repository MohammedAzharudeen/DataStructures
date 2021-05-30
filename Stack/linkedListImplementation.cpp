//Stack - Linked List Implementation.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node * link;	
};

struct Node * top = NULL;

void push(int x)
{
	struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
	temp -> data = x;
	printf("Pushed number is : %d\n",temp->data);
	temp -> link = top;
	top = temp;
}

void pop()
{
	struct Node * temp;
	if(top == NULL) 
	{
		printf("ERROR : The List is Empty\n");
		return;
	}
	temp = top;
	top = top -> link;
	printf("Popped number is : %d\n",temp->data);
	free(temp);
}

void print(){
	struct Node* temp = top;
	printf("List is : ");
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		temp = temp->link;
	}
	printf("\n");
}

int main()
{
	push(2); print();
	push(4); print();
	push(6); print();
	push(8); print();
	pop(); print();
	pop(); print();
}
