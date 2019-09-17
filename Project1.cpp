// name: Andrew Bradley, acb0019
// partner: none
//filename: Project1.cpp
//due date: 11/09/2018
//collaboration: none
//problem: Create a text-based adventure game.

#include <ctime>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

/*Menu class. Displays menu options and handles user's selection. Handles entries
 that are out of bounds. Parent to System class. Contains the function to immediately
 quit.*/ 
class Menu {

private:
   
   int choice;
   string name;

public:

   /*Constructor*/
   Menu();
   /*Start menu. Returns user choice.*/
   int startMenu();
   /*Game menu. Returns user choice.*/
   int gameMenu();
   /*Quits game.*/
   void quit();
 };
 
 /*System class. Child of Menu. The gameplay is run through this class.*/
class System : Menu {
 
   
 public:
   /*Constructor*/
   System();
   /*Controls game*/
   void runGame();
   /*Starts new game.*/
   void newGame(Menu menu, class Character player);
   /*Runs encounters*/
   void encounters(Character& player);
   /*Edits high score list.*/
   void editScoreList(Character player);
   /*Gets high score list.*/
   void getScores();
  
  };
  
 /*Encounter class. Creates the various encounter interactions
   that may occur. Appropriately adjusts the attributes of the
   Character in gameplay.*/
class Encounter {
 
   public:
      /*Constructor*/
   Encounter();
      /*Nothing happens.*/
   void nothing(Character& player);
      /*Encounter a puzzle.*/
   void puzzle(Character& player);
      /*Encounter a professor.*/
   void professor(Character& player);
      /*Ecounter grad student.*/
   void gradStudent(Character& player);
      /*Encounter grunt work.*/
   void gruntWork(Character& player);
      /*Encounter papers.*/
   void gradePapers(Character& player);
      
   };
      
  
 /*Character class. Handles all attributes related to the character.*/ 
class Character {
 
 private:
   string name;
   int score;
   int intelligence;
   int time;
   int money;
   int steps;
 
   
  public:
   /*Constructor1.*/
   Character(int score);
   /*Constructor2.*/
   Character();
   /*Adds to character intelligence.*/
   void gainIntel();
   /*Decrease character intelligence.*/
   void loseIntel();
   /*Increases character time.*/
   void loseOneTime();
   /*Decreases character time.*/
   void loseTime();
   /*Increases character money.*/
   void gainMoney();
   /*Decreases character money.*/
   void loseMoney();
   /*Decrease step count by 1.*/
   void takeStep();
   /*Character attributes.*/
   void getAttributes();
   /*Calculate score.*/
   int calcScore();
   /*Character score.*/
   int getScore();
   /*Character intelligence.*/
   int getIntel();
   /*Character time.*/
   int getTime();
   /*Character money.*/
   int getMoney();
   /*Charcter steps.*/
   int getSteps();
   /*Sets score.*/
   void setScore(int score);
   /*Sets name.*/
   void setName(string name);
   /*Gets name.*/
   string getName();
      
   
   
 };
 
 /**************************************************************
 ***************************************************************
 MAIN FUNCTION**************************************************
 **************************************************************/
 
int main() {

 //Random time generator;
   srand (time (NULL));
   //Runs game.
   System sys;
   sys.runGame();
 
}
 
 /*******************************************************************
 **********Class Functions for Menu**********************************
 ********************************************************************
 */
 
 /*Constructor*/
Menu:: Menu() {
 
}
 
 /*Displays start menu. Handles user input error. Returns user choice*/ 
int Menu::startMenu() {
 
   int input;
   
   cout << "1) Start a New Game of Shelby Center and Dragons!" << endl;
   cout << "2) View top 10 High Scores" << endl;
   cout << "3) Quit" << endl;
   cout << "\n    Please choose an option: ";
   cin >> input;
   while (input < 1 || input > 3){
      cout << "\nIncorrect input. Please enter 1, 2, or 3." << endl;
      cin >> input;
   }
   choice = input;
   
   return input; 
   
}

/*Displays game menu. Handles user error. Returns user input.*/
int Menu::gameMenu() {

   int input;
   
   cout << "\t1) Move forward (takes time, could be risky...)" << endl;
   cout << "\t2) Read technical papers (boost intelligence, takes time)" << endl;
   cout << "\t3) Search for loose change (boost money, takes time)" << endl;
   cout << "\t4) View character" << endl;
   cout << "\t5) Quit the game" << endl;
   cout << "\nPlease choose an action: ";
   cin >> input;
   while (input < 1 || input > 5) {
      cout << "\nIncorrect input. Please enter 1, 2, 3, 4, or 5." << endl;
      cin >> input;
   }
   choice = input;
   
   return input;
}

