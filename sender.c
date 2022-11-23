#include<stdio.h>
#include<unistd.h>
#include<string.h>
//#include<sys/wait.h>
#include<sys/types.h>
void bubblesort(int arr[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	for(j=0;j<n-1-i;j++)
	if(arr[j]>arr[j+1])
	{
		temp=arr[j];
		arr[j]=arr[j+1];
		arr[j+1]=temp;
		
	}
	for(i=0;i<n;i++)
	{
		printf("%d",arr[i]);
	}
}
void selectionsort(int arr[],int n)
{
	int i,j,temp,idx=0;
	for(i=0;i<n-1;i++)
	{
		idx=i;
		for(j=i+1;j<n;j++)
			if(arr[j]<arr[idx])
			idx=j;
			if(arr[idx]!=arr[i])
			{
				temp=arr[idx];
				arr[idx]=arr[i];
				arr[i]=temp;
			}
	
	}
}
int main()
{
	pid_t pid;
	int n,i;
	printf("enter the no. of process:");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	pid=fork();
	if(pid==0)
	{
		wait(NULL);
		bubblesort(arr,n);
	}
	else
	{
		selectionsort(arr,n);
	}
}
