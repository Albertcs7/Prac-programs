import java.util.Scanner;

class complex {
    double real;
    double imag;
    void read() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter real part: ");
        real = sc.nextDouble();
        System.out.print("Enter imaginary part: ");
        imag = sc.nextDouble();
    }

    void display() {
        if (imag >= 0)
            System.out.println(real+" + "+imag+"i");
        else
            System.out.println(real+" - "+(-imag)+"i");
    }

    complex add(complex c) {
        complex temp = new complex();
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    complex multiply(complex c) {
        complex temp = new complex();
        temp.real = (real*c.real)-(imag*c.imag);
        temp.imag = (real*c.imag)+(imag*c.real);
        return temp;
    }
}
 
public class complex_12 {
    public static void main(String[] args) {
        complex c1 = new complex();
        complex c2 = new complex();
        System.out.println("Enter first complex number:");
        c1.read();
        System.out.println("Enter second complex number:");
        c2.read();
        complex sum = c1.add(c2);
        complex product = c1.multiply(c2);
        System.out.println("\nFirst Number:");
        c1.display();
        System.out.println("Second Number:");
        c2.display();
        System.out.println("\nSum:");
        sum.display();
        System.out.println("Product:");
        product.display();
    }
}
