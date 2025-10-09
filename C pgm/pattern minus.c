#include<stdio.h>
int main(){
    int a,i,j;
    printf("enter a number:");
    scanf("%d",&a);
    for(i=a;i>=1;i--){
        for(j=1;j<=i;j++){
            printf("%d\t",j);
            
        }
        printf("\n");
    }
    for(i=a,j=1;i>=1;){
        printf("%d\t",j);
        if(j==i){
            printf("\n");
            i--;
            j=1;
        }
        else{
            j++;	
        }
    }
    system("pause");
return 0;
}   

