//Write a C/C++ Program to implement Binary Search in an Array using Recursion/without Recursion.

#include<stdio.h>

int bs(int a[],int beg,int end, int find, int pos);

void main()
{
	int n,i,find,beg,end,pos = -1;
	printf("Enter the size of the array:- \n");
	scanf("%d",&n);
	beg = 0;
	end = n;
	int a[n];
	printf("Now enter the array elements in assending order:-\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Now enter the element to be searched:-\n");
	scanf("%d",&find);
	pos = bs(a,beg,end,find,pos);
	if(pos>0)
	{
		printf("Item found at position number:- %d\n",pos);
	}
	else
	{
		printf("The element is not present in the array.\n");
	}
}

int bs(int a[],int beg,int end, int find, int pos)
{
	int mid;
	if(end>=beg)
	{
		mid = (end+beg)/2;
		if(a[mid]==find)
		{
			pos= mid+1;
		}
		else if(a[mid]<find)
		{

			beg=mid+1;
			pos = -1;
			pos = bs(a,beg,end,find,pos);
		}
		else
		{
			end=mid-1;
			pos =-1;
			pos = bs(a,beg,end,find,pos);
		}
	}
	return(pos);
}
