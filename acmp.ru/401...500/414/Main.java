import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException{
        Scanner in = new Scanner (new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));

        Solver sl = new Solver();

        sl.solve(in, pw);

        pw.close();
    }   
}

class Solver {
    public void solve(Scanner in, PrintWriter pw) {
        int n = in.nextInt();

        ArrayList<Integer>[] g = new ArrayList[n];

        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<Integer>();

        int x = in.nextInt(), y = in.nextInt();

        for (int i = 2; i <= n; i++) {
            int tmp = in.nextInt();

            g[tmp - 1].add(i - 1);
            g[i - 1].add(tmp - 1);
        }

        LCA sol = new LCA(g, n);
        pw.print((sol.getLCA(x - 1, y - 1) + 1));
    }
}

class LCA {
    ArrayList<Integer>[] g;
    int[] tin, tout;
    int[][] anc;
    int timer, l, n;

    LCA(ArrayList <Integer>[] t_g, int len) {
        g = t_g;
        n = len;
        timer = 0;
        l = 1;

        while ((1 << l) <= n)
            l++;

        anc = new int[n][l + 1];
        tin = new int[n];
        tout = new int[n];

        Dfs(0, 0);
    }

    private boolean isAnc(int a, int b) {
        return (tin[a] <= tin[b] && tout[a] >= tout[b]);
    }

    private void Dfs(int v, int pr) {
        tin[v] = timer++;

        anc[v][0] = pr;

        for (int i = 1; i <= l; i++) {
            anc[v][i] = anc[anc[v][i - 1]][i - 1];
        }   

        for (int to: g[v]) {
            if (to != pr)
                Dfs(to, v);
        }

        tout[v] = timer++;
    }

    public int getLCA(int a, int b) {
        if (isAnc(a, b))
            return a;

        if (isAnc(b, a))
            return b;

        for (int i = l; i >= 0; i--) {
            if (!isAnc(anc[a][i], b)) 
                a = anc[a][i];
        }

        return anc[a][0];
    }
}
