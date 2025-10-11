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
void delete(){
	
}
void sort(){
	
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
	int n,i,ch=0,d;	
	printf("Enter number of employees:");
	scanf("%d",&n);
	while(ch != 5){
		printf("1.insert\n2.delete\n3.sort\n4.search\n5.Display\n");
		printf("Enter a choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				i=0;
				insert(emplist,n,i);
				i++;
				break;
			case 2:
				printf("Enter eno of employee to be deleted:");
				scanf("%d",&d);
				delete(d);
			case 3:
				sort();
				break;
			case 4:
				search();
			case 5:
				display(emplist,n);
				break;
		}
	}
}
