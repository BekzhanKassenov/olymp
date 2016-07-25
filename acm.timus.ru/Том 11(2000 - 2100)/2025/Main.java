import java.util.Scanner;
import java.io.PrintWriter;
import java.math.BigInteger;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);

        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            
            BigInteger ans = BigInteger.ZERO;
            int sum = n;

            for (int i = 0; i < n % k; i++) {
                sum -= n / k + 1;
                ans = ans.add(BigInteger.valueOf(sum * (n / k + 1)));
            }

            for (int i = 0; i < k - n % k; i++) {
                sum -= n / k;
                ans = ans.add(BigInteger.valueOf(sum * (n / k)));
            }

            pw.println(ans.toString());
        }

        pw.close();
    }
}