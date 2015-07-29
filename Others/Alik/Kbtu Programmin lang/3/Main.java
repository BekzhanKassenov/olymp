import java.io.*;
import java.util.*;

class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(new InputStreamReader(System.in));
		int a, n = sc.nextInt(),i, mn = 2000000000;
		for(i=0; i<n; i++) 
		{
		 a = sc.nextInt();
		 mn = Math.min(mn, a);

		}
		System.out.println(mn);
	}
}