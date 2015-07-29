import java.util.*;
import java.io.*;

public class Main
	{
		public static void main(String srgs[])
			{
				Scanner sc = new Scanner(System.in);
				int k = sc.nextInt();
				int[] a = new int[12];
				for (int i = 0; i < 12; i++)
					a[i] = sc.nextInt();

				int ans = 0;
				int mx = 0;
				int j = 0;
				while (ans < k && j <= 12)
					{
						mx = 0;
						for (int i = 0; i < 12; i++)
							if (a[i] > a[mx])
								mx = i;

						ans += a[mx];
						a[mx] = 0;
						j++;
					}
			   if (ans < k)
			   	System.out.println(-1);
			   else
			   	System.out.println(j);
			}
	}