//Wap to perform 2 polynomial addition using linked list.
#include<stdio.h>
#include<stdlib.h>

struct node   //defines the structure of the node
{  
    int coefficient; 
    int power;
    struct node *next;   
};

typedef struct node NODE; //renaming 'struct node' as 'NODE'

NODE* createnode();//this function will only create new nodes when called.
NODE* endinsert(NODE *start,int item,int p); //this function will insert a new node at the beginning of the linked list.
int countnode(NODE *start); // count the number of nodes in each polynomial.
NODE* add(NODE *starta, NODE *startb,NODE *startc);//Used to add two Polynomials.
void display(NODE *start);  // this function will display the linked list if there is any.

void main()
{
	int choice =0;
    int subchoice = 0;
    int item,p;
    NODE *starta,*startb,*startc;
    starta = NULL;
    startb = NULL;
    startc = NULL;
    while(choice != 7)   //this will help to run the whole program in a loop.
    {
    	printf("\n############ Main Menu ############\n");  
        printf("\nChoose one option from the following list:-\n");    
        printf("-->Create or Update the 1st Polynomial press (1)\n-->Create or Update the 2nd Polynomial press (2)\n-->Add two Polynomials press (3)\n-->Show 1st Polynomial press (4)\n-->Show 2nd Polynomial press (5)\n-->Show the Added Polynomial press (6)\n-->Exit press (7)\n");  
        printf("-- Enter your choice? --\n");
        scanf("\n%d",&choice);
        switch(choice)  //this switch case is to provide options for the user.
        {
        	case 1: 
            do
            {   
            	printf("\nEnter coefficient value:-\n");    
    			scanf("%d",&item);
    		    printf("\nEnter power of variable value:-\n");    
    			scanf("%d",&p);      
                starta = endinsert(starta,item,p);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&subchoice);
            }while(subchoice==1);    
            break;
            case 2: 
            do
            {   
            	printf("\nEnter coefficient value:-\n");    
    			scanf("%d",&item);
    		    printf("\nEnter power of variable value:-\n");    
    			scanf("%d",&p);             
                startb = endinsert(startb,item,p);
                printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&subchoice);
            }while(subchoice==1);
            break;
            case 3:
            startc = add(starta,startb,startc);
            if(startc != NULL)
            {
               	display(startc);
            }
            else
            {
             	printf("!!!!!!First enter the polynomials!!!!!!");
            }
            break;
            case 4:  
            display(starta);        
            break;
            case 5:  
            display(startb);        
            break;
            case 6:  
            display(startc);        
            break;
            case 7:  
            exit(7);        
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
        return (one);
    }
}

NODE* endinsert(NODE *start,int item, int p )
{
    NODE *ptr,*temp;  
    ptr = createnode();
    ptr->coefficient = item;
    ptr->power = p;
    if(start == NULL)  //this condition is checking if there is an existing linked list and linking the node accordingly.
    {  
        start  = ptr;
        ptr->next = NULL;
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
        ptr = ptr->next;  
    }
    return(c);
}

NODE* add(NODE *starta, NODE *startb,NODE *startc)
{
	int size1,size2,i=0,flag = 0;
	NODE *temp1,*temp2;
	temp1=starta;
	temp2 = startb;
	int coeff,pow;
	if(starta != NULL && startb != NULL)
	{
		size1 = countnode(starta);
		size2 = countnode(startb);
		if(size1>=size2)
		{
			while(i<size1)
			{
				while(startb!=NULL)
				{
					if(starta->power==startb->power)
					{
						pow = starta->power;
						coeff = starta->coefficient+startb->coefficient;
						startc = endinsert(startc,coeff,pow);
						flag = 1;
					}
					startb = startb->next;
				}
				startb = temp2;
				if(flag==0)
				{
					pow = starta->power;
					coeff = starta->coefficient;
					startc = endinsert(startc,coeff,pow);
				}
                flag =0;
				starta = starta->next;
				i = i+1;
			}
			starta = temp1;
            i=0,flag = 0;
            while(i<size2)
            {
                while(starta!=NULL)
                {
                    if(startb->power==starta->power)
                    {
                        flag++;
                    }
                }
                if(flag==0)
                {
                    pow = startb->power;
                    coeff = startb->coefficient;
                    startc = endinsert(startc,coeff,pow);
                }
            }
		}
		else
		{
			while(i<size2)
			{
				while(starta!=NULL)
				{
					if(starta->power==startb->power)
					{
						pow = startb->power;
						coeff = starta->coefficient+startb->coefficient;
						startc = endinsert(startc,coeff,pow);
						flag = 1;
					}
					starta = starta->next;
				}
				starta = temp1;
				if(flag==0)
				{
					pow = startb->power;
					coeff = startb->coefficient;
					startc = endinsert(startc,coeff,pow);
				}
                flag = 0;
				startb = startb->next;
				i = i+1;
			}
			startb = temp2;
            i=0,flag = 0;
            while(i<size1)
            {
                while(startb!=NULL)
                {
                    if(startb->power==starta->power)
                    {
                        flag++;
                    }
                }
                if(flag==0)
                {
                    pow = starta->power;
                    coeff = starta->coefficient;
                    startc = endinsert(startc,coeff,pow);
                }
            }
		}
	}
	return(startc);
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
        printf("\n############ The Polynomials is ############\n");   
        while (ptr!=NULL)  
        {  
            printf("(%dx^%d)",ptr->coefficient,ptr->power);
            printf("+");
            ptr = ptr ->next;  
        }
    }
    printf("\n");
}     

