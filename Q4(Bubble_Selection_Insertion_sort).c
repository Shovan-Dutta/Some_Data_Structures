/*Write programs to implement the following sorting algorithms on a integer array of N elements.
     - Bubble Sort
     - Selection Sort
     - Insertion Sort*/

//Bubble Sort
#include <stdio.h>

int* bubble(int a[],int n);

void main()
{
	int n,i;
	int *sorted;
	printf("Enter the size of the array:\n");
	scanf("%d",&n);
	int a[n];
	printf("Now enter the array elements:\n");
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sorted = bubble(a,n);
	printf("After sorting:-\n");
	for(i=0;i<n;i++)
	{
	    printf("%d\n", *sorted);
	    sorted=sorted+1;
	}
}
int* bubble(int a[],int n)
{
	int i,j,temp;
	for(i = 0;i<n-1;i++)// this loop is being used to grab the element to be comapred
	{
		for(j=i+1;j<n;j++)// this loop is used to grab the second element to which the first element is to be compared.
		{
			if (a[i]>a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	return(a);
}

//Selection Sort
#include <stdio.h>

int* bubble(int a[],int n);

void main()
{
	int n,i;
	int *sorted;
	printf("Enter the size of the array:\n");
	scanf("%d",&n);
	int a[n];
	printf("Now enter the array elements:\n");
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sorted = bubble(a,n);
	printf("After sorting:-\n");
	for(i=0;i<n;i++)
	{
	    printf("%d\n", *sorted);
	    sorted=sorted+1;
	}
}
int* bubble(int a[],int n)
{
	int i,j,temp;
	for(i = 0;i<n-1;i++)// this loop is being used to grab the element to be comapred
	{
		for(j=i+1;j<n;j++)// this loop is used to grab the second element to which the first element is to be compared.
		{
			if (a[i]>a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	return(a);
}

//Insertion Sort
#include<stdio.h>

int* insertion_sort(int a[],int n);

void main()
{
	int n,*sorted,i;
	printf("Enter the size of the array:-\n");
	scanf("%d",&n);
	int a[n];
	for (i = 0; i<n;i++)
	{
		a[i]=-99;
	}
	sorted = insertion_sort(a,n);
	printf("After implementing insertion sort the array looks like:-\n");
	for(i=0;i<n;i++)
	{
		a[i]= *sorted;
		printf("%d\n",a[i]);
		sorted = sorted + 1;
	}
}

int* insertion_sort(int a[],int n)
{
	int i,j,z,item,l=0,r=0;
	for(i=0;i<n;i++)
	{
		printf("Enter data one at a time:-\n");
		scanf("%d",&item);
		for(j=0;j<n;j++)
		{
			if(a[l]==-99 &&a[r]==-99)//when array is empty
			{
				a[r] = item;
				printf("1st item inserted!\n");
				break;
			}
			else if(a[l]<=item && a[r]>=item)//when array has elements but new element is bigger the some elements but smaller than other elements
			{
				for(z=n-2;z>=r;z--)
				{
					a[z+1] = a[z];
				}
				a[r] = item;
				printf("Item inserted in between!\n");
				break;
			}
			else if(a[l]<=item && a[r] == -99)//when array has elements but the new element is the largest
			{
				a[r] = item;
				printf("Item inserted at the end!\n");
				break;
			}
			else if(a[l]>=item)//when array has elemets but new element is smallest
			{
				for(z=n-2;z>=l;z--)
				{
					a[z+1] = a[z];
				}
				a[l] = item;
				printf("Item inserted in begin!\n");
				break;
			}
		l=r;
		r = r+1;
		}
		l=0;
		r=0;
	}
	return(a);
}
