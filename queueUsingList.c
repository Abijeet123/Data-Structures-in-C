#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node * next;
}*head=NULL,*temp,*temp0;

void createNode () {
  int value;
  printf("Enter the value to be inserted\n");
  scanf("%d",&value);
  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = value;
  temp->next = NULL;
}

void insertNode () {
  createNode ();
  if (head == NULL) {
    head = temp;
  } else {
    temp0 = head;
    while (temp0->next != NULL) {
      temp0 = temp0->next;
    }
    temp0->next = temp;
  }
  printf("Insertion Success!\n");
}

void deleteNode () {
  temp = head;
  head = head->next;
  free(temp);
  printf("Deletion Success!\n");
}

void display () {
  if (head == NULL) {
    printf("Queue is empty\n");
  } else {
    temp = head;
    while (temp -> next != NULL) {
      printf("%d-->",temp->data);
      temp = temp->next;
    }
    printf("%d-->null\n",temp->data );
  }
}

void main () {
  int ch;
  printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
  while (1) {
    printf("Enter your choice: ");
    scanf("%d",&ch );
    switch (ch) {
      case 1:
              insertNode();
              break;
      case 2:
              deleteNode();
              break;
      case 3:
              display();
              break;
      case 4:
              exit(0);
      default:
              printf("Wrong choice!\n");
    }
  }
}
