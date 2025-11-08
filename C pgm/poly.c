#include<stdio.h>
#include<stdlib.h>

struct term{
	int pow;
	int coeff;
};
typedef struct term term;

void insert(term poly[],int num){
	int i=0;
	while(i < num){
		printf("Enter coefficient of %d element:",i+1);
		scanf("%d",&poly[i].coeff);
		
		printf("ENter power:");
		scanf("%d",&poly[i].pow);
		i++;
	}
}

void display(term poly[],int n){
	int i = 0;
	while(i < n){
		if(poly[i].pow == 1){
			printf("%dx",poly[i].coeff);
		}
		else if(poly[i].pow == 0){
			printf("%d",poly[i].coeff);
		}
		else{
			printf("%d",poly[i].coeff);
			printf("x^%d",poly[i].pow);	
		}
		if( i != n-1)
			printf(" + ");
		i++;
	}
}
void addpoly(term poly1[],term poly2[],term res[],int n1,int n2){
	int i = 0,j = 0,k = 0;
	while( i < n1 && j < n2 ){
		if(poly1[i].pow == poly2[j].pow){
			res[k].pow = poly1[i].pow;
			res[k].coeff = poly1[i].coeff + poly2[j].coeff;
			i++;k++;j++;
		}
		else if(poly1[i].pow > poly2[j].pow){
			res[k].pow = poly1[i].pow;
			res[k].coeff = poly1[i].coeff;
			k++;i++;
		}
		else{
			res[k].pow = poly1[j].pow;
			res[k].coeff = poly1[j].coeff;
			k++;j++;
		}
	}
	while (i < n1) {
        res[k].pow = poly1[i].pow;
        res[k].coeff = poly1[i].coeff;
        i++; k++;
    }
    while (j < n2) {
        res[k].pow = poly2[j].pow;
        res[k].coeff = poly2[j].coeff;
        j++; k++;
    }
	printf("\nAfter adding: ");
	display(res,k);
}

int main(){
	term poly1[10],poly2[10],res[20];
	int n1,n2,n3;
	
	printf("Enter number of terms of polynomial 1:");
	scanf("%d",&n1);
	printf("\nEnter elements into poly 1\n");
	insert(poly1,n1);
	
	printf("\nEnter number of terms of polynomial 2:");
	scanf("%d",&n2);
	insert(poly2,n2);
	
	printf("\nfirst poly: ");
	display(poly1,n1);
	
	printf("\nsecond poly: ");
	display(poly2,n2);	
	addpoly(poly1,poly2,res,n1,n2);
	
}


