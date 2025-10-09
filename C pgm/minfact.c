#include<stdio.h>
int main(){
	int n,i;
	float sum=0,temp=1,tem;
	printf("Enter a NUMBER:");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		temp*=i;
		tem=i/temp;
		if(i%2==0){
			sum-=tem;
		}
		else if(i==1){
			sum+=tem;
		}
		else{
			sum+=tem;
		}
	}
	printf("sum=%f\n",sum);
	system("pause");
	return 0;
}
