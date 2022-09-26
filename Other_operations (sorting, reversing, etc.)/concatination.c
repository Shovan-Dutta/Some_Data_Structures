//WAP to concatinate 2 linked list.
#include<stdio.h>
#include<stdlib.h>

struct node   //defines the structure of the node
{  
    int data;  
    struct node *next;   
};

typedef struct node NODE; //renaming 'struct node' as 'NODE'

NODE* createnode();//this function will only create new nodes when called.
NODE* beginsert(NODE *start);  //this function will insert a new node at the beginning of the linked list.
NODE* concatinate(NODE *start1,NODE *start2); //this function will join two linked lists.
void display(NODE *start);

void main()
{
    int choice =0;
    int c = 0; 
    NODE *start1,*start2;
    start1 = NULL;
    start2 = NULL;
    while(choice != 2)   //this will help to run the whole program in a loop.
    {  
        printf("\n############ Main Menu ############\n");  
        printf("\nChoose one option from the following list:-\n");    
        printf("-->Concatinate press (1)\n-->Exit press (2)\n");  
        printf("-- Enter your choice? --\n");         
        scanf("\n%d",&choice);  
        switch(choice)  //this switch case is to provide options for the user.
        {  
            case 1:
            printf("\nCreate the 1st list:-\n");
            do
            {       
                start1 = beginsert(start1);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);
            printf("\n1st list:-\n");
            display(start1);
            printf("\nCreate the 2nd list:-\n");
            do
            {       
                start2 = beginsert(start2);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);
            printf("\n2nd list:-\n");
            display(start2);
            start1 = concatinate(start1,start2);
            printf("The Concatinated List:-\n");
            display(start1);
            break;
            case 2:
            exit(2);
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

NODE* beginsert(NODE *start)
{    
        int item;
        NODE *ptr;  
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
              
            ptr->next = start;  
            start = ptr;  
            printf("--- Node inserted ---\n");  
        }
        return(start);
}

NODE* concatinate(NODE *start1,NODE *start2)
{
    NODE *ptr;
    ptr=start1;
    if(ptr != NULL)
    {
       while (ptr->next!=NULL)  
        {    
            ptr = ptr ->next;  
        } 
        ptr->next = start2;
        printf("\nThe concatination was a success!\n");
    }
    return(start1);
}

void display(NODE *start)  // this function will display the linked list if there is any. 
{  
    NODE *ptr; 
    ptr = start;
    if(ptr == NULL)  
    {  
        printf("!!!!! No List to be printed !!!!!");  
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