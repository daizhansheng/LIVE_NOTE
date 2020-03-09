#include <stdio.h>

#define A_N 5
#define B_N 7
#define C_N (A_N+B_N)
int main(int argc, const char *argv[])
{
	int i = 0,j = 0,k=0;
	int a[A_N] = {1,3,5,7,9};
	int b[B_N] = {2,4,6,8,10,11,12};
	int c[C_N] = {0};

	while(i<A_N && j<B_N){
		while(a[i] < b[j] && i<A_N){
			c[k++] = a[i++];
		}

		while(i<A_N && a[i] > b[j] && j<B_N){
			c[k++] = b[j++];
		}
	}	
	
	while(i == A_N && j<B_N){
		c[k++] = b[j++];
	}

	while(j==B_N && i<A_N){
		c[k++] = a[i++];
	}

	for(k=0; k<C_N; k++){
		printf("%d\t",c[k]);
	}
	puts("");

	return 0;
}
