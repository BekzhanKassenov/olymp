import java.io.*;
import java.util.*;

class Main {
	public static void main(String args[]) throws IOException {
		Scanner sc = new Scanner(new File ("input.txt"));
		int n = sc.nextInt();
		int a[] = new int[n];
		a[0] = 1;
		for (int i = 1; i < n; i++)
			a[i] = a[i - 1] * 2;
		
		for (int i = 0; i < n; i++)
			System.out.println(a[i] + " ");
	}
}
