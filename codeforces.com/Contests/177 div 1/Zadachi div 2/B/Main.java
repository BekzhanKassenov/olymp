import java.util.*;
import java.io.*;

public class Main {
	public static void main(String args[]) {
		InputReader in = new InputReader(new InputStreamReader(System.in));

		PrintWriter pw = new PrintWriter(System.out);

		TaskB sol = new TaskB();

		sol.solve(in, pw);

		pw.close();
	}
}

class TaskB {
	public void solve(InputReader in, PrintWriter pw) {
		int n = in.nextInt(), m = in.nextInt(), d = in.nextInt();

		int[] a = new int[n * m];

		int tmp = -1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				int ind = i * m + j;
				a[ind] = in.nextInt();

				if (tmp == -1)
					tmp = a[ind] % d;
				else
					if (a[ind] % d != tmp) {
						pw.print("-1");
						return;
					}	
			}
		}

		Arrays.sort(a);

		int mid = ((n * m) / 2);

		int ans = 0;
		
		for (int i = 0; i < n * m; i++) {
			ans += Math.abs(a[i] - a[mid]);
		}

		pw.print(ans / d);

	}
}

class InputReader {
	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public InputReader(InputStreamReader stream) {
		reader = new BufferedReader(stream);
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) { 
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (Exception e) {
				throw (new RuntimeException (e));
			}
		}

		return tokenizer.nextToken();	
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}
}