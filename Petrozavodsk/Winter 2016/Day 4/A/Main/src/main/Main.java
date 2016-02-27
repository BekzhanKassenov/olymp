/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

/**
 *
 * @author User
 */
public class Main {
    int n, m;
    BigInteger a[][];
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        new Main().solve();
    }
    
    int posMax(int start, int col) {
        int res = -1;
        for (int i = start; i < n; i++) {
            if (!a[i][col].equals(BigInteger.ZERO) && 
                    (res == -1 || a[res][col].compareTo(a[i][col]) == -1)) {
                res = i;
            }
        }

        return res;
    }
    
    void norm(int rowNum) {
        BigInteger[] row = a[rowNum];
        BigInteger g = row[0];
        for (int i = 1; i < m; i++) {
            g = g.gcd(row[i]);
        }
        
        if (!g.equals(BigInteger.ZERO)) {
            for (int i = 0; i < m; i++) {
                row[i] = row[i].divide(g);
            }
        }
    }
    
    void REF() {
        int col = 0;
        for (int i = 0; i < n; i++) {
            while (col < m && posMax(i, col) == -1) {
                col++;
            }

            if (col == m) {
                break;
            }

            int pos = posMax(i, col);
            for (int j = 0; j < m; j++) {
                BigInteger temp = a[i][j];
                a[i][j] = a[pos][j];
                a[pos][j] = temp;
            }
            
            norm(i);

            BigInteger[] ai = a[i];
            for (int j = i + 1; j < n; j++) {
                if (a[j][col].equals(BigInteger.ZERO)) {
                    continue;
                }
                
                BigInteger[] aj = a[j];
                BigInteger g = aj[col].gcd(ai[col]);
                BigInteger mul1 = aj[col].divide(g);
                BigInteger mul2 = ai[col].divide(g);
                
                for (int k = 0; k < m; k++) {
                    aj[k] = aj[k].multiply(mul2).subtract(ai[k].multiply(mul1));
                }
                
                norm(j);
            }

            col++;
        }
    }
    
    public void solve() {
        InputReader in = new InputReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        
        n = in.nextInt();
        m = in.nextInt();
        a = new BigInteger[n][m];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = in.nextInt();
                a[i][j] = BigInteger.valueOf(x);
            }
        }
        
        REF();
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            boolean ok = false;
            for (int j = 0; j < m; j++) {
                if (!a[i][j].equals(BigInteger.ZERO)) {
                    ok = true;
                }
            }
            
            if (ok) {
                ans++;
            }
        }
        
        /*
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pw.print(a[i][j].toString() + " ");
            }
            pw.println();
        }
                */
        
        pw.print(ans);
        pw.close();
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;
    
    public InputReader(InputStreamReader rd) {
        reader = new BufferedReader(rd);
    }
    
    public String nextToken() {
        try { 
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
        } catch (Exception ex) {
            //
        }
        
        return tokenizer.nextToken();
    }
    
    public int nextInt() {
        return Integer.parseInt(nextToken());
    }
}