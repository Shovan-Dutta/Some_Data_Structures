//Write a program to check whether a binary tree is height-balanced or not.

#include <stdio.h>  
#include <stdlib.h> 

struct node   //defines the structure of the node
{  
    int data;  
    struct node *left;
    struct node *right;   
};

typedef struct node NODE; //renaming 'struct node' as 'NODE'

NODE* createnode();
NODE* insert(NODE *root, NODE *ptr);
NODE* delete(NODE *root,NODE *parent,int item);
int search(NODE *root,int item);
int ishb(struct node *root);// checks if the tree is height balanced
int height(struct node *root);// can return the height of the tree.
int larger(int a, int b);// finds the larger number between 2 numbers.
void preorder(NODE *root); //displays the tree postorder
void inorder(NODE *root); //displays the tree inorder
void postorder(NODE *root); //displays the tree postorder

void main()
{
	int choice = 0,c=0,item,flag;
	NODE *root = NULL, *ptr,*parent=NULL;
	while(choice!=8)
	{
		printf("\n############ Main Menu ############\n");  
        printf("\nChoose one option from the following list:-\n");
        printf("-->Insert a node in Binary Search Tree Press (1)\n-->Delete a node in Binary Search Tree Press (2)\n-->Inorder Traversal Press (3)\n-->Preorder Traversal Press (4)\n-->Postorder Traversal Press (5)\n-->Search a key in Binary Search Tree Press (6)\n-->Is the tree height balanced Press (7)\n-->Exit Press (8)\n");
        printf("-- Enter your choice? --\n");         
        scanf("\n%d",&choice);  
        switch(choice)
        {
        	case 1:
        	do
        	{
        		ptr = createnode();
        		root = insert(root, ptr);
        		printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
        	}while(c==1);
        	break;
        	case 2:
        	do
        	{
        		printf("\nEnter the data you want to delete:-\n");
		        scanf("%d",&item);
        		root = delete(root,parent,item);
        		printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
        	}while(c==1);
        	break;
        	case 3:
        	printf("\n###### Tree as Inorder ######\n");
        	inorder(root);
        	break;
        	case 4:
        	printf("\n###### Tree as Preorder ######\n");
        	preorder(root);
        	break;
        	case 5:
        	printf("\n###### Tree as Postorder ######\n");
        	postorder(root);
        	break;
        	case 6:
        	do
        	{
        		printf("\nEnter the item to be searched\n");
        		scanf("%d", &item);
        		flag = search(root,item);
        		if(flag == item)
        		{
        			printf("\n Item present in the tree\n");
        		}
        		else
        		{
        			printf("\n Item not found in the tree\n");
        		}
        		printf("\n--- Do you want to continue? ---\n-->Press (1) for YES.\n-->Press any other number for NO.\n");
                scanf("%d",&c);
        	}while(c==1);
        	break;
        	case 7:
        	if(ishb(root) == 1)
        	{
     			printf("Height Balanced Tree\n");
    		} 
    		else 
    		{
 				printf("Not a Height Balanced Tree\n");
   			}
        	break;
        	case 8:
        	printf("Exiting...");
        	break;
        	default:
        	printf("\n Please enter a valid choice \n");
        }
	}
}

NODE* createnode()  
{
	int item;
    NODE *one;
    one = (NODE *)malloc(sizeof(NODE*));
    if(one==NULL)   // this condition will check if the node was created
    {
        printf("--- Overflow ---\n");
         
    }
    else
    {
    	printf("\nEnter data:-\n");
    	scanf("%d",&item);
    	one->data = item;
    	one->right = NULL;
    	one->left = NULL;
        return (one);
    }
}

NODE* insert(NODE *root, NODE *ptr)
{
    NODE *current,*parent;     
    if (root== NULL)
    {
    	root = ptr;
    }
    else
    {
    	current = root;
    	while(1)
    	{
    		parent = current;
    		if(ptr->data < current->data)
    		{
    			current = current->left;
    			if(current == NULL)
    			{
    				parent->left = ptr;
    				return(root);
    			}
    		}
    		else
    		{
    			current = current->right;
    			if(current == NULL)
    			{
    				parent->right = ptr;
    				return(root);
    			}
    		}
    	}
    }
}

