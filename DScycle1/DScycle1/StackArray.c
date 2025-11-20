#include <stdio.h>
#define MAX 10
int stack[MAX];
int top = -1;

void push(int);
void pop();
void peek();
void display();

void push(int item) 
{
    if (top == MAX - 1)
    {
        printf("\nStack Overflow\n");
        return;  
    }

    stack[++top] = item;
    printf("\n%d pushed to the Stack\n", item);
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow\n");
        return;  
    }
    printf("\nItem popped from the Stack (%d)\n", stack[top--]);
    
}

void peek() 
{
    if (top == -1) 
    {
        printf("\nStack Empty\n");
        return;  
    }

    printf("\nTop element in the Stack: %d\n", stack[top]);
}

void display() 
{
    if (top == -1) 
    {
        printf("\nStack Empty\n");
        return;  
    }

    printf("\nStack Elements Are: ");
    for (int i = top; i >= 0; i--) 
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() 
{
    int choice, value;
    while (1) {
        printf("\nStack Operation Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);  
        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;  
            case 2:
                pop();
                break;  
            case 3:
                peek();
                break;  
            case 4:
                display();
                break;  
                
            case 5:
                printf("Exiting Program...\n");
                return 0;

            default:
                printf("Invalid Selection\n");
        }
    }

    return 0;
}

