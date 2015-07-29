import java.io.*;
import java.util.*;

public class Main
{
 	  public static void main(String args[])
 	  			throws IOException
        
                {
                	Scanner sc = new Scanner(System.in);//new File ("input.txt"));
                	PrintWriter obj = new PrintWriter(System.out);//new File("output.txt"));
                	int n = sc.nextInt();
 	          	  	int a[] = new int[n];
 	          	  	int d=0;

                	for (int i = 0; i < n; i++)
                	  {
                		a[i] = sc.nextInt();
                	  		
                    }

                  for (int i = 0; i < n; i++)
                  {
                 		 for (int j = 0; j < n; j++)  
                	  		{
                	  			if (a[i] == h[j]) 
                	  			d++;
                	  		}
                	}  		
                		obj.println(d);
                		obj.close();
                }
}
