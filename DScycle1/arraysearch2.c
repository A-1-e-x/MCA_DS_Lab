#include<stdio.h>
void main()
{
	int a[10],i,n,s,flag=0;
	printf("Enter the limit=");
	scanf("%d",&n);
	printf("Enter the elements=");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the element to search=");
	scanf("%d",&s);
	for(i=0;i<n;i++)
	{
		if(a[i]==s)
		{
			printf("%d is found at %d\n",a[i],i+1);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("%d is not found",s);
	}
}
