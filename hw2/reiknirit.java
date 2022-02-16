import java.util.*;

public class f {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();

        Map<Integer, Integer> nums = new HashMap<>();

        for (int i = 0; i < N; i++) {
            int curr = in.nextInt();

            if (nums.containsKey(curr)) {
                nums.put(curr, nums.get(curr) + 1);
            } else {
                nums.put(curr, 1);
            }
        }

        in.close();

        List<Integer> sortedNums = new ArrayList<>(nums.values());
        Collections.sort(sortedNums, Collections.reverseOrder());

        long output = N;
        for (int i = 0; i < sortedNums.size(); i++) {
            N -= sortedNums.get(i);
            output += N;
        }

        System.out.println(output);
    }
}