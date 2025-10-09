#include <stdio.h>
#include <stdlib.h> 

#define MAX 10

struct node {
    int data;
    struct node *link;
};  

struct node *head = NULL;

void InsertFirst();
void InsertLast();
void InsertLocation();

void DeleteFirst();
void DeleteLast();
void DeleteLocation();

void DisplayList();

void InsertFirst() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Space Not Available\n");
        return;
    }
    newnode->link = NULL;
    printf("\nEnter the value to insert at the front: ");
    scanf("%d", &newnode->data);

    newnode->link = head;
    head = newnode;

    printf("Element Inserted: %d\n", newnode->data);
}

void InsertLast() {
    struct node *temp = head, *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Space Not Available\n");
        return;
    }
    newnode->link = NULL;
    printf("\nEnter the value to insert at the end: ");
    scanf("%d", &newnode->data);

    if (head == NULL) {
        head = newnode;
    } else {
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newnode;
    }

    printf("Element Inserted Successfully\n");
}

void InsertLocation() {
    int key;
    struct node *temp = head, *newnode;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter the key (node data) after which to insert: ");
    scanf("%d", &key);

    while (temp != NULL && temp->data != key) {
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Key not found in the list.\n");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Space Not Available\n");
        return;
    }

    printf("Enter the value to insert after %d: ", key);
    scanf("%d", &newnode->data);

    newnode->link = temp->link;
    temp->link = newnode;

    printf("Element Inserted Successfully after %d\n", key);
}

void DeleteFirst() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node *temp = head;
    head = head->link;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void DeleteLast() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node *temp = head, *prev = NULL;

    if (head->link == NULL) {  
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }

    printf("Deleted element: %d\n", temp->data);
    prev->link = NULL;
    free(temp);
}
void DeleteLocation() {
    int key;
    struct node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    printf("Enter the value to delete: ");
    scanf("%d", &key);

    if (head->data == key) {
        temp = head;
        head = head->link;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Element %d not found in the list.\n", key);
        return;
    }

    prev->link = temp->link;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void DisplayList() {
    struct node *temp = head;
    printf("\nCurrent List: ");
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void search(){
	struct node *temp = head;
	int pos=0,found=0,val;
	 if (head == NULL) {
        printf("Empty\n");
        return;
    }
    printf("\n Enter the Value to Search :\t");
    scanf("%d",&val);
    while(temp != NULL){
    	if(temp->data == val){
    		printf("\n%d value found at position %d\n",temp->data,pos);
    		found = 1;
    	}
    	pos++;
    	temp = temp->link;
    }
    if(found == 0){
    		printf("Element Not Found\n");
    	}
}

int main() {
    int choice;
    printf("Singly Linked List!\n");
    
    do{
    
    	printf("\n 1.InsertFirst\n 2.InsertLast\n 3.InsrtLocation\n 4.DeleteFirst\n 5.DeleteLast\n 6.Deleteocation\n 7.Search\n 8.Display\n 9.Exit");
    	printf("\nEnter the choice\n");
    	scanf("%d",&choice);
    	
    	switch(choice){
    		case 1 : InsertFirst();
    			  break;
    			  
    		case 2 : InsertLast();
    			  break;
    			  
    		case 3 : InsertLocation();
    			  break;
    			  
    		case 4 : DeleteFirst();
    			  break;
    			  
    		case 5 : DeleteLast();
    			  break;
    			  
    		case 6 : DeleteLocation();
    			  break;
    			  
    			  
    		case 7 : search();
    			  break;
    			  
    		case 8 : DisplayList();
    			  break;
    			  
    		case 9 : printf("\nExit...\n");
    			  exit(0);
    			  break;
    			  
    		default : printf("Invalid Choice");
    	}
    
    }while(choice !=9);

    return 0;
}
