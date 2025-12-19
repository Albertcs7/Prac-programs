import java.util.Scanner;

class matrix {
    Scanner sc = new Scanner(System.in);
    public int[][] read(int a[][],int r,int c){
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                a[i][j] = sc.nextInt();
            }
        }
        return a;
    }
    public int[][] multiply(int[][] a,int[][] b,int[][] res,int r1,int c2,int c1){
        for(int i = 0; i < r1; i++){
            for(int j = 0; j < c2; j++){
                res[i][j] = 0;
                for(int k = 0; k < c1; k++){
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return res;
    }
    public void disp(int[][] res,int r,int c){
        for(int i=0 ; i<r ; i++){
            for(int j=0 ; j<c ; j++){
                System.out.print(res[i][j]+" ");
            }
            System.out.println();
        }
    }
}

class mult_6{
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        matrix m = new matrix();
        System.out.println("Enter row and column for matrix A:");
        int r1 = sc.nextInt();
        int c1 = sc.nextInt();
        System.out.println("Enter row and column for matrix B:");
        int r2 = sc.nextInt();
        int c2 = sc.nextInt();
        if(c1 != r2){
            System.out.println("Matrix multiplication not possible!");
            return;
        }
        int[][] a = new int[r1][c1];
        int[][] b = new int[r2][c2];
        int[][] res = new int[r1][c2];

        System.out.println("Enter elements of matrix A:");
        a = m.read(a,r1,c1);

        System.out.println("Enter elements of matrix B:");
        b = m.read(b,r2,c2);

        res = m.multiply(a,b,res,r1,c2,c1);

        System.out.println("result of matrix multiplication:");
        m.disp(res,r1,c2);
    }
}