import java.io.*;
import javax.swing.*;
import java.sql.*;
import java.util.*;
import java.awt.*;
import java.text.*;

public class RepublicArmor
{
    private String fraction = "Republic";
    private String combatArm = "Infantry";
   
    private String name;
    private String rang;
   
    private double price;
    private double armor;
   
    private int state;
    private boolean shield;

    ArrayList<String> description_weapon = new ArrayList<String>();
   
   // Infatnry
   
   public RepublicArmor(String name, String rang, double price, double armor, int state, boolean shield)
   {
       name = name;
       rang = rang;
       price = price;
       armor = armor;
       state = state;
       shield = shield;
   }
   
   public RepublicArmor()
   {
       name = "";
       rang = "";
       price = 0.0;
       armor = 0.0;
       state = 0;
       shield = false;
   }
   
   public RepublicArmor(RepublicArmor armour)
   {
       name = armour.name;
       rang = armour.rang;
       price = armour.price;
       armor = armour.armor;
       state = armour.state;
       shield = armour.shield;
   }
   
   public void setName(String name)
   {
       name = name;
   }
   
   public void setcombatArm(String combatArm)
   {
       combatArm = combatArm;
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
    
   public void setArmor(double armor)
   {
       armor = armor;
   }
   
   public void setState(int state)
   {
       state = state;
   }
   
   public void setShield(boolean shield)
   {
       shield = shield;
   }

   public String getName()
   {
      return name;
   }
   
   public String getFraction()
   {
      return fraction;
   }
   
   public String getCombatArm()
   {
      return combatArm;
   }
   
   public String getRang()
   {
      return rang;
   }
   
   public double getPrice()
   {
      return price;
   }
  
   public double getArmor()
   {
      return armor;
   }
   
   public int getState()
   {
      return state;
   }
   
   public boolean getShield()
   {
      return shield;
   }
   
}