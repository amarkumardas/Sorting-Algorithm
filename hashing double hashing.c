/*what is HASH TABLE= It is a data structure in which keys are mapped to array positions by a hash 
 function
Double Hashing
Double hashing is a collision and primary and secndary clustering resolving technique in Open Addressed
Hash tables.

Comparison :
**Linear probing has the best cache performance but suffers from clustering. One more advantage of Linear
probing is easy to compute.

**Quadratic probing lies between the two in terms of cache performance and clustering.
Quadratic probing resolves the primary clustering problem that exists in the linear probing
technique. Quadratic probing provides good memory caching because it preserves some locality
of reference. But linear probing does this task better and gives a better cache performance.
One of the major drawbacks of quadratic probing is that a sequence of successive probes may
only explore a fraction of the table, and this fraction may be quite small. If this happens, then we
will not be able to find an empty location in the table despite the fact that the table is by no means
full.
Although quadratic probing is free from primary clustering, it is still liable to what is known as
secondary clustering. It means that if there is a collision between two keys, then the same probe
sequence will be followed for both. With quadratic probing, the probability for multiple collisions
increases as the table becomes full. This situation is usually encountered when the hash table is
more than full.
Quadratic probing is widely applied in the Berkeley Fast File System to allocate free blocks

**Double hashing has poor cache performance but no clustering. Double hashing requires more computation 
time as two hash functions need to be computed.
 
 DIFFERENCES
 Chaining
1.	Chaining is Simpler to implement.
2.	In chaining, Hash table never fills up, we can always add more elements to chain.
3.	Chaining is Less sensitive to the hash function or load factors.
4.	Chaining is mostly used when it is unknown how many and how frequently keys may be inserted or deleted.
5.	Cache performance of chaining is not good as keys are stored using linked list.
6.	Wastage of Space (Some Parts of hash table in chaining are never used).
7.	Chaining uses extra space for links.

Open Addressing
1.Open Addressing requires more computation.
2.In open addressing, table may become full.
3.Open addressing requires extra care for to avoid clustering and load factor.
4.Open addressing is used when the frequency and number of keys is known.
5.Open addressing provides better cache performance as everything is stored in the same table.
6.In Open addressing, a slot can be used even if an input doesn’t map to it.
7.No links in Open addressing

The smallest prime number defined by modern mathematicians is 2. To be prime, a number must be
divisible only by 1 and the number itself which is fulfilled by the number 2*/

#include<stdio.h>
#include<math.h>
#define MAX 10 //size must be greater then or equal to 7 below 7 it will not fing greatest prime number
int arr[MAX],greatestprimenumber;
/*only it fails to produce 3 and 2 as prime number because if(sum%3==0) will execute.and for 2 if 
condition become true and print not prime number

1 is not prime number.Prime no. is any positive integer that is divisible by exactly two positive
integers that is - itself and 1,it has only two factors that is  itself and 1.*/ 
                
int greatprimenumber(void);
void insert(void);//this code will fail when you enter duplicates elements
void display(void);//this is emplimented only for unique elements
void search(void);
void deleteelement(void);
int main()
{
	int option,i;
 
	greatestprimenumber=greatprimenumber();
	printf("\nGreatest prime number of MAX %d is %d",MAX,greatestprimenumber);//for information
	
	//since arr is global so automatically all index initialize to 0

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
   }while(option< 10546545);
   return 0;
}
void deleteelement()
{
   int element ,i,hash1,hash2,key;
	printf("\nEnter the elements to delete O(1) time : ");
	scanf("%d",&element);
	hash1=element % MAX;//hash 1 formula
    hash2=greatestprimenumber-(element%greatestprimenumber);//hash 2 formula
    key=(hash1 + (0*hash2)) % MAX;//starting 0 because we have to find at one shot
    if(arr[key]==element)
    {
     
    	printf("Deleted element= %d from index %d",arr[key],key);
    	arr[key]=0;//since element got deleted so at that place -1 is placed
	}
	else
	{
		printf("\nElement not found");
	}	
}
void search()//insertion and searching is almost same here
{
	int element,found=0,i,hash1,hash2,key;
	printf("\nEnter the elements to search O(1) time : ");
	scanf("%d",&element);
	hash1=element % MAX;//hash 1 formula
    hash2=greatestprimenumber-(element % greatestprimenumber);//hash 2 formula
    key=(hash1 + (0*hash2)) % MAX;//starting 0 because we have to find at one shot
    if(arr[key]==element)
    {
    	printf(" O(1) Found at index %d element= %d",key,arr[key]);
	}
	else
	{
	 printf("\nElement not found directly O(1) time");
	  printf("\nNow searching linearly :");
	  for(i=0;i<MAX;i++)// if the value does not match, then the search function begins a
	  {                  // sequential search of the array as in book
	  	if(arr[i]==element)
	  	{
	  		found=1;
	  		printf("\nFound at index %d element= %d",i,arr[i]);
		}
	  }
	  if(found==0)
	  {
	  	printf("\n\nElement not present in array.");
	  	printf("\nAll element in array:");
	  	display();
	  }
	}
	
}
void display()
{
	int i,half,h;
	h=half=MAX/2;
	printf("Inserted elements are half half:");
	for(i=0;i<half;i++)
	{
		printf("\n%-5d  ",*(arr+i));//orarr[i]
		printf("%5d",*(arr+ h++));
		
	}
	if(MAX%2!=0)//when max is even then it will not execute
		printf("\n%12d",*(arr+ h));
}
void insert()//if we inserted element serially then it will be inserted with serial index of array
{            //otherwise if element is not serial then function will not produce serial index
	int element,hash1,hash2,key,flag,i;
    printf("\nEnter element except 0 and avoid duplicates to insert: ");
    scanf("%d",&element);
    hash1=element % MAX;//hash 1 formula
    hash2=greatestprimenumber-(element%greatestprimenumber);//hash 2 formula 
    //greatestprimenumber should be smaller than the TABLE_SIZE
	// hash2(key) = PRIME – (key % PRIME) where PRIME is a prime smaller than the TABLE_SIZE.

	for(i=0;i<MAX;i++)
	{
		flag=0;
		key=(hash1 + (i*hash2)) % MAX;//when it wound find index to store then it will 
		if(arr[key]==0)             //increment i from  0 to MAX pdf formula
		{
			flag=1;
		  arr[key]=element; //inserting elements
		  printf("\ninserted element = %d at index %d",arr[key],key);
		  break;
		}
		else
		{
			//printf("\nElement not inserted at index %d element= %d",key,arr[key]);
			printf("\nindex(key) %d is filled with element %d so probing",key,arr[key]);
		
		}
	}
	if(flag==0)//when element is not inserted
	{
		printf("\n Not inserted  element %d program terminated",element);
	}	
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

 
