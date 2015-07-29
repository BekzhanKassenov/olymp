import java.io.*;
import javax.swing.*;
import java.sql.*;
import java.util.*;
import java.awt.*;
import java.text.*;

public class RepublicSpaceFleet
{
    private String fraction = "Republic";
    private String combatArm;
   
    private String name;
    private String rang;
    private String equipment_weapon;
    private String equipment_armor;
   
    private double viewrange;
    private double price;
    private double damage;
    private double armor;
    private double range;
   
    private int accuracy;
    private int state;
    private int contentSupply;
    private int crew;
    private int landing;
    private int hangar;
   
    private boolean shield;
   
    ArrayList<String> description_unit = new ArrayList<String>();
   
   //Space Fleet
   public RepublicSpaceFleet(String name1, String rang1, 
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
   
   public RepublicSpaceFleet() throws IOException
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
   
   public RepublicSpaceFleet(RepublicUnit unit) throws IOException
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
   
   public   void setName(String name1)
   {
       name = name1;
   }
   
   public   void setcombatArm(String combatArm1)
   {
       combatArm = combatArm1;
   }
   
   public   void setFraction(String fraction1)
   {
       fraction = fraction1;
   }
   
   public   void setRang(String rang1)
   {
       rang = rang1;
   }
   
   public   void setEquipmentWeapon(String equipment_weapon1)
   {
       equipment_weapon = equipment_weapon1;
   }
   
   public   void setEquipmentArmor(String equipment_armor1)
   {
       equipment_armor = equipment_armor1;   
   }
   
   public   void setViewRange(double viewrange1)
   {
       viewrange = viewrange1;
   }
   
   public   void setPrice(double price1)
   {
       price = price1;
   }
   
   public   void setDamage(double damage1)
   {
       damage = damage1;
   }
   
   public   void setArmor(double armor1)
   {
       armor = armor1;
   }
   
   public   void setRange(double range1)
   {
       range = range1;
   }
   
   public   void setAccuracy(int accuracy1)
   {
       accuracy = accuracy1;
   }   
   
   public   void setState(int state1)
   {
       state = state1;
   }
   
   public   void setContentSupply(int contentSupply1)
   {
       contentSupply = contentSupply1;
   }
   
   public   void setCrew(int crew1)
   {
       crew = crew1;
   }
   
   public   void setLanding(int landing1)
   {
       landing = landing1;
   }
   
   public   void setHangar(int hangar1)
   {
       hangar = hangar1;
   }
   
   public   void setShield(boolean shield1)
   {
       shield = shield1;
   }
   
   //get
   
   public  String getName()
   {
      return name;
   }
   
   public  String getFraction()
   {
      return fraction;
   }
   
   public  String getCombatArm()
   {
      return combatArm;
   }
   
   public  String getRang()
   {
      return rang;
   }
   
   public  String getEquipmentWeapon()
   {
      return equipment_weapon;
   }
   
   public  String getEquipmentArmor()
   {
      return equipment_armor;
   }
   
   public  double getViewRange()
   {
      return viewrange;
   }
   
   public  double getPrice()
   {
      return price;
   }
   
   public  double getDamage()
   {
      return damage;
   }
   
   public  double getArmor()
   {
      return armor;
   }
   
   public  double getRange()
   {
      return range;
   }
   
   public  int getAccuracy()
   {
      return accuracy;
   }
   
   public  int getState()
   {
      return state;
   }
   
   public  int getContentSupply()
   {
      return contentSupply;
   }
   
   public  int getCrew()
   {
      return crew;
   }
   
   public  int getLanding()
   {
      return landing;
   }
   
   public  int getHangar()
   {
      return hangar;
   }
   
   public boolean getShield()
   {
      return shield;
   }
   
   
}