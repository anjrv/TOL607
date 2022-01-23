import java.util.*;
import java.util.stream.Collectors;

public class b {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int width = in.nextInt();
        int partitions = in.nextInt() + 1;

        Integer[] nums = new Integer[partitions];
        nums[partitions - 1] = width;

        for (int i = 0; i < partitions - 1; i++) {
            nums[i] = in.nextInt();
        }

        in.close();

        Arrays.sort(nums);

        TreeSet<Integer> widths = new TreeSet<>();

        for (int i = 0; i < partitions; i++) {
          widths.add(nums[i]);

          for (int j = i + 1; j < partitions; j++) {
            widths.add(nums[j] - nums[i]);
          }
        }

        System.out.println(
          widths.stream()
            .map(i -> String.valueOf(i))
            .collect(Collectors.joining(" ")));
    }
}
