/*Which is better in a quick sort if I select the pivot as the first element, A) ascending or 
B) descending data?
ans-it doesnt matter when array is sorted in increasing or decreasing order time complexity
will be O(n^2) when array is sorted

What is the fastest sorting algorithm?
Quicksort
The time complexity of Quicksort is O(n log n) in the best case, O(n log n) in the average case
and O(n^2) in the worst case. But because it has the best performance in the average case for
most inputs, Quicksort is generally considered the “fastest” sorting algorithm

HOW code is working?
here when array is in sorted order then we take middle element and index. after that we make
sorted array to unsorted array using sranf function after that placing middle element at pos
arr[0] so that it become pivot element.we arw taking pivot first element of array so middle 
element is placed at index 0 and arr[0] element is place at middle element index*/
#include<stdio.h>
int quicksort(int [],int totalelements,int beg,int end);
void sort(int [],int totalelements);
int main()
{                              //smallest_element keep it greater then only we will get smallest no.
	int arr[50],i,totalelements,swap,temp,hold_pivot_middle_value,pivot_index,smallest_element=99999;
	printf("Enter total number of elements: ");
	scanf("%d",&totalelements);
	printf("Enter element: ");
	for(i=0;i<totalelements;i++)
	{
	  scanf("%d",arr+i);
	  if(arr[i] < smallest_element)	
	    smallest_element=arr[i];//taking smallest element while scanning
	}
	printf("\nSmallest element %d\n",smallest_element);
	printf("Entered elements are :");
		for(i=0;i<totalelements;i++)
	{
	  printf(" %d",*(arr+i));	
	}
	printf("\n");
	//***************************************only this code added to quick sort
	/*since when elements are in sorted order then time becomes o(n^2) so we can  randomize
	the array so that order array become unordered and time reduce to o(nlogn)*/
	
	hold_pivot_middle_value=arr[totalelements/2];/*taking value of middleindex because when array are
	in sorted order then this value have to make pivot because when algo.run due to this middle value
    array will get divided into two half which will reduce time to O(nlogn) */
    
	printf("\npivot %d\n",hold_pivot_middle_value);
	
	srand(time(NULL));//with this it will produce random number
	for(i=totalelements-1;i>=1;i--)//i>=1 because if we give i>=0 then % operator will give wrong ans
	{
	/*if we dont give srand(time(NULL)) then only same number will produce rand func.0 will be sure
	   getting due to for loop stop at 1 like rand()% 1=0 remainder will always be 0.
	  
	  NODE: whatever rand()% i; i  value remainder will be always smaller then i value so index
	        we will get smaller the array size */   
	 
	   temp=rand()% i;//here i should not be 0 if 0 then temp will store garbage value which will
	   printf(" %d",temp);                      //perform illegal operation because temp is index
	   swap=arr[temp];//we are swaping all elements randomly
	   arr[temp]=arr[i];
	   arr[i]=swap;
	   
	   if(arr[temp]==hold_pivot_middle_value)//this will keep track of middle value index so that we
	   {                                     //can swap correctly
	   	pivot_index=temp;
	   }
	   else if(arr[i]==hold_pivot_middle_value)
	   {
	   	pivot_index=i;
	   }
	}
	printf("\nmiddle value is at index %d",pivot_index);
		printf("\nRandomized array after swaping :");
		for(i=0;i<totalelements;i++)
	{
	  printf(" %d",*(arr+i));	
	}
	if(hold_pivot_middle_value == smallest_element)
	{
		printf("\nmiddle value is smallest so need to swap");
	}
	if(hold_pivot_middle_value != arr[0] && hold_pivot_middle_value != smallest_element)
	{/*if middle value is already present at index 0 then noneed to do anything because while sorting
	 pivot element will come at middle index and dividearray into 2 parts and reduce time to o(nlogn)
	 but if middle value not present at index 0 then swap and bring middle value at index 0 so time
	will reduce from n^2 to o(nlogn)and also we have check hold_pivot_middle_value != smallest_element
	because if hold_pivot_middle_value is smallest element in array then array will not get divided 
 into 2 parts and itwill take time O(n^2) so thattime no needto swap pivot as it is smallest element */
	    
		   printf(" \npivot is not at index 0 and also not smallest no. so swap");
	  temp=arr[0];
	  arr[0]=hold_pivot_middle_value;
	  arr[pivot_index]=temp;
    }
	//***************************************************
	printf("\nRandomized array :");
		for(i=0;i<totalelements;i++)
	{
	  printf(" %d",*(arr+i));	
	}
		printf("\n");
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
