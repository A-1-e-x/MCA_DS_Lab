#include<stdio.h>
void main()
{
	int a[10],i,n,j,del;
	printf("Enter the limit=");
	scanf("%d",&n);
	printf("Enter the elements=\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the element you want to delete=\n");
	scanf("%d",&del);
	for(i=0;i<n;i++)
	{
		if(a[i]==del)
		{
			for(j=i;j<n-1;j++)
			{
				a[j]=a[j+1];
			}
			n--;
			i--;
		}
	}
	printf("Updated array=");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}x
