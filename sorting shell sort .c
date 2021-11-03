/*IT is modified version of insertion sort.It is comparision based sorting
1.Time complexity of shell short depends on gap.its best case time complexity is O(n *logn)
and worst case is O(n*log^2n).
Time complexity of shell sort is generally assumed to be near to O(n) and less than O(n^2)
as determining its time complexity is still an open problem**********8

2.The best case of shell sort is when array is already sorted.The number of comparision is
 less.
3.It is inplace sorting algorithm
4.It is unstable sort as relative order of elements with equal values may change
5.It has beeen observed that shell sort is 5 times faster then bubble sort and twice faster
 than insertion sort its closest competitor.******************
6.There are various increment sequences or gab sequences in shell sort which produce various
 complexity betweeen O(n) and  O(n^2). */
 
#include<stdio.h>
#define MAX 20      //whole code working try example 14 18 19 37 23 40 29 30 11
void shellsort(int*,int totalelements);
int main()
{
	int arr[MAX],i,totalelements;
	printf("\nEnter total number of elements : ");
	scanf("%d",&totalelements);
	printf("\nEnter element: ");
	for(i=0;i<totalelements;i++)
	{
		scanf("%d",&arr[i]);	 
	}
	shellsort(arr,totalelements);
	printf("\nElements after sorted: ");
	for(i=0;i<totalelements;i++)
	{
		printf(" %d",arr[i]); 
	}
  return 0;	
}

void shellsort(int*arr,int totalelements)
{
	int gab,i,j,swap;               //when gab become 1 then it start working like insertion sort
	for(gab=totalelements/2; gab>=1; gab=gab/2)//gab>=0 useless
	{
		for(j=gab;j<totalelements;j++)
		{
			for(i=j-gab; i>=0; i=i-gab)//itwill check till i=0
			{
				if(arr[i+gab] > arr[i])
				{
					break;
				}
				else
				{
					swap=arr[i+gab];
					arr[i+gab]=arr[i];
					arr[i]=swap;
				}
			}
		}
	}
}
