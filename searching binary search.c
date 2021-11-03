/*The worst case complexity is Equal when compared with the average case complexity of a
binary search algorithm.

Which one of the following is true?
1.For a binarysearch the best-case occurs when the target item is in the beginning of the search list.=F
2.For a binarysearch,the best-case occurs when the target is at the end of the search list.F
3.For a binarysearch,the worst-case is when the target item is not in the search list.=T
4.For a binarysearch,the worst-case is when the target is found in the middle of the search list.=F

1 is not correct. The best case is NOT when the first element is the target, it is when the middle element
is the target, as you compare the middle element to the target, not the first element, so if the middle
element is the target - the algorithm will finish in one iteration.

3. is indeed correct, as you will need to go through the algorithm and terminate at the "worst" stop 
clause, where the list is empty, needed log(n) iterations.

2. is false because best case is when the middle element is the target
***********************************************
Worst complexity: O(log n)
Average complexity: O(log n)
Best complexity: O(1)
Space complexity: O(1)

If array size is very very large then exponential search will perform better then binary search.if 
element is at index  0 or 1.. then in large size array exponential search will perform better 0(logn)
VIDEO>Exponential Search - better than Binary search? (Explained) TECH DOSE 
*/
#include<stdio.h>// It can also find number of duplicates elements
#include<conio.h> 
int main()
{
int n,num,i,arr[20],lb=0,ub,mid,found=0,beg=0,end,left,right;
printf("\nEnter in sorteed order");
printf("\nenter no of elements in the array:");
scanf("%d",&n);
end=ub=n-1;
printf("\n enter the elements:");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("\nenter the number that has to be searched:");
scanf("%d",&num);
while(lb<=ub)
{
mid=(lb+ub)/2;//we need floor value so integer/integer gives integer so this work well
if(arr[mid]==num)
{
	found=1;//it was common so only one statement is enough
	if((mid==beg) && (arr[mid+1] != num && arr[mid] == num))//when element is at beginning
	{                      //arr[mid] == num no need to check look above code already check
	 printf("\n%d found at location %d",num,mid);
	 printf("\nNO duplicate present");
     //found=1;
	// break;//terminate while loop	
	}
	else if((mid==end) && (arr[mid-1] != num && arr[mid] == num))//when element is at end
	{                       //arr[mid] == num no need to check look above code already check
	 printf("\n%d found at location %d",num,mid);
	 printf("\nNO duplicate present");
     //found=1;
	 //break;//terminate while loop	
	}                                  //when element at any index 
    else if(((mid!=beg) && (arr[mid+1] != num)) && ((mid!=end) && (arr[mid-1] !=num))) 
	{/*or else if( arr[mid+1] != num && arr[mid-1] !=num) it checks both condition beg or end noneed
	 to check (mid!=beg) and (mid!=end) because oviously mid will not equal to end or beg because 
	 upper code already checked.so we can remove 2 condition */
	 printf("\n%d found at location %d",num,mid);
	 printf("\nNO duplicate present");
     //found=1;
	 //break;//terminate while loop	
	}
/*if((((mid==beg)||(mid==end)) && ((arr[mid+1] != num) || (arr[mid-1] != num))) || ((arr[mid+1] != num) && (arr[mid-1] != num)))
   {//compressed code just remove upper code and add this code work well
	printf("\n%d found at location %d",num,mid);
	printf("\nNO duplicate present");	
   }*/
	else//when element is dublicate then it will work
	{
		left=right=mid;
	   while( (right<= end) && (arr[right]==num))//right<= end;to stop illegal operation on array
	   {
	   	printf("\n%d found at location %d",num,right);
	   	right++;
	   }
	   left--;//decrease 1 to get left node 
	   while((left >= beg) && (arr[left] == num))//left >= beg; to stop illegal operation on array
	   {
	   	printf("\n%d found at location %d",num,left);
	   	left--;
	   }
	   //break;//terminate while loop	
	}
	break;//it was common so only one statement is enough
}
else if(arr[mid] > num)//no need to give arr[mid] >= num 
{
ub=mid-1;
}
else if(arr[mid] < num)
{
lb=mid+1;
}
}//while loop

if(found==0)
{
printf("\n%d not found in array",num);
}
getch();
return 0;
}
