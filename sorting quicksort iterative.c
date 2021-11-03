/*we are sorting by taking FIRST ELEMENT as pivot or last element as pivot but when elements are in
sorted order or in reversed order then this choice is bad choice because we will select minimum 
or maximum value as pivot after partitioning the list either left or right side will be completely
empty so it is bad choice .so we have to take random element or median of three 

values (first middle last) as pivot elements selection of pivot is very important because it will
decrese worst case time complexity ie. O(n^2). so taking random element as is best choice to avoid
worst time complexity O(n^2) proved mathematically.

when elements are in sorted order then quick sort worst case time complexity goes to O(n^2)
due to sorted order it forms skrew so time goes to n^2

QuickSort is an unstable algorithm because wedo swapping of elements according to pivot's position
(without considering their original positions)************************/ 

#include<stdio.h>
int quicksort(int [],int totalelements,int beg,int end);
void sort(int [],int totalelements);
int main()
{
	int arr[50],i,totalelements;
	printf("Enter total number of elements: ");
	scanf("%d",&totalelements);
	printf("Enter element: ");
	for(i=0;i<totalelements;i++)
	{
	  scanf("%d",arr+i);	
	}
	sort(arr,totalelements);
	printf("After iterative quick sort:");
	for(i=0;i<totalelements;i++)
	{
	  printf(" %d",*(arr+i));	
	}
	return 0;
}
void sort(int arr[],int totalelements)
{
  /*stack size can be kept less than 10 only limited amount of space is used
   it is better to make stack dynamically because we dont know how much space will
  occupy during run time but very less space will occupied************************/
   int stackbeg[10],stackend[10],top=-1,beg,end,indexofpivot;
   if(totalelements>1)//if user enter totalelements 1 then nothing will execute even
                      //while loop will not execute because of top value
   {
   	top++;
   stackbeg[top]=0;//first inserting beg and end index
   stackend[top]=totalelements-1;
   }
   while(top!=-1)
   {
   	beg=stackbeg[top]; //poping
   	end=stackend[top]; 
   	--top;
   	indexofpivot=quicksort(arr,totalelements,beg,end);
   	//indexofpivot-1 is end of sub array
   	if(beg < indexofpivot-1)//for leftsub array
   	 {
   	 	top++;
   		stackbeg[top]=beg;
   		stackend[top]=indexofpivot-1;
     }
     //beg must be smaller than end ultimately indexofpivot+1 is beg
     if(indexofpivot+1 < end)//for rightsub tree
     {
     	top++;
     	stackbeg[top]=indexofpivot+1;
   		stackend[top]=end;
	 }
   }	
}
int quicksort(int arr[],int totalelements,int beg,int end)
{//here leftside of pivot all smaller and equal to pivot will be there and right side all greater no.
	int pivot=arr[beg],swap,pivotindex=beg;
	
	while(beg < end)
	{
 /***when elements in array are in decreasingorder then when quicksort applied variable beg will
  run till last index ofarray after that itwill again increment by 1 which is more then arraysize
  then it would be illegal to access array so this (beg <=end) is applied to avoid ILLEGAL excess*/
		
	 while( (beg <=end) && arr[beg] <= pivot)
	     beg++;                         
	 while(arr[end] > pivot)//here no illegaloperation will beperformed coz it will cross beg and stop
		end--;
		
	  if(beg < end)
	   {
		 swap=arr[beg];
		 arr[beg]=arr[end];//swaping beg and end
		 arr[end]=swap;	
	   }	
	}
	      swap=arr[pivotindex];//swaping and placing element at right place
		  arr[pivotindex]=arr[end];
		  arr[end]=swap;
     return end;//returning right position index of element
}
