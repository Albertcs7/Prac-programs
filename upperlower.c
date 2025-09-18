#include <stdio.h>
int main() {
    int n, i, j, isEqual = 1;
    printf("Enter size of the square matrix: ");
    scanf("%d", &n);
    int a[n][n];
    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(a[i][j] != a[j][i]) {
                isEqual = 0;
                break;
            }
        }
    }
    if(isEqual)
        printf("The upper triangular part is equal to the lower triangular part.\n");
    else
        printf("The upper triangular part is NOT equal to the lower triangular part.\n");
		system("pause");
		return 0;
}

