import java.util.*;

public class falling_apart {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    short N = in.nextShort();

    Integer[] nums = new Integer[N];

    for (int i = 0; i < N; i++) {
      nums[i] = in.nextInt();
    }

    in.close();

    Arrays.sort(nums, Collections.reverseOrder());

    int alice = 0;
    int bob = 0;

    for (int i = 0; i < N; i++) {
      if (i % 2 == 0) {
        alice += nums[i];
      } else {
        bob += nums[i];
      }
    }

    System.out.printf("%d %d%n", alice, bob);
  }
}
