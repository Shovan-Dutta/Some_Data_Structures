/*1. Write a program to implement Stack using array.
2. Write a program to implement Stack using linked list.
3. Write a program to implement Queue using array.
4. Write a program to implement Queue using linked list.*/

//1
#include<stdio.h>

int* push(int a[], int n);
void pop(int a[]);
void display(int a[]);

int top = -1;

void main()
{
    int choice =0, c = 0, n,i;
    int *changed;
    printf("\n Before we begin please enter the size of the Stack:- \n");
    scanf("%d",&n);
    int a[n];
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
                changed = push(a,n);
                for(i=0;i<=top;i++)
                {
                    a[i]= *changed;
                    changed = changed + 1;
                }
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);    
            break;  
            case 2:  
            do
            {                
                pop(a);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);        
            break; 
            case 3:
            if(top  != -1)
            {
                printf("\n%d is the top element of the Stack.\n",a[top]);
            }
            else
            {
                printf("\n Stack empty Peek not possible!\n");
            }
            break;
            case 4:
            if(top != -1)
            {
                printf("\nStack is not empty!\n");
            } 
            else
            {
                printf("\n Stack is empty! \n");
            }
            break;
            case 5:
            display(a); 
            break; 
            case 6:
            printf("\nExiting...\n");
            break;   
            default:  
            printf("\n!!Please enter valid choice!!\n"); 
        }  
    }
}

int* push(int a[], int n)
{
    int data;
    if(top == n-1)
    {
        printf("\n!!!!!!!!! Stack Overflow !!!!!!!!!\n");
    }
    else
    {
        printf("\n Enter the data you want to push in the stack:- \n");
        scanf("%d",&data);
        top = top + 1;
        a[top] = data;
    }
    return(a);
}

void pop(int a[])
{
    if(top == -1)
    {
        printf("\n!!!!!!!!! Stack Underflow !!!!!!!!!\n");
    }
    else
    {
        printf("\n%d is being poped!\n",a[top]);
        top = top - 1;
    }
}

void display(int a[])
{
    int i =top;
    if(top == -1)
    {
        printf("\n!!!!!!!!! No Stack exists to be printed !!!!!!!!!\n");
    }
    else
    {
        printf("\n############ Printing Stack ############\n");
        while(i>=0)
        {
            printf("%d\n",a[i]);
            i--;
        }
    }
}

//2
#include<stdio.h>
#include<stdlib.h>

struct node   //defines the structure of the node
{  
    int data;  
    struct node *next;   
};

typedef struct node NODE;

NODE* createnode();//this function will only create new nodes when called.
NODE* push(NODE *top);  //this function will push new element in stack.
NODE* pop(NODE *top);  //this function will pop an element from stack.
void display(NODE *top);  // this function will display the stack if there is any.

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
        if(top == NULL)  //this condition is checking if there is an existing stack and pushing the data accordingly.
        {  
            top  = ptr;
            ptr->next = NULL;
            printf("\n--- 1st Data Pushed ---\n");
        }  
        else  
        {  
              
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
	}
	return(top);
}

void display(NODE *top)  // this function will display the stack if there is any. 
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

//3
#include<stdio.h>

int* enqueue(int a[],int n);  //this function will enqueue a new data at the end of the queue.
void dequeue(int a[]);  //this function will dequeue an element from queue.
void display(int a[]);  // this function will display the queue if there is any.

int front = -1;
int back = -1;

void main()
{
    int choice =0, c = 0, n,i;
    int *changed;
    printf("\n Before we begin please enter the size of the Queue:- \n");
    scanf("%d",&n);
    int a[n];
    while(choice != 6)   //this will help to run the whole program in a loop.
    {  
    	if(front>back)
    	{
    		front=-1;
    		back=-1;
    	}
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
                changed = enqueue(a,n);
                for(i=front;i<=back;i++)
                {
                    a[i]= *changed;
                    changed = changed + 1;
                }
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);    
            break;  
            case 2:  
            do
            {                
                dequeue(a);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
            }while(c==1);        
            break; 
            case 3:
            if(front!=-1 && front<=back)
            {
                printf("\n%d is the first element of the Queue.\n",a[front]);
            }
            else
            {
                printf("\n Queue empty Peek not possible!\n");
            }
            break;
            case 4:
            if(front!=-1 && front<=back)
            {
                printf("\n Queue is not empty!\n");
            } 
            else
            {
                printf("\n Queue is empty! \n");
            }
            break;
            case 5:
            display(a); 
            break; 
            case 6:
            printf("\nExiting...\n");
            break;   
            default:  
            printf("!!Please enter valid choice!!"); 
        }  
    }
}

int* enqueue(int a[],int n)
{
	int data;
	if(front==-1 && back==-1)
	{
		printf("\n Enter the data you want to enqueue in the queue:- \n");
        scanf("%d",&data);
		front=0;
		back=0;
		a[back] = data;
	}
	else if(back>=front && back < n)
	{
		printf("\n Enter the data you want to enqueue in the queue:- \n");
        scanf("%d",&data);
        back=back+1;
        a[back] = data;
	}
	else
	{
		printf("\n!!!! Queue full !!!!\n");
	}
	return(a);
}

void dequeue(int a[])
{
	if(front == -1 || front > back)
	{
		printf("\n!!!!!! Empty Queue !!!!!!\n");
	}
	else
	{
		printf("\n%d is being dequeued!\n",a[front]);
		front = front + 1;
	}
}

void display(int a[])
{
	int i;
	if(front!=-1 && front<=back)
	{
		printf("\n############ Printing Queue ############\n");
		for(i=front;i<=back;i++)
		{
			printf("%d\n",a[i]);
		}
	}
	else
	{
		printf("\n!!!!!!!!! No Queue exists to be printed !!!!!!!!!\n");
	}
}

//4
#include<stdio.h>
#include<stdlib.h>

struct node   //defines the structure of the node
{  
    int data;  
    struct node *next;   
};

typedef struct node NODE;

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
        printf("--- 1st Data Enqueued ---\n");
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
        printf("--- Data Enqueue ---\n"); 
    }
    return(start);
}

NODE* dequeue(NODE *start)
{
	if(start == NULL)
	{
		printf("!!!!!! Empty Queue !!!!!!");
	}
	else
	{
		printf("Data dequeued is :- %d",start->data);
		start = start->next;
	}
	return(start);
}

void display(NODE *start) 
{  
    NODE *ptr;  
    ptr = start;   
    if(ptr == NULL)  
    {  
        printf("!!!!!!!!! No Queue exists to be printed !!!!!!!!!");  
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
