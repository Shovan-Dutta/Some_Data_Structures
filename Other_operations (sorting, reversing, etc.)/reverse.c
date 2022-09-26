//WAP to find the reverse of the linked list.
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
NODE* reverse(NODE *start,NODE *revstart); //this function reverses the complete linked list.
void display(NODE *start);  // this function will display the linked list if there is any.

void main()
{
    int choice =0;
    int c = 0; 
    NODE *start;
    NODE *revstart;
    start = NULL;
    revstart = NULL;
    while(choice != 5)   //this will help to run the whole program in a loop.
    {  
        printf("\n############ Main Menu ############\n");  
        printf("\nChoose one option from the following list:-\n");    
        printf("-->Create Linked List (1)\n-->Create the reverse of linked list press (2)\n-->Show press (3)\n-->Show reverse press (4)\n-->Exit press (5)\n");  
        printf("-- Enter your choice? --\n");         
        scanf("\n%d",&choice);  
        switch(choice)  //this switch case is to provide options for the user.
        {  
            case 1: 
            do
            {                
                start = beginsert(start);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);
                  
            break;  
            case 2:
            revstart = reverse(start,revstart);
            display(revstart);
            break; 
            case 3:
            display(start); 
            break; 
            case 4:
            display(revstart);
            break;
            case 5:
            exit(5);
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
            printf("--- Node inserted at the begining ---\n");  
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
	    while(ptr2!=NULL)
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
	}
	else
	{
		printf("!!!!!There is no Linked List to begin with!!!!!\n!!!!!Please create a Linked List first!!!!! \n");
	}
	return(revstart);
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
        printf("\n####### Printing List #######\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr ->next;  
        }  
    }  
}