#include<stdio.h>  //insertion sort works even for duplicates data
int main()//worst casetime O(n^2)when array is in decendeing order and besst case when array
{                                                             // is increasingorder O(n)
	int arr[50],size,i,j,temp;
	printf("\nEnter total number of elements: "); 
	scanf("%d",&size);
	printf("\nEnter elements: ");
	for(i=0;i<size;i++)
	{                     //***insertion sort is STABLE and inplace.it is also suitable for linked list
	  scanf("%d",arr+i);   //its modified version is shell short but shell sort is not stable but faster	
	}                      //than insertion sort.insertion sort is stable  shell sort is not stable
/*	for(i=1;i<size;i++)
	{
		temp=arr[i]; 
		for(j=i-1;j>=0;j--)
		{                           //or
			if(arr[j] > temp)
			{
				arr[j+1]=arr[j];
			}
			else
			{
			 break;
			}
		}
		arr[j+1]=temp;
 }*/
	for(i=1;i<size;i++)
	{
		temp=arr[i];
		j=i-1;
		while(j>=0 && arr[j] > temp )
		{
			arr[j+1]=arr[j];
			j--;
		}
			arr[j+1]=temp;
	}
		printf("\nAfter insertion sort elements are : ");
		for(i=0;i<size;i++)
	{
	  printf("%d ",*(arr+i));//using pointer
	}
	return 0;
}

