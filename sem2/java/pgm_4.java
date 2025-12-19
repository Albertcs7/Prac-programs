import java.util.Scanner;

class sortsearch {

    public void sort(int a[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        System.out.println("\nAfter sorting:");
        disp(a, n);
    }

    public void disp(int a[], int n) {
        System.out.println("ARRAY IS : ");
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }

    public void search(int a[], int n) {
        Scanner sc = new Scanner(System.in);
        System.out.println("\nEnter element to search:");
        int key = sc.nextInt();

        for (int i = 0; i < n; i++) {
            if (a[i] == key) {
                System.out.println("Element found at position: "+(i+1));
                return;
            }
        }
        System.out.println("Element not found.");
    }
}

public class pgm_4 {
    public static void main(String args[]) {
	int ch=0,n=0;
    Scanner sc = new Scanner(System.in);
	System.out.println("Enter number of array elements:");
        n = sc.nextInt();
        int[] arr = new int[n];
        sortsearch obj = new sortsearch();
	
    do{
        System.out.println("1.Add elements\n2.Sort\n3.Search\n4.Display\n5.Exit\nENter the choice:");
	    ch = sc.nextInt();
        switch(ch){
            case 1:
                System.out.println("Enter the elements:");
                for (int i = 0; i < n; i++) {
                    arr[i] = sc.nextInt();
                }
                break;
            case 2:
                obj.sort(arr, n);
                break;
            case 3:
                obj.search(arr,n);
                break;
            case 4:
                obj.disp(arr, n);
                break;
            case 5:
		    	return;
	    }
    }while(ch != 6);
    }
}
