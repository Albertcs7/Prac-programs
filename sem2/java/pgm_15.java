class vehicle {
    String brand;
    int speed;

    void displayVehicle() {
        System.out.println("Brand: " + brand);
        System.out.println("Speed: " + speed + " km/h");
    }
}
class engine {
    String type;
    int hp;

    void displayEngine() {
        System.out.println("Engine Type: " + type);
        System.out.println("hp: " + hp);
    }
}

class Car extends vehicle {
    int year;
    engine e;  

    Car(String brand, int speed, int year, String type, int hp) {
        this.brand = brand;
        this.speed = speed;
        this.year = year;
        e = new engine();
        e.type = type;
        e.hp = hp;
    }

    void displayCar() {
        displayVehicle();  
        System.out.println("Model Year: " + year);
        e.displayEngine(); 
    }
}

public class pgm_15 {
    public static void main(String[] args) {
        Car c = new Car("Toyota", 180, 2023, "Petrol", 120);
        c.displayCar();
    }
}
