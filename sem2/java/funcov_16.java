class dept{
    final void show(){
        System.out.println("Tis is inside parent class...");
    }
}
class course extends dept{
    void disp(){
        System.out.println("This is in child class...");
    }
}
public class funcov_16 {
    public static void main(String args[]){
        course c =new course();
        c.show();
        c.disp();
    }    
}
