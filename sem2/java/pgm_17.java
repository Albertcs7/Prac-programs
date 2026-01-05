class animal {
    void kind() {
        System.out.println("This is an animal and is inside parent class");
    }
}
class dog extends animal {
    void kind() {
        System.out.println("This is a dog and is inside child class");
    }

    void display() {
        super.kind();
        kind();
    }
}
public class pgm_17 {
    public static void main(String[] args) {
        dog d = new dog();
        d.display();
    }
}

