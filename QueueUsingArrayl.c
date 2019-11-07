#include<stdio.h>
#include<stdlib.h>
#define max 50

int front=-1,rear=-1,top=-1,Q[max];


void insert () {
  int value;
  printf("Enter the value to be inserted : ");
  scanf("%d",&value);
  if (front == -1 && rear == -1) {
    front++;
  }else{
    if (rear == max - 1) {
      printf("Queue full\n");
      return;
    }
    }
    rear++;
    Q[rear] = value;
    printf("Insertion success!\n");
}


void delete () {
  if (front == -1 /*&& rear == -1*/) {
    printf("Queue empty\n");
  }else{
    if (front == rear) {
      front = rear = -1;
      return ;
    }
    front++;
    printf("Deletion success\n");
  }
}

void display () {
  if (top == rear && (front == -1 && rear == -1) ) {
    printf("Queue empty\n");
  }else {
    int i;
    for (i=front;i<=rear;i++) {
      printf("%d ",Q[i] );
    }
    printf("\n");
  }
}

int main() {
  int ch;
  printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
  while (1) {
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch (ch) {
      case 1:
              insert();
              break;
      case 2:
              delete();
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
  return 0;
}
