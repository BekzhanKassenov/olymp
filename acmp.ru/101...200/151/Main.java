import java.util.*;
import java.io.*;

public class Main {
    public static void main(String args[]) throws FileNotFoundException{
        Scanner sc = new Scanner(new File("input.txt"));
        
        PrintWriter pw = new PrintWriter(new File("output.txt"));

        Solver sol = new Solver();

        sol.solve(sc, pw);
        
        pw.close();
    }
}

class Solver {
    ArrayList <Integer>[] g;

    int n;

    int[] color;

    boolean dfs(int v, int col) {
        color[v] = col;

        for (int to : g[v]) {
            if (color[to] == 0) {
                if (!dfs(to, 3 - col))
                	return false;
            }
            else
                if (color[to] == col)
                    return false;   
        }

        return true;
    }

    void solve(Scanner in, PrintWriter out) {
        n = in.nextInt();

        int m = in.nextInt();

        g = new ArrayList <Integer>[n];

        color = new int[n];

        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<Integer> ();

        int x, y;

        for (int i = 0; i < m; i++) {
            x = in.nextInt();
            y = in.nextInt();

            g[--x].add(--y);
            g[y].add(x);
        }

        boolean flag = true;

        for (int i = 0; i < n; i++)
            if (color[i] == 0)
                flag &= dfs(i, 1);

        out.print(flag ? "YES" : "NO");
    }
}