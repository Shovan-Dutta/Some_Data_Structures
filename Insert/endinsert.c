//WAP to create a linked list by inserting nodes at the end and printing that linked list.
#include<stdio.h>
#include<stdlib.h>

struct node   //defines the structure of the node
{  
    int data;  
    struct node *next;   
};

typedef struct node NODE; //renaming 'struct node' as 'NODE'

NODE* createnode();//this function will only create new nodes when called.
NODE* endinsert(NODE *start);  //this function will insert a new node at the end of the linked list.
void display(NODE *start);  // this function will display the linked list if there is any.

void main()
{
    int choice =0;
    int c = 0; 
    NODE *start;
    start = NULL;
    while(choice != 3)   //this will help to run the whole program in a loop.
    {  
        printf("\n############ Main Menu ############\n");  
        printf("\nChoose one option from the following list:-\n");    
        printf("-->Insert at end press (1)\n-->Show press (2)\n-->Exit press (3)\n");  
        printf("-- Enter your choice? --\n");         
        scanf("\n%d",&choice);  
        switch(choice)  //this switch case is to provide options for the user.
        {  
            case 1: 
            do
            {                
                start = endinsert(start);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);
            break;  
            case 2:  
            display(start);        
            break; 
            case 3:
            exit(3);
            break;    
            default:  
            printf("Please enter valid choice..");  
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
        printf("--- New node has been successfully allocated in the memory ---\n");
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
        ptr->next = NULL;
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
        ptr->next = NULL;
        printf("--- Node inserted at the end ---\n"); 
    }
    return(start);
}

void display(NODE *start) 
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
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr ->next;  
        }  
    }  
}