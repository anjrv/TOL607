import java.util.*;

public class b {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String input = in.nextLine();

        in.close();

        String output = input
                .replace("flatbaka", "petsa")
                .replace("bauk", "dos")
                .replace("k", "g")
                .replace("y", "u");

        System.out.println(output);
    }
}
