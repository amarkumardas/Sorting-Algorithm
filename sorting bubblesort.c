/*bubble sort works even for duplicates data

time complexity worst case O(n^2) best case if we use flag variable omega(n) 
THis code is optimised with flag variable that means if array is already sorted then time complexity
would be omega O(n)
 
bubble sort is stable and inplace sort*/ 
#include<stdio.h>  
int main()
{
	int arr[50],size,i,j,temp,flag=0;
	printf("\nEnter total number of elements: ");
	scanf("%d",&size);
	printf("\nEnter elements: ");
	for(i=0;i<size;i++)                  /
	{
	  scanf("%d",arr+i);	 
	}
	for(i=0;i<size-1;i++)      //it is optimised
	{
		flag=0;
		for(j=0;j<size-1-i;j++)//i is use to avoid unnecessary comparision
		{
		    if(arr[j] > arr[j+1])
			{
			   temp=arr[j];
			   arr[j]=arr[j+1];//swaping
			   arr[j+1]=temp; 
			   flag=1;	
			}	
		}
		if(flag==0)//sometimes array get sorted early so to avoid extra iteration break is used to
		{                                                                //terminate outer for loop
			break;
		}
	}
	printf("\nAfter Bubble sort elements are : ");
		for(i=0;i<size;i++)
	{
	  printf("%d ",*(arr+i));//using pointer
	}
	return 0;
}
