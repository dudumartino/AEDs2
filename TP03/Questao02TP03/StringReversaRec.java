import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class StringReversaRec {
    static Scanner scanner = new Scanner(System.in, StandardCharsets.ISO_8859_1);

    public static void main(String[] args) {
        System.setOut(new PrintStream(System.out, true, StandardCharsets.ISO_8859_1));
        solve();
    }

    static void solve() {
        String line = scanner.nextLine();

        if (!isEOF(line)) {
            System.out.println(reverseString(line));
            solve();
        }
    }
    
    static boolean isEOFRec(String line, String flag, int i) {
        if (i == flag.length()) {
            return true;
        }
        if (line.charAt(i) != flag.charAt(i)) {
            return false;
        }
        return isEOFRec(line, flag, i + 1);
    }

    static boolean isEOF(String line) {
        String flag = "FIM";
        if (flag.length() != line.length()) {
            return false;
        }
        return isEOFRec(line, flag, 0);
    }

    static String reverseString(String string) {
        if (string.isEmpty()) {
            return "";
        }
        return reverseString(string.substring(1)) + string.charAt(0);
    }
}