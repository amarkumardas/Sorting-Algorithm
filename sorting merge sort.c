/* Iterative C program for merge sort bottom up.*****Time complexity O(nlogn)
Video->https://www.youtube.com/watch?v=Eid6JEHZ7nw&t=436s
Video->2.7.3 MergeSort in-depth Analysis abdul bari

Merge is a process that combine two sorted list into single sorted list
ADVANTAGES
1.Itis suitable for very large size like millions of record.No other sort algo support verylarge sizes
2.It is also suitable for sorting two linked list without using third list
3.it also support External sorting by bringing part of file in main memeory RAM and sort part by part
4.it is stable means order is maintained while sorting

Disadvantages
1.It uses extra place so it is not INPLACE sort.it is not suitable for arrays because it will require
extra space but in case of sorting two sorted linked list it does not require extra space.
2.When data is small like n<=15 then it takes more time then insertion sort time complexity O(n^2)
  so when size of data is small merge sort will take help of Insertion sort but why insertion sort
  because insertion sort is also stable and aslo suitable for linked list thats the reason,and also
  bubble sort is stable.
  Algorithm is stable by nature like Insertion Sort, Merge Sort and Bubble Sort 
3.ifwe perform mergesort using recursive then stacksize will be o(logn) + extra space O(n)=O(n log n)
*/
#include<stdlib.h> 
#include<stdio.h>
#define MAX 50
void mergesort(int arr[],int noofelements);
void mergepass(int [],int temp[],int size,int noofelements);
void merge(int [],int[],int low1,int up1,int low2,int up2);
void copy (int[],int[],int noofelements);
#define MAX 50
int main() 
{ 
	 int arr[MAX],i,noofelements;
	 printf("\nEnter total number of elements: ");
	 scanf("%d",&noofelements);
	 printf("\nEnter elements: ");
	 for(i=0;i<noofelements;i++)
	 {
	 	scanf("%d",&arr[i]);
	 }
	 mergesort(arr,noofelements);
	 printf("\nSorted list is: ");
	 for(i=0;i<noofelements;i++)
	 {
	 	printf("%d ",arr[i]);
	 }
	return 0; 
} 
void mergesort(int arr[],int noofelements)
{
//first we have to sort 1 element so size is pass 1 initailly then 2 then 4..
	int temp[MAX],size=1;
	while(size < noofelements)
	{
	  mergepass(arr, temp, size, noofelements);
	  size=size*2;	
	}
}
void mergepass(int arr[],int temp[],int size,int noofelements)
{
	int low1,up1,low2,up2,k,i;
	low1=0;
	while(low1+size < noofelements)
	{
		up1=low1+size-1;
		low2=low1+size;
		up2=low2+size-1;
		if(up2>=noofelements)//when up2 becomes greater then no. of elements then this will work
		{                    //and make up2 initialize with last index of array that is last element
			up2=noofelements-1;
		}
		 merge( arr,temp, low1, up1,low2,up2);
		 low1=up2+1;//updating low1	
	}
/*when noofelements is odd then during merge one element do not get store in temp array
due to odd when noofelements is even then during merge all element get store in temp arrray
and copy all elements in original array so if statement will only execute when one element is left
so this func will copy only 1 left element int temp[] and copy func will copy all elements in
original array*/
 
	if(low1 < noofelements)//it works when no. of elements is odd otherwise not.
	{                      //it will add last element to temp array 
	  temp[low1]=arr[low1];	
	}
	 copy (arr,temp,noofelements);//we are copying in original array so original array get updated  
}                                  //and start shorting
void merge(int arr[],int temp[],int low1,int up1,int low2,int up2)
{
	int k=low1,i=low1,j=low2;//we dont need k just in place of k replace low1 then remove k
	while(i<=up1 && j<=up2)
	{
		if(arr[i] < arr[j])
		{
			temp[k++]=arr[i++];
		}
		else //if(arr[j]<arr[i])
		{	
			temp[k++]=arr[j++];
		}
	}
	while(i <= up1)//equal is important**
	{
	  temp[k++]=arr[i++];	
	}
	while(j <= up2)
	{
	  temp[k++]=arr[j++];	
	}	
}
void copy (int arr[],int temp[],int noofelements)
{
//when noofelements is odd then during merge one element do not get store in temp array
//due to odd when no. of elements is even then during merge all element get store in temp array
//so when one elemnet is left we dont want to copy that left element in original array we
// want to copy only sorted element so in else statement variable k hold position to copy
// only sorted elements
	int i;
	for(i=0;i<noofelements;i++)
	{
		arr[i]=temp[i];
	} 
}
 
