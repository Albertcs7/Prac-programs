import java.util.Scanner;

public class guess_3 {
    public static void main(String args[]){
        Scanner sc =new Scanner(System.in);
        int key = 25, user_inp,count = 1,ch =1;
        do{
            System.out.println("Enter a number between 20 and 30:");
            user_inp = sc.nextInt();
            if(user_inp == key){
                System.out.println("Yay its correct...The number of attempt is "+count);
                ch = 0;
            } 
            else if(user_inp > 30 || user_inp < 20){
                System.out.println("Please enter a number between 20 and 30...");  
                count++; 
            }  
            else{
                System.out.println("NO... your guess is wrong\nattempt = "+count);
                count++;
            }
        }while(ch != 0);
    }
}
