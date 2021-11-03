/*time COMPLEXITY of heapify method is O(n) to bulid heap which is better than heap meathod O(nlogn)
this code is  very similar to heap sort
->in youtube code explaination is wrong(jenneys)this is right code
    //**here first user enter elements then max heapify is created in different way then sorted
//video->7.9Heap Sort | Heapify Method | Build Max Heap Algorithm */
#include<stdio.h>//TIME COMPLEXITY is O(n logn)
#define MAX 50
void modified_heapifymehod(int *arr,int i ,int totalelements);
int main()                          // 8 7 9 10 3 4 1 12 6 5
{
	int arr[MAX],i,j,totalelements,element,swap,temp;
	printf("\nEnter total number of elements : ");   //this is BINARY HEAP
	scanf("%d",&totalelements);
	printf("\nEnter element: ");
	for(i=0;i<totalelements;i++)
	{
		scanf("%d",&arr[i]);	 
	}
	for(i=(totalelements/2)-1; i>=0; i--)//creating max heapify only this isdefferent from heap sort
	{                  //(totalelements/2)-1 formula to get leaf node since array index start from 0 
		  modified_heapifymehod(arr, i , totalelements );//O(n)	 
	}
	printf("max heapify: ");//arrangement is different from max heap 
	                        
	for(i=0;i<totalelements;i++)//for information
	{ 
		printf(" %d",arr[i]); 
	}
	for(j=totalelements-1 ;j > 0 ; j--)//no need j>=0 it just do extra execution which is not needed
   {
   	 temp=arr[0];
   	 arr[0]=arr[j];//swapping root element to last element
	 arr[j]=temp;
	 modified_heapifymehod(arr,0,j);
   }
	printf("\nElements after sorted: ");
	for(i=0;i<totalelements;i++)
	{
		printf(" %d",arr[i]); 
	}	
}
void modified_heapifymehod(int *arr,int parent ,int totalelements)//i can be called parent or root
{
	int child,temp,j=totalelements;
  // parent=parent;//parent is root not needed
	do
	{
	 child=parent*2+1;//leftnode of parent element
	 
	/*(child < j-1) this check there is 1 child or 2child if there is 1 child then condition will fail 
	   and if 2 child then condition true  and if there is no child then also it fail*/
	 if((child < j-1) && arr[child] < arr[child+1])
	    child++;  
	  	//comparing max sibling with parent
	 if((child < j) && arr[parent] < arr[child]) //(child < j) this indicate that there is one child
	 {
	  temp=arr[parent];
	  arr[parent]= arr[child];//swaping max sibling with parent
	  arr[child]=temp; 
	 }
	parent=child;//making sibling new root
	}while(child < j);	
}

