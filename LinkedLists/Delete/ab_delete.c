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
NODE* begdelete(NODE *start);
NODE* delafter(NODE *start); //deletes nodes after a particular node
NODE* delbefore(NODE *start);//deletes before a particular node
NODE* delvalue(NODE *start);//deletes a specific value
int countnode(NODE *start);
NODE* deletespecific(NODE *start);  //this function will delete a specific node of the linked list.
void display(NODE *start);

void main()
{
    int choice =0;
    int c = 0; 
    NODE *start;
    start = NULL;
    while(choice != 7)   //this will help to run the whole program in a loop.
    {  
        printf("\n############ Main Menu ############\n");  
        printf("\nChoose one option from the following list:-\n");    
        printf("-->Insert at begining press (1)\n-->Delete at specific position press (2)\n-->Delete before a value press (3)\n-->Delete after a value press (4)\n-->Delete a specific value press (5)\n-->Show press (6)\n-->Exit press (7)\n");  
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
            do
            {                
                start = deletespecific(start);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);
            break;
            case 3: 
            do
            {                
                start = delbefore(start);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);
            break;
            case 4: 
            do
            {                
                start = delafter(start);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);
            break;
            case 5:
            do
            {                
                start = delvalue(start);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);
            break;
            case 6:
            display(start); 
            break; 
            case 7:
            exit(7);
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

NODE* begdelete(NODE *start)
{
    if(start == NULL)
    {
        printf("!!!!!! No available nodes to be deleted !!!!!!");
    }
    else
    {
        printf("Data deleted is :- %d",start->data);
        start = start->next;
    }
    return(start);
}

NODE* delbefore(NODE *start)
{
    NODE *temp, *temp2, *temp3;
    int val,i;
    printf("\n Enter the value before which you want to delete:-\n");
    scanf("%d",&val);
    if (start != NULL)
    {
        temp = start;
        temp2 = temp->next;
        temp3 = temp2->next;
        if(temp->data == val)
        {
            printf("\nDelete operation not possible as no node available before this node\n");
        }
        else if(temp2->data == val)
        {
            i = temp->data;
            printf("\n The value being deleted is %d.\n",i);
            start = temp2;
        }
        while(temp3 != NULL)
        {
            if(temp3->data == val)
            {
                i = temp2->data;
                temp->next = temp3;
                printf("\n The value being deleted is %d.\n",i);
                temp = temp->next;
                temp2 = temp->next;
                temp3 = temp2->next;
            }
            else
            {
                temp=temp->next;
                temp2 = temp2->next;
                temp3 = temp3->next;
            }
        }
    }
    else
    {
        printf("\n Empty list so operation not possible \n");
    }
    return(start);
}

/*NODE* delafter(NODE *start)
{
    NODE *temp, *temp2;
    int pos, i=1,count=0;
    count = countnode(start);
    printf("\nThe current number of nodes in the Linked list is:- %d\n So please enter the location after where you want to delete accordingly!\n",count);
    scanf("%d", &pos);
    printf("\n");
    temp = start;
    while(i < pos)
    {
        temp = temp->next; 
        if(temp->next == NULL)
        {
            printf("Wrong input\n");
            return start;
        }
        
        i++;
    }
    temp2 = temp->next;
    temp->next = temp2->next;
    return start;
}*/

NODE* delafter(NODE *start)
{
    NODE *temp, *temp2;
    int val,i;
    printf("\n Enter the value after which you want to delete:-\n");
    scanf("%d",&val);
    if (start != NULL)
    {
        temp = start;
        while(temp!= NULL)
        {
            if(temp->data == val)
            {
                if(temp->next == NULL)
                {
                    printf("\nDelete operation not possible as no node available after this node\n");
                }
                else
                {
                    temp2 = temp->next;
                    i = temp2->data;
                    temp2 = temp2->next;
                    temp->next = temp2;
                    printf("\n The value being deleted is %d.\n",i);
                }
            }
            temp = temp->next;
        }
    }
    else
    {
        printf("\n Empty list so operation not possible \n");
    }
    return(start);
}

NODE* deletespecific(NODE *start)
{
    NODE *temp,*temp2;
    int pos, i=1, count=0;
    count = countnode(start);
    printf("\nThe current number of nodes in the Linked list is:- %d\n So please enter the location which you want to delete accordingly!\n",count);
    scanf("%d", &pos);
    printf("\n");
    if(pos == 1)
    {
        start = begdelete(start);
    }
    else
    {
        temp = start;
        while(i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
    }
    return (start);
}

NODE* delvalue(NODE *start)
{
    int val,i=1,y=1,flag=0;
    NODE * ptr,*ptr2;
    printf("\nEnter the value you want to delete:-\n");
    scanf("%d",&val);
    ptr = start;
    while(ptr != NULL)
    {   
        if(ptr->data == val)
        {
            if(i==1)
            {
                start = begdelete(start);
            }
            else
            {
                ptr2 = start;
                while(y<i-1)
                {
                    ptr2=ptr2->next;
                    y++;
                }
                printf("Data found and deleted is :- %d",ptr->data);
                ptr2->next = ptr->next;
            }
            flag++;
        }
        ptr=ptr->next;
        i++;
    }
    if(flag>0)
    {
        printf("\nsuccess!\n");
    }
    else
    {
        printf("\n!!!!!!!!! Data was not present in the list !!!!!!!!!\n");
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
        printf("\n####### Printing List #######\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr ->next;  
        }  
    }  
}