import java.util.Scanner;
class calc{
    public void add(int n1,int n2){
        System.out.println("Addition = "+ (n1+n2));
    }
    public void sub(int n1,int n2){
        System.out.println("Substraction = "+ (n1-n2));
    }
    public void mult(int n1,int n2){
        System.out.println("Multiplication = "+ (n1*n2));
    }
    public void div(int n1,int n2){
        if(n2 != 0){
            System.out.println("Division = "+ (n1/n2));
            return;
        }
        System.out.println("Division not possible");
    }
}
public class cal_11 {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        calc c = new calc();
        System.out.println("Enter two number:");
        int n1 = sc.nextInt();
        int n2 = sc.nextInt();
        c.add(n1,n2);
        c.sub(n1,n2);
        c.mult(n1,n2);
        c.div(n1,n2);
    }
}
