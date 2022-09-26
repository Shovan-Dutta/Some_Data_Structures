/*Write a Program to implement a Doubly Linked List having the following functionalities.
- Insert
--- Insert at Beginning
--- Insert at End
--- Insert at any position
- Display
- Delete
--- Delete from beginning
--- Delete from End
--- Delete from any position
- Sort the list
- Reverse the list
- Merge to lists*/
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
int countnode(NODE *start);
NODE* beginsert(NODE *start);  //this function will insert a new node at the beginning of the linked list.
NODE* endinsert(NODE *start);  //this function will insert a new node at the end of the linked list.
NODE* abinsert(NODE *start);  //this function will insert a new node before or after of the linked list.
NODE* createlist(NODE *start); //Creates list indirectly calling beginsert or end insert.
NODE* begdelete(NODE *start);  //this function will delete a node at the beginning of the linked list.
NODE* enddelete(NODE *start);  //this function will insert a new node at the end of the linked list.
NODE* deleteall(NODE *start); // this function deletes the complete linked list.
NODE* abdelete(NODE *start); //this function deletes nodes anywhere in the linked list.
NODE* delafter(NODE *start); //deletes nodes after a particular node
NODE* delbefore(NODE *start);//deletes before a particular node
NODE* deletespecific(NODE *start);  //this function will delete a specific node of the linked list.
NODE* delvalue(NODE *start);//deletes a specific value
NODE* concatinate(NODE *start1,NODE *start2); //this function will join two linked lists.
NODE* reverse(NODE *start,NODE *revstart); //this function reverses the complete linked list.
NODE* sort(NODE *start); // sorts the linked list in ascending order.
void display(NODE *start);  // this function will display the linked list if there is any.

void main()
{
    int choice = 0;
    int subchoice1=0;
    int c = 0; 
    NODE *start;
    NODE *revstart;//to store the reverse of the original list.
    NODE *start1,*start2;//to store extra linked list for concatination.
    start = NULL;
    revstart = NULL;
    while(choice != 9)   //this will help to run the whole program in a loop.
    {  
        printf("\n############ Main Menu ############\n");  
        printf("\nChoose one option from the following list:-\n");    
        printf("-->To Create List press(1)\n-->For Other Insert options press(2)\n-->To Delete press(3)\n-->Create the reverse of List press (4)\n-->Sort List press (5)\n-->Show List press (6)\n-->Show reversed List press (7)\n-->Concatinate press (8)\n-->Exit press (9)\n");  
        printf("-- Enter your choice? --\n");         
        scanf("\n%d",&choice);  
        switch(choice)  //this switch case is to provide options for the user.
        {  
            case 1:
            do
            {                
                start = createlist(start);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);
            display(start);
            break;
            case 2:
            printf("\nChoose one option from the following list:-\n");
            printf("-->To Insert at begining press(1)\n-->To Insert at end press (2)\n-->To insert any where (3)\n-->To Go back to main menu Press(4)\n"); 
            printf("-- Enter your choice? --\n");
            scanf("\n%d",&subchoice1);
            switch (subchoice1)
            {
                case 1: 
                do
                {                
                    start = beginsert(start);
                    display(start);
                    printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                    scanf("%d",&c);
                }while(c==1);          
                break;  
                case 2: 
                do
                {                
                    start = endinsert(start);
                    display(start);
                    printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                    scanf("%d",&c);
                }while(c==1);
                break; 
                case 3:
                do
                {                
                    start = abinsert(start);
                    display(start);
                    printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                    scanf("%d",&c);
                }while(c==1);
                break;
                case 4:
                break; 
                default:  
                printf("!!Please enter valid choice!!"); 
            }
            break;
            case 3:
            printf("\nChoose one option from the following list:-\n");
            printf("-->To Delete at begining press(1)\n-->To Delete at end press (2)\n-->To Delete the full Linked List Press (3)\n-->To Delete from any position Press (4)\n"); 
            printf("-- Enter your choice? --\n");
            scanf("\n%d",&subchoice1);
            switch (subchoice1)
            {
                case 1: 
                do
                {                
                    start = begdelete(start);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
                }while(c==1);
                subchoice1=0;     
                break;  
                case 2: 
                do
                {                
                    start = enddelete(start);
                    printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                    scanf("%d",&c);
                }while(c==1);
                subchoice1=0;
                break;
                case 3:
                start = deleteall(start);  
                break;
                case 4:
                do
                {                
                    start = abdelete(start);
                    printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                    scanf("%d",&c);
                }while(c==1);
                subchoice1=0;
                break;
                default:  
                printf("!!Please enter valid choice!!"); 
                subchoice1=0;
            }
            break;
            case 4:
            revstart = reverse(start,revstart);
            display(revstart);
            break; 
            case 5:
            start = sort(start);
            break;
            case 6:
            display(start);
            break;
            case 7:
            display(revstart);
            break; 
            case 8:
            start1 = NULL;
            start2 = NULL;
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
            case 9:
            printf("Exiting....");
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
            ptr->prev = NULL;
            printf("--- 1st Node inserted ---\n");
        }  
        else  
        {  
            ptr->prev = NULL;
            ptr->next = start;  
            start = ptr;  
            printf("--- Node inserted at the begining ---\n");  
        }
        return(start);
}

NODE* createlist(NODE *start)
{
    start = beginsert(start);
    return (start);
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

NODE* abinsert(NODE *start)
{
    int c,count = 0;
    count = countnode(start);
    int item,i,loc;
    NODE *ptr,*temp,*temp2;
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
            loc = loc-1;
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
            temp2 = temp->next;
            temp2->prev = ptr;
            ptr->next = temp2;
            ptr->prev = temp;
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
            loc = loc-1;
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
            temp2 = temp->next;
            temp2->prev = ptr;
            ptr->next = temp2;
            ptr->prev = temp;
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
            if (loc > count)
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
                temp2 = temp->next;
            	temp2->prev = ptr;
            	ptr->next = temp2;
            	ptr->prev = temp;
            	temp->next = ptr;
                printf("Node inserted!\n");
                return(start);
            }
        }
    }
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
        start->prev = NULL;
    }
    return(start);
}

