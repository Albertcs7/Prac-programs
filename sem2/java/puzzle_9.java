import java.util.Scanner;

public class puzzle_9 {
    public static void disp(int[][] mat){
        for(int i=0 ; i<4 ; i++){
            for(int j=0 ; j<4 ; j++){
                if(mat[i][j] == 0){
                    System.out.print(" \t");
                }
                else{
                System.out.print(mat[i][j]+"\t");
                }
            }
            System.out.println("\n");
        }
    }
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        int[][] mat = {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,0,11},
            {13,14,15,12}
        };
        int[][] cop = {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,0}
        };
        do{
            System.out.println("PUZZLE IS:");
            disp(mat);
            System.out.println("Enter the number to switch:");
            int sw = sc.nextInt();
            boolean moved = false;
            for(int i=0 ; i<4 && !moved ; i++){
                for(int j=0 ; j<4 && !moved ; j++){
                    if(mat[i][j] == 0){
                        if(i + 1 < 4 && mat[i+1][j] == sw){
                            int temp = mat[i][j];
                            mat[i][j] = mat[i+1][j];
                            mat[i+1][j] = temp;
                            moved = true;
                        }
                        else if(j + 1 < 4 && mat[i][j+1] == sw){
                            int temp = mat[i][j];
                            mat[i][j] = mat[i][j+1];
                            mat[i][j+1] = temp;
                            moved = true;
                        }
                        else if(i - 1 >= 0 && mat[i-1][j] == sw){
                            int temp = mat[i][j];
                            mat[i][j] = mat[i-1][j];
                            mat[i-1][j] = temp;
                            moved = true;
                        }
                        else if(j - 1 >= 0 && mat[i][j-1] == sw){
                            int temp = mat[i][j];
                            mat[i][j] = mat[i][j-1];
                            mat[i][j-1] = temp;
                            moved = true;
                        }
                    }
                }
            }
            
            disp(mat);
            boolean win = true;
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    if(mat[i][j] != cop[i][j]) {
                        win = false;
                        break;
                    }
                }
            }
            if(win){
                System.out.println("You WON...");
                break;
            }

        }while(true);    
    }
}
