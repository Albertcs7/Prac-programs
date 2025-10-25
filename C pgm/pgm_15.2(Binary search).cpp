#include<stdio.h>
int i;

void insert(int a[], int n){
	printf("ENter the elements:");
	for(i=0 ; i<n ; i++){
		scanf("%d",&a[i]);
	}
}

void sort(int a[], int n){
	int temp,j;
	for(i=0 ; i<n ; i++){
		for(j=i+1 ; j<n ;j++){
			if(a[i] > a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key)
            return mid;
        (a[mid] < key) ? (low = mid + 1) : (high = mid - 1);
    }
    return -1;
}

 int main(){
 	int n,se,pos;
 	printf("Enter of size of array:");
 	scanf("%d",&n);
 	int a[n];
	insert(a,n);
	printf("enter the element to search:");
	scanf("%d",&se);
	sort(a,n);
	printf("\n");
	pos = binarySearch(a, n, se);
    int pos = binarySearch(a, n, se);
	(pos != -1) ? printf("Element %d found at position %d (index %d).\n", se, pos + 1, pos) : printf("Element %d not found.\n", se);				
    return 0;
 }
