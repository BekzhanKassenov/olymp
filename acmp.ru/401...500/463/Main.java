import java.io.*;
import java.util.*;


public class Main {
	public static void main(String[] args) throws IOException {
		FileReader re = new FileReader ("input.txt");
		PrintWriter pw = new PrintWriter("output.txt");

		InputReader in = new InputReader(re);

		Task sol = new Task();

		sol.solve(in, pw);

		pw.close();
	}
}

class Task {
	public void solve(InputReader in, PrintWriter out) {
		int k = in.nextInt();
		int m = in.nextInt();

		String s = in.next();

		int ans = 0;

		for (int i = 0; i < s.length(); i++) {
			char tmp = s.charAt(i);
			ans = (ans * k + num(tmp)) % m; 
		}

		out.print(ans);
	}

	int num(char c) {
     	if (c >= '0' && c <= '9') {
     		return (int) (c - '0');
     	}

     	return ((int) (c - 'A') + 10);
    }
}

class InputReader {
	public BufferedReader reader;
	public StringTokenizer tokenizer;

	InputReader(FileReader input) {
		reader = new BufferedReader(input);
		tokenizer = null;
	}

	public String next() {
	 	while (tokenizer == null || !tokenizer.hasMoreTokens()) {
	 		try {
	 			tokenizer = new StringTokenizer(reader.readLine());
	 		} catch (Exception e) {
	 			throw new RuntimeException (e);
	 		}
	   	}

	 	return tokenizer.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}
}   	