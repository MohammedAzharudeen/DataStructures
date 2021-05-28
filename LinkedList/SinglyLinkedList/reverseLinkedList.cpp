//Reverse a Linked List

#include<stdlib.h>
#include<stdio.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* head;

void Reverse()
{
	struct Node *current,*prev,*next;
	current = head;
	prev = NULL;
	while(current!=NULL)
	{
		next = current ->next;
		current -> next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

void insert(int x)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node -> data = x;
	new_node -> next = NULL;
	if(head==NULL) 
		head = new_node;
	else
		new_node -> next = head;
		head = new_node;
}

void print(){
	struct Node* temp = head;
	//printf("List is : ");
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	head = NULL;    //empty list
	insert(2);	
	insert(4);
	insert(6);
	insert(5);      //List : 2,4,6,5
	printf("List is : ");
	print();
	printf("The reversed List is : ");
	Reverse();
	print();
	
}
