#include<stdio.h>
int main(){
	int a[2][2] = {{1,2},{4,5}};
	int det=0;
	int i,j;
	printf("THe  matrix is:\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	det = ((a[0][0] * a[1][1]) - (a[0][1] * a[1][0]));
	
	printf("the determinant is:%d\n ",det);

	
		
	system("pause");
	return 0;
}
