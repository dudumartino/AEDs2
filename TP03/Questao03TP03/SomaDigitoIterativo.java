import java.util.Scanner;

public class SomaDigitoIterativo {

    public static boolean isFIM(String s) {
        return s.equals("FIM");
    }

    public static int digitsSum(String s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum += Character.getNumericValue(s.charAt(i));
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String line;

        line = scanner.nextLine();
        while (!isFIM(line)) {
            System.out.println(digitsSum(line));
            line = scanner.nextLine();
        }

        scanner.close();
    }
}