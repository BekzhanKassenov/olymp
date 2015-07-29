import java.util.Arrays;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.Comparator;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(in, out);
		out.close();
	}
}

class TaskE {
    static final int LG = 30;
    int n, m;
    ArrayList <Integer> g[];
    int[][] anc;
    int[] tin;
    int[] tout;
    int timer = 0;
    int[] depth;
    int[] size;

    void dfs(int v, int par, int d) {
        depth[v] = d;
        size[v] = 1;
        tin[v] = timer++;

        anc[v][0] = par;
        for (int i = 1; i < LG; i++) {
            anc[v][i] = anc[anc[v][i - 1]][i - 1];
        }

        for (int to : g[v]) {
            if (to != par) {
                dfs(to, v, d + 1);
                size[v] += size[to];
            }
        }

        tout[v] = timer++;
    }

    boolean isAncestor(int a, int b) {
        return tin[a] <= tin[b] && tout[b] <= tout[a];
    }

    int goUp(int a, int b) {
        for (int i = LG - 1; i >= 0; i--) {
            if (!isAncestor(anc[a][i], b)) {
                a = anc[a][i];
            }
        }

        return a;
    }

    int getLCA(int a, int b) {
        int result = -1;

        if (isAncestor(a, b)) {
            result = a;
        } else if (isAncestor(b, a)) {
            result = b;
        } else {
            result = anc[goUp(a, b)][0];
        }

        return result;
    }

    int processQuery(int a, int b) {
        int l = getLCA(a, b);
        int result = -1;

        if (a == b) {
            result = n;
        } else if (depth[a] - depth[l] == depth[b] - depth[l]) {
            a = goUp(a, l);
            b = goUp(b, l);

            result = n - size[a] - size[b];
        } else {
            if (depth[a] < depth[b]) {
                int temp = a;
                a = b;
                b = temp;
            }

            int to = a;
            int dist = depth[a] + depth[b] - 2 * depth[l];

            if (dist % 2 == 1) {
                result = 0;
            } else {
                dist /= 2;

                for (int i = LG - 1; i >= 0; i--) {
                    if (depth[a] - depth[anc[to][i]] < dist) {
                        to = anc[to][i];
                    }
                }

                int mid = anc[to][0];
                result = size[mid] - size[to];
            }
        }

        return result;
    }

    public void solve(InputReader in, PrintWriter out) {
        n = in.nextInt();
        g = new ArrayList [n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList <>();
        }
        anc = new int[n][LG];
        tin = new int[n];
        tout = new int[n];
        depth = new int[n];
        size = new int[n];

        int x, y;
        for (int i = 0; i < n - 1; i++) {
            x = in.nextInt() - 1;
            y = in.nextInt() - 1;

            g[x].add(y);
            g[y].add(x);
        }

        dfs(0, 0, 0);
        m = in.nextInt();

        while (m-- > 0) {
            x = in.nextInt() - 1;
            y = in.nextInt() - 1;

            out.println(processQuery(x, y));
        }
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
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