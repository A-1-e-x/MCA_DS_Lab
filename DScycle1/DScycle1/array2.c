#include<stdio.h>
void main()
{
	int a[10],i,n;
	printf("Enter the limit=");
	scanf("%d",&n);
	printf("Enter the elements=");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Even numbers are=");
	for(i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			printf("%d\n",a[i]);
		}
	}
}
