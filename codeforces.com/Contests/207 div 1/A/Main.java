import java.util.*;
import java.io.*;

public class Main {
  	int[] flag, l, r, x, a;

  	void push(int v, int l, int r) {
 		if (l > r)
 			return;

 		if (flag[v] != -1) {
 			if (l == r)
 				a[l] = flag[v];
 			else 
 				flag[v << 1] = flag[(v << 1) + 1] = flag[v];
 			
 			flag[v] = -1;
 		}	
	}

	void upd(int v, int l, int r, int z_l, int z_r, int val) {
		push(v, l, r);
		if (l > r || z_l > z_r || l > z_r || r < z_l)
			return;

		if (l >= z_l && r <= z_r) {
			flag[v] = val;
			push(v, l, r);
		} else {
		 	int mid = (l + r) >> 1;
		
	 		upd(v << 1, l, mid, z_l, z_r, val);
	 		upd((v << 1) + 1, mid + 1, r, z_l, z_r, val);
		}	
	}

	int get(int v, int l, int r, int ind) {
		push(v, l, r);

		if (l > r || ind > r || ind < l)
			return 0;

		if (l == r && l == ind)
			return a[l];

		int mid = (l + r) >> 1;

		return get(v << 1, l, mid, ind) + get((v << 1) + 1, mid + 1, r, ind);
	}

	public static void main(String[] args) {
		new Main().run();
	}
	private void run() {
		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int n, m;

		n = in.nextInt();
		m = in.nextInt();

		l = new int[n];
		r = new int[n];
		x = new int[n];
		a = new int[n];
		flag = new int [4 * n];

		for (int i = 0; i < n; i++) {
			l[i] = in.nextInt();
			r[i] = in.nextInt();
			x[i] = in.nextInt();
		 	l[i]--;
		 	r[i]--; 
		 	x[i]--;
		}

		a[x[n - 1]] = -1;

		for (int i = n - 1; i >= 0; i--) {
			upd(1, 0, n - 1, l[i], x[i] - 1, x[i] + 1);
			upd(1, 0, n - 1, x[i] + 1, r[i], x[i] + 1);
		}

		for (int i = 0; i < n; i++) {
	    	int k = get(1, 0, n - 1, i);
	    	out.print((k == -1) ? 0 : k);
	    	out.print(" ");
		}
	}
}
class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}