/*Immediately quits the program*/
void Menu::quit() {

   exit(0);
   
}

   

 /*******************************************************************
 **************Class Functions for System****************************
 ********************************************************************
 */
  
  /*Constructor*/ 
System::System() {}

/*Runs main menu options.*/
void System::runGame() {

   
   Character player(0);
   Menu menu;
   //Main menu
   int choice = menu.startMenu();
   while (choice != 3) {
      switch (choice) {
      //Starts new game.
         case 1:
            cout << "Entering game..." << endl;
            newGame(menu, player);
            break;
      //Displays high scores.
         case 2:
            getScores();
            break;    
      }
      cout << "\n\n";
      choice = menu.startMenu();
   }
      //Quits game.
   quit();
   
   
   
}

//Runs game menu options.
void System::newGame(Menu menu, Character player) {

   
   player.getAttributes();
   
   //Runs game while player attributes are greater than 0.
   while (player.getSteps() > 0 &&
          player.getIntel() > 0 &&
          player.getMoney() > 0 &&
          player.getTime() > 0)    {
          
      cout << "\nYou are " << player.getSteps() << " steps from the goal."
              " Time left: " << player.getTime() << "\n" << endl;
                
      int choice = menu.gameMenu();
      
      switch (choice) {
         //Step forward. May experience encounter.
         case 1:
         
            encounters(player);
                      
            break;
         //Read technical paper.  
         case 2:
          
            cout << "\tLook at Mr./Ms. Smarty McSmartpants reading a technical "
                  "paper. \n\tYeah, you're smarter. Now go outside and make some "
                  "friends!" << endl;
            player.loseTime();
            player.gainIntel();
                  
            break;
         //Look for loose change.
         case 3:
            
            cout << "\tYou found some loose change! Great! Now it will only\n\t"
                    "take 29 years, 364 days, 23 hours, and 57 minutes to pay off\n\t"
                    "your student debt!" << endl;
            player.loseTime();
            player.gainMoney();
            
            break;
         //Display current character attributes.
         case 4:
            player.getAttributes();
            break;
         //Quit game.
         case 5:
            quit();
            break;
      }
   }
   
   
   //If statements handle a losing game.
   if (player.getIntel() < 1) {
      
      cout << "\n\tYour brain has turned to mush. You can no longer continue!" << endl;
      quit();
   }
   if (player.getTime() < 1) {
      
      cout << "\n\tThere's no time!!!!\n\tLike literally, there's no time left.\n\t"
              "You lost." << endl;
      quit();
   }
   if (player.getMoney() < 1) {
   
      cout << "\n\tYou are completely broke. You are forced to live under a bridge,\n\t"
              "performing questionable acts for money." << endl;
              
      quit();
   }
   
   //If player wins, this code will execute.
   player.calcScore();
   cout << "\nChristopher Columbus. Neil Armstrong. Bill Gates. The guy who invented the hot dog.\n"
           "What do these people have in common? They were trailblazers. Are we adding one more to the\n"
           "list? LOL no. You went 20 steps down a hallway. Get over yourself.\n\n"
           "\tFinal score: " << player.getScore() << endl;
     
   //Adds score to list if eligible. 
   editScoreList(player);
    
   quit();       
           
}
  
/*Runs encounters based on probability of encounter occuring*/ 
void System::encounters(Character& player) {
   
   Encounter enc;
   int encNum = rand() % 1001;
      
   if (encNum < 251) {
      enc.nothing(player);
   }
   else if (encNum < 551) {
      enc.puzzle(player);
   }
   else if (encNum < 651) {
      enc.professor(player);
   }
   else if (encNum < 751) {
      enc.gradStudent(player);
   }
   else if (encNum < 901) {
      enc.gruntWork(player);
   }
   else{
      enc.gradePapers(player);
   }
         
   player.takeStep();
   player.loseOneTime();
          
}

 /*Edits high score list.*/
