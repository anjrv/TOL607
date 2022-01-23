import java.util.*;

public class d {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();

        Integer[] nums = new Integer[N];

        for (int i = 0; i < N; i++) {
            nums[i] = in.nextInt();
        }

        in.close();

        Arrays.sort(nums);

        long res = 0;

        for (int i = 1; i < N; i++) {
            res += Math.abs(nums[i] - nums[i - 1]);
        }

        System.out.println(Math.pow(res, 2));
    }
}
