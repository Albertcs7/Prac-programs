import java.util.Scanner;

class student {
    int sno;
    String sname;
    String sprogram;
    void read() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter student number: ");
        sno = sc.nextInt();
        sc.nextLine(); 
        System.out.print("Enter student name: ");
        sname = sc.nextLine();
        System.out.print("Enter student program: ");
        sprogram = sc.nextLine();
    }
    void display() {
        System.out.println("student Number: "+sno);
        System.out.println("student Name: "+sname);
        System.out.println("Program: "+sprogram);
    }
    boolean compare(student s) {
        return (this.sno == s.sno &&
                this.sname.equals(s.sname) &&
                this.sprogram.equals(s.sprogram));
    }
}

public class student_14{
    public static void main(String[] args) {
        student s1 = new student();
        student s2 = new student();
        System.out.println("Enter details for first student:");
        s1.read();
        System.out.println("\nEnter details for second student:");
        s2.read();
        System.out.println("\nFirst student details:");
        s1.display();
        System.out.println("\nSecond student details:");
        s2.display();
        if (s1.compare(s2)) {
            System.out.println("\nstudents are EQUAL.");
        } else {
            System.out.println("\nstudents are NOT EQUAL.");
        }
    }
}
