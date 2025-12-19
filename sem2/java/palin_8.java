import java.util.Scanner;
class check{
    public int reverse(int num){
        int rev =0;
        int d; 
        while( num != 0){
            d = num % 10;
            num = num/10;
            rev = rev*10 + d;
        }
        return rev;
    }
}
public class palin_8 {
    public static void main(String args[]){
        check r = new check();
        int rev;
        Scanner sc = new Scanner(System.in);
        System.out.println("ENter the num to check:");
        int num = sc.nextInt();
        rev = r.reverse(num);
        if( num == rev)
            System.out.println("It is PALINDROME..");
        else
            System.out.println("It is not PALINDROME");
    }
}
