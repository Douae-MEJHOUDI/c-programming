#include <stdio.h>

int main()
{
	int a=0 ,b=0 ;
	int z=0;
	scanf("%d%d",&a,&b);
	printf("a=%d et b=%d \n",a,b);
	z=a;
	a=b;
	b=z;
	printf(" après permutation : \n a=%d et b=%d \n",a,b);
	return 0;
}	
