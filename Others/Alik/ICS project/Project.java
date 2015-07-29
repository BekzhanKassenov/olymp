import java.io.*;
import javax.swing.*;
import java.sql.*;
import java.util.*;
import java.awt.*;
import java.text.*;
//import hsa.*;

public class Project
{
   static ArrayList<String> Units_List = new ArrayList<String>();
   
   //SavedGames List
   //static SavedGame[] SavedGameList;
   
   //ArmyEditor List
   //static ArmyVariations[] ArmyVariationsList;
   
   //Unit List Arrays
   //Republic Unit Arrays
   static RepublicInfantry[][] RepInfantryList;
   static int RepInfantrySize;
   static RepublicEnginery[][] RepEngineryList;
   static int RepEnginerySize;
   //static RepublicSpaceFleet[][] RepSpaceList;
   //CIS Unit Arrays
//   static CisInfantry[][] CisInfantryList;
//   static CisEnginery[][] CisEngineryList;
   //static CisSpaceFleet[][] CisSpaceList;
   //Republic Armory
   static RepublicWeapon[] RepWeaponList;
   static int RepWeaponSize;
   //static RepublicWeapon[][] RepSpaceWeaponList;
   static RepublicArmor[] RepArmorList;
   //static RepublicArmor[][] RepSpaceArmorList;
   //CIS Armory
//   static CisWeapon[][] CisWeaponList;
//   static CisWeapon[][] CisTechWeaponList;
   //static CisWeapon[][] CisSpaceWeaponList;
//   static CisArmor[][] CisArmorList;
//   static CisArmor[][] CisTechArmorList;
   //static CisArmor[][] CisSpaceArmorList;
   
   
   static String fraction_array;
   static String combatArm_array;
   
   static int number_array;
   static String name_array;
   static String fullname_array;
   static String rang_array;
   static String equipment_weapon_array;
   static String equipment_armor_array;
   
   static double viewrange_array;
   static double price_array;
   static double damage_array;
   static double armor_array;
   static double range_array;
   
   static int accuracy_array;
   static int speed_array;
   static int state_array;
   static int contentSupply_array;
   static int crew_array;
   static int landing_array;
   static int hangar_array;
   
   static int squad_array;
   static boolean shield;
   
