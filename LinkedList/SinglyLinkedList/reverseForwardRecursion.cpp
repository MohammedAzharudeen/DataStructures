//Print elements of a linked list in forward and reverse order using recursion

#include<stdlib.h>
#include<stdio.h>

struct Node
{
	int data;
	struct Node* next;
};

void print(struct Node * p)
{
	if(p == NULL) return;      //Exit condition
	printf("%d ",p->data);      //first print the value in the node
	print(p->next);            //Recursive call
}

void reversePrint(struct Node * p)
{
	if(p == NULL) return;      //Exit condition
	reversePrint(p->next);     //Recursive call
	printf("%d ",p->data);     //first print the value in the node

}

struct Node * insert(struct Node * head,int data)
{
	struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = data;
	temp -> next = NULL;
	if(head == NULL)
	{
		head = temp;
	}
	else
	{
		struct Node * temp1 = head;
		while(temp1 -> next != NULL)
		{
			temp1 = temp1 -> next;
		}
		temp1 -> next = temp;
	}
	return head;
}

int main()
{
	struct Node * head = NULL;      //local variable
	head = insert(head,2);
	head = insert(head,4);
	head = insert(head,6);
	head = insert(head,5);
	printf("List in forward order : \n");
	print(head);
	printf("\n");
	printf("List in reverse order : \n");
	reversePrint(head);
}
