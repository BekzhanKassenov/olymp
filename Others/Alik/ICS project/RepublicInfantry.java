import java.io.*;
import javax.swing.*;
import java.sql.*;
import java.util.*;
import java.awt.*;
import java.text.*;

public class RepublicInfantry
{
     private String fraction = "Republic";
     private String combatArm;
     
     private int number;
     
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
     private int speed;
     private int state;
     private int contentSupply;
     private int crew;
     private int landing;
     private int hangar;
     
     private int squad;
     private boolean shield;
   
     ArrayList<String> description_unit = new ArrayList<String>();
   
   //Infantry
   public RepublicInfantry(int number1, String name1, String rang1, String weapon1, String armor1, 
                       double viewrange1, double price1, double damage1, double armour1,
                       int accuracy1, int speed1, int contentSupply1, boolean shield1, int squad1) throws IOException
   {
       combatArm = "Infantry";
       name = name1;
       rang = rang1;
       equipment_weapon = weapon1;
       equipment_armor = armor1;
      
       viewrange = viewrange1;
       price = price1;
       damage = damage1;
       armor = armour1;
      
       accuracy = accuracy1;
       speed = speed1;
       contentSupply = contentSupply1;
       shield = shield1;
       squad = squad1;
      
   }
   
   public RepublicInfantry() throws IOException
   {
       combatArm = "Infantry";
       name = "null";
       rang = "";
       equipment_weapon = "";
       equipment_armor = "";
      
       viewrange = 0.0;
       price = 0.0;
       damage = 0.0;
       armor = 0.0;
       range = 0.0;
      
       accuracy = 0;
       speed = 0;
       state = 0;
       contentSupply = 0;
       shield = false;
       squad = 0;
   
   }
   
   public RepublicInfantry(RepublicInfantry unit) throws IOException
   {
       combatArm = "Infantry";
       name = unit.name;
       rang = unit.rang;
       equipment_weapon = unit.equipment_weapon;
       equipment_armor = unit.equipment_armor;
      
       viewrange = unit.viewrange;
       price = unit.price;
       damage = unit.damage;
       armor = unit.armor;
       range = unit.range;
      
       accuracy = unit.accuracy;
       speed = unit.speed;
       state = unit.state;
       contentSupply = unit.contentSupply;
       shield = unit.shield;
       squad = unit.squad;
      
   }
   
   public String getDescription()
   {
      StringBuffer lines = new StringBuffer();
      lines.append("Name:"); lines.append("     "); lines.append(name); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("Fraction:"); lines.append("    "); lines.append(fraction); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("Combat Arm:"); lines.append("     "); lines.append(combatArm); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("Rang:"); lines.append("     "); lines.append(rang); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("Weapon:"); lines.append("      "); lines.append(equipment_weapon); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("Armor:"); lines.append("    "); lines.append(equipment_armor); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("View distance:"); lines.append("     "); lines.append(viewrange); lines.append(" meters"); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("Price:"); lines.append("    "); lines.append(price); lines.append(" credits"); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("Damage:"); lines.append("    "); lines.append(damage); lines.append(" per minute"); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("Damage Reduction:"); lines.append("    "); lines.append(armor); lines.append(" %"); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("Accuracy on middle distance:"); lines.append("    "); lines.append(accuracy); lines.append(" %"); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("Attack Speed:"); lines.append("    "); lines.append(speed); lines.append(" shots/minute"); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("Content supply:"); lines.append("    "); lines.append(contentSupply); lines.append(" credits"); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("Shield:"); lines.append("    "); if (shield)lines.append("power shield"); else lines.append("no shield"); lines.append("\n");
      lines.append("-----------------------------------------------------"); lines.append("\n");
      lines.append("Troopers in the squad:"); lines.append("    "); lines.append(squad); lines.append(" troopers"); lines.append("\n");
   	
      return lines.toString();
   }
   
   public void setNumber(int number1)
   {
      number = number1;
   }
   
   public    void setName(String name1)
   {
       name = name1;
   }
   
   public    void setcombatArm(String combatArm1)
   {
       combatArm = combatArm1;
   }
   
   public    void setFraction(String fraction1)
   {
       fraction = fraction1;
   }
   
   public    void setRang(String rang1)
   {
       rang = rang1;
   }
   
   public    void setEquipmentWeapon(String equipment_weapon1)
   {
       equipment_weapon = equipment_weapon1;
   }
   
   public    void setEquipmentArmor(String equipment_armor1)
   {
       equipment_armor = equipment_armor1;   
   }
   
   public    void setViewRange(double viewrange1)
   {
       viewrange = viewrange1;
   }
   
   public    void setPrice(double price1)
   {
       price = price1;
   }
   
   public    void setDamage(double damage1)
   {
       damage = damage1;
   }
   
   public    void setArmor(double armor1)
   {
       armor = armor1;
   }
   
   public    void setRange(double range1)
   {
       range = range1;
   }
   
   public    void setAccuracy(int accuracy1)
   {
       accuracy = accuracy1;
   }   
   
   public void setSpeed(int speed1)
   {
      speed = speed1;
   }
   
   public    void setState(int state1)
   {
       state = state1;
   }
   
   public    void setContentSupply(int contentSupply1)
   {
       contentSupply = contentSupply1;
   }
   
   public    void setCrew(int crew1)
   {
       crew = crew1;
   }
   
   public    void setLanding(int landing1)
   {
       landing = landing1;
   }
   
   public    void setHangar(int hangar1)
   {
       hangar = hangar1;
   }
   
   public    void setShield(boolean shield1)
   {
       shield = shield1;
   }
   
   public void setSquad(int squad1)
   {
      squad = squad1;
   }
   
   //get
   
   public int getNumber()
   {
      return number;
   }
   
   public   String getName()
   {
      return name;
   }
   
   public   String getFraction()
   {
      return fraction;
   }
   
   public   String getCombatArm()
   {
      return combatArm;
   }
   
   public   String getRang()
   {
      return rang;
   }
   
   public   String getEquipmentWeapon()
   {
      return equipment_weapon;
   }
   
   public   String getEquipmentArmor()
   {
      return equipment_armor;
   }
   
   public   double getViewRange()
   {
      return viewrange;
   }
   
   public   double getPrice()
   {
      return price;
   }
   
   public   double getDamage()
   {
      return damage;
   }
   
   public   double getArmor()
   {
      return armor;
   }
   
   public   double getRange()
   {
      return range;
   }
   
   public   int getAccuracy()
   {
      return accuracy;
   }
   
   public int getSpeed()
   {
      return speed;
   }
   
   public   int getState()
   {
      return state;
   }
   
   public   int getContentSupply()
   {
      return contentSupply;
   }
   
   public   int getCrew()
   {
      return crew;
   }
   
   public   int getLanding()
   {
      return landing;
   }
   
   public   int getHangar()
   {
      return hangar;
   }
   
   public boolean getShield()
   {
      return shield;
   }
   
   public int getSquad()
   {
      return squad;
   }
}
