#include<stdio.h>
int main(){
    char a;
    printf("Enter the number:");
    scanf(" %c",&a);
    switch(a){
              case 'a':
              case 'e':
              case 'i':
              case 'o':
              case 'u':
                   printf("Its vowel");
              default:
                      printf("NOt vowel");
					}
              
    return 0;                                                                    
}
     

