#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
}*top=NULL,*temp;

void createNode () {
  int value;
  printf (" Enter the value\n");
  scanf("%d",&value);
  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = value;
  temp -> next = NULL;
}

void Push() {
  createNode();
  temp->next = top;
  top = temp;
}

void Pop () {
  if (top == NULL) {
    printf("Stack underflow\n");
  } else {
    temp = top;
    top = top -> next;
    free(temp);
    printf("Deletion success\n");
  }
}

void Display () {
  temp = top;
  while (temp -> next != NULL) {
    printf ("%d-->",temp->data);
    temp = temp -> next;
  }
  printf ("%d-->null\n",temp->data);
}

void Search() {
  int value;
  printf ("Enter the value to be Searched\n");
  scanf ("%d",&value);
  temp = top;
  while (temp->data != value) {
    if (temp -> next == NULL) {
      printf ("%d not found\n",value);
      return ;
    }
    temp = temp -> next;
  }
  printf ("%d found",value);
}

void main () {
  int ch;
  printf("1.Push\n2.Pop\n3.Display\n4.Search\n5.Exit\n");
  while (1) {
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch) {
      case 1:
              Push();
              break;
      case 2:
              Pop();
              break;
      case 3:
              Display();
              break;
      case 4:
              Search();
              break;
      case 5:
              exit(0);
      default:
              printf("Wrong choice!\n");
    }
  }
}
