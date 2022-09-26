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
NODE* endinsert(NODE *start);  //this function will insert a new node at the end of the linked list.
NODE* abinsert(NODE *start);  //this function will insert a new node before or after of the linked list.
void display(NODE *start);  // this function will display the linked list if there is any.

void main()
{
    int choice =0;
    int c = 0; 
    NODE *start;
    start = NULL;
    while(choice != 4)   //this will help to run the whole program in a loop.
    {  
        printf("\n############ Main Menu ############\n");  
        printf("\nChoose one option from the following list:-\n");    
        printf("-->Insert before or after or at a given location press (1)\n-->Show press (2)\n-->Exit press (3)\n");  
        printf("-- Enter your choice? --\n");         
        scanf("\n%d",&choice);  
        switch(choice)  //this switch case is to provide options for the user.
        {  
            case 1: 
            do
            {                
                start = abinsert(start);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);
            break; 
                  
            break;  
            case 2: 
            display(start); 
            break; 
            case 3:
            exit(3); 
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
        printf("--- New node has been successfully allocated in the memory ---\n");
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

int countnode(NODE *start)
{
    NODE *ptr;  
    ptr = start;
    int c=0;
    while (ptr!=NULL)  
    {  
        c++;  
        ptr = ptr ->next;  
    }
    return(c);
}

NODE* abinsert(NODE *start)
{
    int c,count = 0;
    count = countnode(start);
    int item,i,loc;
    NODE *ptr,*temp;
    printf ("Insert after or before or at a location:-\n-->Press (1) for After a location\n-->Press (2) for Before a location\n-->Press (3) for at a location \n");
    scanf("%d",&c);
    temp=start;
    switch(c)
    {
        case 1:
        if(start != NULL)
        {
            ptr = createnode();
            printf("Enter the location after where you want to insert:- \n");  
            scanf("\n%d",&loc);
            printf("\nEnter value:-\n");    
            scanf("%d",&item);
            ptr->data = item; 
            for(i=0;i<loc;i++)
            {
                temp = temp->next;
                if(temp==NULL)
                {
                    printf("!!!!can't insert!!!!\n Instead use insert at begin or at end or at a position operation.\n");  
                    return(start);
                }
            }
            ptr->next = temp->next;
            temp->next = ptr;
            printf("Node inserted after the given position\n");
            return(start);
        }
        else
        {
            printf("!!First create a linked list using insert at begin or at end operations!!\n");
            return(start);
        }
        break;
        case 2:
        if(start != NULL)
        {
            ptr = createnode();
            printf("Enter the location before where you want to insert:- \n");  
            scanf("\n%d",&loc);
            printf("\nEnter value:-\n");    
            scanf("%d",&item);
            ptr->data = item;
            for(i=0;i<loc-1;i++)
            {
                temp = temp->next;
                if(temp==NULL)
                {
                    printf("!!!!can't insert!!!!\n Instead use insert at begin or at end or at a position operation.\n");  
                    return(start);
                }
            }
            ptr->next = temp->next;
            temp->next = ptr;
            printf("Node inserted before the given position\n");
            return(start);
        }
        else
        {
            printf("!!First create a linked list using insert at begin or at end operations!!\n");
            return(start);
        }
        break;
        case 3:
        printf("\nThe current number of nodes in the Linked list is:- %d\n So please enter the location number accordingly!\n",count);
        scanf("\n%d",&loc);
        if (loc ==1)
        {
            start = beginsert(start);
            return(start);
        }
        else
        {
            if (loc >= count)
            {
                start = endinsert(start);
                return(start);
            }
            else
            {
                ptr = createnode();
                printf("\nEnter value:-\n");    
                scanf("%d",&item);
                ptr->data = item;
                loc = loc-1;
                for(i=0;i<loc-1;i++)
                {
                    temp = temp->next;
                    if(temp==NULL)
                    {
                        printf("!!!!can't insert!!!!\n");  
                        return(start);
                    }
                }
                ptr->next = temp->next;
                temp->next = ptr;
                printf("Node inserted!\n");
                return(start);
            }
        }
    }
}

void display(NODE *start)  // this function will display the linked list if there is any. 
{  
    int c;
    NODE *ptr;  
    ptr = start;   
    if(ptr == NULL)  
    {  
        printf("!!!!!!!!! No list exists to be printed !!!!!!!!!");  
    }  
    else  
    {  
        c = countnode(start);
        printf("\nThe current number of nodes in the Linked list is:- %d",c);
        printf("\n############ Printing List ############\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr ->next;  
        }  
    }  
}     