NODE* delete(NODE *root,NODE *parent, int item)
{
	int flag=0;
	NODE *current,*temp,*temp2;
	if(root== NULL)
	{
		printf("\n!!Binary search tree is empty so delete not possible!!\n");
		return(root);
	}
	else
	{
		current = root;
		if(item < current->data) //to search the left subtree
		{
		    parent = current;
            delete(current->left,parent,item);
		}
		else if(item > current->data) // to search the right subtree
		{
		    parent = current;
			delete(current->right,parent,item);
		}
		else if (item == current->data)// when we actually find the data
		{
			printf("\n Data was successfully deleted!\n");
			if(current->left == NULL && current->right == NULL)// the node has no child
			{
				if(parent->left == current)
				    parent->left = NULL;
				else
				    parent->right = NULL;
				flag = 1;
			}
			else if(current->left == NULL) // the node has a right child
			{
			    if(parent->left == current)
				    parent->left = current->right;
				else
				    parent->right = current->right;
				flag = 1;
			}
			else if(current->right == NULL) // the node has a left child
			{
			    if(parent->left == current)
				    parent->left = current->left;
				else
				    parent->right = current->left;
				flag = 1;
			}
			else
			{
			    if(parent->left == current)
				    parent->left = current->right;
				else
				    parent->right = current->right;
				temp = current->left;
				insert(root,temp);
			}
		}

	}
	/*if(flag != 1)
	{
		printf("\nItem not present in the tree to be deleted!\n");
	}*/
	return(root);
}

void preorder(NODE *root) //displays the tree postorder
{  
   	NODE *ptr;
    if(root == NULL)//Check whether tree is empty
    {  
        printf("Tree is empty\n");  
          return;  
    }  
    else 
    {   
    	ptr = root; 
    	printf("%d ", ptr->data);   
        if(ptr->left!= NULL)
        {
            postorder(ptr->left);  
        }  
        if(ptr->right!= NULL) 
        {
        	postorder(ptr->right);
        } 
    }        
}

void inorder(NODE *root) //displays the tree inorder
{  
   	NODE *ptr;
    if(root == NULL)//Check whether tree is empty
    {  
        printf("Tree is empty\n");  
          return;  
    }  
    else 
    {   
    	ptr = root;    
        if(ptr->left!= NULL)
        {
            inorder(ptr->left);  
        }
        printf("%d ", ptr->data);  
        if(ptr->right!= NULL) 
        {
        	inorder(ptr->right);
        } 
    }        
}

void postorder(NODE *root) //displays the tree postorder
{  
   	NODE *ptr;
    if(root == NULL)//Check whether tree is empty
    {  
        printf("Tree is empty\n");  
          return;  
    }  
    else 
    {   
    	ptr = root;    
        if(ptr->left!= NULL)
        {
            postorder(ptr->left);  
        }  
        if(ptr->right!= NULL) 
        {
        	postorder(ptr->right);
        }
        printf("%d ", ptr->data); 
    }        
}

int search(NODE *root,int item)
{
	if(root==NULL)
	{
		return(-999);
	}
	else if(root->data<item)
	{
		search(root->right,item);
	}
	else if(root->data>item)
	{
		search(root->left,item);
	}
	else if(root->data== item)
	{
		return (item);
	}
	else
	{
		return(-999);
	}
}

int larger(int a, int b)
{
 if(a >= b)
 {
     return a;
 }
 else
 {
     return b;
 }
}

int height(struct node *root)
{
    int leftHeight, rightHeight;
    if(root == NULL)
    {
        return 0;
    }
    else
    {
    	leftHeight = height(root->left);
    	rightHeight = height(root->right);
    }
    return larger(leftHeight, rightHeight) + 1;
}

int ishb(struct node *root)
{
   int leftHeight, rightHeight;
   if(root == NULL)
   {
       return 1; 
   }
   leftHeight = height(root->left);
   rightHeight = height(root->right);
   if(abs(leftHeight - rightHeight) <= 1 &&ishb(root->right) &&ishb(root->left))
       return 1;
   else
       return 0;
}
