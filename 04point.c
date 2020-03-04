#include <stdio.h>

void swap1(int a,int b)
{
	int temp;
	temp = a;
	a    = b;
	b    = temp;
}

void swap2(int *a,int *b)
{
	int temp;
	temp = *a;
	*a   = *b;
	*b   = temp;
}

void swap3(int *a,int *b)
{
	int *temp;

	temp = a;
	a    = b;
	b    = temp;
}

void swap4(int *a,int *b)
{
	int *temp;
	*temp  = *a;
	*a     = *b;
	*b     = *temp;
}

void swap5(int *a,int *b)
{
	int *temp = NULL;
	*temp  = *a;
	*a     = *b;
	*b     = *temp;
}

void swap6(int *a,int *b)
{
	int data;
	int *temp = &data;
	*temp  = *a;
	*a     = *b;
	*b     = *temp;
}


int main(int argc, const char *argv[])
{
	int a=5,b=10;

	printf("a = %d,b = %d\n",a,b);
	swap1(a,b);
	printf("a = %d,b = %d\n",a,b);
	a=5;
	b=10;
	swap2(&a,&b);
	printf("a = %d,b = %d\n",a,b);
	a=5;
	b=10;
	swap3(&a,&b);
	printf("a = %d,b = %d\n",a,b);
	a=5;
	b=10;
	swap4(&a,&b);
	printf("a = %d,b = %d\n",a,b);
#if 0
	a=5;
	b=10;
	swap5(&a,&b);
	printf("a = %d,b = %d\n",a,b);
#endif	
	a=5;
	b=10;
	swap6(&a,&b);
	printf("a = %d,b = %d\n",a,b);




	return 0;
}
