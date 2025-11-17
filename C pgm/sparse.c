#include <stdio.h>

// Function to input matrix
void insert(int r, int c, int a[r][c]) {
    int i, j;
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

// Function to display matrix and count non-zero elements
int dispmat(int r, int c, int a[r][c]) {
    int i, j, count = 0;
    printf("\nMatrix is:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            printf("%d\t", a[i][j]);
            if(a[i][j] != 0)
                count++;
        }
        printf("\n");
    }
    return count;
}

// Function to convert to sparse matrix
void convert(int r, int c, int a[r][c], int count, int spa[count + 1][3]) {
    int i, j, k = 1;
    spa[0][0] = r;
    spa[0][1] = c;
    spa[0][2] = count;

    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            if(a[i][j] != 0) {
                spa[k][0] = i;
                spa[k][1] = j;
                spa[k][2] = a[i][j];
                k++;
            }
        }
    }
}

// Function to display sparse matrix
void disspar(int count, int spa[count + 1][3]) {
    int i, j;
    printf("\nSparse matrix is:\n");
    printf("Row\tColumn\tValue\n");
    for(i = 0; i < count + 1; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d\t", spa[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int r, c;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    int a[r][c];
    printf("\nEnter elements:\n");
    insert(r, c, a);

    int count = dispmat(r, c, a);

    int spa[count + 1][3];
    convert(r, c, a, count, spa);

    disspar(count, spa);

    return 0;
}

