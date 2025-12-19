import java.io.*;
class pgm_2 {
    public static void main(String args[]) {
        int n1, n2, ch, res = 0;

        n1 = Integer.parseInt(args[0]);
        n2 = Integer.parseInt(args[1]);
        ch = Integer.parseInt(args[2]);

        switch (ch) {
            case 1:
                res = n1 + n2;
                System.out.println("Sum: " + res);
                break;
            case 2:
                res = n1 - n2;
                System.out.println("Difference: " + res);
                break;
            case 3:
                res = n1 * n2;
                System.out.println("Product: " + res);
                break;
            case 4:
                if (n2 == 0) {
                    System.out.println("cannot divide by zero...");
                    return;  
                }
                res = n1 / n2;
                System.out.println("Quotient: " + res);
                break;
            default:
                System.out.println("Invalid choice!");
                return;
        }
    }
}
