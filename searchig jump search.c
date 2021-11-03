#include<stdio.h>//without finding duplicates time complexity =rootn
#include<stdlib.h>//it is better the linear search***
#include<math.h>
void linear_search(int *arr,int beg ,int end,int search_element );
int main()
{
	int *arr,i,total_elements,search_element,gab_jump,beg,end,flag=0;
	printf("\nEnter total number of elements: ");
	scanf("%d",&total_elements);
	arr=(int*)malloc(sizeof(int)*total_elements);//dynamically created array
	printf("\nEnter sorted array otherwise it will not work");
	printf("\nEnter element: ");
	for(i=0; i<total_elements;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nEnter element to search in array: ");
	scanf("%d",&search_element);
	end=gab_jump=sqrt(total_elements);//initially assignig end wth gab value 
	beg=0;
	while(end <= total_elements-1)
	{
	 if(arr[end] <= search_element)//if element is at index arr[end] then linear search can be avoided
	 {
	  if(arr[end]==search_element)
	  {
	   printf("\nElement %d Found at index %d ",arr[end],end);
	   break;//terminate while loop
	  }
	  else
	  {
	  	beg=end;
	  	end=end+gab_jump;//updating jump
	  }
	 }
	 else if(arr[end] >= search_element)//if control comes here it means element will be sure here
	 {                                   //if not then linear function will print not found 
	   if(arr[end]==search_element)//if element is at index arr[end] then linear search can be avoided
	    {
	     printf("\nElement %d Found at index %d ",arr[end],end);
	     break;//terminate while loop
	    }
	    else
	    {
	      linear_search(arr,beg,end,search_element);
	      break;
		}
	 }
	}
	if(end >= total_elements)//will work only when end become greater or equal to total_elements
	{
	  linear_search(arr,beg,total_elements-1,search_element);
	/*we are passing total_elements-1 because end is greater then array size so total_elements-1
	 is passed so that it point to last index of array */	
	}
	free(arr);//dynamically created so freeing it
	return 0;
}
void linear_search(int *arr,int beg ,int end,int search_element)
{
  int i,flag=0;
  for(i=beg; i<=end ; i++)
  {
  	if(arr[i]==search_element)
  	{
  	  printf("\nElement %d Found at index %d ",arr[i],i);
	  flag=1;	
	}
  }
  if(flag==0)
  {
  	printf("\nElement %d not found in array",search_element);
  }
}
