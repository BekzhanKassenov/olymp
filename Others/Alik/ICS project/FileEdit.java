import java.io.*;
import javax.swing.*;
import java.sql.*;
import java.util.*;
import java.awt.*;
import java.text.*;

class FileEdit
{
   static  ArrayList<String> Units_List = new ArrayList<String>();

   public static int LineCount(String filename) throws IOException
   {
      String input;
      int m = 0;
      
      File file = new File(filename);
      Scanner inputfile = new Scanner(file);
      
      while(inputfile.hasNext())
      {
         input = inputfile.nextLine();
         m++;
      }
      
      inputfile.close();
      
      return m;
                                          
   }   
   
   
   public static  void Add(String fileName, String str) throws IOException
   {
      
   	int SIZE = LineCount(fileName);
	   BufferedReader bufferedReader = new BufferedReader(new FileReader (fileName));
   	
      for (int i = 0; i< (SIZE-1); i++)
      {
   		Units_List.add(bufferedReader.readLine());
   	}
      
      bufferedReader.close();
      
      Units_List.add(str);
      
	   BufferedWriter buffered = new BufferedWriter(new FileWriter(fileName));
      
      for (int i = 0; i<=Units_List.size(); i++)
	   {
         buffered.write(Units_List.get(i));
         buffered.newLine();
      }
      buffered.flush();
      
      
   }
   
   public  String Print(String filename) throws IOException
   {
      String line = null;
      StringBuffer lines = new StringBuffer();
   	FileReader reader = new FileReader(filename);
	   BufferedReader bufferedReader = new BufferedReader(reader);
   	while ( (line = bufferedReader.readLine()) != null)
      {
   		lines.append(line);
   		lines.append("\n");
   	}
      
      bufferedReader.close();
      
      return lines.toString();
                                          
   }
   
      
}