//Wap to implement insertion sort using linked list.
#include<stdio.h>
#include<stdlib.h>

struct node   //defines the structure of the node
{  
    int data;  
    struct node *next;   
};

typedef struct node NODE; //renaming 'struct node' as 'NODE'

NODE* createnode();//this function will only create new nodes when called.
NODE* insertion_sort(NODE *start);//this function is used to implement insertion sort.
void display(NODE *start);  // this function will display the linked list if there is any.

void main()
{
    int choice = 0,c;
    NODE *start;
    start = NULL;
    while(choice!=3)
    {
        printf("\n############ Main Menu ############\n");  
        printf("\nChoose one option from the following list:-\n");    
        printf("-->Insert with insertion sort press (1)\n-->Show press (2)\n-->Exit press (3)\n");  
        printf("-- Enter your choice? --\n");         
        scanf("\n%d",&choice);
        switch(choice)  //this switch case is to provide options for the user.
        {  
            case 1: 
            do
            {
                start = insertion_sort(start);
                printf("Do you want to continue:- \nPress (1) to continue.\nPress any other number to stop\n ");
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

NODE* insertion_sort(NODE *start)
{
    NODE *temp,*temp2,*ptr;
    int item;
    ptr = createnode();
    printf("Enter the data:- \n");
    scanf("%d",&item);
    ptr->data = item;
    if (start==NULL)
    {
    start = ptr;
    ptr->next = NULL;
    printf("1st Node Inserted!\n");
    }
    else
    {
        temp = start;
        temp2=start;
        while(temp2 != NULL)
        {
            if(temp->data>=item)
            {
                if (temp ==start)
                {
                    ptr->next=start;
                    start = ptr;
                    printf("Node inserted at the beginning according to insertion sort!\n");
                    break;
                }
                else
                {
                    ptr->next = temp;
                    temp2->next = ptr;
                    printf("Node inserted according to insertion sort!\n");
                    break;
                }
            }
            else if(item>=temp->data && temp->next == NULL)
            {
                    temp->next = ptr;
                    ptr->next = NULL;
                    printf("Node inserted at the end according to insertion sort!\n");
                    break;
            }
            temp2=temp;
            temp=temp->next;
        }
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
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr ->next;  
        }  
    }  
}