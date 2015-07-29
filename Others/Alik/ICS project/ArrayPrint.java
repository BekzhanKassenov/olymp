import java.io.*;
import javax.swing.*;
import java.sql.*;
import java.util.*;
import java.awt.*;
import java.text.*;



public class ArrayPrint
{
   
   public static String RepublicInfantry(RepublicInfantry[][] array) throws IOException
   {
      StringBuffer lines = new StringBuffer();
      for (int i = 0; i<array.length;i++)
      {
         for (int col = 0; col<array[i].length; col++)
         {
            lines.append(array[i][col].getName());
   		   lines.append("\t\t");
         }
         lines.append("\n");
      }
      return lines.toString();
      
   }
   
   public static String RepublicEnginery(RepublicEnginery[][] array) throws IOException
   {
      StringBuffer lines = new StringBuffer();
      for (int i = 0; i<array.length;i++)
      {
         for (int col = 0; col<array[i].length; col++)
         {
            lines.append(array[i][col].getName());
   		   lines.append("\t\t       ");
         }
         lines.append("\n");
      }
      return lines.toString();
      
   }
   
   private static String RepublicWeapon(RepublicWeapon[][] array) throws IOException
   {
      StringBuffer lines = new StringBuffer();
      for (int i = 0; i<array.length;i++)
      {
         for (int col = 0; col<array[i].length; col++)
         {
            lines.append(array[i][col].getName());
   		   
         }
         lines.append("\n");
      }
      
      return lines.toString();
      
   }
   
   public static String RepublicArmor(RepublicArmor[][] array) throws IOException
   {
      StringBuffer lines = new StringBuffer();
      for (int i = 0; i<array.length;i++)
      {
         for (int col = 0; col<array[i].length; col++)
         {
            lines.append(array[i][col].getName());
   		   
         }
         lines.append("\n");
      }
      
      return lines.toString();
      
   }
}