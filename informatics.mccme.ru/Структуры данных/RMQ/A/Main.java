import java.util.*;
import java.io.*;

public class Main {
 	public static void main(String args[]) {
 		InputReader in = new InputReader(new InputStreamReader(System.in));
 		PrintWriter pw = new PrintWriter(System.out);

 		Solver sl = new Solver();

 		sl.solve(in, pw);

 		pw.close();
 	}
}

class Solver {
	public void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();

		int[] a = new int[n];

		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}

		int m = in.nextInt();

		SegmentTree tr = new SegmentTree(a, n);

		int l, r;

		for (int i = 0; i < m; i++) {
			l = in.nextInt();
			r = in.nextInt();
			Pair res = tr.getMax(l, r);
			out.println(res.first + " " + res.second);
		}
	}
}

class Pair {
	int first, second;

	Pair(int F, int S) {
		first = F;
		second = S;
	}
}

class SegmentTree {
	int[] a;

	Pair[] t;

	int n;

	SegmentTree(int[] t_a, int len) {
		a = t_a;
		n = len;
		t = new Pair[n * 4 + 10];
		
		build(1, 0, n - 1);
	}

	private void build(int v, int l, int r) {
		if (l > r)
			return;

		if (l == r) {
			t[v].first = a[l];
			t[v].second = l;
			return;
		}

		int m = (l + r) >> 1;

		build((v << 1), l, m);
		build((v << 1) + 1, m + 1, r);

		if (t[(v << 1)].first > t[(v << 1) + 1].first) {
			t[v].first = t[v << 1].first; 
			t[v].second = t[v << 1].second;
		} else {
			t[v].first = t[(v << 1) + 1].first;	
			t[v].second = t[(v << 1) + 1].second;
		}
	}

	public Pair getMax(int l, int r) {
		return maxQuery(1, 0, n - 1, l, r);
	}

	private Pair maxQuery(int v, int cur_l, int cur_r, int l, int r) {
		if (cur_l > cur_r || cur_l > r || cur_r < l)
			return new Pair(-1, -1);

		if (cur_l >= l && cur_r <= r)
			return t[v];

		int m = (cur_l + cur_r) >> 1;

		Pair ans1 = maxQuery((v << 1), cur_l, m, l, r);
		Pair ans2 = maxQuery((v << 1) + 1, m + 1, cur_r, l, r);

		if (ans1.first > ans2.first)
			return ans1;
		else
			return ans2;
	}

	public void update(int pos, int val) {
		a[pos] = val;
		updQuery(1, 0, n - 1, pos);
	}

	private void updQuery(int v, int l, int r, int pos) {
		if (l > r || pos < l || pos > r)
			return;

		if (l == r) {
			t[v].first = a[l];
			t[v].second = l;
			return;
		}

		int m = (l + r) >> 1;

		if (pos <= m)
			updQuery(v << 1, l, m, pos);
		else
			updQuery((v << 1) + 1, m + 1, r, pos);

	   	if (t[(v << 1)].first > t[(v << 1) + 1].first) {
			t[v].first = t[v << 1].first; 
			t[v].second = t[v << 1].second;
		} else {
			t[v].first = t[(v << 1) + 1].first;	
			t[v].second = t[(v << 1) + 1].second;
		}
	}
}

class InputReader {
	StringTokenizer tokenizer;
	BufferedReader reader;

	InputReader(InputStreamReader stream) {
		reader = new BufferedReader(stream);
		tokenizer = null;
	}

	public String next() {
		while(tokenizer == null || !tokenizer.hasMoreTokens())
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException (e);
			}

		return tokenizer.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}
}