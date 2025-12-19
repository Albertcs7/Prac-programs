import java.util.Scanner;
class maxnum_7{
    public static int maximum(int num1,int num2){
        int m = num1>num2? num1 : num2;
        return m;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter three number;");
        int n1 = sc.nextInt();
        int n2 = sc.nextInt();
        int n3 = sc.nextInt();
        int maxi = maximum(maximum(n1,n2),n3);
        System.out.println("Maximum of three number is: "+maxi);
    }
}