/*Write a program to implement a circular linked list with the following operations:
Insert a node in the list
Delete a node from the list
Search an element in the list
Reverse the list*/

#include<stdio.h>
#include<stdlib.h>

struct node   //defines the structure of the node
{  
    int data;  
    struct node *next;   
};

typedef struct node NODE; //renaming 'struct node' as 'NODE'

NODE* createnode();//this function will only create new nodes when called.
NODE* endinsert(NODE *start);  //this function will insert a new node at the beginning of the linked list.
NODE* reverse(NODE *start, NODE *revstart); //this function reverses the complete linked list.
NODE* enddelete(NODE *start);  //this function will insert a new node at the end of the linked list.
int search(NODE *start); //this function searches for an element in the linked list.
void display(NODE *start);  // this function will display the linked list if there is any.

void main()
{
    int choice = 0;
    int s;
    int c = 0; 
    NODE *start;
    NODE *revstart;
    NODE *start1,*start2;
    start = NULL;
    revstart = NULL;
    while(choice != 6)   //this will help to run the whole program in a loop.
    {  
        printf("\n############ Main Menu ############\n");  
        printf("\nChoose one option from the following list:-\n");    
        printf("-->To Insert a node press(1)\n-->To Delete a node press(2)\n-->Show List press(3)\n-->Create the reverse of List press (4)\n-->To search press (5)\n-->To Exit press (6)\n");  
        printf("-- Enter your choice? --\n");         
        scanf("\n%d",&choice);  
        switch(choice)  //this switch case is to provide options for the user.
        {  
          case 1:
          do
          {                
            start = endinsert(start);
            display(start);
            printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
            scanf("%d",&c);
          }while(c==1);
          display(start);
          break;
          case 2:
          do
          {
            start = enddelete(start);
            display(start);
            printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
            scanf("\n%d",&c);
          }while(c==1);
          display(start);
          break;
          case 3:
          display(start);
          break;
          case 4:
          revstart = reverse(start,revstart);
          break;
          case 5:
          do
          {
            s = search(start);
            if(s!=-1)
            {
              printf("\nThe element was found at the %d position.\n",s+1);
            }
            else
            {
              printf("\nThe element is not present in the array.\n");
            }
            printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
            scanf("\n%d",&c);
          }while(c==1);
          break;
          case 6:
          printf("Exiting...");
          break;  
          default:  
          printf("!!Please enter valid choice!!");  
        }  
    }
}

NODE* createnode()  
{
    NODE *one;
    one = (NODE *)malloc(sizeof(NODE*));
    if(one==NULL)   // this condition will check if the node was created
    {
        printf("--- Overflow. Sorry for the in convenience caused ---\n");
    }
    else
    {
        return (one);
    }
}

NODE* endinsert(NODE *start)
{
    int item;
    NODE *ptr,*temp;
    ptr = createnode();
    printf("\nEnter value\n");    
    scanf("%d",&item);    
    ptr->data = item;
    if(start == NULL)  //this condition is checking if there is an existing linked list and linking the node accordingly.
    {  
        start  = ptr;
        ptr->next = start;
        printf("--- 1st Node inserted ---\n");
    }
    else
    {
        temp = start;
        while(temp->next != start)
        {
            temp = temp ->next;  
        }
        temp ->next = ptr;
        ptr->next = start;
        printf("--- Node inserted at the end ---\n"); 
    }
    return(start);
}


NODE* reverse(NODE *start,NODE *revstart)
{
    NODE *ptr,*ptr2;
    revstart= NULL;
    if(start != NULL)
    {
        ptr2 = start;
        while(ptr2->next!=start)
        {
            ptr = createnode();
            ptr->data = ptr2->data;
            if(revstart == NULL)  //this condition is checking if there is an existing linked list and linking the node accordingly.
            {  
                revstart  = ptr;
                ptr->next = NULL;
                //printf("--- 1st Node inserted ---\n");
            }  
            else  
            {  
                ptr->next = revstart;  
                revstart = ptr;  
                //printf("--- Node inserted at the begining ---\n");  
            }
            ptr2 = ptr2->next;  
        }
        ptr = createnode();
        ptr->data = ptr2->data;
        ptr->next = revstart;
        revstart = ptr; 
        ptr=revstart;
        printf("\n############ Printing Rrverse List ############\n");
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr ->next;  
        }
    }
    else
    {
        printf("!!!!!There is no Linked List to begin with!!!!!\n!!!!!Please create a Linked List first!!!!! \n");
    }
    return(revstart);
}

NODE* enddelete(NODE *start)
{   struct node *ptr,*ptr1;
    if(start == NULL)
    {
        printf("!!!!!! No available nodes to be deleted !!!!!!");
    }
    else
    {
        ptr = start;
        if (ptr->next==start)
        {
            printf("Data deleted is :- %d",ptr->data);
            start = NULL;
        }
        else
        {
           while(ptr->next != start)  
            {  
            ptr1 = ptr;  
            ptr = ptr ->next;  
            }  
            printf("Data deleted is :- %d",ptr->data);
            ptr1->next = start; 
        }
    }
    return(start);
}

int search(NODE *start)
{
  NODE *ptr;
  int search,s=-1,count =0;
  printf("\nEnter the element you want to Search:-\n");
  scanf("%d",&search);
  ptr  = start;
  if(ptr == NULL)
  {
    printf("\n!!!!!!!!! No List exists to be searched !!!!!!!!!\n");
  }
  while(ptr->next != start)
  {
    if(search == ptr->data)
    {
      s=count;
    }
    count++;
    ptr = ptr->next;
  }
  if(search == ptr->data)
  {
    s=count;
  }
  return(s);
}

void display(NODE *start)  // this function will display the linked list if there is any. 
{  
    NODE *ptr;  
    ptr = start;   
    if(ptr == NULL)  
    {  
        printf("!!!!!!!!! No list exists to be printed !!!!!!!!!");  
    }  
    else  
    {  
      printf("\n############ Printing List ############\n");   
      while(ptr->next!=start)
      {  
        printf("\n%d",ptr->data);  
        ptr = ptr ->next;
      }
      printf("\n%d",ptr->data);
    }  
}
