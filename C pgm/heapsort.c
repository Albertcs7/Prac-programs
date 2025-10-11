#include<stdio.h>
#define max 20

int arr[max];
void heapify(int a[], int n, int i){
	int temp;
	int larg = i;
	int left = 2*i+1;
	int right = 2*i+2;
	
	if(left < n && a[left] > a[larg])
		larg = left;
		
	if(right < n && a[right] > a[larg])
		larg = right;
	
	if( larg != i){
		temp = a[i];
		a[i] = a[larg];
		a[larg] = temp;
	}
	heapify(a,n,larg);
}

void heapsort(int a[],int n){
	int i;
	for(i=n/2-1 ; i>=0 ; i--){
		heapify(a,n,i);	
	}
	for()
	
}
void display(){
	
}
int main(){
	int n,i;
	printf("Enter the  number of elements:");
	scanf("%d",&n);
	for(i=0 ; i<n ; i++)
		scanf("%d",&arr[i]);	
	heapsort(arr,n);
	display(arr,n);
}
