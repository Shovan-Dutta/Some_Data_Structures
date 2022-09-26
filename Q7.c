/*1. Write a program to implement Queue using circular linked List.
2. Write a program to Implement Stack using Doubly Linked List.
3. Write a program to Implement Queue using Doubly Linked List.*/

//1.
#include<stdio.h>
#include<stdlib.h>

struct node   //defines the structure of the node
{  
    int data;  
    struct node *next;   
};

typedef struct node NODE; //renaming 'struct node' as 'NODE'

NODE* createnode();//this function will only create new nodes when called.
NODE* enqueue(NODE *start);  //this function will insert a new node at the beginning of the linked list.
NODE* dequeue(NODE *start);  //this function will insert a new node at the end of the linked list.
void display(NODE *start);  // this function will display the queue if there is any.

void main()
{
    int choice =0, c = 0, data=0;
    NODE *start;
    start = NULL;
    while(choice != 6)   //this will help to run the whole program in a loop.
    {  
        printf("\n############ Queue Menu ############\n");  
        printf("\nChoose one option from the following list:-\n");    
        printf("-->To Enqueue press (1)\n-->To Dequeue press (2)\n-->To Peek press (3)\n-->To check isEmpty press (4)\n-->Display Queue press (5)\n-->Exit press (6)\n");  
        printf("-- Enter your choice? --\n");         
        scanf("\n%d",&choice);  
        switch(choice)  //this switch case is to provide options for the user.
        {  
            case 1: 
            do
            {                
                start = enqueue(start);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);    
            break;  
            case 2:  
            do
            {                
                start = dequeue(start);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);        
            break; 
            case 3:
            if(start != NULL)
            {
                data = start->data;
                printf("\n%d is the first element of the Queue.\n",data);
            }
            else
            {
                printf("\n Queue empty Peek not possible!\n");
            }
            break;
            case 4:
            if(start != NULL)
            {
                printf("\n Queue is not empty!\n");
            } 
            else
            {
                printf("\n Queue is empty! \n");
            }
            break;
            case 5:
            display(start); 
            break; 
            case 6:
            exit(6);
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

NODE* enqueue(NODE *start)
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

NODE* dequeue(NODE *start)
{
	NODE *last;
	if(start == NULL)
    {
        printf("\n!!!!!! Empty Queue !!!!!!\n");
    }
    else
    {
        printf("Data dequeued is %d",start->data);
        last = start;
        while(last->next != start)
        {
        	last = last->next;
        }
        start = start->next;
        last->next = start;
    }
    return(start);

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

//2.
#include <stdio.h>
#include <stdlib.h>

struct node   //defines the structure of the node
{  
    int data;  
    struct node *next; 
    struct node *prev;  
};

typedef struct node NODE; //renaming 'struct node' as 'NODE'

NODE* createnode();//this function will only create new nodes when called.
NODE* push(NODE *top);  //this function will insert a new node at the beginning of the linked list.
NODE* pop(NODE *top);  //this function will delete a node at the beginning of the linked list.
void display(NODE *top);  // this function will display the linked list if there is any.

void main()
{
    int choice =0, c = 0, data=0;
    NODE *top;
    top = NULL;
    while(choice != 6)   //this will help to run the whole program in a loop.
    {  
        printf("\n############ Stack Menu ############\n");  
        printf("\nChoose one option from the following list:-\n");    
        printf("-->To Push press (1)\n-->To Pop press (2)\n-->To Peek press (3)\n-->To check isEmpty press (4)\n-->Display Stack press (5)\n-->Exit press (6)\n");  
        printf("-- Enter your choice? --\n");         
        scanf("\n%d",&choice);  
        switch(choice)  //this switch case is to provide options for the user.
        {  
            case 1: 
            do
            {                
                top = push(top);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);    
            break;  
            case 2:  
            do
            {                
                top = pop(top);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);        
            break; 
            case 3:
            if(top != NULL)
            {
                data = top->data;
                printf("\n%d is the top element of the Stack.\n",data);
            }
            else
            {
                printf("\n Stack empty Peek not possible!\n");
            }
            break;
            case 4:
            if(top != NULL)
            {
                printf("\nStack is not empty!\n");
            } 
            else
            {
                printf("\n Stack is empty! \n");
            }
            break;
            case 5:
            display(top); 
            break; 
            case 6:
            exit(6);
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
        printf("--- Overflow ---\n");
         
    }
    else
    {
        return (one);
    }
}

NODE* push(NODE *top)
{    
        int item;
        NODE *ptr;  
        ptr = createnode();
        printf("\nEnter value\n");    
        scanf("%d",&item);    
        ptr->data = item;
        if(top == NULL)  //this condition is checking if there is an existing linked list and linking the node accordingly.
        {  
            top  = ptr;
            ptr->next = NULL;
            ptr->prev = NULL;
            printf("\n--- 1st Data Pushed ---\n");
        }  
        else  
        {  
            ptr->prev = NULL;
            ptr->next = top;  
            top = ptr;  
            printf("\n--- Data Pushed ---\n");  
        }
        return(top);
}

NODE* pop(NODE *top)
{
    if(top == NULL)
    {
        printf("\n!!!!!! Stack UnderFlow !!!!!!\n");
    }
    else
    {
        printf("\nData Poped is :- %d\n",top->data);
        top = top->next;
        top->prev = NULL;
    }
    return(top);
}

void display(NODE *top)  // this function will display the linked list if there is any. 
{  
    NODE *ptr;  
    ptr = top;   
    if(ptr == NULL)  
    {  
        printf("\n!!!!!!!!! No Stack exists to be printed !!!!!!!!!\n");  
    }  
    else  
    {  
        printf("\n############ Printing Stack ############\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr ->next;  
        }  
    }  
}

//3.
#include <stdio.h>
#include <stdlib.h>

struct node   //defines the structure of the node
{  
    int data;  
    struct node *next; 
    struct node *prev;  
};

typedef struct node NODE; //renaming 'struct node' as 'NODE'

NODE* createnode();//this function will only create new nodes when called.
NODE* enqueue(NODE *start);  //this function will enqueue a new node at the end of the queue.
NODE* dequeue(NODE *start);  //this function will dequeue an element from queue.
void display(NODE *start);  // this function will display the queue if there is any.

void main()
{
    int choice =0, c = 0, data=0;
    NODE *start;
    start = NULL;
    while(choice != 6)   //this will help to run the whole program in a loop.
    {  
        printf("\n############ Queue Menu ############\n");  
        printf("\nChoose one option from the following list:-\n");    
        printf("-->To Enqueue press (1)\n-->To Dequeue press (2)\n-->To Peek press (3)\n-->To check isEmpty press (4)\n-->Display Queue press (5)\n-->Exit press (6)\n");  
        printf("-- Enter your choice? --\n");         
        scanf("\n%d",&choice);  
        switch(choice)  //this switch case is to provide options for the user.
        {  
            case 1: 
            do
            {                
                start = enqueue(start);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);    
            break;  
            case 2:  
            do
            {                
                start = dequeue(start);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);        
            break; 
            case 3:
            if(start != NULL)
            {
                data = start->data;
                printf("\n%d is the first element of the Queue.\n",data);
            }
            else
            {
                printf("\n Queue empty Peek not possible!\n");
            }
            break;
            case 4:
            if(start != NULL)
            {
                printf("\n Queue is not empty!\n");
            } 
            else
            {
                printf("\n Queue is empty! \n");
            }
            break;
            case 5:
            display(start); 
            break; 
            case 6:
            exit(6);
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
        printf("--- Overflow ---\n");
         
    }
    else
    {
        return (one);
    }
}

NODE* enqueue(NODE *start)
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
        ptr->next = NULL;
        ptr->prev = NULL;
        printf("--- 1st Node inserted ---\n");
    }
    else
    {
        temp = start;
        while(temp->next != NULL)
        {
            temp = temp ->next;  
        }
        temp ->next = ptr;
        ptr->prev = temp;
        ptr->next = NULL;
        printf("--- Node inserted at the end ---\n"); 
    }
    return(start);
}

NODE* dequeue(NODE *start)
{
    if(start == NULL)
    {
        printf("\n!!!!!! Empty Queue !!!!!!\n");
    }
    else
    {
        printf("\nData dequeued is %d\n",start->data);
        start = start->next;
        start->prev = NULL;
    }
    return(start);
}

void display(NODE *start)  // this function will display the linked list if there is any. 
{  
    NODE *ptr;  
    ptr = start;   
    if(ptr == NULL)  
    {  
        printf("\n!!!!!!!!! No Queue exists to be printed !!!!!!!!!\n");  
    }  
    else  
    {  
        printf("\n############ Printing Queue ############\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr ->next;  
        }  
    }  
}