   static ArrayList<String> description_unit = new ArrayList<String>();
   
   
   public static void main(String[] args) throws IOException
   {
      String input; 
      int n;
      
      createArrays_Rep();
      
      do
      {
      
         input = JOptionPane.showInputDialog("                [Main Menu]\n"+
                                             "**********************************\n"+
                                             "1. Start\n"+
                                             "2. Army Editor\n"+
                                             "3. Settings // Not Available Yet\n"+
                                             "4. Unit List\n"+
                                             "5. Tutorial // Not Available Yet\n"+
                                             "0. Exit\n"+
                                             "**********************************");
         n = 1;
         
         switch (input)
         {
            case "1":
            Start();
            n++;
            break;
            
            case "2":
            ArmyEditor();
            n++;
            break;
            
            case "3":
            Settings();
            n++;
            break;
            
            case "4":
            UnitList();
            n++;
            break;
            
            case "5":
            Tutorial();
            n++;
            break;
            
            case "0":
            ExitGame();
            n++;
            break;
            
            default:
            JOptionPane.showMessageDialog(null, "Error! Enter only values from 0 to 5.");
            
            
         } // Switch case
         
      } // while loop
      
      while (n==1);
   } // main method
   
   
   public static void createArrays_Rep() throws IOException
   {
      int size;
      String fileName;
      String line=null, str;
      boolean next = true;
      BufferedReader bufferedReader;
      RepInfantrySize=0;
      RepEnginerySize=0;
      
      bufferedReader = new BufferedReader(new FileReader("Units\\Equipment\\Weapons\\Republic\\Weapon List.txt"));
      number_array = 0;
      while ((line = bufferedReader.readLine())!=null)   
         {
               number_array++;
               RepWeaponSize++;
         }
      bufferedReader.close();
      RepWeaponList = new RepublicWeapon[RepWeaponSize];
      for (int i = 0; i< RepWeaponSize; i++)
      {
         RepWeaponList[i] = new RepublicWeapon();
      }
      
      bufferedReader = new BufferedReader(new FileReader("Units\\Equipment\\Weapons\\Republic\\Full Weapon List.txt"));
      for (int i = 0; i<RepWeaponList.length;i++)
      {
            number_array = Integer.parseInt(bufferedReader.readLine());
            RepWeaponList[i].setNumber(number_array);
            
            name_array = bufferedReader.readLine();
            RepWeaponList[i].setName(name_array);
            
            fullname_array = bufferedReader.readLine();
            RepWeaponList[i].setFullName(fullname_array);
            
            price_array = Double.parseDouble(bufferedReader.readLine());
            RepWeaponList[i].setPrice(price_array);
            
            damage_array = Double.parseDouble(bufferedReader.readLine());
            RepWeaponList[i].setDamage(damage_array);
            
            accuracy_array = Integer.parseInt(bufferedReader.readLine());
            RepWeaponList[i].setAccuracy(accuracy_array);
            
            speed_array = Integer.parseInt(bufferedReader.readLine());
            RepWeaponList[i].setSpeed(speed_array);
            
      }
      bufferedReader.close();
      
      
      bufferedReader = new BufferedReader(new FileReader ("Units\\Republic\\Infantry\\Unit List.txt"));
      RepInfantryList = new RepublicInfantry[5][];
      number_array = 0;
      for (int i = 0; i < RepInfantryList.length; i++)
      {
         next = true;
         int col = 0;
         while (next && (line = bufferedReader.readLine())!=null)   
         {
            
            if (line.equals("Rang II:") || line.equals("Rang III:") || line.equals("Rang IV:") || line.equals("Rang V:"))
            {
               next = false;
            }
            else if (line.equals("Rang I:"))
            {
               next = true;
            }
            else
            {
               col++;
               number_array++;
               RepInfantrySize++;
            }
            
         }
         RepInfantryList[i] = new RepublicInfantry[col+1];
   	}
      bufferedReader.close();
      
      for (int i = 0; i<RepInfantryList.length;i++)
      {
         for (int col = 0; col<RepInfantryList[i].length; col++)
         {
            RepInfantryList[i][col] = new RepublicInfantry();
         }
      }
      
      bufferedReader = new BufferedReader(new FileReader("Units\\Republic\\Infantry\\Full List.txt"));
      for (int i = 0; i<RepInfantryList.length;i++)
      {
         if (i==0) name_array = "Rang   I:"; 
         if (i==1) name_array = "Rang  II:";
         if (i==2) name_array = "Rang III:";
         if (i==3) name_array = "Rang IV:";
         if (i==4) name_array = "Rang  V:";
         RepInfantryList[i][0].setName(name_array);
         
         for (int col = 1; col<RepInfantryList[i].length; col++)
         {
            number_array = Integer.parseInt(bufferedReader.readLine());
            RepInfantryList[i][col].setNumber(number_array);
            
            name_array = bufferedReader.readLine();
            RepInfantryList[i][col].setName(name_array);
            
            rang_array = bufferedReader.readLine();
            RepInfantryList[i][col].setRang(rang_array);
            
            equipment_weapon_array = bufferedReader.readLine();
            RepInfantryList[i][col].setEquipmentWeapon(equipment_weapon_array);
            
            equipment_armor_array = bufferedReader.readLine();
            RepInfantryList[i][col].setEquipmentArmor(equipment_armor_array);
            
            viewrange_array = Double.parseDouble(bufferedReader.readLine());
            RepInfantryList[i][col].setViewRange(viewrange_array);
            
            price_array = Double.parseDouble(bufferedReader.readLine());
            RepInfantryList[i][col].setPrice(price_array);
            
            //RepInfantryList[i][col].setDamage(RepInfantryWeaponList[row][column].getDamage());
            
            //RepInfantryList[i][col].setArmor(RepInfantryWeaponList[row][column].getArmor());
            
            accuracy_array = Integer.parseInt(bufferedReader.readLine());
            RepInfantryList[i][col].setAccuracy(accuracy_array);
            
            contentSupply_array = Integer.parseInt(bufferedReader.readLine());
            RepInfantryList[i][col].setContentSupply(contentSupply_array);
            
            int n = Integer.parseInt(bufferedReader.readLine());
            if (n==0) RepInfantryList[i][col].setShield(false);
            else RepInfantryList[i][col].setShield(true);
            
            squad_array = Integer.parseInt(bufferedReader.readLine());
            RepInfantryList[i][col].setSquad(squad_array);
                       
         }
         
      }
      bufferedReader.close();
      
      
      //Enginery
      bufferedReader = new BufferedReader(new FileReader ("Units\\Republic\\Enginery\\Unit List.txt"));
      RepEngineryList = new RepublicEnginery[5][];
      
      number_array = 0;
      for (int i = 0; i<RepEngineryList.length; i++)
      {
         next = true;
         int col = 0;
         while (next && (line = bufferedReader.readLine()) != null)
         {
            if (line.equals("Rang II:") || line.equals("Rang III:") || line.equals("Rang IV:") || line.equals("Rang V:"))
            {
               next = false;
            }
            else if (line.equals("Rang I:"))
            {
               next = true;
            }
            else
            {
               col++;
               number_array++;
               RepEnginerySize++;
            }
            
         }
         RepEngineryList[i] = new RepublicEnginery[col+1];
   	}
      bufferedReader.close();
      
      
      for (int i = 0; i<RepEngineryList.length;i++)
      {
         for (int col = 0; col<RepEngineryList[i].length; col++)
         {
            RepEngineryList[i][col] = new RepublicEnginery();
         }
      }
      
      bufferedReader = new BufferedReader(new FileReader("Units\\Republic\\Enginery\\Full List.txt"));
      for (int i = 0; i<RepEngineryList.length;i++)
      {
         if (i==0) name_array = "Rang   I:"; 
         if (i==1) name_array = "Rang  II:";
         if (i==2) name_array = "Rang III:";
         if (i==3) name_array = "Rang IV:";
         if (i==4) name_array = "Rang  V:";
         RepEngineryList[i][0].setName(name_array);
         
         for (int col = 1; col<RepEngineryList[i].length; col++)
         {
            number_array = Integer.parseInt(bufferedReader.readLine());
            RepEngineryList[i][col].setNumber(number_array);
            
            name_array = bufferedReader.readLine();
            RepEngineryList[i][col].setName(name_array);
            
            fullname_array = bufferedReader.readLine();
            RepEngineryList[i][col].setFullName(fullname_array);
            
            rang_array = bufferedReader.readLine();
            RepEngineryList[i][col].setRang(rang_array);
            
            equipment_weapon_array = bufferedReader.readLine();
            RepEngineryList[i][col].setEquipmentWeapon(equipment_weapon_array);
            
            equipment_armor_array = bufferedReader.readLine();
            RepEngineryList[i][col].setEquipmentArmor(equipment_armor_array);
            
            viewrange_array = Double.parseDouble(bufferedReader.readLine());
            RepEngineryList[i][col].setViewRange(viewrange_array);
            
            price_array = Double.parseDouble(bufferedReader.readLine());
            RepEngineryList[i][col].setPrice(price_array);
            
            damage_array = Double.parseDouble(bufferedReader.readLine());
            RepEngineryList[i][col].setDamage(damage_array);
            
            armor_array = Double.parseDouble(bufferedReader.readLine());
            RepEngineryList[i][col].setArmor(armor_array);
            
            accuracy_array = Integer.parseInt(bufferedReader.readLine());
            RepEngineryList[i][col].setAccuracy(accuracy_array);
            
            contentSupply_array = Integer.parseInt(bufferedReader.readLine());
            RepEngineryList[i][col].setContentSupply(contentSupply_array);
            
            crew_array = Integer.parseInt(bufferedReader.readLine());
            RepEngineryList[i][col].setCrew(crew_array);
            
            landing_array = Integer.parseInt(bufferedReader.readLine());
            RepEngineryList[i][col].setLanding(landing_array);
           
            int n = Integer.parseInt(bufferedReader.readLine());
            if (n==0) RepEngineryList[i][col].setShield(false);
            else RepEngineryList[i][col].setShield(true);
            
         }
         
      }
      bufferedReader.close();
      
      MainMenu();
   }//createArrays method
   
   public static String printRepublicWeapon() throws IOException
   {
      StringBuffer lines = new StringBuffer();
      for (int i = 0; i<RepWeaponList.length;i++)
      {
         lines.append("("+RepWeaponList[i].getNumber()+")");
         lines.append(" "+RepWeaponList[i].getName());
         lines.append("\n");
      }
      return lines.toString();
      
   }
   
