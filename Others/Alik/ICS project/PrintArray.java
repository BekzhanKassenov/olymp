import java.io.*;
import javax.swing.*;
import java.sql.*;
import java.util.*;
import java.awt.*;
import java.text.*;


public class PrintArray
{
   public String PrintArray(RepublicUnit[][] array) throws IOException
   {
      StringBuffer lines = new StringBuffer();
      for (int i = 0; i<array.length;i++)
      {
         for (col = 0; col<array[i].length; col++)
         {
            lines.append(array.getName());
   		   lines.append("\n");
         }
      }
      
      return lines.toString();
      
   }
   
   public String PrintArray(RepublicWeapon[][] array) throws IOException
   {
      StringBuffer lines = new StringBuffer();
      for (int i = 0; i<array.length;i++)
      {
         for (col = 0; col<array[i].length; col++)
         {
            lines.append(array.getName());
   		   lines.append("\n");
         }
      }
      
      return lines.toString();
      
   }
   
   public String PrintArray(RepublicArmor[][] array) throws IOException
   {
      StringBuffer lines = new StringBuffer();
      for (int i = 0; i<array.length;i++)
      {
         for (col = 0; col<array[i].length; col++)
         {
            lines.append(array.getName());
   		   lines.append("\n");
         }
      }
      
      return lines.toString();
      
   }
   
   public String PrintArray(CisUnit[][] array) throws IOException
   {
      StringBuffer lines = new StringBuffer();
      for (int i = 0; i<array.length;i++)
      {
         for (col = 0; col<array[i].length; col++)
         {
            lines.append(array.getName());
   		   lines.append("\n");
         }
      }
      
      return lines.toString();
      
   }
   
   public String PrintArray(CisWeapon[][] array) throws IOException
   {
      StringBuffer lines = new StringBuffer();
      for (int i = 0; i<array.length;i++)
      {
         for (col = 0; col<array[i].length; col++)
         {
            lines.append(array.getName());
   		   lines.append("\n");
         }
      }
      
      return lines.toString();
      
   }
   
   public String PrintArray(CisArmor[][] array) throws IOException
   {
      StringBuffer lines = new StringBuffer();
      for (int i = 0; i<array.length;i++)
      {
         for (col = 0; col<array[i].length; col++)
         {
            lines.append(array.getName());
   		   lines.append("\n");
         }
      }
      
      return lines.toString();
      
   }

}