NODE* enddelete(NODE *start)
{   struct node *ptr;
    if(start == NULL)
    {
        printf("!!!!!! No available nodes to be deleted !!!!!!");
    }
    else
    {
        ptr = start;
        if (ptr->next==NULL)
        {
            printf("Data deleted is :- %d",ptr->data);
            start = NULL;
        }
        else
        {
           while(ptr->next != NULL)  
            {   
            	ptr = ptr ->next;  
            }  
            printf("Data deleted is :- %d",ptr->data);
            ptr = ptr->prev;
            ptr->next = NULL;
        }
    }
    return(start);
}

NODE* deleteall(NODE *start)
{
    if (start == NULL)
    {
        printf("!!!!!! No available Linked List to be deleted !!!!!!");
    }
    else
    {
        start = NULL;
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
        temp2 = temp2->next;
        temp2->prev = temp; 
        temp->next = temp2;
    }
    return (start);
}

NODE* delvalue(NODE *start)
{
    int val,i=1,y=1,flag=0;
    NODE * ptr,*ptr2,*ptr3;
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
                ptr2 = ptr->prev;
                ptr3 = ptr->next;
                printf("Data found and deleted is :- %d",ptr->data);
                ptr3->prev = ptr2;
                ptr2->next = ptr3;
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

NODE* delbefore(NODE *start)
{
    NODE *temp, *temp2, *temp3;
    int val;
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
            printf("\n The value being deleted is %d.\n",temp->data);
            start = temp2;
            temp2->prev = NULL;
        }
        while(temp3 != NULL)
        {
            if(temp3->data == val)
            {
                temp2 = temp3->prev;
                temp = temp2->prev;
                printf("\n The value being deleted is %d.\n",temp2->data);
                temp3->prev = temp;
                temp->next = temp3;
                temp3 = temp3->next;
            }
            else
            {
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

NODE* delafter(NODE *start)
{
    NODE *temp, *temp2;
    int val;
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
                    printf("\n The value being deleted is %d.\n",temp2->data);
                    temp2 = temp2->next;
                    temp2->prev = temp;
                    temp->next = temp2;
                    
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

NODE* abdelete(NODE *start)
{
    int choice =0;
    int c = 0;
    printf("\nChoose one option from the following list:-\n");    
    printf("-->Delete at specific position press (1)\n-->Delete before a value press (2)\n-->Delete after a value press (3)\n-->Delete a specific value press (4)\n");  
    printf("-- Enter your choice? --\n");         
    scanf("\n%d",&choice);  
    switch(choice)  //this switch case is to provide options for the user.
    {  
        case 1: 
        do
        {                
            start = deletespecific(start);
            display(start);
            printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
            scanf("%d",&c);
        }while(c==1);   
        break;  
        case 2: 
        do
        {                
            start = delbefore(start);
            display(start);
            printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
            scanf("%d",&c);
        }while(c==1);
        break;
        case 3: 
        do
        {                
            start = delafter(start);
            display(start);
            printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
            scanf("%d",&c);
        }while(c==1);
        break;
        case 4: 
        do
        {                
            start = delvalue(start);
            printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
            scanf("%d",&c);
        }while(c==1);
        break;   
        default:  
        printf("!!Please enter valid choice!!");  
    }  
    return(start);
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
        printf("\n############ Printing Doubly Linked List ############\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr ->next;  
        }  
    }  
}

NODE* sort(NODE *start)
{
    NODE *temp,*next;
    int var;
    temp=start;
    if(temp == NULL)
    {
        printf("\n!!!!!!!There is no list to be sorted!!!!!!!\n");
    }
    else
    {
        while(temp->next != NULL)
        {
            next=temp->next;
            while(next != NULL)
            {
                if(temp->data > next->data)
                {
                    var = temp->data;
                    temp->data = next->data;
                    next->data = var;
                }
                next = next->next;
            }
            temp = temp->next;
        }
    }
    return (start);
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
                ptr->prev = NULL;
                //printf("--- 1st Node inserted ---\n");
            }  
            else  
            {  
                ptr->prev = NULL;
                ptr->next = revstart;
                revstart->prev = ptr;  
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
        start2->prev = ptr;
        printf("\nThe concatination was a success!\n");
    }
    return(start1);
}
