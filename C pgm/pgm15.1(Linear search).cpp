#include<stdio.h>

void insert(int a[], int n){
	int i;
	printf("ENter the elements:");
	for(i=0 ; i<n ; i++){
		scanf("%d",&a[i]);
	}
}

void search(int a[], int n, int se){
	int i;
	for(i=0 ; i<n ; i++){
		if(a[i] == se){
			printf("Element found at %d ",i);
		}
	}
}
 int main(){
 	int n,se;
 	printf("Enter of size of array:");
 	scanf("%d",&n);
 	int a[n];
	insert(a,n);
	printf("enter the element to search:");
	scanf("%d",&se);
	search(a,n,se);
 }
