#include<stdio.h>
#include<string.h>
#define max 50

int stack[max],top =-1;

void push(char ch){
  if (top == max-1) {
    return ;
  }else {
    top++;
    stack[top] = ch;
  }
}
char pop(){
  if (top == -1) {
    return ;
  }else {
    char k = stack[top];
    top--;
    return k;
  }
}
char isOperator(char ch) {
  if (ch == '^' ||ch == '+' ||ch == '-' ||ch == '*' ||ch == '/' ) {
    return 1;
  }
  return 0;
}

int precedence(char ch){
  if (ch == '^') {
    return 3;
  }else if (ch == '*' ||ch == '/' ) {
    return 2;
  }else if (ch == '*' ||ch == '-' ) {
    return 1;
  }
}

void infixToPostfix(char infix[],char postfix[]){
  int i=0,j=0;
  char x,item;
  item = infix[i];
  push('(');
  strcat(infix,")");
  while (item != '\0') {
    if (item == '(') {
      push('(');
    }else if (isalpha(item)) {
      postfix[j] = item;
      j++;
    }else if (isOperator(item)) {
      x=pop();
      while (isOperator(x) && precedence(x) >= precedence(item)) {
        postfix[j] = x;
        j++;
        x = pop();
      }
      push(x);
      push(item);
      /* code */
    }else if(item == ')'){
      x = pop();
      while (x != '(') {
        postfix[j] = x;
        j++;
        x=pop();
      }
    }
    i++;
    item = infix[i];
  }
  //postfix[j] = '\0';
}

main(){
  char infix[max],postfix[max];
  gets(infix);
  infixToPostfix(infix,postfix);
  puts(postfix);
}
