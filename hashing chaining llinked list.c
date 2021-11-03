/*If we keep entering serial data then key also generate serial index from 0 to max 
**here we dont need to worry about size of array

A chained hash table is faster than a simple hash table **************************************

While the cost of inserting a key in a chained hash table is O(1), the cost of deleting and searching
a value is given as O(m) where m is the number of elements in the list of that location. Searching
and deleting takes more time because these operations scan the entries of the selected location
for the desired key.
In the worst case, searching a value may take a running time of O(n), where n is the number of
key values stored in the chained hash table. This case arises when all the key values are inserted into
the linked list of the same location (of the hash table). In this case, the hash table is ineffective.

The main advantage of using a chained hash table is that it remains effective even when the number
of key values to be stored is much higher than the number of locations in the hash table. However,
with the increase in the number of keys to be stored, the performance of a chained hash table does
degrade gradually (linearly). For example, a chained hash table with 1000 memory locations and
10,000 stored keys will give 5 to 10 times less performance as compared to a chained hash table
with 10,000 locations. But a chained hash table is still 1000 times faster than a simple hash table.

The other advantage of using chaining for collision resolution is that its performance, unlike
quadratic probing, does not degrade when the table is more than half full. This technique is absolutely
free from clustering problems and thus provides an efficient mechanism to handle collisions.

However, chained hash tables inherit the disadvantages of linked lists. First, to store a key
value, the space overhead of the next pointer in each entry can be significant. Second, traversing
a linked list has poor cache performance, making the processor cache ineffective

***PROS AND CONS OF HASHING
One advantage of hashing is that no extra space is required to store the index as in the case of
other data structures. In addition, a hash table provides fast data access and an added advantage
of rapid updates.
On the other hand, the primary drawback of using the hashing technique for inserting and
retrieving data values is that it usually lacks locality and sequential retrieval by key. This makes
insertion and retrieval of data values even more random

APPLICATIONS OF HASHING
Hash tables are widely used in situations where enormous amounts of data have to be accessed
to quickly search and retrieve information
1.Hashing is used for database indexing. 
2.Hashing technique is used to implement compiler symbol tables in C++. The compiler uses a
symbol table to keep a record of all the user-defined symbols in a C++ program. Hashing facilitates
the compiler to quickly look up variable names and other attributes associated with symbols.

3.Hashing is also widely used for Internet search engines.
4.to quickly access Drivers Licenses/Insurance Cards
*/
#include<stdio.h>//work even for duplicates elements
#include<stdlib.h>
#include<math.h>
#define MAX 7//size must be greater then or equal to 7 below 7 it will not fing greatest prime number
int greatestprimenumber;
/*only it fails to produce 3 and 2 as prime number because if(sum%3==0) will execute.and for 2 if 
condition become true and print not prime number*/ 
/*
insertion best case O(1) searching and deletion O(m) m is no. of elements present in that index

 Searching and deleting takes more time because these operations scan the entries of the selected location
for the desired key.(worst case, searching a value may take a running time of O(n), where n is the number of
key values stored in the chained hash table. This case arises when all the key values are inserted into
the linked list of the same location (of the hash table))*/

struct list 
{
	int data;
	struct list *next;
}; 
 /*since it is array of pointers then size is pointer*size=4*size.we can create array of pointer dynamically
 like we can give only pointer size like (struct list *)malloc(sizeof(struct list *) * max);.also we have to 
 initialize with 0 so calloc can be usedit saves space */

