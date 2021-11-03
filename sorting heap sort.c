 /*not at all in youtube code very time consuming to bulid logic
in youtube code explaination is wrong(jenneys)this is right code
to find total number of nodes in complete binaty tree formula is 2^0+2^1+....2^n= 2^n-1

 time COMPLEXITY of heap method is O(n log n) to bulid heap 
 here to build max heal time is (nlog n) whereas in heapify time is O(n)
 *Which sorting algorithm is also known as
tournament sort?ans=heap sort*/
#include<stdio.h>  
#define MAX 50 //try example 1 2 3 4 5 6 7 8 9 11 whole code will work or 8 7 9 10 3 4 1 12 6 5
void createmaxheap(int *,int element,int i);    
void deletetogetsorted(int *,int totalelements);
void modified_deletetogetsorted(int *,int totalelements);
int main()  //this code will sort in increasing order because this is max heap  
{                                         
	int arr[MAX],i,totalelements,element;
	printf("\nEnter total number of elements : ");
	scanf("%d",&totalelements);
	printf("\nEnter element: ");
	for(i=0;i<totalelements;i++)
	{
		scanf("%d",&element);
		createmaxheap(arr,element,i);  //insertion is done from down to up
	}
	printf("\nMax heap elements in array: ");
	for(i=0;i<totalelements;i++)//for information
	{
		printf(" %d",arr[i]); 
	}
	//deletetogetsorted(arr,totalelements);
	modified_deletetogetsorted(arr,totalelements);//sort code and understable***
	printf("\nElements after sorted: ");
	for(i=0;i<totalelements;i++)
	{
		printf(" %d",arr[i]); 
	}
return 0;	
}
void createmaxheap(int *arr,int element,int i)//O(n log n)
{/*at run time elements is inserted to last of array then taking to top by comparing to its parents
  in this way max heap is created*/
	int parent,swap;
	arr[i]=element;
	while(i > 0)//when i=0 then it will not execute only when i is greater than 0 then it execute
	{             //formula to get parent node
	  parent=(i-1)/2;//or floor((i-1)/2);floor value both are integer so it will return floor integer
	  if(arr[parent] < arr[i]) //no need to give <= it just do extra swapping
	  {
	  	swap=arr[i];
	  	arr[i]=arr[parent];
	  	arr[parent]=swap;     //max heap only this is different from heapify
	  	i=parent;
	  }
	  else
	  {
	   break;//break while loop
      }
	}
}
void deletetogetsorted(int *arr,int totalelement)
{/*first swapping first element and last element in array then first element is compared 
  to its left and right child if any child is greater then swapping the elements 
  so that smaller elements will be at last of array or tree*/
  
	int i=0,j=0,swap,leftchild, rightchild,childlargeindex,totalelements ;
	for(j=totalelement; j>1; j--)//j>1 it will run till j=2 means every thing will be sorted
	{//totalelements-1 so that it will start from exactly last element
       swap=arr[0];
	   arr[0]=arr[j-1];
	   arr[j-1]=swap; //deleting to get sorted elements
	   i=0;
	   totalelements=j-1;//first element is swap to last so size will be reduced so -1
	 while(i < totalelements)/*here <= not needed because if we use than always first element
	       will become 0 so in for loop if condition is given to check i==1 there it breaks so
	       output will be right*/
	   {
	   leftchild=i*2+1;
	   rightchild=i*2+2;
	   if((leftchild >= totalelements) && (rightchild >= totalelements))//condition to break loop
	   { //this will execute when there are last two child 
	     break;
	   }
/*if stataement will run when only one chld is present ie left child and it will not work when there
 is two child when leftchild=5 and total elements is 6 then condition becomes true ie 5+1=6 thismeans
thereis noly one leftchild present and when leftchild=5 and total elements is 7 then condition become
false ie. 5+1 not equal to 7 this means there are two child present so condition fails */

	   if( leftchild+1==totalelements)//when there is only one child then this will work
	   {
	   	   if(arr[i] <= arr[leftchild])//since it is max heap then greater element should be up and 
	   	   {//smaller element should be down but if greater element is up and smaller element is 
	   	    //down then no need to execute so else statement will break or terminate
	   	   	 swap=arr[i];
	         arr[i]=arr[leftchild];
	         arr[leftchild]=swap;
	         i=leftchild;
	                   
	         break;//if condition is true break because it is last node break while loop
		   }
		  else //break while loop
		  break;//if condition is false then probably it should terminate because it is at last node
	   }
	   else//when two child is present then this will execute
	   {
	      childlargeindex=(arr[leftchild] >=  arr[rightchild])? leftchild : rightchild;
	        if(arr[i] <= arr[childlargeindex])//need <= example 5 4 2 1 6 5 0
	        {  //when element is at right place then no need to swap so else  will execute 
	         swap=arr[i];
	         arr[i]=arr[childlargeindex];
	         arr[childlargeindex]=swap;
	         i=childlargeindex;
	       }
	       else            //break while loop
		   break;//if condition is false then loop should terminate that means element is at right place
       }   
	}
  }
}
void modified_deletetogetsorted(int *arr,int totalelements)
{
   int j,temp,parent,child;
   for(j=totalelements-1 ;j > 0 ; j--)//no need j>=0 it just do extra execution which is not needed
   {
   	 temp=arr[0];
   	 arr[0]=arr[j];//swapping root element to last element
	 arr[j]=temp;
	 parent=0;//parent is root we are initializing parent to 0 always because it will always need to 
	do        //heapify from 0 as root in this case
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
}

