import java.io.*;
import java.util.*;

class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(new InputStreamReader(System.in));
		int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt(), d = sc.nextInt();
		
		if ((a+b)%2 == (c+d)%2) 
			System.out.println("YES"); 
		else 
			System.out.println("NO");
	}
}