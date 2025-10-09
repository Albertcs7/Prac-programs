#include<stdio.h>
int main(){
	int a[2][2] = {{1,2},{4,5}};
	
	int tr[2][2];
	int i,j,k;
	printf("The matrix is:\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			tr[j][i] = a[i][j];	
		}
	}
	printf("The matrix after transpose is:\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d\t",tr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
	
