#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
    struct node *rlink;
};

struct node *head = NULL;

void insertfirst() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nNo Space Available\n");
        return;
    }
    printf("\nEnter the element to insert at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->link = NULL;
    newnode->rlink = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        newnode->rlink = head;
        head->link = newnode;
        head = newnode;
    }
    printf("%d inserted successfully.\n", newnode->data);
}

void insertlast() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nNo Space Available\n");
        return;
    }

    printf("\nEnter the value to insert at the end: ");
    scanf("%d", &newnode->data);
    newnode->link = NULL;
    newnode->rlink = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->rlink != NULL)
            temp = temp->rlink;
        temp->rlink = newnode;
        newnode->link = temp;
    }
    printf("%d inserted successfully.\n", newnode->data);
}

void insertlocation() {
    struct node *newnode, *temp = head, *nxt;
    int key;

    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("Enter the key after which you want to insert: ");
    scanf("%d", &key);

    while (temp != NULL && temp->data != key)
        temp = temp->rlink;

    if (temp == NULL) {
        printf("\nKey not found.\n");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nNo space available.\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &newnode->data);
    newnode->link = NULL;
    newnode->rlink = NULL;

    nxt = temp->rlink;
    newnode->link = temp;
    newnode->rlink = nxt;
    temp->rlink = newnode;
    if (nxt != NULL)
        nxt->link = newnode;

    printf("%d inserted successfully.\n", newnode->data);
}

void deletefirst() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    struct node *temp = head;
    printf("%d deleted.\n", temp->data);

    if (temp->rlink == NULL) {
        head = NULL;
    } else {
        head = temp->rlink;
        head->link = NULL;
    }
    free(temp);
}

void deletelast() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    struct node *temp = head;
    if (temp->rlink == NULL) {
        printf("%d deleted.\n", temp->data);
        head = NULL;
        free(temp);
        return;
    }

    while (temp->rlink != NULL)
        temp = temp->rlink;

    printf("%d deleted.\n", temp->data);
    temp->link->rlink = NULL;
    free(temp);
}

void deletelocation() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    int key;
    printf("Enter the key to delete: ");
    scanf("%d", &key);

    struct node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->rlink;

    if (temp == NULL) {
        printf("\nElement not found.\n");
        return;
    }

    if (temp->link == NULL) { // deleting first node
        head = temp->rlink;
        if (head != NULL)
            head->link = NULL;
    } else if (temp->rlink == NULL) { // deleting last node
        temp->link->rlink = NULL;
    } else { // middle node
        temp->link->rlink = temp->rlink;
        temp->rlink->link = temp->link;
    }

    printf("%d deleted successfully.\n", temp->data);
    free(temp);
}

void search() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    int key, pos = 0, found = 0;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("%d found at position %d\n", key, pos);
            found = 1;
        }
        temp = temp->rlink;
        pos++;
    }

    if (!found)
        printf("Element not found.\n");
}

void display() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nElements in the list:\n");
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->rlink;
    }
    printf("\n");
}

int main() {
    int choice;
    printf("Doubly Linked List Operations:\n");

    do {
        printf("\n1. Insert First\n2. Insert Last\n3. Insert After Key\n4. Delete First\n5. Delete Last\n6. Delete by Key\n7. Search\n8. Display\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertfirst(); break;
            case 2: insertlast(); break;
            case 3: insertlocation(); break;
            case 4: deletefirst(); break;
            case 5: deletelast(); break;
            case 6: deletelocation(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice!\n");
        }
    } while (choice != 9);

    return 0;
}

