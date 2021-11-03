/*IT is similar to binary search JUst to find MID value is different here

elements should be shorted in AP OR GP OR HP progression series then only we can excess O(1)********
->if array is not uniform that is not in AP then no.of comparision will increase to search the elements
 that is it will check index starting from 0 1 2 to n which is WORST case o(n)
->if uniform of array is less then no.of comparision will be more to search
->if uniform of array is more then no.of comparision will be less to search 
->this technique fails to find duplicates element completely example 1 2 3 4 4 and 1 2 2 2 2 3
->perfect to use when elements are in GP.
-> duplicates elements are not able to find impossible like 1 2 2 2 2 3.no idea code must be modified**
   

-> When array is completely uniform and sorted and  when we try to find element that is not present in
   array then this algo find in O(1) time complexity but that search element should be greater then all
   element in array like 2,4,8 then search element should be 9or10,11..if search element is smaller
   then it will not work in O(1) ********************
  
 Condition for interpolation search
 1.Array should be sorted and should be uniformly distributed means gab between elements should be same
 2.Array should be completely uniform then only it perform better than binary search.it completey depend
 on uniformly distributed element
 
Interpolation search, also called as extrapolation search. Interpolation searching algorithm is only
used when the elements in an array is sorted and evenly distributed. Interpolation search algorithm
is the combination of both binary search algorithm and linear search algorithm.********

Advantages - Interpolation Search
When all elements in the list are sorted and evenly distributed, then executing time of Interpolation
search algorithm is log(log n) i.e) Best case

Given a sorted array of n uniformly distributed values arr[], write a function to search for a
 particular element x in the array.?
Linear Search finds the element in O(n)time,Jump Search takes O(rootn)time and Binary Searchtake O(Log n)
time.The Interpolation Search is an improvement over Binary Search for instances, where the values in a
sorted array are uniformly distributed. Binary Search always goes to the middle element to check. On
the other hand, interpolation search may go to different locations according to the value of the key 
being searched. For example, if the value of the key is closer to the last element, interpolation 
search is likely to start search toward the end side.
DISADVANTAGE
1.It completely fails and run infinite when we search or enter value which is less then all element in
  array and  not present in array .read below statement detail
2.when we search or enter element which is not present in array an t is greater then all element in array 
 then mid value becomes greater then array size but terminate sucessfully as element not found
 
3.it takes more time to search element when array is not in AP or uniform*/

#include<stdio.h>
int main() //TIMEcomplexity average case O(log(log n)  WORST case o(n)
{          //best case O(1) when array is completely uniform like 2,4,6,8 gab is 1 in each element
	int arr[200],beg,last,mid,i,n,element,found=0;//,j=1,holdmid=-1,denominator,numerator;
	//float temp,temp2;
	printf("\nEnter Total no. of elements: ");
	scanf("%d",&n);
	printf("\nEnter %d elements: ",n);
	for(i=0;i<n;i++)
	scanf("%d",arr+i);
	printf("Enter elements to search: ");
	scanf("%d",&element);
	beg=0;
	last=n-1;
	while(beg<=last)
	{
	      
    //mid=(beg+last)/2;//take floor value for binary search
   /* if(arr[last]-arr[beg])
    {
    	denominator=arr[last]-arr[beg];
	}
	else
	{
		j=0;          //if  denominator is 0 then it will produce wrong ouput so checking
		denominator=1;
	}
    numerator=element-arr[beg];
  
    temp=(float)numerator/denominator; //taking floating value
   
     if(j==0)
    {
      	temp=j;
	}
	printf("N= %d ",numerator);
    printf("D= %d",denominator);
    printf("\ndivisionofND=%f",temp);//extra informaion ==0.571429
    temp2=(last-beg)*temp; 
    printf("\ntemp2=%f",temp2);//extra informaion ==4.000000
	mid=beg+temp2;  //==4 mid will take floor value*/

	 
   mid=beg+(last-beg)*(float)(element-arr[beg])/(arr[last]-arr[beg]);//second way to do directly
	//we want (element-arr[beg])/(arr[last]-arr[beg]) as float so converted to (float)
	//we have to carefull if denominator becomes 0 as element-arr[beg])/arr[last]-arr[beg])******
	//so searching for duplicates should be avoided.i think denominator will never become 0 because
	//in array element will be sorted so arr[last] will always greater then arr[beg] 
	printf("\nmid %d",mid);
	
	if((mid<=n-1)&&arr[mid]==element)/*sometimes mid value becomes greater then array size so if this
	condition arr[mid]==element execute then itwould be illegal so checking (mid<=n-1) in if condition.
	mid value becomes greater when we try to search or enter value which is greater then all the
	elements present in array then mid value becomes greater like array element 1,2,3 and we search value
	10 then mid value will become greater ie mid=9 which is greater then array size.
	
**mid value will also become -ve like array element 2,4,6,8,10 and we try to search element 7 then mid 
becomes md=-2 and code run infinite.
in this situation mid value should increase then only it will terminate because 7 is not present inarray
 so CONCLUSION is*****************************
 1.It completely fails and run infinite when we search or enter value which is less then all element in array
   and not present in array like above example searching element 7.
2.when we search or enter element which is greater then all element in array then mid value becomes 
 greater then array size but terminate sucessfully as element not found*/ 
	{
	//holdmid=mid;
	 printf("\nElement %d found at position %d",element,mid);
	 found=1;
	 break;
	}
	
		
/*	if (element <= arr[mid])
			{
		
			
			/*if((mid!=n-1) && element==arr[mid+1])
			{
				beg=mid+1;
			}
			else if( (mid==n-1) || element!=arr[mid+1]  )
			{
				printf("break");
				break;
			}
			else
			{*/
			/* last=mid-1;
			//}
		
		}
		 else//if(element >= arr[mid])
		{
			beg=mid+1;
		}*/
		if((mid<=n-1) && element < arr[mid])
		{
			last=mid-1;
		}
		else
		beg=mid+1;
		printf("beg=%d",beg);
	}
	if(found==0)
	{
		printf("\nElement %d not found.",element);
	}
	return 0;
}
  
