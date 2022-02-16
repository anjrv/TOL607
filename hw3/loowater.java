import java.util.*;

public class loowater {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();

        while (n > 0 && m > 0) {
            int[] heads = new int[n];
            int[] knights = new int[m];

            // Need to clear scanner even if doomed
            for (int i = 0; i < n; i++) {
                heads[i] = in.nextInt();
            }

            for (int i = 0; i < m; i++) {
                knights[i] = in.nextInt();
            }

            if (n > m) {
                System.out.println("Loowater is doomed!");
            } else {
                Arrays.sort(heads);
                Arrays.sort(knights);
                int currKnight = 0;

                int coins = 0;
                boolean victory = false;

                for (int i = 0; i < n; i++) {
                    if (currKnight == m)
                        break;

                    if (knights[currKnight] < heads[i]) {
                        // Too short;
                        currKnight++;
                        i--;
                    } else if (knights[currKnight] >= heads[i]) {
                        // Tall enough
                        coins += knights[currKnight];
                        currKnight++;

                        if (i == (n - 1)) {
                            // Last head
                            victory = true;
                            break;
                        }
                    }
                }

                if (victory) {
                    System.out.println(coins);
                } else {
                    System.out.println("Loowater is doomed!");
                }
            }

            n = in.nextInt();
            m = in.nextInt();
        }

        in.close();
    }
}
