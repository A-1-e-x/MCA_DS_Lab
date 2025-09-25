#include<stdio.h>
void main()
{
	int a[10],i,n,sum=0;
	printf("Enter the limit=");
	scanf("%d",&n);
	printf("Enter the elements=");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		sum=a[i]+sum;
	}
	printf("Sum of array=%d",sum);
}