   public static String printRepublicInfantry() throws IOException
   {
      StringBuffer lines = new StringBuffer();
      for (int i = 0; i<RepInfantryList.length;i++)
      {
         lines.append(" "+RepInfantryList[i][0].getName());
         lines.append("       ");
         for (int col = 1; col<RepInfantryList[i].length; col++)
         {
            lines.append("("+RepInfantryList[i][col].getNumber()+")");
            lines.append(" "+RepInfantryList[i][col].getName());
   		   lines.append("       ");
         }
         lines.append("\n");
         lines.append("\n");
      }
      return lines.toString();
      
   }
   
   public static String printRepublicEnginery() throws IOException
   {
      StringBuffer lines = new StringBuffer();
      for (int i = 0; i<RepEngineryList.length;i++)
      {
         lines.append(" "+RepEngineryList[i][0].getName());
         lines.append("       ");
         for (int col = 1; col<RepEngineryList[i].length; col++)
         {
            lines.append("("+RepEngineryList[i][col].getNumber()+")");
            lines.append(" "+RepEngineryList[i][col].getName());
   		   lines.append("       ");
         }
         lines.append("\n");
         lines.append("\n");
      }
      return lines.toString();
      
   }
   
   
   public static void MainMenu() throws IOException
   {
      String input; 
      int n;
                                          
      do
      {
         input = JOptionPane.showInputDialog("                [Main Menu]\n"+
                                             "**********************************\n"+
                                             "1. Start\n"+
                                             "2. Army Editor\n"+
                                             "3. Settings // Not Available Yet\n"+
                                             "4. Unit List\n"+
                                             "5. Tutorial // Not Available Yet\n"+
                                             "0. Exit\n"+
                                             "**********************************");
         n = 1;
         
         switch (input)
         {
            case "1":
            Start();
            n++;
            break;
            
            case "2":
            ArmyEditor();
            n++;
            break;
            
            case "3":
            Settings();
            n++;
            break;
            
            case "4":
            UnitList();
            n++;
            break;
            
            case "5":
            Tutorial();
            n++;
            break;
            
            case "0":
            ExitGame();
            n++;
            break;
            
            default:
            JOptionPane.showMessageDialog(null, "Error! Enter only values from 0 to 5.");
            
         } // Switch case
         
      } // while loop
      
      while (n==1);
   
   }// MainMenu method
   
   
   public static void Start() throws IOException
   {
      String input;
      int n;
      
      do
      {
         
         input = JOptionPane.showInputDialog("                [Start Menu]\n"+
                                             "**********************************\n"+
                                             "1. Begin the Battle\n"+
                                             "2. Choose Army\n"+
                                             "3. Load Game // Not Available Yet\n"+
                                             "0. Back to Main Menu\n"+
                                             "**********************************");
         n = 1;
         
         switch (input)
         {
            case "1":
            JOptionPane.showMessageDialog(null, "Sorry.. Not Available Yet");
            //Begin the Battle Process();
            //n++;
            break;
            
            case "2":
            ChooseArmy();
            n++;
            break;
            
            case "3":
            LoadGame();
            n++;
            break;
            
            case "0":
            MainMenu();
            n++;
            break;
            
            default:
            JOptionPane.showMessageDialog(null, "Error! Enter only values from 0 to 3.");
            
         } // Switch case
         
      }// while loop
            
      while (n==1);
      
   }// Start method
   
   
   public static void ChooseArmy() throws IOException
   {
      String input;
      int n;
      
      do
      {
      
         input = JOptionPane.showInputDialog("                [Choose Army]\n"+
                                             "**********************************\n"+
                                             "1. <Created Variations List>\n"+
                                             "0. Back\n"+
                                             "**********************************");
         n = 1;
         
         switch (input)
         {
            case "1":
            JOptionPane.showMessageDialog(null, "Sorry.. Not Available Yet");
            // <Created Variations List>
            //n++;
            break;
            
            case "0":
            Start();
            n++;
            break;
            
            default:
            JOptionPane.showMessageDialog(null, "Error! Enter only values 0 or 1.");
            
         } // Switch case
         
      }// while loop
      
      while (n==1);
   
   }// ChooseArmy method
   
   
   public static void LoadGame() throws IOException
   {
      String input;
      int n;
      
      do
      {
      
         input = JOptionPane.showInputDialog("                [Load Game]\n"+
                                             "**********************************\n"+
                                             "1. <Saved Games List> // Not Available Yet\n"+
                                             "0. Back\n"+
                                             "**********************************");
         n = 1;
         
         switch (input)
         {
            case "1":
            JOptionPane.showMessageDialog(null, "Sorry.. Not Available Yet");
            //<Saved Games List>();
            //n++;
            break;
            
            case "0":
            Start();
            n++;
            break;
            
            default:
            JOptionPane.showMessageDialog(null, "Error! Enter only values 0 or 1.");
            
         } // Switch case
         
      }// while loop
      
      while (n==1);
   
   } // LoadGame method
   
   
   public static void ArmyEditor() throws IOException
   {
      String input;
      int n;
      
      do
      {
      
         input = JOptionPane.showInputDialog("                [Army Editor]\n"+
                                             "**********************************\n"+
                                             "1. Create New Variation\n"+
                                             "2. Edit the Old Variation\n"+
                                             "0. Back to Main Menu\n"+
                                             "**********************************");

         n = 1;
         
         switch (input)
         {
            case "1":
            JOptionPane.showMessageDialog(null , "Sorry.. Not Available Yet");
            //<Army Creation Process>
            //n++;
            break;
            
            case "2":
            JOptionPane.showMessageDialog(null, "Sorry.. Not Available Yet");
            //<Created Variations List>
            //n++;
            break;
            
            case "0":
            MainMenu();
            n++;
            break;
            
            default:
            JOptionPane.showMessageDialog(null, "Error! Enter only values from 0 to 2.");
            
         } // Switch case
         
      }// while loop
      
      while (n==1);
   
   }// ChooseArmy method
   
