import java.util.*;
import java.io.*;

public class Main
	{
		static Scanner sc;
		static PrintWriter pw;

		long n;

		final long INF = ((((long) 1) << 63) - 1);

		long s(long n1)
			{
				long ans = 0;

				while (n1 > 0)
					{
						ans += (n1 % 10);
						n1 /= 10;
					}
				return ans;
			}

	  	long check(long c)
	  		{
	  			double d = c * c + 4 * n;

	  			long ans = INF;

	  			long k = (long)Math.sqrt(d);

	  			if (k * k == d)
	  				{
	  					long x = (-c + k);
	  					if (x > 0 && x % 2 == 0)
	  						if (s(x / 2) == c) 
	  							ans = Math.min(ans, x / 2);
	  				}
	  			return ans;
	  		}

		void solve()
			throws IOException
				{
					n = sc.nextLong();

					long ans = INF;

					for (long i = 0; i <= 99; i++)
						ans = Math.min(ans, check(i));

					if (ans != INF)
						pw.print(ans);

					else
						pw.print(-1);	
				}



		public static void main(String args[])
			throws IOException
				{
					sc = new Scanner (System.in);
					pw = new PrintWriter (System.out);

					try
						{
							new Main().solve();
						}
					finally
						{
							pw.close();
						}
				}

		
}