void System::editScoreList(Character player) {
   
   Character topScores[10];
   //Filename containing high score list
   string filename = "HighScores.txt";
   //Checks to see if file exists.
   if (ifstream(filename.c_str())) {
      ifstream fileIn(filename.c_str());
      
      //Populates array
      for(int i = 0; i < 10; i++) {
         Character c;
         string name;
         int score;
         fileIn >> name >> score;
         if(name == "") {
            c.setName("---");
            c.setScore(0);
         }
         else {
            c.setName(name);
            c.setScore(score);
         }
         
         
         topScores[i] = c;
      } 
      fileIn.close();
     //Adds player to array if within top 10 scores.
      for(int i = 0; i < 10; i++) {
      
         if(player.getScore() >=  topScores[i].getScore()) {
            topScores[9] = player;
         }
      }
      //Sorts array.
      Character temp;
      for(int i = 9; i > 0; i--) {
        
         if(topScores[i].getScore() > topScores[i-1].getScore()) {
            temp = topScores[i-1];
            topScores[i-1] = topScores[i];
            topScores[i] = temp;
         }
      }
      
      
      //Outputs new file with names and scores.
      ofstream outStream(filename.c_str());
      for(int i = 0; i < 10; i++) {
      
         string name = topScores[i].getName();
         int score = topScores[i].getScore();
         outStream << name << "\t" << score << endl;
      }  
      outStream.close();  
   }
   else {
      //Creates file with single name and score.
      ofstream outStream(filename.c_str());
      outStream << player.getName() << "\t\t" << player.getScore() << endl;
      outStream.close();
   }
   
   return;
   
   
   
}
      
      
      
   
   
   /*Gets high score list.*/
void System::getScores(){

 
   string filename = "HighScores.txt";
//Checks to see if file exists.
   if (ifstream(filename.c_str())) {
      ifstream fileIn(filename.c_str());
      string line;
      //Prints name and score.
      while (getline(fileIn, line)) {
         
         cout << line << endl; 
      }
      fileIn.close();
   }
   else {
      cout << "No scores to display.";
   }
      
}




      

  
  
  
 /*************************************************
 ***********Class Functions for Character**********
 **************************************************
 */
 
 /*Constructor1.*/
Character::Character(int theScore) {
   
   cout << "What's your name? ";
   cin >> name;
   cout << "\n====================================="
             "\n|              Welcome, " << name << "         |"
             "\n=====================================\n" << endl;
             
   steps = 20;
  
   time = (rand() % 21) + 40;
   intelligence = (rand() % 11) + 10;
   money = (rand() % 11) + 10;
   score = theScore;

      
}

/*Constructor2.*/
Character::Character() {

   
}

/*Displays character attributes.*/
void Character::getAttributes() {

   cout << "You have: \n" << endl;
   cout << "intelligence: " << intelligence << endl;
   cout << "time: " << time << endl;
   cout << "money: " << money << endl;
   cout << endl;
   
}


   /*Adds to character intelligence.*/
void Character::gainIntel() {
   
   intelligence += (rand() % 5) + 1;
   return;
}
   
   /*Decrease character intelligence.*/
void Character::loseIntel() {
   
   intelligence -= (rand() % 10) + 1;
   return;
}
   
   /*Decreases character time.*/
void Character::loseOneTime() {
   
   time -= 1;
   return;
}
    
   /*Decreases character time.*/
void Character::loseTime() {
   
   time -= (rand() % 5) + 1;
   return;
}
    
   /*Increases character money.*/
void Character::gainMoney() {
   
   money += (rand() % 5) + 1;
   return;
}
   
   /*Decreases character money.*/
void Character::loseMoney() {
   
   money -= (rand() % 10) + 1;
   return;
}
   
   /*Decrease step count by 1.*/
void Character::takeStep() {
   
   steps -= 1;
   return;
}
      
   /*Character score.*/
int Character::getScore() {
   
   return score;
}
   
   /*Character intelligence.*/
int Character::getIntel() {
      
   return intelligence;
}
   
   /*Character time.*/
int Character::getTime() {
   
   return time;
}
   
   /*Character money.*/
int Character::getMoney() {
   
   return money;
}
   
   /*Charcter steps.*/
int Character::getSteps() {
   
   return steps;
}

void Character::setScore(int newScore) {

   score = newScore;
   return;
}

   /*Sets name.*/
void Character::setName(string newName) {
   
   name = newName;
   return;
}

 /*Calculate score.*/
int Character::calcScore() {
   
   score = time * intelligence * money;
   return score;
}
   
     /*Gets name.*/
string Character::getName() {
   
   return name;
}



   
 /*************************************************
 ***********Class Functions for Encounter**********
 **************************************************
 */

      /*Constructor*/
Encounter::Encounter(){};
      /*Nothing happens.*/
void Encounter::nothing(Character& player) {
      
   cout << "Nothing happens!\n" << endl;
   
   return;
}
      
      /*Encounter a puzzle.*/
