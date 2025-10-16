#include <stdio.h>

// Compare two strings (like strcmp)
int compare(char s1[], char s2[]) {
    int i=0;
    while(s1[i]!='\0' && s2[i]!='\0') {
        if(s1[i]!=s2[i])
            return s1[i]-s2[i];
        i++;
    }
    return s1[i]-s2[i];
}

// Copy one string to another (like strcpy)
void copy(char d[], char s[]) {
    int i=0;
    while(s[i]!='\0') {
        d[i]=s[i];
        i++;
    }
    d[i]='\0';
}

// Sort strings using Bubble Sort
void sort(char a[][50], int n) {
    int i,j;
    char t[50];
    for(i=0;i<n-1;i++) {
        for(j=0;j<n-i-1;j++) {
            if(compare(a[j],a[j+1])>0) {
                copy(t,a[j]);
                copy(a[j],a[j+1]);
                copy(a[j+1],t);
            }
        }
    }
}

// Binary Search on sorted strings
int search(char a[][50], int n, char key[]) {
    int low=0,high=n-1,mid,c;
    while(low<=high) {
        mid=(low+high)/2;
        c=compare(a[mid],key);
        if(c==0)
            return mid;
        else if(c<0)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}

int main() {
    int n,i,res;
    char key[50];
    printf("Enter number of strings: ");
    scanf("%d",&n);
    char a[n][50];
    printf("Enter %d strings:\n",n);
    for(i=0;i<n;i++)
        scanf("%s",a[i]);
    sort(a,n);
    printf("Sorted strings:\n");
    for(i=0;i<n;i++)
        printf("%s\n",a[i]);
    printf("Enter string to search: ");
    scanf("%s",key);
    res=search(a,n,key);
    if(res==-1)
        printf("String %s not found.\n",key);
    else
        printf("String %s found at position %d.\n",key,res+1);
    return 0;
}

