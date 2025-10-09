
#include<stdio.h>

int main(){
	int n=1,sum=0,rem,d;
	d = n;
	do{
		rem = n % 10;
		n /= 10;
		sum += (rem*rem*rem);
		  
	}while(n != 0);
	if(d == sum){
		printf("is armstrong\n");
		
	}
	else{
		printf("not armstromg\n");
	}
	
	return 0;
}
