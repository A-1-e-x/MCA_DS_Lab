#include<stdio.h>
#define MAX 5
int queue[MAX];
int font=-1,rear=-1;
int isfull()
{
	if((rear+1)%MAX==font)
	{
		return 1;
	}
	return 0;
}

int isempty()
{
	if(font==-1 && rear==-1)
	{
		return 1;
	}
	return 0;
}

void display()
{
	int i;
	if(isempty())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements are:");
	i=font;
	do{
		printf("%d\t",queue[i]);
		i=(i+1)%MAX;
	}while(i!=(rear+1)%MAX);
	printf("\n");
}

void dequeue()
{
	if(isempty())
	{
		printf("\n Queue is empty\n");
		return;
	}
	printf("\n %d is deleted\n",queue[font]);
	if(font==rear)
	{
		font=rear=-1;
	}
	else
	{
		font=(font+1)%MAX;
	}
}

void enqueue()
{
	int x;
	if(isfull())
	{
		printf("\nQueue is full\n");
		return;
	}
	printf("Enter the elements to insert:");
	scanf("%d",&x);
	if(isempty())
	{
		font=rear=0;
	}
	else
	{
		rear=(rear+1)%MAX;
	}
	queue[rear]=x;
	printf("\nElement %d inserted successfully\n",queue[rear]);
}

void search()
{
    int key, i, found = 0;
    if (isempty())
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nEnter the element to search:");
    scanf("%d", &key);
    i = font;
    do {
        if (queue[i] == key)
        {
            int pos = (i - font + MAX) % MAX + 1;
            printf("\nElement %d found at position %d\n", key, pos);
            found = 1;
            break;
        }
        i = (i + 1) % MAX;
    } while (i != (rear + 1) % MAX);
    if (!found)
    {
        printf("Element %d not found in the queue\n", key);
    }
}


int main()
{
	int choice;
	printf("Circular queue using array..");
	do{
		printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.SEARCH\n5.EXIT\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: enqueue();
			        break;
			case 2: dequeue();
			        break;
			case 3: display();
			        break;
			case 4: search();
			        break;
			case 5: printf("\nExiting....\n");
				return 0;
			default:printf("\nINVALID CHOICE\n");
			        break;
		}
	}while(choice!=5);
	return 0;
}        
