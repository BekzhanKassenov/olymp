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
                                             "3. Armory"+
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
            JOptionPane.showMessageDialog(null, "Sorry.. Not Available Yet");
            //n++;
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
                                                          "3. Back"+
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
                        UnitList_ChooseCisCombatArm();
                        n++;
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
                                                             "3. Space Fleet\n"
                                                             "4. Back"+
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
   
   public static void UnitList_ShowRepublicInfantry()
   {
      String input;
      int n;
      
      do
            {
            
               String combatArminput = JOptionPane.showInputDialog("Republic Infantry Units\n"+
                                                             PrintArray(RepInfantryList)+"/n"
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
   
   public static void UnitList_ShowRepublicEnginery()
   {
      String input;
      int n;
      
      do
            {
            
               String combatArminput = JOptionPane.showInputDialog("Republic Infantry Units\n"+
                                                             PrintArray(RepEngineryList)+"/n"
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
                                                             "3. Space Fleet\n"
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
   
   public static void UnitList_ShowCisInfantry()
   {
      String input;
      int n;
      
      do
            {
            
               String combatArminput = JOptionPane.showInputDialog("CIS Infantry Units\n"+
                                                             PrintArray(CisInfantryList)+"/n"
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
                                                             PrintArray(CisEngineryList)+"/n"
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
   
   
   public static void UnitList_Edit() throws IOException
   {
      String input;
      int n;
      
      do
      {
      
         input = JOptionPane.showInputDialog("                [Edit Unit List]\n"+
                                             "**********************************\n"+
                                             "1. Add Units\n"+
                                             "2. Delete Units(Only for added units!)\n"+
                                             "3. Edit Unit's Parameters(Only for added units!)\n"+
                                             "0. Back to Main Menu\n"+
                                             "**********************************");
         n = 1;
         
         switch (input)
         {
            case "1":
            JOptionPane.showMessageDialog(null, "Sorry.. Not Available Yet");
            //Unit_Add();
            //n++;
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
   
   /*
   public static void Unit_Add() throws IOException
   {
      String name = JOptionPane.showInputDialog("Enter the Name of new Unit.");
            
            do
            {
            
               String fractioninput = JOptionPane.showInputDialog("Choose unit's fraction\n"+
                                                             "**********************************\n"+
                                                             "1. Republic\n"+
                                                             "2. Confederation of Independent Systems\n"+
                                                             "0. Back to Main Menu\n"+
                                                             "**********************************");
                       n = 1;
         
                       switch (fractioninput)
                       {
                           case "1":
                           String fraction = "Republic";
                           n++;
                           break;
                           
                           case "2":
                           String fraction = "Confederation of Independent Systems";
                           n++;
                           break;
                           
                           default:
                           JOptionPane.showMessageDialog(null, "Error! Enter only values 0 or 2.");
            
                        } // Switch case
         
                                      
            }
            while(n==1);
            
            do
            {
            
               String combatArminput = JOptionPane.showInputDialog("Choose unit's Combat Arm\n"+
                                                             "**********************************\n"+
                                                             "1. Infantry\n"+
                                                             "2. Enginery\n"+
                                                             "3. Space Fleet\n"
                                                             "0. Back\n"+
                                                             "**********************************");
                       n = 1;
         
                       switch (combatArminput)
                       {
                           case "1":
                           String fraction = "Infantry";
                           n++;
                           break;
                           
                           case "2":
                           String fraction = "Enginery";
                           n++;
                           break;
                           
                           case "3":
                           String fraction = "Space Fleet";
                           n++;
                           break;
                           
                           default:
                           JOptionPane.showMessageDialog(null, "Error! Enter only values from 0 to 3.");
            
                        } // Switch case
         
                                      
            }
            while(n==1);
   
   }//Unit_Add method
   */