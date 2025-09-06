#include<stdio.h>
int main(){
	int a[2][2] = {{1,2},{4,5}};
	int b[2][2] = {{3,4},{6,3}};
	int sum[2][2];
	int i,j,k;
	printf("THe first matrix is:\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("THe second matrix is:\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			sum[i][j]=0;
			for(k=0;k<2;k++){
				sum[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	printf("THe matrix after multy is:\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d\t",sum[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
