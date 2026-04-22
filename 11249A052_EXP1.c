#include<stdio.h>
int F(int n)
{
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		return 1;
	} 
	else
	{
		return F(n-1)+F(n-2);
	}	
}
int main()
{
	int n;
	printf("Enter the no of charecters in febonicci series:");
	scanf("%d",&n);
	printf("The Febonicci series (%d)th term is:%d",n,F(n));
	return 0;
}

