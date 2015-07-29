import java.util.*;
import java.io.*;

public class Main {
	public static void main(String args[]) {
		InputReader in = new InputReader(new InputStreamReader(System.in));

		PrintWriter pw = new PrintWriter(System.out);

		TaskA sol = new TaskA();

		sol.solve(in, pw);

		pw.close();
	}
}

class TaskA {
	public void solve(InputReader in, PrintWriter pw) {
		int n = in.nextInt(), k = in.nextInt();

		int l, r;

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			l = in.nextInt(); r = in.nextInt();

			cnt += (r - l + 1);
		}

		pw.print(((k - cnt % k) + k) % k);
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