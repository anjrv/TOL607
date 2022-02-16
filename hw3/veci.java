import java.util.*;

public class e {
    private static int value = 1000000;
    private static int target = 0;

    private static void permHelper(String s, String res) {
        if (s.length() == 0) {
            int curr = Integer.parseInt(res);
            if (curr > target && curr < value) {
                value = curr;
            }

            return;
        }

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            permHelper(s.substring(0, i).concat(s.substring(i + 1)), res + c);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String num = in.nextLine();
        target = Integer.parseInt(num);

        in.close();

        permHelper(num, "");

        if (value == 1000000) {
            System.out.println(0);
        } else {
            System.out.println(value);
        }
    }
}
