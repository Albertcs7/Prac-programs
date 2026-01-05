import java.util.Scanner;
class Employee {
    int eno;
    String ename;
    double esal;
    void read() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter employee number: ");
        eno = sc.nextInt();
        System.out.print("Enter employee name: ");
        ename = sc.next();
        System.out.print("Enter employee salary: ");
        esal = sc.nextDouble();
    }
    void display() {
        System.out.println("Employee Number: " + eno);
        System.out.println("Employee Name: " + ename);
        System.out.println("Employee Salary: " + esal);
    }
    boolean compareEno(int no) {
        if (eno == no)
            return true;
        else
            return false;
    }
}
public class pgm_19 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of employees: ");
        int n = sc.nextInt();
        Employee emp[] = new Employee[n];
        for (int i = 0; i < n; i++) {
            emp[i] = new Employee();
            System.out.println("\nEnter details of employee " + (i + 1));
            emp[i].read();
        }
        System.out.println("\nEmployee Details:");
        for (int i = 0; i < n; i++) {
            emp[i].display();
            System.out.println();
        }
        System.out.print("Enter employee number to search: ");
        int searchEno = sc.nextInt();
        boolean found = false;
        for (int i = 0; i < n; i++) {
            if (emp[i].compareEno(searchEno)) {
                System.out.println("\nEmployee Found:");
                emp[i].display();
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Employee not found");
        }
    }
}
