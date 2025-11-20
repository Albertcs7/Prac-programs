#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
} node;
node *head=NULL;

//Function to insert
void insert(int a)
{
	node *t;
	if(head==NULL)
	{
		head=(node *) malloc(sizeof(node));
		head->data=a;
		head->next=NULL;
	}
	else
	{
		t=head;
		while(t->next)
		{
			t=t->next;
		}
		t->next=(node *)malloc(sizeof(node));
		t->next->data=a;
		t->next->next=NULL;
	}
}

//function too delete
void delete(int a)
{
	 
	node *t;
	if(head==NULL)
	{
		printf("list is empty!\n");
	}
	else if(head->data==a)
	{
		node *temp = head;
    	head = head->next;
    	free(temp);
   	 	printf("element deleted\n");
	}
	else
	{
		t=head;
		while(t->next && t->next->data!=a)
		{
			t=t->next;
		}
		if(t->next==NULL)
		{
			printf("element not found");
		}
		else
		{
			printf("element deleted");
			node *temp=t->next;
			t->next=t->next->next;
			free(temp);
		}
	}
}

//function to seaarch element
void search(int ch)
{
	node *t=head;
	int pos=0;
	while(t)
	{
		pos++;
		if(t->data==ch)
		{
			printf("element present in position:%d\n",pos);
			break;
		}
		if(t->next==NULL)
		{
			printf("element not found");
			break;
		}
		t=t->next;
	}

}

//Function to count elements
void count()
{
	node *t=head;
	int count=0;
	while(t)
	{
		count++;
		t=t->next;
	}
	printf("no of nodes in the list:%d",count);
}

//function to replace element
void replace(int e)
{
	int x;
	node *t=head;
	printf("enter new value to insert:");
	scanf("%d",&x);
	if(head==NULL)
	{
		printf("list is empty!\n");
	}
	else if(head->data==e)
	{
		printf("element replaced");
		head->data=x;
	}
	else
	{
		while(t->next && t->next->data!=e)
		{
			t=t->next;
		}
		if(t->next==NULL)
		{
			printf("element not found");
		}
		else
		{
			printf("element replaced");
			t->next->data=x;
		}
	}
}
void sort()
{
	int temp;
	node *i,*j,*min;
	for(i=head;i;i=i->next)
	{
		min=i;
		for(j=i->next;j;j=j->next)
		{
			if(j->data < min->data)
			{
				min=j;
			}
		}
		if(i!=min)
		{
			temp=i->data;
			i->data=min->data;
			min->data=temp;
		}
	}
	printf("list have been sorted successfully");
}
void reverse() {
    node *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("list reversed\n");
}
void display()
{
	node *t=head;
	if(!head)
	{
		printf("empty list");
		return;
	}
	while(t)
	{
		printf("%d->",t->data);
		t=t->next;
	}
	printf("NULL");
	
}

int menu()
{	
    int input;
    printf("\nLINKED LIST\n");
    printf("1.insert \n2.delete \n3.search\n4.display\n5.sort\n6.find and replace\n7.reverse\n8.count nodes\n9.exit\nenter your choice:");
    scanf("%d", &input); // Read user menu choice
    return input;
}

void process()
{
    int ch;
    for(ch = menu(); ch != 9; ch = menu()) // Loop until user exits
    {
        switch(ch)
        {
            case 1:
                printf("enter element:");
                scanf("%d", &ch); // Reuse 'ch' to take element input
                insert(ch); // Insert element into array
                break;
            case 2:
            	display();
            	printf("enter element to delete:");
            	scanf("%d",&ch);
                delete(ch); // Delete an element
                break;
            case 3:
                printf("enter search element:");
                scanf("%d", &ch); // Reuse 'ch' to take search input
                search(ch); // Search for element
                break;
            case 4:
                display(); // Display array contents
                break;
            case 5:
                sort(); // Sort the array
                break;
                
            case 6:
            	printf("enter element to be replaced:");
            	scanf("%d",&ch);
            	replace(ch);
            	break;
            case 7:
            	reverse();
            	break;
            case 8:
            	count();
            	break;
            default:
                printf("wrong choice\n"); // Invalid menu choice
        }
    }
}


// Main function
int main()
{
    process(); // Start menu-driven operations
    return 0;
}