   public static void Settings() throws IOException
   {
      String input;
      int n;
      
      BufferedReader bufferedReader = new BufferedReader(new FileReader ("Settings\\GameDifficulty.txt"));
   	String gamedifficulty = bufferedReader.readLine();
      bufferedReader.close();
      
      BufferedReader bufferedReader1 = new BufferedReader(new FileReader ("Settings\\GameSpeed.txt"));
   	String gamespeed = bufferedReader1.readLine();
      bufferedReader.close();
      
      do
      {
         input = JOptionPane.showInputDialog("                [Settings]\n"+
                                             "**********************************\n"+
                                             "1. Game Difficulty\n"+
                                             "2. Game Speed\n"+
                                             "0. Back to Main Menu\n"+
                                             "**********************************");
         n = 1;
         
         switch (input)
         {
            case "1":
            Switch_GameDifficulty(gamedifficulty);
            n++;
            break;
            
            case "2":
            Switch_GameSpeed(gamespeed);
            n++;
            break;
            
            case "0":
            MainMenu();
            n++;
            break;
            
            default:
            JOptionPane.showMessageDialog(null, "Error! Enter only values from 0 to 2.");
            
         } // Switch case
         
      }// while loop
      
      while (n==1);
   
   }// Settings method
   
   
   public static void Switch_GameDifficulty(String gamedifficulty) throws IOException
   {
      String input;
      int n;
      
      do
      {
      
         input = JOptionPane.showInputDialog("                [Choose Game Difficulty]\n"+
                                             "Current diffuculty: "+gamedifficulty+"\n"+
                                             "**********************************\n"+
                                             "1. Easy\n"+
                                             "2. Normal\n"+
                                             "3. Hard\n"+
                                             "0. Back\n"+
                                             "**********************************");

         n = 1;
         
         switch (input)
         {
            case "1":
            Difficulty_Change("easy");
            n++;
            break;
            
            case "2":
            Difficulty_Change("normal");
            n++;
            break;
            
            case "3":
            Difficulty_Change("hard");
            n++;
            break;
            
            case "0":
            Settings();
            n++;
            break;
            
            default:
            JOptionPane.showMessageDialog(null, "Error! Enter only values from 0 to 3.");
            
         } // Switch case
         
      }// while loop
      
      while (n==1);
   
   }// Switch_GameDiffuculty method
   
   
   public static void Difficulty_Change(String gamedifficulty) throws IOException
   {
      BufferedWriter buffered = new BufferedWriter(new FileWriter("Settings\\GameDifficulty.txt"));
      buffered.write(gamedifficulty);
      buffered.flush();
      
      Switch_GameDifficulty(gamedifficulty);
   
   }//Diffuculty_Easy method
   
   
   public static void Switch_GameSpeed(String gamespeed) throws IOException
   {
      String input;
      int n;
      
      do
      {
      
         input = JOptionPane.showInputDialog("                [Choose Game Speed]\n"+
                                             "Current speed: "+ gamespeed +"\n"+
                                             "**********************************\n"+
                                             "1. Slow(1 week per move)\n"+
                                             "2. Medium(2 weeks per move)\n"+
                                             "3. Fast(1 month per move)\n"+
                                             "0. Back\n"+
                                             "**********************************");

         n = 1;
         
         switch (input)
         {
            case "1":
            Speed_Change("slow");
            n++;
            break;
            
            case "2":
            Speed_Change("medium");
            n++;
            break;
            
            case "3":
            Speed_Change("fast");
            n++;
            break;
            
            case "0":
            Settings();
            n++;
            break;
            
            default:
            JOptionPane.showMessageDialog(null, "Error! Enter only values from 0 to 3.");
            
         } // Switch case
         
      }// while loop
      
      while (n==1);
   
   }// Switch_GameSpeed method
   
   
   public static void Speed_Change(String gamespeed) throws IOException
   {
      BufferedWriter buffered = new BufferedWriter(new FileWriter("Settings\\GameSpeed.txt"));
      buffered.write(gamespeed);
      buffered.flush();
      
      Switch_GameSpeed(gamespeed);
   
   }//Speed_Change method
   
   
   public static void UnitList() throws IOException
   {
      String input;
      int n;
      
      do
      {
      
         input = JOptionPane.showInputDialog("                [Unit List]\n"+
                                             "**********************************\n"+
                                             "1. Show Units\n"+
                                             "2. Edit Unit List\n"+
                                             "3. Armory\n"+
                                             "0. Back to Main Menu\n"+
                                             "**********************************");

         n = 1;
         
         switch (input)
         {
            case "1":
            UnitList_ChooseFraction();
            n++;
            break;
            
            case "2":
            UnitList_Edit();
            n++;
            break;
            
            case "3":
            UnitList_ShowRepublicWeapon();
            n++;
            break;
            
            case "0":
            MainMenu();
            n++;
            break;
            
            default:
            JOptionPane.showMessageDialog(null, "Error! Enter only values from 0 to 2");
            
         } // Switch case
         
      }// while loop
      
      while (n==1);
   
   }//UnitList method
   
   
   public static void UnitList_ChooseFraction() throws IOException
   {
      String input;
      int n;
      
      do
         {
         
            String fractioninput = JOptionPane.showInputDialog("Choose unit's fraction\n"+
                                                          "**********************************\n"+
                                                          "1. Republic\n"+
                                                          "2. Confederation of Independent Systems\n"+
                                                          "3. Back\n"+
                                                          "0. Exit to Main Menu\n"+
                                                          "**********************************");
                    n = 1;
             
                    switch (fractioninput)
                    {
                        case "1":
                        UnitList_ChooseRepublicCombatArm();
                        n++;
                        break;
                           
                        case "2":
                        JOptionPane.showMessageDialog(null, "Sorry.. Not Available Yet");
                        //UnitList_ChooseCisCombatArm();
                        //n++;
                        break;
                        
                        case "3":
                        UnitList();
                        n++;
                        break;
                        
                        case "0":
                        MainMenu();
                        n++;
                        break;
                        
                        default:
                        JOptionPane.showMessageDialog(null, "Error! Enter only values from 0 to 3.");
            
                     } // Switch case
         
                                      
         }
         while(n==1);
      
   }// UnitList_All method
   
   
   public static void UnitList_ChooseRepublicCombatArm() throws IOException
   {
      String input;
      int n;
      
      do
            {
            
               String combatArminput = JOptionPane.showInputDialog("Choose Republic's Combat Arm\n"+
                                                             "**********************************\n"+
                                                             "1. Infantry\n"+
                                                             "2. Enginery\n"+
                                                             "3. Space Fleet\n"+
                                                             "4. Back\n"+
                                                             "0. Exit to Main Menu\n"+
                                                             "**********************************");
                       n = 1;
         
                       switch (combatArminput)
                       {
                           case "1":
                           UnitList_ShowRepublicInfantry();
                           n++;
                           break;
                           
                           case "2":
                           UnitList_ShowRepublicEnginery();
                           n++;
                           break;
                           
                           case "3":
                           JOptionPane.showMessageDialog(null, "Sorry.. Not Available Yet");
                           //UnitList_ShowRepublicSpaceFleet();
                           //n++;
                           break;
                           
                           case "4":
                           UnitList_ChooseFraction();
                           n++;
                           break;
                        
                           case "0":
                           MainMenu();
                           n++;
                           break;
                           
                           default:
                           JOptionPane.showMessageDialog(null, "Error! Enter only values from 0 to 4.");
            
                        } // Switch case
         
                                      
            }
            while(n==1);
   
   }
   
