import java.util.Scanner;

class CString {
    String str;
    void read() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        str = sc.nextLine();
    }

    void display() {
        System.out.println(str);
    }

    boolean compare(CString s) {
        return this.str.equals(s.str);
    }

    CString add(CString s) {
        CString temp = new CString();
        temp.str = this.str + s.str;
        return temp;
    }

    CString concatenate(CString s) {
        CString temp = new CString();
        temp.str = this.str + s.str;
        return temp;
    }
}

public class CString_13 {
    public static void main(String[] args) {
        CString s1 = new CString();
        CString s2 = new CString();
        System.out.println("Enter first string:");
        s1.read();
        System.out.println("Enter second string:");
        s2.read();
        System.out.println("\nFirst String:");
        s1.display();
        System.out.println("Second String:");
        s2.display();
        if (s1.compare(s2))
            System.out.println("\nStrings are equal");
        else
            System.out.println("\nStrings are not equal");

        CString added = s1.add(s2);
        System.out.println("\nAfter Add:");
        added.display();
        CString conc = s1.concatenate(s2);
        System.out.println("After Concatenate:");
        conc.display();
    }
}