void Encounter::puzzle(Character& player) {
      
   cout << "\nPuzzle time!" << endl;
      
   int randQ = (rand() % 10) + 1;
   string answer;
   //Questions to answer.
   switch(randQ) {
      
      case 1: 
      
         cout << "\n\tWhat is the capitol of Alaska?" << endl;
         cin >> answer;
         if(answer == "Juneau") {
            cout << "Correct! You are smart! Gain intelligence.\n";
            player.gainIntel();
         }
         else {
            cout << "That's wrong! Lose intelligence.\n";
            player.loseIntel();
         }
         break;
      case 2: 
      
         cout << "\n\tI may have ears, but I cannot hear. What am I?" << endl;
         cin >> answer;
         if(answer == "Corn" || answer == "corn") {
            cout << "Correct! You are smart! Gain intelligence.\n";
            player.gainIntel();
         }
         else {
            cout << "That's wrong! Lose intelligence\n";
            player.loseIntel();
         }
         break;
         
      case 3: 
      
         cout << "\n\tHow many colors in a rainbow?" << endl;
         cin >> answer;
         if(answer == "7" || answer == "seven" || answer == "Seven") {
            cout << "That's correct. Here's some money.";
            player.gainMoney();
         }
         else {
            cout << "That's wrong! You lost money.\n";
            player.loseMoney();
         }
         break;
         
      case 4:
       
         cout << "\n\tDavid's father has three sons : Snap, Crackle and _____ ?" << endl;
         cin >> answer;
         if(answer == "David") {
            cout << "That's correct. Here's some money.";
            player.gainMoney();
         }
         else {
            cout << "That's wrong! You lost money.\n";
            player.loseMoney();
         }
         break;
         
      case 5:
       
         cout << "\n\tWhat has many keys, but can't even open a single door?" << endl;
         cin >> answer;
         if(answer == "piano" || answer == "Piano") {
            cout << "That's correct. Here's some money.";
            player.gainMoney();
         }
         else {
            cout << "That's wrong! You lost money.\n";
            player.loseMoney();
         }
         break;
         
      case 6:
       
         cout << "\n\tI am not alive, but I grow; I don't have lungs, but I need air;\n"
                  "\tI don't have a mouth, but water kills me. What am I?" << endl;
         cin >> answer;
         if(answer == "fire" || answer == "Fire") {
            cout << "That's correct. Here's some money.";
            player.gainMoney();
         }
         else {
            cout << "That's wrong! You lost money.\n";
            player.loseMoney();
         }
         break;
         
      case 7:
       
         cout << "\n\tWhat is the highest mountain in the world?" << endl;
         cin >> answer;
         if(answer == "Everest") {
            cout << "That's correct. Gain intelligence.";
            player.gainIntel();
         }
         else {
            cout << "That's wrong! You lost intelligence.\n";
            player.loseIntel();
         }
         break;
   
   
      case 8:
       
         cout << "\n\tWhat year did the moon landing occur?" << endl;
         cin >> answer;
         if(answer == "1969") {
            cout << "That's correct. Gain intelligence.";
            player.gainIntel();
         }
         else {
            cout << "That's wrong! You lost intelligence.\n";
            player.loseIntel();
         }
         break;
         
      case 9:
       
         cout << "\n\tWhere is the world's busiest airport located?" << endl;
         cin >> answer;
         if(answer == "Atlanta") {
            cout << "That's correct. Gain intelligence.";
            player.gainIntel();
         }
         else {
            cout << "That's wrong! You lost intelligence.\n";
            player.loseIntel();
         }
         break;
         
      case 10:
       
         cout << "\n\tWho is the current CEO of Apple(last name)?" << endl;
         cin >> answer;
         if(answer == "Cook") {
            cout << "That's correct. Here's some money.";
            player.gainMoney();
         }
         else {
            cout << "That's wrong! You lost some money.\n";
            player.loseMoney();
         }
         break;
   
   }
      
   return;
  
}
       
      /*Encounter a professor.*/
void Encounter::professor(Character& player){
      
   cout << "You encounter a professor!\n"
                 "You're smarter, but you have lost time!" << endl;
   player.gainIntel();
   player.loseTime();
   return;
}
                 
         
      /*Ecounter grad student.*/
void Encounter::gradStudent(Character& player) {
      
   cout << "\tIt's another grad student......\n"
                 "\tYou don't care about their sob story,\n"
                 "\tbut you listen anyways, cause you're\n"
                 "\tnice. But now you have less time.\n";
   player.loseTime();
   return;
}
      
      /*Encounter grunt work.*/
void Encounter::gruntWork(Character& player) {
      
   cout << "\tGrunt work!!!!!! Nooooooooo!!!!!!\n"
                 "\tYou lose time and intelligence!\n";
   player.loseTime();
   player.loseIntel();
   return;
}
      
      /*Encounter papers.*/
void Encounter::gradePapers(Character& player) {
      
   cout << "\tGrading papers. Not fun, but the extra\n"
                 "\tcash is nice.\n"
                 "\tYou lose time, but gain money.\n";
   player.loseTime();
   player.gainMoney();
   return;
}
      

   
  
  


