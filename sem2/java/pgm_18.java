class Person {
    String name;
    int age;
    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
}
class Student extends Person {
    int rollNo;
    Student(String name, int age, int rollNo) {
        super(name, age);
        this.rollNo = rollNo;
    }

    void display() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Roll No: " + rollNo);
    }
}
public class pgm_18 {
    public static void main(String[] args) {
        Student s = new Student("Arun", 20, 101);
        s.display();
    }
}
