#include<stdio.h>

struct date{
	int day;
	int month;
	int year;
};
typedef struct date date;

void insertDate(date d[],int n){
	printf("ENter day month year:");
	scanf("%d %d %d",&d[n].day,&d[n].month,&d[n].year);
}
void compareDate(date d[],int n1,int n2){
	if(d[n1].year == d[n2].year && d[n1].month == d[n2].month && d[n1].day == d[n2].day){
		printf("Same date\n");
	}
	else{
		printf("NOt same");
	}
}
void display(date d[],int n){
	printf("%d/%d/%d\n",d[n].day,d[n].month,d[n].year);
}

int main(){
	date d[10];
	int n1=0,n2=1;
	printf("Enter date 1\n");
	insertDate(d,n1);
	display(d,n1);
	printf("enter date 2:\n");
	insertDate(d,n2);
	display(d,n2);
}