struct list *arr[MAX]={NULL};//since global then automatically initialize to null array of pointers
int greatprimenumber(void);
void insert(void);
void display(void);
void search(void);
void deleteelement(void);
int main()
{
	int option,i;
greatestprimenumber=greatprimenumber();//this function work efficiently if hash table size is between 7 to n
	                                  //it take less time complexty
	printf("\nGreatest prime number of MAX %d is %d",MAX,greatestprimenumber);
	do
	{
	printf("\n\n1.To insert\n2.Display\n3.Search\n4.Delete");
	printf("\nEnter your option :");
	scanf("%d",&option);
	switch(option)//here only integer value is passed not float
	{
	   case 1:insert();
	          break;
	   case 2:display();
	          break;
	   case 3:search();
	          break;
	   case 4: deleteelement ();
	          break	;
	}
   }while(option < 566546468);
	return 0;
}
void deleteelement(void)//if duplicates element present then it will delete only 1 recent element
{
	struct list *ptr,*temp,*prev;
    int element ,hash1,hash2,key,found=0;
	printf("\nEnter the elements to delete : ");
	scanf("%d",&element);
	hash1=element % MAX;//hash 1 formula
    hash2=greatestprimenumber-(element%greatestprimenumber);//hash 2 formula
    key=(hash1 + (0*hash2)) % MAX;//starting 0 because we have to find at one shot
    ptr=arr[key];
    
 if(ptr != NULL)//when arr[key] is null then this if statement will prevent illegal operation   
 {
      /*arr[key]->data==element not required in if statement coz at beginning only 1 element is present then
	    surely deleted element will be present*/
    if(arr[key]->next==NULL && arr[key]->data==element )//this means only 1 element is present at beginning
    { 
    	printf("\nElement %d deleted from index %d",arr[key]->data,key);
		free(arr[key]);//deleting starting element	
     	arr[key]=NULL;//no element so initializing to null
		found=1;	
	}
	else if(arr[key]->next != NULL && arr[key]->data==element)//it work when first element is to delete and
	{                                                        //elements is more then 2 eg:6 55 6 6
		printf("\nElement %d deleted from index %d",arr[key]->data,key);
	    temp=arr[key];//storing starting address 
		arr[key]=arr[key]->next;//assigning second address to beginning
		free(temp);
		found=1;	
	}
	 else
	 {
       while(ptr!=NULL) 
	   {
	   	if(ptr->data==element)
	   	{
	   	 printf("\nElement %d deleted from index %d",ptr->data,key);
	   	 //prev->next=ptr->next; or
	   	 temp=ptr->next;//next address is stored in temp
	   	 prev->next=temp;
	   	 free(ptr);//ptr is address of element to delete it is important otherwise memeory leak occurr
	   	 found=1;
	   	 break;//terminate while loop
		}
		  prev=ptr;
	   	  ptr=ptr->next;//traversing
	   }
     }
	if(	found==0)
	printf("\nElement not found.");
  }
  else
  printf("\nElement not found.");
}
void search(void)
{
	struct list *ptr;
	int element,found=0,hash1,hash2,key;//found=0 if at first while loop become false then it 
	printf("\nEnter the elements to search : ");//means element is not present and print not found
	scanf("%d",&element);
	hash1=element % MAX;//hash 1 formula
    hash2=greatestprimenumber-(element%greatestprimenumber);//hash 2 formula
    key=(hash1 + (0*hash2)) % MAX; 
    ptr=arr[key];
     while(ptr!=NULL)
	{
	   	if(ptr->data==element)
	   	{
	   			found=1;
	   		 printf("\nElement found  %d at Index %d",ptr->data,key);
		}
	   	 ptr=ptr->next;//traversing
	}
	if(	found==0)
	printf("\nElement not found.");
}
void display(void)
{
	int i;
	struct list *ptr;
	printf("\n******All data at INDEX******");
	for(i=0;i<MAX;i++)
	{
		printf("\nElement at index %d = ",i);
		ptr=arr[i];
	   while(ptr!=NULL)//traversing
	   {
	   	 printf(" %d",ptr->data);
	   	 ptr=ptr->next;
	   }
	}
}
void insert(void)
{
	int element,hash1,hash2,key;
    printf("\nEnter element to insert: ");
    scanf("%d",&element);
     
    hash1=element % MAX;//hash 1 formula
    hash2=greatestprimenumber - (element % greatestprimenumber);//hash 2 formula
	// hash2(key) = PRIME – (key % PRIME) where PRIME is a prime smaller than the TABLE_SIZE.
    key=(hash1 + (0*hash2)) % MAX;//key will be generated at one shot only
 
     if(arr[key]==NULL)
     {
     	printf("Index %d is empty %d",key,arr[key]);
     	struct list *newnode=(struct list*)malloc(sizeof(struct list));//no need here just put to top
     	newnode->data=element;
     	newnode->next=NULL;
     	arr[key]=newnode;//newnode is inserted at start of list to avoid traversing;
	 }
	 else
	 {
	  struct list *newnode=(struct list*)malloc(sizeof(struct list));//no need hhere just put to top
	  newnode->data=element;
      newnode->next=arr[key];//linking
      arr[key]=newnode;//newnode is inserted at start of list to avoid traversing and search func. 
	 }                                                     //would find recent element fast*******
	 printf("\nElement %d inserted at index %d O(1) ",element,key);

}
int greatprimenumber(void)
{//this function work efficiently if hash table size is between 7 to n.. it take less time complexty
//*************************************************************************************************
/*How to Tell if a Large Number is Prime?***THIS FUNCTION IS ON THIS CONCEPT*********
There are some Prime Number Formulas, which can be used to find the primes. To check whether a large
number is a prime number or not, follow the steps given below:

Step 1: Check the units place of that number. If it ends with 0, 2, 4, 6 and 8, it is not a prime number.
Note: “Numbers ending with 0, 2, 4, 6 and 8 are never prime numbers.”**********

Step 2: Take the sum of the digits of that number. It the sum is divisible by 3, the number is not a
 prime number.Note: “Numbers whose sum of digits are divisible by 3 are never prime numbers.”

Step 3: After confirming the falsity of steps 1 and 2, find the square root of the given number.

Step 4: If the obtained number is a perfect square, retake its square root again.

Step 5: Divide the given number by all the prime numbers equal to its square root.

Step 6: If the number is divisible by any of the prime numbers equal to its square root,
 it is not a prime number; otherwise, it is prime
 
Assuming that hash table size is greater or equal to 7.If hash table size is 7 then
greater prime number will be 5
*/
int i,last_digit,n,sum,b,k,flag;//video PRIME or COMPOSITE ? Check in 10 Seconds 
float a;
for(i=MAX-1; i>=4; i--)//greater prime number must be smaller then hash table size so MAX-1
{
 while(1)
 {
  last_digit=i%10;
  sum=0;
  //video->time 1:40 Prime Numbers - Sieve of Eratosthenes Region 10 ESC
  if((last_digit==0) || ( last_digit==2 || ( last_digit==4 || (last_digit==6 || last_digit==8 ))))
  {//watch video why 0 2 4 6 8 is taken
	printf("\n%d is not prime number because it last digit may be 0 ,2 ,4 ,6 ,8",i);
	break;//terminate while loop
  }
  else
  {
	n=i;
	while(n!=0)//if sum of its digit is divisible by 3 then it is not prime number
	{
	  last_digit=n%10;
	  sum=sum+last_digit;//adding digit one by one
	  n=n/10;
	}
	if(sum%3==0)
	{
	 printf("\n%d is not prime number because sum of its digit is %d and divisible by 3",i,sum);
	 break;//terminate while loop
	}	
  }/*from here no. i is checked it is perfectsquarenumber or not.First square root is taken out
   of number i if it obtained perfectsquarenumber then again square root is taken out and then
   Dividing the given number by all the prime numbers to its square root.
   If after first finding square root the number obtained is not perfect square number then
   in else statement just Dividing the given number by all the prime numbers equal to its first
    square root. */
    
   a=sqrt(i);//a should be float datatype then only it detect perfect square number
   b=a;//instead of taking variable b we can reuse variabe last_digit inplace of b because we need
   flag=0;                                   //interger variable so last_digit is integer variable
   if(a==b)                                 
   {
   	printf("\n%d is perfect square number because after point 0000 is formed %f\n",i,a);
   	
   	/*if a number except 2 and 3 is perfect square number and its last digit is 1, 3, 5, 9,or 7 then it
	 is not prime number.example 121 is perfect square no. but see its last digit 1 so it is not prime
	 number because 121 is divisible by 11.Another example 4 is perfect square number but see last digit
	 is 4 and it does not match with either of this number 1, 3, 5, 9,or 7 so if statement will become
     false  and for loop will detect that it is not primne number because it will be divisible by
	2 so it will print not prime number.number 3 and 2 cannot be detect as prime number because
	upper while  condition become true for 3 and print not prime number and for 2upper if statement become
	true and print not prime number that the reason */
   	if((i%10==1) || (i%10==3 || (i%10==5 || (i%10==9 || i%10==7))))//it saves lot of time
   	{               //7 is checked last because 7 comes when i value cross crore no like 10000000
   	 printf("\n%d is perfect square number but its last digit may be 1, 3, 5, 9,7 So It is not prime no.",i);
	 break;//terminate while loop
	}
   	
   	b=sqrt(b);//again taking square root
   	  
	/*k<=b equal to (=) is very much important example 16 square root is 4 it is perfect square so again
	  squarequare root taken then 2.so if we dont give = in for loop then condition would be false and
	  print 16 is prime no.*/
	 
   	for(k=2;k<=b;k++)//since b is integer datatype so floor square root value is stored in b
   	{
	   /*here k is 2 because if k is 1 then this condition if(i%k==0) will always become true and
     	produce wrong output.we can reuse variable last_digit in place of k*/
	 
   	  if(i%k==0)//if it divide with any no. till square root then it is prime number
	  {
	   printf("\n%d is not prime number because it is divided by %d",i,k);
	   flag=1;
	   break;//terminate for loops
	  }	
	}
   }
   else//if number is not perfect square number
   {
   	printf("\n%d is not perfect square number because after point 0000 is not formed %f",i,a);
   	for(k=2 ;k<=(int)a;k++)//since a is float variable so type casting into int.It has square root value
   	{//Video->Check if a number is prime (Algorithm/code/program) Vivekanand Khyade - Algorithm Every Day
   	  if(i%k==0)//if it divide with any no. till square root then it is not prime number
	  {
	   printf("\n%d is not prime number because it is divided by %d",i,k);
	   flag=1;
	   break;//terminate for loop
	  }		
	}
   }
   if(flag==1)
   {
   	break;//terminate while loop
   }
   else if(flag==0)
    {
   	printf("\n%d is prime number",i);
   	return i;
    }
 }//while loop
}//for loop
}
/*
int greatprimenumber(void)
{//code concept video PRIME or COMPOSITE ? Check in 10 Seconds 
	int i,j,k,flag,flag2 ,lastdigit,squareroot,sum,n,digit;
	for(i=MAX-1;i>=2;i--) 
	{
		sum=0;
		flag=0;
		flag2=0;
		lastdigit=i%10;
	   	if((lastdigit==0 || lastdigit==2 ||lastdigit==4 ) || (lastdigit==6||lastdigit==8))
	   	{
	   	   printf("\nenter in if value i= %d ",i);
		   flag=1;	
		}
		else  
	   {
	   	  n=i;
		  while(n!=0)
		  {
			digit=n%10;
			sum=sum+digit;//adding digit one by one
			n=n/10;
	      }
		 if(sum%3==0)
		  {
		  		//if(sum==3) 
		  	   // {
		  		// printf(" %d ",sum);
			    // }//it may produce error when value is 12 then 1+2=3 then it will also execute
		  	printf("\nEnter in else %d divisible by 3",i);
			flag=1;
		  }
	   }
	   
		if(flag==0)
		{
		 
	     	for(j=1;j<i;j++)//1
	    	{
			  squareroot=j*j;
			  if(squareroot > i)//it should be greater then number i not equal to i
			  {
			  	printf("\nj= %d squareroot= %d greater than %d",j,squareroot,i);
			   //start dividing i with all the prime number below value of j as rule so not using k<=j
			    	for(k=2;k<j;k++)//2 
				   {  //here k is 2 because if k is 1 then this condition if(i%k==0) will always become
				      // true and produce wrong output
				   	    printf("\nk= %d %% %d",k,i);
				    	if(i%k==0)//divide by k value if it divide then it is not prime number
					     {
					       flag2=2;
					       printf("\nBreak loop 2 ");
					       break;//terminate forloop 2	
					     }
			       }
			        if(flag2!=2)//it should be here  because  if(squareroot > i) fails it will execute
			    	{           //but we dont want to execute this so it is inside  if(squareroot > i)
					return i;
				    }
					if(flag2==2)
				  {
				  	printf("\nBreak loop 1 ");
					break;//terminate forloop 1
				  } 
				    
			  }
			   
				  // if(flag2!=2)//error
			    	//{
				//	return i;
				   // }   
	        }	  
	   }	
  }
  return 2;	   	
} */  
/*How to Tell if a Large Number is Prime?
There are some Prime Number Formulas, which can be used to find the primes. To check whether a large
 number is a prime number or not, follow the steps given below:

Step 1: Check the units place of that number. If it ends with 0, 2, 4, 6 and 8, it is not a prime number.
Note: “Numbers ending with 0, 2, 4, 6 and 8 are never prime numbers.”

Step 2: Take the sum of the digits of that number. It the sum is divisible by 3, the number is not a
 prime number.Note: “Numbers whose sum of digits are divisible by 3 are never prime numbers.”

Step 3: After confirming the falsity of steps 1 and 2, find the square root of the given number.

Step 4: If the obtained number is a perfect square, retake its square root again.

Step 5: Divide the given number by all the prime numbers below its square root.

Step 6: If the number is divisible by any of the prime numbers less than its square root, it is not a prime
 number; otherwise, it is prime.*/
