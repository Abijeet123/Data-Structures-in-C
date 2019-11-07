#include<stdio.h>
#include<stdlib.h>
#define max 50

int top = -1, stack[max];

void Push () {
  if (top == max - 1) {
    printf("Stack overflow\n");
  }else{
    int value;
    printf("Enter the value to be pushed\n");
    scanf("%d",&value);
    top++;
    stack[top] = value;
  }
}

void Pop () {
  if (top == -1) {
    printf("Stack underflow\n");
  }else{
    top--;
  }
}

void Display () {
  if (top == -1) {
    printf ("Stack underflow\n");
  }else{
    int i;
    for ( i=0; i<= top; i++) {
      printf ("%d ",stack[i]);
    }
    printf("\n");
  }
}

void Search () {
  int value;
  printf("Enter the value to be searchd\n");
  scanf("%d",&value);
  int i;
  for (i=0 ; i<=top ; i++) {
    if (stack[i] == value) {
      printf("%d found in stack\n",value);
      return ;
    }
  }
  printf("%d not found in stack\n",value);
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
