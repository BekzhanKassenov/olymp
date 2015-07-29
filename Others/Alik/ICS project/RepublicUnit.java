import java.io.*;
import javax.swing.*;
import java.sql.*;
import java.util.*;
import java.awt.*;
import java.text.*;

public class RepublicUnit
{
   static String fraction = "Republic";
   static String combatArm;
   
   static String name;
   static String rang;
   static String equipment_weapon;
   static String equipment_armor;
   
   static double viewrange;
   static double price;
   static double damage;
   static double armor;
   static double range;
   
   static int accuracy;
   static int state;
   static int contentSupply;
   static int crew;
   static int landing;
   static int hangar;
   
   static boolean shield;
   
   static ArrayList<String> description_unit = new ArrayList<String>();
   
   //Infantry
   public RepublicUnit(String name1, String rang1, String weapon1, String armor1, 
                       double viewrange1, double price1, 
                       int accuracy1, int contentSupply1) throws IOException
   {
       combatArm = "Infantry";
       name = name1;
       rang = rang1;
       equipment_weapon = weapon1;
       equipment_armor = armor1;
      
       viewrange = viewrange1;
       price = price1;
      
       accuracy = accuracy1;
       contentSupply = contentSupply1;
      
   }
   
   public RepublicUnit(int po) throws IOException
   {
       combatArm = "Infantry";
       name = "11";
       rang = "";
       equipment_weapon = "";
       equipment_armor = "";
      
       viewrange = 0.0;
       price = 0.0;
      
       accuracy = 0;
       contentSupply = 0;
   
   }
   
   public RepublicUnit(RepublicUnit unit) throws IOException
   {
       combatArm = "Infantry";
       name = unit.name;
       rang = unit.rang;
       equipment_weapon = unit.equipment_weapon;
       equipment_armor = unit.equipment_armor;
      
       viewrange = unit.viewrange;
       price = unit.price;
      
       accuracy = unit.accuracy;
       contentSupply = unit.contentSupply;
      
   }
   
   //Enginery
   public RepublicUnit(String name1, String rang1, 
                       double viewrange1, double price1, double damage1, double armor1, double range1, 
                       int accuracy1, int state1, int contentSupply1, int crew1, int landing1, boolean shield1) throws IOException
   {
       combatArm = "Enginery";
       name = name1;
       rang = rang1;
      
       viewrange = viewrange1;
       price = price1;
       damage = damage1;
       armor = armor1;
       range = range1;
      
       accuracy = accuracy1;
       state = state1;
       contentSupply = contentSupply1;
       crew = crew1;
       landing = landing1;
       shield = shield1;
      
   }
   
   public RepublicUnit(String str) throws IOException
   {
       combatArm = "Enginery";
       name = "22";
       rang = "";
      
       viewrange = 0.0;
       price = 0.0;
       damage = 0.0;
       armor = 0.0;
       range = 0.0;
      
       accuracy = 0;
       state = 0;
       contentSupply = 0;
       crew = 0;
       landing = 0;
       shield = false;
      
   }
   
   public RepublicUnit(RepublicUnit unit, String str) throws IOException
   {
       combatArm = "Enginery";
       name = unit.name;
       rang = unit.rang;
      
       viewrange = unit.viewrange;
       price = unit.price;
       damage = unit.damage;
       armor = unit.armor;
       range = unit.range;
      
       accuracy = unit.accuracy;
       state = unit.state;
       contentSupply = unit.contentSupply;
       crew = unit.crew;
       landing = unit.landing;
       shield = unit.shield;
      
   }
   
   //Space Fleet
   public RepublicUnit(String name1, String rang1, 
                       double price1, double damage1, double armor1, double range1, 
                       int accuracy1, int state1, int contentSupply1, int crew1, int landing1, int hangar1, boolean shield1) throws IOException
   {
       combatArm = "Space Fleet";
       name = name1;
       rang = rang1;
      
       price = price1;
       damage = damage1;
       armor = armor1;
       range = range1;
      
       accuracy = accuracy1;
       state = state1;
       contentSupply = contentSupply1;
       crew = crew1;
       landing = landing1;
       hangar = hangar1;
       shield = shield1;
      
   }
   
