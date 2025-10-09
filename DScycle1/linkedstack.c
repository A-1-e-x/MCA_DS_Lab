#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node*top=NULL;

void push();
void pop();
void display();
void peek();
void search();


void push()
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\nNo Space Available\n");
		return;
	}
	newnode->link=NULL;
	printf("\nEnter the value to insert to front\n");
	scanf("%d",&newnode->data);
	if(top==NULL)
	{
		top=newnode;
	}
	else
	{
		newnode->link=top;
		top=newnode;
	}
	printf("\nElement inserted %d",newnode->data);
}

void pop()
{
	struct node *temp=top;
	if(top==NULL)
	{
		printf("\n STACK UNDERFLOW\n");
		return;
	}
	printf("\n %d is popped",temp->data);
	top=temp->link;
	free(temp);
}

void display()
{
	struct node *temp=top;
	if(top==NULL)
	{
		printf("\nNo Elements\n");
		return;
	}
	printf("\n Elements in stack are:\n");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->link;
	}
}

void peek()
{
	struct node *temp=top;
	if(top==NULL)
	{
		printf("\nSTACK UNDERFLOW\n");
		return;
	}
	printf("Top element is %d",temp->data);
}

void search()
{
	struct node *temp=top;
	int key,found=0,pos=0;
	if(top==NULL)
	{
		printf("\n STACK UNDER FLOW\n");
		return;
	}
	printf("\n Enter the elments to search\n");
	scanf("%d",&key);
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			printf("\n %d Elements found at %d\n",temp->data,pos+1);
			found=1;
		}
		temp=temp->link;
		pos++;
	}
	if(!found)
	{
		printf("\n Elements not founded\n");
	}
}

void main()
{
	int choice;
	do{
		printf("\n......STACK.......\n");
		printf("\n1.push()\n2.pop()\n3.peek()\n4.display()\n5.search()\n6.Exit");
		printf("\n Enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: peek();
				break;
			case 4: display();
				break;
			case 5: search();
				break;
			case 6: printf("\n Exit\n");
				break;
			default: printf("Enter vaild choice");
				 break;
		}
	}while(choice!=6);
}					 