   public static void UnitList_ShowRepublicWeapon() throws IOException
   { 
      String input;
      int n;
      
      do
      {
            
         String combatArminput = JOptionPane.showInputDialog("Republic Weapon Units\n"+
                                                             printRepublicWeapon()+"\n"+
                                                             "**********************************\n"+
                                                             "0. Back\n"+
                                                             "**********************************");
          n = 1;
         
          switch (combatArminput)
          {
                           
             case "0":
             UnitList();
             n++;
             break;
                           
             default:
             for (int i = 0; i<RepWeaponList.length;i++)
             {
                  if ( Integer.parseInt(combatArminput)==RepWeaponList[i].getNumber())
                  {
                     JOptionPane.showMessageDialog(null, RepWeaponList[i].getDescription()+"\n");
                     UnitList_ShowRepublicWeapon();
                   }
                  if (Integer.parseInt(combatArminput)>RepInfantrySize)
                  {
                      JOptionPane.showMessageDialog(null, "Error! Enter only values from 0.");
                      UnitList_ShowRepublicWeapon();
                }
               
               }
            
            } // Switch case
         
                                      
      }
      while(n==1);
   }
   
   public static void UnitList_ShowRepublicInfantry() throws IOException
   { 
      String input;
      int n;
      
      do
      {
            
         String combatArminput = JOptionPane.showInputDialog("Republic Infantry Units\n"+
                                                             printRepublicInfantry()+"\n"+
                                                             "**********************************\n"+
                                                             "0. Back\n"+
                                                             "**********************************");
          n = 1;
         
          switch (combatArminput)
          {
                           
             case "0":
             UnitList_ChooseRepublicCombatArm();
             n++;
             break;
                           
             default:
             for (int i = 0; i<RepInfantryList.length;i++)
             {
                 for (int col = 0; col<RepInfantryList[i].length; col++)
                 {
                  if ( Integer.parseInt(combatArminput)==RepInfantryList[i][col].getNumber())
                  {
                     JOptionPane.showMessageDialog(null, RepInfantryList[i][col].getDescription()+"\n");
                     UnitList_ShowRepublicInfantry();
                   }
                  if (Integer.parseInt(combatArminput)>RepInfantrySize)
                  {
                      JOptionPane.showMessageDialog(null, "Error! Enter only values from 0.");
                      UnitList_ShowRepublicInfantry();
                  }
                
                }
               
               }
            
            } // Switch case
         
                                      
      }
      while(n==1);
   }
   
   public static void UnitList_ShowRepublicEnginery() throws IOException
   { 
      String input;
      int n;
      
      do
      {
            
         String combatArminput = JOptionPane.showInputDialog("Republic Enginery Units\n"+
                                                             printRepublicEnginery()+"\n"+
                                                             "**********************************\n"+
                                                             "0. Back\n"+
                                                             "**********************************");
          n = 1;
         
          switch (combatArminput)
          {
                           
             case "0":
             UnitList_ChooseRepublicCombatArm();
             n++;
             break;
                           
             default:
             for (int i = 0; i<RepEngineryList.length;i++)
             {
                 for (int col = 0; col<RepEngineryList[i].length; col++)
                 {
                  if ( Integer.parseInt(combatArminput)==RepEngineryList[i][col].getNumber())
                  {
                     JOptionPane.showMessageDialog(null, RepEngineryList[i][col].getDescription()+"\n");
                     UnitList_ShowRepublicEnginery();
                   }
                  if (Integer.parseInt(combatArminput)>RepEnginerySize)
                  {
                      JOptionPane.showMessageDialog(null, "Error! Enter only values from 0.");
                      UnitList_ShowRepublicEnginery();
                  }
                }
               }
            
            } // Switch case
         
                                      
      }
      while(n==1);
   }
   
   /*
   public static void UnitList_ChooseCisCombatArm() throws IOException
   {
      String input;
      int n;
      
      do
            {
            
               String combatArminput = JOptionPane.showInputDialog("Choose CIS' Combat Arm\n"+
                                                             "**********************************\n"+
                                                             "1. Infantry\n"+
                                                             "2. Enginery\n"+
                                                             "3. Space Fleet\n"+
                                                             "4. Back"+
                                                             "0. Exit to Main Menu\n"+
                                                             "**********************************");
                       n = 1;
         
                       switch (combatArminput)
                       {
                           case "1":
                           UnitList_ShowCisInfantry();
                           n++;
                           break;
                           
                           case "2":
                           UnitList_ShowCisEnginery();
                           n++;
                           break;
                           
                           case "3":
                           JOptionPane.showMessageDialog(null, "Sorry.. Not Available Yet");
                           //UnitList_ShowCisSpaceFleet();
                           //n++;
                           break;
                           
                           case "4":
                           UnitList_ChooseFraction();
                           n++;
                           break;
                        
                           case "0":
                           MainMenu();
                           n++;
                           break;
                           
                           default:
                           JOptionPane.showMessageDialog(null, "Error! Enter only values from 0 to 4.");
            
                        } // Switch case
         
                                      
            }
            while(n==1);
   
   }
   
   public static void UnitList_ShowCisInfantry() throws IOException
   {
      String input;
      int n;
      
      do
            {
            
               String combatArminput = JOptionPane.showInputDialog("CIS Infantry Units\n"+
                                                             Array.Print(CisInfantryList)+"/n"+
                                                             "**********************************\n"+
                                                             "0. Back\n"+
                                                             "**********************************");
                       n = 1;
         
                       switch (combatArminput)
                       {
                           
                           case "0":
                           MainMenu();
                           n++;
                           break;
                           
                           default:
                           JOptionPane.showMessageDialog(null, "Error! Enter only values from 0.");
            
                        } // Switch case
         
                                      
            }
            while(n==1);
   }
   
   public static void UnitList_ShowCisEnginery()
   {
      String input;
      int n;
      
      do
            {
            
               String combatArminput = JOptionPane.showInputDialog("CIS Infantry Units\n"+
                                                             PrintArray(CisEngineryList)+"/n"+
                                                             "**********************************\n"+
                                                             "0. Back\n"+
                                                             "**********************************");
                       n = 1;
         
                       switch (combatArminput)
                       {
                           
                           case "0":
                           MainMenu();
                           n++;
                           break;
                           
                           default:
                           JOptionPane.showMessageDialog(null, "Error! Enter only values from 0.");
            
                        } // Switch case
         
                                      
            }
            while(n==1);
   }
   */
   
