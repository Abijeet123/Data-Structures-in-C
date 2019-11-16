#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *right;
    struct node *left;
}*root=NULL,*temp;

struct node *createNode(int value) {
  
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->right = temp->left = NULL;
    return temp;
}


struct node* insertNode(struct node *root,int value) {
    if (root == NULL ||  root->data == value)
    {
        return createNode(value);
    }
    else
    {
        if (root->data < value)
        {
            root->right = insertNode(root->right,value);
        }
        else
        {
            root->left = insertNode(root->left,value);
        }
        
        
    }
    
    
}

struct node* search(struct node *node ,int value) {
    if (node == NULL || node->data == value)
    {
        return node;
    }
    if (node->data > value) 
    {
        return search(node->right,value);
    }
    else
    {
        return search(node->left,value);
    }
    
    
    
}

void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->data); 
        inorder(root->right); 
    } 
} 

struct node* minValue(struct node* node) {
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
    
}

struct node* maxValue(struct node* node)
{
    while(node->right != NULL)  node = node->right;
    return node;
}

struct node* deleteNode(struct node* node,int value)
{
    if (node == NULL)
    {
        return node;
    }
    else
    {
        if (value < node->data)
        {
            node->left = deleteNode(node->left,value);
        }
        else if (value > node->data)
        {
            node->right = deleteNode(node->right,value);
        }
        else 
        {
            if (node->left == NULL)
            {
                temp = node->right;
                free(node);
                return temp;
            }
            else if (node->right == NULL)
            {
                temp = node->left;
                free(node);
                return temp;
            }
             else
        {
            temp = minValue(node);
            node->data = temp->data;
            node->right = deleteNode(node->right,temp->data);
        }
            
            
        }
       
        
        
        
    }
    
    
};



void main(){
    int ch,value;
    printf("0.Instantiate tree\n1.Insert\n2.Search\n3.Display\n4.Minimum value\n5.Maximum value\n6. Delete\n89.Exit\n");
    while (1)
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 0:
                printf("Enter the value to create tree with\n");
                scanf("%d",&value);
                root=createNode(value);
                break;
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d",&value);
            insertNode(root,value);
            break;
        case 2:
            printf("Enter the value to be searched: ");
            scanf("%d",&value);
            if (search(root,value))
            {
                printf("Element %d found in the tree \n",value);
            }
            else
            {
                printf("Element %d not found\n",value);
            }
            break;
        case 3:
                inorder(root);
                break;
        case 4:
                printf("Minimum value = %d \n",minValue(root)->data);
                break;
        case 5:
                printf("Maximum value = %d\n",maxValue(root)->data);
                break;
        case 6:
                printf("Enter the value to be deleted: ");
                scanf("%d",&value);
                deleteNode(root,value);
                break;
        case 89:
                exit(0); 
                break;
        
        default:
            printf("You entered wrong choice");
            break;
        }
    }
    
}










