import java.util.Scanner;

public class array_5 {

    static void printArray(int[] a) {
        for (int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
        System.out.println();
    }

    static void sumArray(int[] a) {
        int sum = 0;
        for (int i = 0; i < a.length; i++)
            sum += a[i];
        System.out.println("Sum of array = " + sum);
    }

    static void printElement(int x) {
        System.out.println("Single element value = " + x);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter array size: ");
        int n = sc.nextInt();

        int[] a = new int[n];
        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();

        System.out.println("Passing entire array:");
        printArray(a);

        System.out.println("Passing anonymous array:");
        sumArray(new int[]{1, 2, 3});

        System.out.print("Enter index to pass single element: ");
        int index = sc.nextInt();
        printElement(a[index]);

        sc.close();
    }
}