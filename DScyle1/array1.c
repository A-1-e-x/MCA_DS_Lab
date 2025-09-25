#include<stdio.h>
void main()
{
	int a[10],i,n;
	printf("Enter the limit");
	scanf("%d",&n);
	printf("Enter the numbers=");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Elements are=");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
