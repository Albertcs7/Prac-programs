#include<stdio.h>

struct poly{
	int coef;
	int exp;
};
typedef struct poly poly;

void readpoly(poly exp[],int n){
	int i;
	for(i=0 ; i<=n ; i++){
		printf("Enter coefficiant:");
		scanf("%d",&exp[i].coef);
		printf("Enter exponent:");
		scanf("%d",&exp[i].exp);
	}
}

int addPoly(poly exp1[],poly exp2[],int n1,int n2,poly result[]){
		int i=0, j=0, k=0;
		while(i<n1 && j<n2){
			if(exp1[i].exp == exp2[j].exp){
				result[k].coef = exp1[i].coef + exp2[j].coef;
				result[k].exp = exp1[i].exp;
				i++; j++; k++;
			}
			else if(exp1[i].exp > exp2[j].exp){
				result[k].coef = exp1[i].coef;
				result[k].exp = exp1[i].exp;
				i++; k++;
			}else{
				result[k].coef = exp2[i].coef;
				result[k].exp = exp2[i].exp;
				j++; k++;
			}
			
		}
		while(i < n1) {
	        result[k].coef = exp1[i].coef;
	        result[k].exp = exp1[i].exp;
	        i++; k++;
	    }
	
	    while(j < n2) {
	        result[k].coef = exp2[j].coef;
	        result[k].exp = exp2[j].exp;
	        j++; k++;
	    }
	
	    return k;
}

void display(poly exp[],int n){
	int i;
	for(i=0 ; i<=n ; i++){
		if(i != 0 && exp[i].coef >= 0){
			printf(" + ");
		}
		if(exp[i].exp == 0){
			printf("%d",exp[i].coef);
		}else{
		printf("%dx^%d",exp[i].coef,exp[i].exp);
		}
	}
		
}

int main(){
	poly exp1[20] , exp2[20],result[20];
	int i, n1,n2;
	printf("Enter the degree of 1st:");
	scanf("%d",&n1);
	readpoly(exp1,n1);
	printf("1st exp:");
	display(exp1,n1);
	printf("\nEnter the degree of 2st:");
	scanf("%d",&n2);
	printf("2nd exp:");
	readpoly(exp2,n2);
	display(exp2,n2);
	addPoly(exp1,exp2,n1,n2,result);
	printf("\nThe expression is after addition:");
	display(result,n1);
}
