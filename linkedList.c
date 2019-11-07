#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
}*head=NULL,*temp,*temp0;

void createNode () {
  int value;
  printf("Enter the value to create node with");
  scanf("%d",&value);
  temp  = (struct node*)malloc(sizeof(struct node));
  temp->data=value;
  temp->next=NULL;
}

void insertAtBeginning ()  {
  createNode();
    temp->next=head;
    head = temp;
}

void insertAtEnd () {
  if (head  ==  NULL) {
    insertAtBeginning ();
  }else{
    temp0  = head;
    while (temp0->next != NULL) {
      temp0  = temp0->next;
    }
    createNode ();
    temp0->next=temp;
  }
}

void insertAfter () {
  int val;
  printf("Enter the value after which you want to insert\n");
  scanf("%d",&val);
  createNode ();
  while (temp0->data != val) {
    temp0 = temp0->next;
  }
  temp->next = temp0->next;
  temp0->next = temp;
}

void deleteBeginning (){
  if (head->next == NULL) {
    head == NULL;
  }else{
    temp = head;
    head = head->next;
    free(temp);
  }
}

void deleteEnd (){
  if (head->next == NULL) {
    head == NULL;
  }else{
    temp = head;
    while (temp->next != NULL) {
      temp0 = temp;
      temp = temp->next;
    }
    temp0->next=NULL;
    free(temp);
  }
}

void deleteSpecific (){
  int val;
  printf("Enter the value to be deleted\n");
  scanf("%d",&val);
  temp = head;
  while (temp->data != val){
    if (temp->next == NULL) {
      printf("%d not found!\n",val);
      return ;
    }else{
      temp0=temp;
      temp = temp->next;
    }
  }
  temp0->next = temp->next;
  free(temp);
}

void display () {
  if (head == NULL) {
    printf("List is empty\n");
    return ;
  }
  temp = head;
  while (temp->next != NULL) {
    printf("%d-->",temp->data);
    temp = temp->next;
  }
  printf("%d-->NULL\n",temp->data );
}

void search () {
  int val;
  printf("Enter the value to be searched\n");
  scanf("%d",&val);
  temp = head;
  while (temp->data != val) {
    if (temp->next == NULL) {
      printf("Element not found\n");
      return ;
    }else if (temp->next->data == val) {
      printf("Element found\n");
      return ;
    }
    temp = temp->next;
  }
}


void main(){
  int ch;
  printf("1.Insert At Beginning\n2.Insert at end\n 3. Insert After\n 4. display \n 5. Search\n 6. Delete Beginning \n 7. Delete end \n 8. Delete specific\n 9.Exit\n");
  while (1) {
    scanf("%d",&ch);
    switch(ch){
      case 1:
              insertAtBeginning ();
              break;
      case 2:
              insertAtEnd ();
              break;
      case 3:
              insertAfter ();
              break;
      case 4:
              display ();
              break;
      case 5:
              search ();
              break;
      case 6:
              deleteBeginning ();
              break;
      case 7:
              deleteEnd ();
              break;
      case 8:
              deleteSpecific ();
              break;
      case 9:
              exit (0);
      default :
                printf("Entered wrong choice\n");
    }
  }
}
