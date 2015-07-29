/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.lang.StringBuilder;

/**
 *
 * @author User
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    
    InputReader in;
    PrintWriter pw;
    public static void main(String[] args) throws Exception {
        try {
            new Main().run();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
    
    public void run() throws Exception { 
        try {
            in = new InputReader(new FileReader("transformations.in"));
            pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        } catch (FileNotFoundException ex) {
            throw new RuntimeException(ex);
        }
        
        int t = in.nextInt();

        BigInteger ten, four, two, three, five, six, seven, eight, nine, sixteen;
        two = BigInteger.valueOf(2);
        three = BigInteger.valueOf(3);
        four = BigInteger.valueOf(4);
        five = BigInteger.valueOf(5);
        six = BigInteger.valueOf(6);
        seven = BigInteger.valueOf(7);
        eight = BigInteger.valueOf(8);
        nine = BigInteger.valueOf(9);
        ten = BigInteger.valueOf(10);
        sixteen = BigInteger.valueOf(16);

        StringBuilder build = new StringBuilder();

        skip: for (int k = 0; k < t; k++) {
            long n = in.nextLong();
            
            BigInteger a;
            a = BigInteger.valueOf(n);
            
            String result = "";
            while (!a.equals(four)) {
                BigInteger modulus = a.mod(ten);
                
                //System.out.println(a);

                if (modulus.equals(four)) {
	               	result = result + 'B';
		            a = a.divide(ten);
		        } else if (modulus.equals(BigInteger.ZERO)) {
		        	result = result + 'A';
		            a = a.divide(ten);
                } else if (modulus.equals(two) || modulus.equals(five) || modulus.equals(seven)) {
                	a = a.multiply(two);
                	result = result + "C";
                } else if (modulus.equals(BigInteger.ONE) || modulus.equals(six)) {
                	a = a.multiply(four);
                	result = result + "CC";
                } else if (modulus.equals(three) || modulus.equals(eight)) {
                	a = a.multiply(eight);
                	result = result + "CCC";
                } else if (modulus.equals(nine)) {
                	a = a.multiply(sixteen);
                	result = result + "CCCC";
                } 

            	if (result.length() > 200) {
            		System.out.println("-1");
            		continue skip;
            	}
            }

            build.append(new StringBuilder(result).reverse().toString());
            build.append("\n");
        } 
        pw.print(build.toString());
        pw.close();
    }              
    
    class InputReader {
        BufferedReader br;
        StringTokenizer tokenizer;
        
        InputReader(FileReader in) {
            br = new BufferedReader(in);
            tokenizer = null;
        }
        
        String nextToken() throws IOException{
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                 	tokenizer = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        
        int nextInt() throws Exception{
            return Integer.parseInt(nextToken());
        }    
        
        long nextLong() throws Exception {
            return Long.parseLong(nextToken());
        }
    }
}
