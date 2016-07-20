import java.io.File;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by bekzhan on 7/20/16.
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);//new File("input.txt"));
        int k = sc.nextInt();
        int n = sc.nextInt();

        BigInteger dp[] = new BigInteger[n + 1];
        dp[0] = BigInteger.ONE;
        for (int i = 1; i <= n; i++) {
            dp[i] = BigInteger.ZERO;
            for (int j = Math.max(i - k, 0); j < i; j++) {
                dp[i] = dp[i].add(dp[j]);
            }
        }

        System.out.print(dp[n].toString());
    }
}