   public static void UnitList_Edit() throws IOException
   {
      String input;
      int n;
      
      do
      {
      
         input = JOptionPane.showInputDialog("                [Edit Unit List]\n"+
                                             "**********************************\n"+
                                             "1. Add Units(Only Infantry Units)\n"+
                                             "2. Delete Units(Only for added units!)\n"+
                                             "3. Edit Unit's Parameters(Only for added units!)\n"+
                                             "0. Back to Main Menu\n"+
                                             "**********************************");
         n = 1;
         
         switch (input)
         {
            case "1":
            Unit_Add();
            n++;
            break;
            
            case "2":
            JOptionPane.showMessageDialog(null, "Sorry.. Not Available Yet");
            //UnitList_Remove();
            //n++;
            break;
            
            case "3":
            JOptionPane.showMessageDialog(null, "Sorry.. Not Available Yet");
            //UnitList_Settings();
            //n++;
            break;
                        
            case "0":
            UnitList();
            n++;
            break;
            
            default:
            JOptionPane.showMessageDialog(null, "Error! Enter only values 0 or 1.");
            
         } // Switch case
         
      }// while loop
      
      while (n==1);
   
   }//UnitList_Edit method
   
   
   public static void Unit_Add() throws IOException
   {
      name_array = JOptionPane.showInputDialog("Enter the Name of new Unit.");
      int n;
            
            do
            {
            
               String fractioninput = JOptionPane.showInputDialog("Choose unit's fraction\n"+
                                                             "**********************************\n"+
                                                             "1. Republic\n"+
                                                             "2. Confederation of Independent Systems\n"+
                                                             "0. Back\n"+
                                                             "**********************************");
                       n = 1;
         
                       switch (fractioninput)
                       {
                           case "1":
                           fraction_array = "Republic";
                           combatArm_array = "Infantry";
                           Unit_Add_RepBasic();
                           n++;
                           break;
                           
                           case "2":
                           JOptionPane.showMessageDialog(null, "Sorry.. Not Available Yet");
                           //String fraction = "Confederation of Independent Systems";
                           //n++;
                           break;
                           
                           case "0":
                           Unit_Add();
                           n++;
                           break;
                           
                           default:
                           JOptionPane.showMessageDialog(null, "Error! Enter only values 0 or 2.");
            
                        } // Switch case

         
                                      
            }
            while(n==1);
    
   }//Unit_Add method
   
   public static void Unit_Add_RepBasic() throws IOException
   {
      String input;
      int n;
      
      do
      {
            
         input = JOptionPane.showInputDialog("Choose Unit's Basic\n"+
                                                    printRepublicInfantry()+"\n"+
                                                    "**********************************\n"+
                                                    "0. Back\n"+
                                                    "**********************************");
          n = 1;
         
          switch (input)
          {
                           
             case "0":
             Unit_Add();
             n++;
             break;
                           
             default:
             for (int i = 0; i<RepInfantryList.length;i++)
             {
                 for (int col = 1; col<RepInfantryList[i].length; col++)
                 {
                  if ( Integer.parseInt(input)==RepInfantryList[i][col].getNumber())
                  {
                     Unit_Add_RepWeapon(i, col);
                     n++;
                  }
                  if (Integer.parseInt(input)>RepInfantrySize)
                  {
                      JOptionPane.showMessageDialog(null, "Error! Enter only values from 0.");
                      UnitList_ShowRepublicInfantry();
                  }
                
                }
               
               }
            
            } // Switch case
         
                                      
      }
      while(n==1);
   
   }//Unit_Add_ChooseRepBacis method
   
   public static void Unit_Add_RepWeapon(int i, int col) throws IOException
   {
      String input;
      int n;
      
      do
      {
            
         input = JOptionPane.showInputDialog("Choose Unit's Weapon\n"+
                                             printRepublicWeapon()+"\n"+
                                             "**********************************\n"+
                                             "0. Back\n"+
                                             "**********************************");
          n = 1;
         
          switch (input)
          {
                           
             case "0":
             UnitList_ChooseRepublicCombatArm();
             n++;
             break;    
             default:
             n++;
                 for (int j = 1; j < RepWeaponList.length; j++)
                 {
                     if ( Integer.parseInt(input)==RepWeaponList[j].getNumber())
                     {
                        String fileName = "Units\\Republic\\Infantry\\Full List.txt";
                        
                        int SIZE = FileEdit.LineCount(fileName);
	                     BufferedReader bufferedReader = new BufferedReader(new FileReader (fileName));
   	                  
                        for (int t = 0; t< (SIZE-1); t++)
                        {
   	                  	
                           if(bufferedReader.readLine().equals(""+RepInfantryList[i][RepInfantryList[i].length].getNumber()))
                           {
                              Units_List.add(""+(++RepInfantrySize));
                              Units_List.add(name_array);
                              Units_List.add(RepInfantryList[i][col].getRang());
                              Units_List.add(RepInfantryList[i][col].getEquipmentWeapon());
                              Units_List.add(RepInfantryList[i][col].getEquipmentArmor());
                              Units_List.add(""+RepInfantryList[i][col].getViewRange());
                              Units_List.add(""+(RepInfantryList[i][col].getPrice()+RepWeaponList[j].getPrice()));
                              Units_List.add(""+RepWeaponList[j].getDamage());
                              Units_List.add(""+RepInfantryList[i][col].getArmor());
                              Units_List.add(""+RepInfantryList[i][col].getAccuracy());
                              Units_List.add(""+RepWeaponList[j].getSpeed());
                              Units_List.add(""+RepInfantryList[i][col].getContentSupply());
                              if (RepInfantryList[i][col].getShield()) Units_List.add("1"); else Units_List.add("0");
                              Units_List.add(""+RepInfantryList[i][col].getSquad());
                           }
                           Units_List.add(bufferedReader.readLine());
   	                  }
                        
                        bufferedReader.close();
                        
	                     BufferedWriter buffered = new BufferedWriter(new FileWriter(fileName));
                        
                        for (int t = 0; t<=Units_List.size(); t++)
	                     {
                           buffered.write(Units_List.get(t));
                           buffered.newLine();
                        }
                        buffered.flush();
                        
                        n++;
                     }
                     if (Integer.parseInt(input)>RepWeaponList.length)
                     {
                         JOptionPane.showMessageDialog(null, "Error! Enter only values from 0.");
                         UnitList_ShowRepublicInfantry();
                     }
                     
                     String fileName = "Units\\Republic\\Infantry\\Unit List.txt";
                        
                        int SIZE = FileEdit.LineCount(fileName);
	                     BufferedReader bufferedReader = new BufferedReader(new FileReader (fileName));
   	                  
                        for (int t = 0; t< (SIZE-1); t++)
                        {
   	                  	Units_List.add(bufferedReader.readLine());
                           if (i==0)
                           if(bufferedReader.readLine().equals("Rang I:"))
                           {
                              Units_List.add("("+(++RepInfantrySize)+")");
                              Units_List.add(name_array);
                           }
                           if (i==1)
                           if(bufferedReader.readLine().equals("Rang II:"))
                           {
                              Units_List.add("("+(++RepInfantrySize)+")");
                              Units_List.add(name_array);
                           }
                           if (i==2)
                           if(bufferedReader.readLine().equals("Rang III:"))
                           {
                              Units_List.add("("+(++RepInfantrySize)+")");
                              Units_List.add(name_array);
                           }
                           if (i==3)
                           if(bufferedReader.readLine().equals("Rang IV:"))
                           {
                              Units_List.add("("+(++RepInfantrySize)+")");
                              Units_List.add(name_array);
                           }
                           if (i==4)
                           if(bufferedReader.readLine().equals("Rang V:"))
                           {
                              Units_List.add("("+(++RepInfantrySize)+")");
                              Units_List.add(name_array);
                           }
                           
   	                  }
                        
                        bufferedReader.close();
                        
	                     BufferedWriter buffered = new BufferedWriter(new FileWriter(fileName));
                        
                        for (int t = 0; t<=Units_List.size(); t++)
	                     {
                           buffered.write(Units_List.get(t));
                           buffered.newLine();
                        }
                        buffered.flush();
                        
                        n++;
                     }
                     if (Integer.parseInt(input)>RepWeaponList.length)
                     {
                         JOptionPane.showMessageDialog(null, "Error! Enter only values from 0.");
                         UnitList_ShowRepublicInfantry();
                     }
                 
            } // Switch case
         
                                      
      }
      while(n==1);
      
    CreateArrays_Rep();
    JOptionPane.showMessageDialog(null, "Unit Addition Successful");
    UnitList();
   }//Unit_Add_RepWeapon method
   