   public RepublicUnit(String str, String str1) throws IOException
   {
       combatArm = "Space Fleet";
       name = "";
       rang = "";
      
       price = 0.0;
       damage = 0.0;
       armor = 0.0;
       range = 0.0;
      
       accuracy = 0;
       state = 0;
       contentSupply = 0;
       crew = 0;
       landing = 0;
       hangar = 0;
       shield = false;
      
   }
   
   public RepublicUnit(RepublicUnit unit, String str, String str1) throws IOException
   {
       combatArm = "Space Fleet";
       name = unit.name;
       rang = unit.rang;
      
       price = unit.price;
       damage = unit.damage;
       armor = unit.armor;
       range = unit.range;
      
       accuracy = unit.accuracy;
       state = unit.state;
       contentSupply = unit.contentSupply;
       crew = unit.crew;
       landing = unit.landing;
       hangar = unit.hangar;
       shield = unit.shield;
      
   }
   
   //set
   
   public  static void setName(String name1)
   {
       name = name1;
   }
   
   public  static void setcombatArm(String combatArm1)
   {
       combatArm = combatArm1;
   }
   
   public  static void setFraction(String fraction1)
   {
       fraction = fraction1;
   }
   
   public  static void setRang(String rang1)
   {
       rang = rang1;
   }
   
   public  static void setEquipmentWeapon(String equipment_weapon1)
   {
       equipment_weapon = equipment_weapon1;
   }
   
   public  static void setEquipmentArmor(String equipment_armor1)
   {
       equipment_armor = equipment_armor1;   
   }
   
   public  static void setViewRange(double viewrange1)
   {
       viewrange = viewrange1;
   }
   
   public  static void setPrice(double price1)
   {
       price = price1;
   }
   
   public  static void setDamage(double damage1)
   {
       damage = damage1;
   }
   
   public  static void setArmor(double armor1)
   {
       armor = armor1;
   }
   
   public  static void setRange(double range1)
   {
       range = range1;
   }
   
   public  static void setAccuracy(int accuracy1)
   {
       accuracy = accuracy1;
   }   
   
   public  static void setState(int state1)
   {
       state = state1;
   }
   
   public  static void setContentSupply(int contentSupply1)
   {
       contentSupply = contentSupply1;
   }
   
   public  static void setCrew(int crew1)
   {
       crew = crew1;
   }
   
   public  static void setLanding(int landing1)
   {
       landing = landing1;
   }
   
   public  static void setHangar(int hangar1)
   {
       hangar = hangar1;
   }
   
   public  static void setShield(boolean shield1)
   {
       shield = shield1;
   }
   
   //get
   
   public static String getName()
   {
      return name;
   }
   
   public static String getFraction()
   {
      return fraction;
   }
   
   public static String getCombatArm()
   {
      return combatArm;
   }
   
   public static String getRang()
   {
      return rang;
   }
   
   public static String getEquipmentWeapon()
   {
      return equipment_weapon;
   }
   
   public static String getEquipmentArmor()
   {
      return equipment_armor;
   }
   
   public static double getViewRange()
   {
      return viewrange;
   }
   
   public static double getPrice()
   {
      return price;
   }
   
   public static double getDamage()
   {
      return damage;
   }
   
   public static double getArmor()
   {
      return armor;
   }
   
   public static double getRange()
   {
      return range;
   }
   
   public static int getAccuracy()
   {
      return accuracy;
   }
   
   public static int getState()
   {
      return state;
   }
   
   public static int getContentSupply()
   {
      return contentSupply;
   }
   
   public static int getCrew()
   {
      return crew;
   }
   
   public static int getLanding()
   {
      return landing;
   }
   
   public static int getHangar()
   {
      return hangar;
   }
   
   public boolean getShield()
   {
      return shield;
   }
   
   
}