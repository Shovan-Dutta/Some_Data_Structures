// Write a C/C++ Program to implement Linear Search in an Array.
#include<stdio.h>

int ls(int a[],int find,int n,int pos);

void main()
{
	int n,i,find,pos = -1;
	printf("Enter the size of the array:- \n");
	scanf("%d",&n);
	int a[n];
	printf("Now enter the array elements:-\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Now enter the element to be searched:-\n");
	scanf("%d",&find);
	pos = ls(a,find,n,pos);
	if(pos>0)
	{
		printf("Item found at position number:- %d\n",pos);
	}
	else
	{
		printf("The element is not present in the array.\n");
	}
}

int ls(int a[],int find,int n,int pos)
{
	int i;
	for(i=0;i<n;i++)
	{
		if (a[i]==find)
		{
			pos = i+1;
			break;
		}
	}
	return pos;
}
