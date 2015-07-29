import java.io.*;
import javax.swing.*;
import java.sql.*;
import java.util.*;
import java.awt.*;
import java.text.*;

public class RepublicWeapon
{
    private String fraction = "Republic";
    private String combatArm = "Infantry";
    private String fullname;
    private String name;
    private String rang;
   
    private double price;
    private double damage;
    private double range;
   
    int accuracy;
    int number;
    int speed;
   
    ArrayList<String> description_weapon = new ArrayList<String>();
   
   public RepublicWeapon(String name1, String fullname1, double price1, double damage1, double range1, int accuracy1, int speed1)
   {
       name = name1;
       fullname = fullname1;
       
       price = price1;
       damage = damage1;
      
       accuracy = accuracy1;
       speed = speed1;
   }
   
   public RepublicWeapon()
   {
       name = "";
       fullname = "";
      
       price = 0.0;
       damage = 0.0;
      
       accuracy = 0;
       speed = 0;
   }
   
   public RepublicWeapon(RepublicWeapon weapon)
   {
       name = weapon.name;
      
       price = weapon.price;
       damage = weapon.damage;
      
       accuracy = weapon.accuracy;
   }
   
    //set
    
   public String getDescription()
   {
      StringBuffer lines = new StringBuffer();
      lines.append("Name:"); lines.append("     "); lines.append(fullname); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("Fraction:"); lines.append("    "); lines.append(fraction); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("Combat Arm:"); lines.append("     "); lines.append(combatArm); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("Price:"); lines.append("    "); lines.append(price); lines.append(" credits"); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("Damage:"); lines.append("    "); lines.append(damage); lines.append(" per minute"); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("Accuracy on middle distance:"); lines.append("    "); lines.append(accuracy); lines.append(" %"); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("Attack Speed:"); lines.append("    "); lines.append(speed); lines.append(" shots/minute"); lines.append("\n");
      
      return lines.toString();
   } 
    
   public void setNumber(int number1)
   {
      number = number1;
   }
   
   public void setName(String name1)
   {
       name = name1;
   }
   
   public void setFullName(String fullname1)
   {
       fullname = fullname1;
   }
   
   public void setFraction(String fraction)
   {
       fraction = fraction;
   }
   
   public void setRang(String rang)
   {
       rang = rang;
   }
   
   public void setPrice(double price)
   {
       price = price;
   }
   
   public void setDamage(double damage)
   {
       damage = damage;
   }
   
   public void setRange(double range)
   {
       range = range;
   }
   
   public void setSpeed(int speed1)
   {
      speed = speed1;
   }
   

   
   public void setAccuracy(int accuracy)
   {
       accuracy = accuracy;
   }   
      //get
   
   public int getNumber()
   {
      return number;
   }
   
   public String getName()
   {
      return name;
   }
   
   public  String getFullName()
   {
      return fullname;
   }

   
   public String getFraction()
   {
      return fraction;
   }
   
   public String getRang()
   {
      return rang;
   }
   
   public double getPrice()
   {
      return price;
   }
   
   public double getDamage()
   {
      return damage;
   }
   
   public int getSpeed()
   {
      return speed;
   }
   

   
   public double getRange()
   {
      return range;
   }
   
   public int getAccuracy()
   {
      return accuracy;
   }
   
}