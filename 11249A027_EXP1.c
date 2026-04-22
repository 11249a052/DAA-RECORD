/*#include<stdio.h>
int main()
{
	int a=0;int b=1;
	int c;
	int n;/
	int i;
	printf("Enter the no of terms want in the febonacci series:");
	scanf("%d",&n);
	if(n==0||n==1)
	{
		printf("fib(%d):%d",n,n);
		
	}
	for(i=0;i<=n;++i)
	{
		c=a+b;
		a=b;
		b=c;
	}
	printf("fib(%d):%d",n,c);
	return 0;
	
	
}*/
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

