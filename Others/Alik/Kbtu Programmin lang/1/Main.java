import java.io.*;
import java.util.*;
class Main
{
	public static void main(String args[])
		{
			Scanner sc = new Scanner(new InputStreamReader (System.in));
			PrintWriter pw = new PrintWriter(new OutputStreamWriter (System.out));
			int a = sc.nextInt();
			int b = sc.nextInt();
			pw.println(a+b);
			pw.close();

		}
}