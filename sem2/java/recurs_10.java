import java.util.Scanner;
public class recurs_10 {
    public static void recb(int n){
    if (n == 0)
        return;
    System.out.print(n);
    recb(n - 1);
    if (n == 1)
        System.out.println();
    System.out.print(n);
}
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number:");
        int n = sc.nextInt();
        recb(n);
    }
}
