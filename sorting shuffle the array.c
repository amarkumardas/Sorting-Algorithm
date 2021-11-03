#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,temp,swap;
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	srand(time(NULL));//with this it will produce random number
	for(i=10-1;i>=1;i--)
	{
	   temp=rand()% i;//if we dont give srand(time(NULL)) then only same number will produce rand func
	   //printf(" %d",temp);
	   swap=arr[temp];
	   arr[temp]=arr[i];
	   arr[i]=swap;
	}
	printf("\n");
	for(i=0;i<10;i++)
	{
		printf(" %d",arr[i]);
	}
	return 0;
}
