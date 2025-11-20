#include<stdio.h>
void main()
{
	int a[10],i,n,j,temp;
	printf("Enter the limit=");
	scanf("%d",&n);
	printf("Enter the elements=");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("Sorted array=");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
}