   public static void CreateArrays_Rep() throws IOException
   {
      int size;
      String fileName;
      String line=null, str;
      boolean next = true;
      BufferedReader bufferedReader;
      RepInfantrySize=0;
      RepEnginerySize=0;
      
      bufferedReader = new BufferedReader(new FileReader("Units\\Equipment\\Weapons\\Republic\\Weapon List.txt"));
      number_array = 0;
      while ((line = bufferedReader.readLine())!=null)   
         {
               number_array++;
               RepWeaponSize++;
         
         }
      bufferedReader.close();
      RepWeaponList = new RepublicWeapon[RepWeaponSize];
      for (int i = 0; i< RepWeaponSize; i++)
      {
         RepWeaponList[i] = new RepublicWeapon();
      }
      
      bufferedReader = new BufferedReader(new FileReader("Units\\Equipment\\Weapons\\Republic\\Full Weapon List.txt"));
      for (int i = 0; i<RepWeaponList.length;i++)
      {
            number_array = Integer.parseInt(bufferedReader.readLine());
            RepWeaponList[i].setNumber(number_array);
            
            name_array = bufferedReader.readLine();
            RepWeaponList[i].setName(name_array);
            
            fullname_array = bufferedReader.readLine();
            RepWeaponList[i].setFullName(fullname_array);
            
            price_array = Double.parseDouble(bufferedReader.readLine());
            RepWeaponList[i].setPrice(price_array);
            
            damage_array = Double.parseDouble(bufferedReader.readLine());
            RepWeaponList[i].setDamage(damage_array);
            
            accuracy_array = Integer.parseInt(bufferedReader.readLine());
            RepWeaponList[i].setAccuracy(accuracy_array);
            
            speed_array = Integer.parseInt(bufferedReader.readLine());
            RepWeaponList[i].setSpeed(speed_array);
            
      }
      bufferedReader.close();
      
      
      bufferedReader = new BufferedReader(new FileReader ("Units\\Republic\\Infantry\\Unit List.txt"));
      RepInfantryList = new RepublicInfantry[5][];
      number_array = 0;
      for (int i = 0; i < RepInfantryList.length; i++)
      {
         next = true;
         int col = 0;
         while (next && (line = bufferedReader.readLine())!=null)   
         {
            
            if (line.equals("Rang II:") || line.equals("Rang III:") || line.equals("Rang IV:") || line.equals("Rang V:"))
            {
               next = false;
            }
            else if (line.equals("Rang I:"))
            {
               next = true;
            }
            else
            {
               col++;
               number_array++;
               RepInfantrySize++;
            }
            
         }
         RepInfantryList[i] = new RepublicInfantry[col+1];
   	}
      bufferedReader.close();
      
      for (int i = 0; i<RepInfantryList.length;i++)
      {
         for (int col = 0; col<RepInfantryList[i].length; col++)
         {
            RepInfantryList[i][col] = new RepublicInfantry();
         }
      }
      
      bufferedReader = new BufferedReader(new FileReader("Units\\Republic\\Infantry\\Full List.txt"));
      for (int i = 0; i<RepInfantryList.length;i++)
      {
         if (i==0) name_array = "Rang   I:"; 
         if (i==1) name_array = "Rang  II:";
         if (i==2) name_array = "Rang III:";
         if (i==3) name_array = "Rang IV:";
         if (i==4) name_array = "Rang  V:";
         RepInfantryList[i][0].setName(name_array);
         
         for (int col = 1; col<RepInfantryList[i].length; col++)
         {
            number_array = Integer.parseInt(bufferedReader.readLine());
            RepInfantryList[i][col].setNumber(number_array);
            
            name_array = bufferedReader.readLine();
            RepInfantryList[i][col].setName(name_array);
            
            rang_array = bufferedReader.readLine();
            RepInfantryList[i][col].setRang(rang_array);
            
            equipment_weapon_array = bufferedReader.readLine();
            RepInfantryList[i][col].setEquipmentWeapon(equipment_weapon_array);
            
            equipment_armor_array = bufferedReader.readLine();
            RepInfantryList[i][col].setEquipmentArmor(equipment_armor_array);
            
            viewrange_array = Double.parseDouble(bufferedReader.readLine());
            RepInfantryList[i][col].setViewRange(viewrange_array);
            
            price_array = Double.parseDouble(bufferedReader.readLine());
            RepInfantryList[i][col].setPrice(price_array);
            
            //RepInfantryList[i][col].setDamage(RepInfantryWeaponList[row][column].getDamage());
            
            //RepInfantryList[i][col].setArmor(RepInfantryWeaponList[row][column].getArmor());
            
            accuracy_array = Integer.parseInt(bufferedReader.readLine());
            RepInfantryList[i][col].setAccuracy(accuracy_array);
            
            contentSupply_array = Integer.parseInt(bufferedReader.readLine());
            RepInfantryList[i][col].setContentSupply(contentSupply_array);
            
            int n = Integer.parseInt(bufferedReader.readLine());
            if (n==0) RepInfantryList[i][col].setShield(false);
            else RepInfantryList[i][col].setShield(true);
            
            squad_array = Integer.parseInt(bufferedReader.readLine());
            RepInfantryList[i][col].setSquad(squad_array);
                       
         }
         
      }
      bufferedReader.close();
      
      
      //Enginery
      bufferedReader = new BufferedReader(new FileReader ("Units\\Republic\\Enginery\\Unit List.txt"));
      RepEngineryList = new RepublicEnginery[5][];
      
      number_array = 0;
      for (int i = 0; i<RepEngineryList.length; i++)
      {
         next = true;
         int col = 0;
         while (next && (line = bufferedReader.readLine()) != null)
         {
            if (line.equals("Rang II:") || line.equals("Rang III:") || line.equals("Rang IV:") || line.equals("Rang V:"))
            {
               next = false;
            }
            else if (line.equals("Rang I:"))
            {
               next = true;
            }
            else
            {
               col++;
               number_array++;
               RepEnginerySize++;
            }
            
         }
         RepEngineryList[i] = new RepublicEnginery[col+1];
   	}
      bufferedReader.close();
      
      
      for (int i = 0; i<RepEngineryList.length;i++)
      {
         for (int col = 0; col<RepEngineryList[i].length; col++)
         {
            RepEngineryList[i][col] = new RepublicEnginery();
         }
      }
      
      bufferedReader = new BufferedReader(new FileReader("Units\\Republic\\Enginery\\Full List.txt"));
      for (int i = 0; i<RepEngineryList.length;i++)
      {
         if (i==0) name_array = "Rang   I:"; 
         if (i==1) name_array = "Rang  II:";
         if (i==2) name_array = "Rang III:";
         if (i==3) name_array = "Rang IV:";
         if (i==4) name_array = "Rang  V:";
         RepEngineryList[i][0].setName(name_array);
         
         for (int col = 1; col<RepEngineryList[i].length; col++)
         {
            number_array = Integer.parseInt(bufferedReader.readLine());
            RepEngineryList[i][col].setNumber(number_array);
            
            name_array = bufferedReader.readLine();
            RepEngineryList[i][col].setName(name_array);
            
            fullname_array = bufferedReader.readLine();
            RepEngineryList[i][col].setFullName(fullname_array);
            
            rang_array = bufferedReader.readLine();
            RepEngineryList[i][col].setRang(rang_array);
            
            equipment_weapon_array = bufferedReader.readLine();
            RepEngineryList[i][col].setEquipmentWeapon(equipment_weapon_array);
            
            equipment_armor_array = bufferedReader.readLine();
            RepEngineryList[i][col].setEquipmentArmor(equipment_armor_array);
            
            viewrange_array = Double.parseDouble(bufferedReader.readLine());
            RepEngineryList[i][col].setViewRange(viewrange_array);
            
            price_array = Double.parseDouble(bufferedReader.readLine());
            RepEngineryList[i][col].setPrice(price_array);
            
            damage_array = Double.parseDouble(bufferedReader.readLine());
            RepEngineryList[i][col].setDamage(damage_array);
            
            armor_array = Double.parseDouble(bufferedReader.readLine());
            RepEngineryList[i][col].setArmor(armor_array);
            
            accuracy_array = Integer.parseInt(bufferedReader.readLine());
            RepEngineryList[i][col].setAccuracy(accuracy_array);
            
            contentSupply_array = Integer.parseInt(bufferedReader.readLine());
            RepEngineryList[i][col].setContentSupply(contentSupply_array);
            
            crew_array = Integer.parseInt(bufferedReader.readLine());
            RepEngineryList[i][col].setCrew(crew_array);
            
            landing_array = Integer.parseInt(bufferedReader.readLine());
            RepEngineryList[i][col].setLanding(landing_array);
           
            int n = Integer.parseInt(bufferedReader.readLine());
            if (n==0) RepEngineryList[i][col].setShield(false);
            else RepEngineryList[i][col].setShield(true);
            
         }
         
      }
      bufferedReader.close();
      
      UnitList();
   }//createArrays method
   
   
     
