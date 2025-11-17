#include<stdio.h>

void sort(int a[],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i] > a[j]){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void display(int a[],int n){
	int i,j;
	for(i=0;i<n;i++){
			printf("%d\t",a[i]);
	}
}
void search(int a[],int key,int n){
	int low = 0;
	int high = n-1;
	int mid = 0;
	while(low <= high){
		mid = (high+low)/2;
		if(a[mid] == key){
			printf("\n%d found at %d",key,mid+1);
			return;
		}
		else if(a[mid] < key){
			low = mid+1;
		}	
		else{
			high = mid-1;
		}
	}
}	
int main(){
	int n,i=0,key;
	printf("Enter number of elements:");
	scanf("%d",&n);
	int a[n];
	int ch=0;
	while(1){
		printf("\n1.insert\n2.display\n3.sort\n4.search\n5.exit\nenter choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter elements:");
				while(i < n){
					scanf("%d",&a[i]);
					i++;
				}
				break;
			case 2:
				printf("\nArray is:");
				display(a,n);
				break;
			case 3:
				sort(a,n);
				break;
			case 4:
				printf("\nENter element to search:");
				scanf("%d",&key);
				search(a,key,n);
				break;
			case 5:
				return 0;
		}
	}
}
