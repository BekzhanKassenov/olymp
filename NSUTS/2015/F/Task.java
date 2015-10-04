import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.Locale;

class Solver {
	int Q;
	final static double D = 100000000.0;
	
	public void solve() throws Exception {
		Scanner sc = new Scanner(new FileInputStream("input.txt"));
		sc.useLocale(Locale.ENGLISH);

        PrintWriter pw = new PrintWriter(new FileOutputStream("output.txt"));
		
		Q = sc.nextInt();
		
		for (int i = 0; i < Q; i++) {
			double a = sc.nextDouble();
			double b = sc.nextDouble();
			double c = sc.nextDouble();
			
			long la = (long) (a * D);
			long lb = (long) (b * D);
			long lc = (long) (c * D);
			
			BigInteger ba = BigInteger.valueOf(la);
			BigInteger bb = BigInteger.valueOf(lb);
			BigInteger bc = BigInteger.valueOf(lc);
			
			BigInteger lhs = ba.multiply(bc);
			lhs = lhs.add(ba.multiply(bb));
			lhs = lhs.add(bc.multiply(bb));
			lhs = lhs.multiply(BigInteger.valueOf((long)D));
			
			BigInteger rhs = ba.multiply(bb).multiply(bc);
			if (lhs.compareTo(rhs) == -1) {
				pw.println("YES");
			} else {
				pw.println("NO");
			}
		}
		
		pw.close();
	}
}

public class Task {

	public static void main(String args[]) throws Exception {
        new Solver().solve();
	}
}
