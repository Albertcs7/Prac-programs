#include<stdio.h>
#include<stdlib.h>

struct emp {
	int eno;
	char ename[15];
	int salary;
	int dno;
};
typedef struct emp emp;

void insert(emp emplist[], int n,int i){
	printf("Enter the ENO, Ename, Salary, Dno: ");
	scanf("%d %s %d %d",&emplist[i].eno,emplist[i].ename,&emplist[i].salary,&emplist[i].dno);
}
void delete(emp emplist[], int d,int n){
	int i;
	while(i < n-1){
		if(emplist[i].eno == d){
			printf("Deleted:%d",emplist[i].ename);
			emplist[i] = emplist[i+1];
		}
	}
}
void sortName(emp emplist[],int n){
	int i,j;
	emp temp[15];
	for(i=0;i<n;i++){
		for(j=i+1 ; j<n ;j++ ){
			if(emplist[i].ename > emplist[i+1].ename ){
				temp[i] = emplist[i];
				emplist[i] = emplist[j];
				emplist[j] = temp[i];						
			}
		}
	}
}
void search(){
	
}
void display(emp emplist[], int n) {
    int i;
	printf("\nEno\tName\tSalary\tDno\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%d\n", emplist[i].eno, emplist[i].ename, emplist[i].salary, emplist[i].dno);
    }
}

int main(){
	emp emplist[100];
	int n,i=0,ch=0,d;	
	printf("Enter number of employees:");
	scanf("%d",&n);
	while(ch != 5){
		printf("1.insert\n2.delete\n3.sort\n4.search\n5.Display\n");
		printf("Enter a choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				insert(emplist,n,i);
				i++;
				break;
			case 2:
				printf("Enter eno of employee to be deleted:");
				scanf("%d",&d);
				delete(emplist,d,n);
			case 3:
				sortName(emplist,i);
				break;
			case 4:
				search();
			case 5:
				display(emplist,i);
				break;
		}
	}
}