   public static void Tutorial() throws IOException
   {
      String input;
      int n;
      
      do
      {
      
         input = JOptionPane.showInputDialog("                [Tutorial]\n"+
                                             "**********************************\n"+
                                             "1. Begin Tutorial\n"+
                                             "0. Back to Main Menu\n"+
                                             "**********************************");

         n = 1;
         
         switch (input)
         {
            case "1":
            JOptionPane.showMessageDialog(null, "Sorry.. Not Available Yet");
            //<Tutorial Process>
            //n++;
            break;
                        
            case "0":
            MainMenu();
            n++;
            break;
            
            default:
            JOptionPane.showMessageDialog(null, "Error! Enter only values 0 or 1.");
            
         } // Switch case
         
      }// while loop
      
      while (n==1);
   
   }//Tutorial Method
   
   
   public static void ExitGame() throws IOException
   {
      String input;
      int n;
      
      do
      {
      
         input = JOptionPane.showInputDialog("                [Exit?]\n"+
                                             "**********************************\n"+
                                             "Are sure want to exit the game?\n"+
                                             "1. Yes\n"+
                                             "0. Back to Main Menu\n"+
                                             "**********************************");

         n = 1;
         
         switch (input)
         {
            case "1":
            System.exit(2);
            n++;
            break;
            
            case "0":
            MainMenu();
            n++;
            break;
            
            default:
            JOptionPane.showMessageDialog(null, "Error! Enter only values 0 or 1.");
            
         } // Switch case
         
      }// while loop
      
      while (n==1);
   
   }// ExitGame method
   
}// Project class