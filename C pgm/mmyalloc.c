#include<stdio.h>
#include<stdlib.h>

int main(){
	int *p,n,i;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	p = (int*)calloc(n,sizeof(int));
	for(i=0 ; i<n ; i++){
		scanf("%d",&p[i]);
	}
	printf("Elements are:");
	for(i=0 ; i<n ; i++){
		printf("%d\t",p[i]);
	}
	free(p);
}
