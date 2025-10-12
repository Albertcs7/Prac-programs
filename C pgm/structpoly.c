#include<stdio.h>

struct poly{
	int coef;
	int exp;
};
typedef struct poly poly;

int main(){
	poly exp[20];
	int i, n;
	printf("Enter the degree:");
	scanf("%d",&n);
	for(i=0 ; i<=n ; i++){
		printf("Enter coefficiant:");
		scanf("%d",&exp[i].coef);
		printf("Enter exponent:");
		scanf("%d",&exp[i].exp);
	}
	printf("The expression is:");
	for(i=0 ; i<=n ; i++){
		if(i != 0 && exp[i].coef >= 0){
			printf(" + ");
		}
		printf("%dx^%d",exp[i].coef,exp[i].exp);
	}
}
