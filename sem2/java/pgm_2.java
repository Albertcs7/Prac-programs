class pgm_2 {
    public static void main(String args[]) {
        int n1, n2, ch, res = 0;

        n1 = Integer.parseInt(args[0]);
        n2 = Integer.parseInt(args[1]);
        ch = Integer.parseInt(args[2]);

        switch (ch) {
            case 1:
                res = n1 + n2;
                break;

            case 2:
                res = n1 - n2;
                break;

            case 3:
                res = n1 * n2;
                break;

            case 4:
                if (n2 == 0) {
                    System.out.println("Error: Division by zero!");
                    return;  
                }
                res = n1 / n2;
                break;

            default:
                System.out.println("Invalid choice!");
                return;
        }

        System.out.println("Result: " + res);
    }
}
