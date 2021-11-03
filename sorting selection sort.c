/*selection Sort is not STABLE because it swaps non-adjacent elements.but can be made stable by
 if instead of swapping, the minimum element is placed in its position without
swapping i.e. by placing the number in its position by pushing every element one step forward.
it is iNPLACE sorting*/
#include<stdio.h>  //selection sort works even for duplicates data.
int main()//time worst case  O(n^2) and best case also omega(n^2)
{
	int arr[50],size,i,j,min,temp;
	printf("\nEnter total number of elements: ");
	scanf("%d",&size);
	printf("\nEnter elements: ");
	for(i=0;i<size;i++)
	{                     //**************it is the algo that require less number of swap o(n)
	  scanf("%d",arr+i);	
	}
	for(i=0;i<size-1;i++)
	{
		min=i;
		for(j=i+1;j < size;j++)
		{
			if(arr[min] > arr[j])
			{
				min=j;  //only index is changed
			}
		}
		if(min != i)//it will indicate to swap only min ia changed
		{
		temp=arr[min];
		arr[min]=arr[i];  //swaping
		arr[i]=temp;
	   }
	}
	printf("\nAfter Selection sort elements are : ");
	for(i=0;i<size;i++)
	{
	  printf("%d ",*(arr+i));//using pointer
	}
	return 0;
}
//7.5 Selection Sort Algorithm | Data Structure jenneys lectures
