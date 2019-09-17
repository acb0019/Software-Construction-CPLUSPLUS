// name: Andrew Bradley, acb0019
// partner: none
//filename: Project2.cpp
//due date: 12/07/2018
//collaboration: none
//problem: Create a teller system to be used by employees at a
//         banking establishment.



#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;
class Staff {
   
   private:
   
   string userId;
   string password;
   string staffType;
   
   
   public:
   
      /*Constructor*/
   Staff();
      /*Sets userId*/
   void setUserId(string id);
      /*Returns userId*/
   string getUserId();
      /*Sets password*/
   void setPassword(string word);
      /*Returns password*/
   string getPassword();
      /*Sets staff member type*/
   void setStaffType(int type);
      /*Returns the type of staff member*/
   string getStaffType();
      
   };
   
class Clients{
   
   private:
   
   string name;
   string address;
   string ssn;
   string employer;
   int annInc;
   int acctNo;
   string acctType;
   double acctBal;
   
   public:
   /*Constructor*/
   Clients();
   /*Gets client name.*/
   string getName();
   /*Sets client name.*/
   void setName(string input);
   /*Gets client address.*/
   string getAddress();
   /*Sets client address.*/
   void setAddress(string input);
   /*Gets client social security number*/
   string getSSN();
   /*Sets client social security number*/
   void setSSN(string input);
   /*Gets client employer.*/
   string getEmployer();
   /*Sets client employer.*/
   void setEmployer(string input);
   /*Gets client annual income.*/
   int getAnnInc();
   /*Sets client annual income.*/
   void setAnnInc(int input);
   /*Displays all client information*/
   void displayInfo();
   
   };
   
class Accounts{
   
   private:
   
   int acctNum;
   string acctName;
   string acctType;
   double acctBal;
      
  public:
      /*Constructor*/
   Accounts();
      /*Gets account number.*/
   int getAcctNum();
      /*Sets account number.*/
   void setAcctNum(int input);
      /*Gets account name.*/
   string getAcctName();
      /*Sets account name.*/
   void setAcctName(string input);
      /*Gets account type.*/
   string getAcctType();
      /*Sets account type.*/
   void setAcctType(string type);
      /*Gets account balance.*/
   double getAcctBal();
      /*Sets accout balance.*/
   void setAcctBal(double input);
      /*Adds a deposit.*/
   void addDeposit(double deposit);
      /*Subtracts a withdraw.*/
   void subWithdraw(double withdraw);
   };

class System {

private:

   int uses;
   string currentUser;
   vector <Staff> staffMembers;
   vector <Clients> clients;
   vector <Accounts> accounts;

public:

/*Constructor*/
   System();
/*Runs Teller System*/
   void runSystem();
/*Idle Menu*/
   int idleMenu();
/*Loads account and client info to the system*/
   void loadInfo();
/*Login Menu*/
   int loginMenu();
/*System Admin Menu*/
   void sysAdminMenu();
/*Branch Staff Menu*/
   void branchStaffMenu();
/*Client and Account Management Menu*/
   void clientAcctMgmtMenu();
/*Adds a Branch Staff Member*/
   void addBranchStaff();
/*Deletes a Branch Staff Member*/
   void deleteBranchStaff();
/*Displays the Branch Staff Members*/
   void displayBranchStaff();
/*Changes the password of the staff member*/
   void changePassword();
/*Adds a client*/
   void addClient();
/*Adds an account*/
   void addAccount();
/*Edits client info*/
   void editClientInfo();
/*Manages an account*/
   void manageAccount();
 /*Saves Client and Account Information*/
   void saveInfo();
/*Creates Auto Admin*/
   void autoAdmin();
/*Quits*/
   void quit();
};



     


/**************************************************************
***************************************************************
MAIN FUNCTION**************************************************
**************************************************************/

int main() {

   //Initializes and runs the teller system.
   System startSys;
   startSys.runSystem();
  
}


/**************************************************************
***************************************************************
Class Functions for System************************************
**************************************************************/
/*Constructor*/
System::System(){}

/*Runs the teller system*/
void System::runSystem(){

   //Loads client and account data into vectors.
   loadInfo();
   //Creates default admin.
   autoAdmin();
 
   
   int memberType;
   int choice = 0;
   
   //Runs system until quit is selected.
   while (choice != 2) { 
      //Gets idle menu choice.  
      choice = idleMenu();
   
      switch (choice) {
      
         case 1:
            //Variable that represents the member type of the user. 1 - Sys Admin, 2 - Branch Staff 
            //Determines the menu options available.
            memberType = loginMenu();
            
            
            switch(memberType) {
               case 1:
                  sysAdminMenu();
                  break;
            
               case 2:
                  branchStaffMenu();
                  break;
            
            }
         
            break;
      
         case 2: 
            quit();
         
         default:
            cout << "Not a valid entry.\n";
      
      }
   }
   
}
  
/*Idle menu. Returns choice to login or quit.*/
int System::idleMenu(){

   
   int choice;
   cout << "========================================================" 
           "\n|     Welcome to the Auburn Branch of Tiger Bank!      |" 
           "\n========================================================" << endl;
           
   cout << "1)  Login" << endl;
   cout << "2)  Quit" << endl;
   cout << "   Please choose an option: ";
   cin >> choice;
   return choice;
}

/*Loads account and client information from text files to the system.*/
void System::loadInfo(){

   string line;
   //name of file containing clients
   string clientFile = "client-info.txt";
   //name of file containing accounts
   string accountFile = "account-info.txt";
   //checks to see if client file exists
   if (ifstream(clientFile.c_str())) {
      //creates ifstream
      ifstream clientFileIn(clientFile.c_str());
      //Populates client vector with client objects
      while (getline(clientFileIn, line)) {
      
         Clients addClient;
         string name, address, ssn, employer, annInc;
         getline(clientFileIn, name);
         if (name == ""){
            break;
         }
         getline(clientFileIn, address);
         getline(clientFileIn, ssn);
         getline(clientFileIn, employer);
         getline(clientFileIn, annInc);
         //Annual income is changed from string type to int type
         int annuInc = atoi(annInc.c_str());
         //Sets client info
         addClient.setName(name); addClient.setAddress(address); addClient.setSSN(ssn);
         addClient.setEmployer(employer); addClient.setAnnInc(annuInc);
         //Adds client object to vector
         clients.push_back(addClient);
         
      }
      clientFileIn.close();
     
   }
   
   //checks if account file exists
   if (ifstream(accountFile.c_str())) {
      //creates account file ifstream
      ifstream accountFileIn(accountFile.c_str());
      //Reads data from account file. Creates accounts object with
      //data from file. Adds object to accounts vector.
      while (getline(accountFileIn, line)) {
         Accounts addAcc;
         string acctName, acctType, acctNum, acctBal;
         getline(accountFileIn, acctNum);
         if (acctNum == ""){
            break;
         }
         getline(accountFileIn, acctName);
         getline(accountFileIn, acctType);
         getline(accountFileIn, acctBal);
         //changes the account number from string to integer
         int acctNumb = atoi(acctNum.c_str());
         //changes the accout balance from string to double
         double acctBala = atof(acctBal.c_str());
         addAcc.setAcctNum(acctNumb); addAcc.setAcctName(acctName); 
         addAcc.setAcctType(acctType); addAcc.setAcctBal(acctBala);
         //adds accounts object to vector
         accounts.push_back(addAcc);
      }
      accountFileIn.close();
   }
   
     
   return;
}
      
/*Login Process*/
int System::loginMenu(){

   string userId;
   string password;
   int correct = 0;
   
   cout << "======================================================"
           "\n|      Login to Access the Teller Terminal System      |"
           "\n======================================================" << endl;
   while (correct == 0) {
      //Gets user name and password
      cout << "User Name: ";
      cin >> userId;
      cout << "Password: ";
      cin >> password;
   
      //Checks validity of user name and password
      for (int i = 0; i < staffMembers.size(); i++) {
                           
         if (staffMembers[i].getUserId() == userId) {
            if (staffMembers[i].getPassword() == password) {
               currentUser = userId;
               //Returns  1 if staff type is Sys Admin
               if (staffMembers[i].getStaffType() == "Sys Admin") {
                  return 1;
               }
               //Returns 2 if staff type is Branch Staff Member
               return 2;
               
            }
         }
      
         correct = 0;
      }
      cout << "The user name or password is incorrect. Try again!" << endl;
   }
}

/*System Admin Menu*/
void System::sysAdminMenu() {
   
   int choice;
   while(choice != 6) {
      cout << "=======================================================\n"
              "|    Teller Terminal System - System Administration    |\n"
              "=======================================================" << endl;
      cout << "1) Client and Account Management" << endl;
      cout << "2) Add a branch staff member" << endl;
      cout << "3) Delete a branch staff member" << endl;
      cout << "4) Display branch staff" << endl;
      cout << "5) Change password" << endl;
      cout << "6) Exit" << endl;
      cout << "   Please choose an option: ";
      cin >> choice;
      
      switch (choice) {
      
         case 1:
            //Menu to manage client and account info
            clientAcctMgmtMenu();
            break;
         case 2:
            //Adds a branch staff member
            addBranchStaff();
            break;
         case 3:
            //Deletes a branch staff member
            deleteBranchStaff();
            break;
         case 4:
            //Displays the existing branch staff employees
            displayBranchStaff();
            break;
         case 5:
            //Changes the password of the current user
            changePassword();
            break;
         case 6:
            //Clears the current user id before exiting.
            currentUser = "";
            break;
         default:
            cout << "Not a valid entry.\n";
      }
   }
   return;
}

/*Branch Staff Menu*/
void System::branchStaffMenu(){

   int choice;
   while (choice != 3) {
      cout << "=========================================================\n"
            "|         Teller Terminal System - Branch Staff         |\n"
            "=========================================================\n";
      cout << "1) Client and Account Management" << endl;
      cout << "2) Change password" << endl;
      cout << "3) Exit" << endl;
      cout << "Please choose an option: ";
      cin >> choice;
       
      switch (choice) {
         case 1:
            //Manages client and account info
            clientAcctMgmtMenu();
            break;
         case 2:
            //Changes id of current user
            changePassword();
            break;
         case 3:
            //Clears current user data before returning to idle screen.
            currentUser = "";
            return;
         default:
            cout << "Not a valid entry.\n";
      }  
   }   
}
  
 /*Client and Account Management Menu*/
void System::clientAcctMgmtMenu(){

   int choice;
   while (choice != 6) {
      cout << "=========================================================\n"
              "| Teller Terminal System - Client and Account Management |\n"
              "=========================================================\n";
      cout <<  "1) Add a client\n"
               "2) Add an account\n"
               "3) Edit Client Information\n"
               "4) Manage an account\n"
               "5) Save Client and Account Information\n"
               "6) Exit\n"
               "Please choose an option: ";
      cin >> choice;
      
      switch(choice) {
      
         case 1:
            //adds a client
            addClient();
            break;
         case 2:
            //adds an account
            addAccount();
            break;
         case 3:
            //edits client info
            editClientInfo();
            break;
         case 4:
            //Existing accounts can be accessed to complete
            //deposits and withdraws.
            manageAccount();
            break;
         case 5:
           //Saves existing client and account data into text files.
            saveInfo();
            break;
         case 6:
            //Exits menu
            return;
         default:
            cout << "Not a valid entry.\n";
            
      }        
   }
}
/*Adds a Branch Staff Member*/
void System::addBranchStaff(){

   Staff newStaff;
   string userID;
   string password;
   int role;
   int choice;
   
   //New Branch Staff User Name
   cout << "User name: ";
   cin.ignore();
   getline(cin, userID);
   newStaff.setUserId(userID);
   //New Brach Staff Password
   cout << "Password: ";
   getline(cin, password);
   newStaff.setPassword(password);
   //Role of new Branch Staff employee
   cout << "Role (1 - Administrator; 2 - Branch Staff) : ";
   cin >> role;
   newStaff.setStaffType(role);
   //Confirms addition of new employee.
   cout << "1)Confirm\n2)Cancel\n\tPlease choose an option: ";
   cin >> choice;
   switch (choice) {
      case 1:
         //Adds to staff member vector.
         staffMembers.push_back(newStaff);
         cout << "A new branch staff was added!\n"
                 "User Name: " << userID << "\tRole: "
              << newStaff.getStaffType() << endl;
      case 2:
         //Returns without adding employee.
         cout << endl;
         return;
      default:
         cout << "Not a valid entry.\n";
         
   }
     
              
}
/*Deletes a Branch Staff Member*/
void System::deleteBranchStaff(){

   string userId;
   int choice;
   
   //User name of employee to be deleted.
   cout << "Delete a user - User Name: ";
   cin >> userId;
   //Searches current employee info for the User name.
   for(int i = 0; i < staffMembers.size(); i++) {
      if (staffMembers[i].getUserId() == userId) {
         //Confirms deletion.
         cout << "1)Confirm\n2)Cancel\n\tPlease choose an option; ";
         cin >> choice;
         switch (choice) {
            case 1:
               //Deletes employee info.
               staffMembers.erase(staffMembers.begin() + i);
               cout << "User has been deleted.\n" << endl;
               return;
            case 2:
               //Returns without deleting info.
               return;
            default:
               cout << "Not a valid entry.\n";
         }
      }
   }
   cout << "User was not found. No deletion has occured.\n" << endl;
   return;
}
        
    
    
    

   /*Displays the Branch Staff Members*/
void System::displayBranchStaff(){

   //Prints out number of Branch Staff members along with their respective user
   //names and roles.
   cout << "There are " << staffMembers.size() << " users in the system." << endl;
   for (int i = 0; i < staffMembers.size(); i++) {
      cout << i+1 << ". User Name: " << staffMembers[i].getUserId() 
           << "\tRole: " << staffMembers[i].getStaffType() << endl;
   }
   
   return;
}

/*Changes the password of the staff member*/
void System::changePassword(){

   string newPassword;
   int check = 0;
   do{
      //Gets new password.
      cout << "New Password: ";
      cin >> newPassword;
   
      //Checks to see if new password is different than old password.
      for (int i = 0; i < staffMembers.size(); i++){
         if (staffMembers[i].getUserId() == currentUser) {
            //Error message if new password is the same as the old password.
            if (staffMembers[i].getPassword() == newPassword){
               cout << "Error - New password must be different from previous " 
                        "password.";
            }
            else {
               //Sets new password.
               staffMembers[i].setPassword(newPassword);
               return;
                  
            }
         }
      }
   }
       while(check == 0);
}

/*Adds a client*/
void System::addClient(){  
   
   Clients newClient;
   string name, address, ssn, employer;
   int annInc;
   
   cout << "A new client will be added:" << endl;
   //Gets client name
   cout << "Client name: ";
   cin.ignore();
   getline(cin, name);
   newClient.setName(name);
   //Gets client address
   cout << "Address: ";
   getline(cin, address);
   newClient.setAddress(address);
   //Gets client social security number
   cout << "Social Security Number: ";
   getline(cin, ssn);
   newClient.setSSN(ssn);
   //Gets client's employer
   cout << "Employer: ";
   getline(cin, employer);
   newClient.setEmployer(employer);
   //Gets client's annual income
   cout << "Annual income: ";
   cin >> annInc;
   newClient.setAnnInc(annInc);
   //Adds new client to vector of clients
   clients.push_back(newClient);
   cout << "A new client was added!\n\n";
   
   return;   
}   

/*Adds an Account*/
void System::addAccount() { 

   string name;
   Accounts account;
   int acctNum;
   string acctType;
   double balance;
   
   //Gets the client who will own the account.
   cout << "Choose a client:";
   cin.ignore();
   getline(cin, name);
   
   for (int i = 0; i < clients.size(); i++) {
      //Validates client's existance.
      if (clients[i].getName() == name) {
         cout << "A new account will be created for " << name << "..." << endl;
         //Creates account number
         cout << "Account Number: ";
         cin >> acctNum;
         account.setAcctNum(acctNum);
         //Owner of account
         account.setAcctName(name);
         //Sets accout type
         cout << "Account Type: ";
         cin.ignore();
         getline(cin,acctType);
         //Sets account balance
         account.setAcctType(acctType);
         cout << "Balance: ";
         cin >> balance;
         account.setAcctBal(balance);
         //Adds account to accouts vector
         accounts.push_back(account);
         cout << "\tA new account was created for " << name << "!" << endl;
         return;
      }
   }
   cout << "Error - The client is not in the system." << endl;
  
   return;
}

/*Edits client info*/
void System::editClientInfo(){

   string name;
   Clients client;
   int choice;
   string address;
   string ssn;
   string employer;
   int income;
   
   //Gets client whose information will be edited
   cout << "Choose a client: ";
   cin.ignore();
   getline(cin, name);
   for (int i = 0; i < clients.size(); i++) {
      //Validates existance of client
      if (clients[i].getName() == name) {
         //Displays current client information
         clients[i].displayInfo();
         cout << "Client " << name << "'s information will be updated." << endl;
         cout << "1) Confirm" << endl;
         cout << "2) Cancel" << endl;
         cout << "Please choose an option: ";
         cin >> choice;
         switch (choice) {
            //Client information inputs.
            case 1:
               cout << "Address: ";
               cin.ignore();
               getline(cin, address);
               clients[i].setAddress(address);
               cout << "Social Security Number: ";
               getline(cin, ssn);
               clients[i].setSSN(ssn);
               cout << "Employer: ";
               getline(cin, employer);
               clients[i].setEmployer(employer);
               cout << "Annual Income: ";
               cin >> income;
               clients[i].setAnnInc(income);
               cout << "\t" << name << "'s information has been updated." << endl;
               break;
            //Returns without editing info. 
            case 2:
               return;
            default:
               cout << "Not a valid entry.\n";
         }
      }
   }
   cout << "Error-No such client exists." << endl;
   return;
}    

/*Manages an account.*/         
void System::manageAccount(){

   int acctNum;
   int choice;
   double dep, withd;
   //Gets account to be managed.
   cout << "Which account will be managed? ";
   cin >> acctNum;
   for(int i = 0; i < accounts.size(); i++) {
      //Checks for existance of account.
      if (accounts[i].getAcctNum() == acctNum) {
         cout << "Manage account " << acctNum << " for "
              << accounts[i].getAcctName() << "." << endl;
         //Management options.
         cout << "1) Deposit\n"
                 "2) Withdraw\n"
                 "3) Cancel\n"
                 "\tPlease choose an option: ";
         cin >> choice;
         switch (choice) {
            //Deposits money into the account.
            case 1:
               cout << "Deposit amount: ";
               cin >> dep;
               accounts[i].addDeposit(dep);
               cout << "Balance of account " << acctNum << " is: "
                    << accounts[i].getAcctBal() << endl;
               return;
            //Withdraws money from the account.
            case 2:
               cout << "Withdraw amount: ";
               cin >> withd;
               accounts[i].subWithdraw(withd);
               cout << "Balance of account " << acctNum << " is: "
                    << accounts[i].getAcctBal() << endl;
               return;
            //Exits with no account adjustment
            case 3:
               return;
            default:
               cout << "Not a valid entry.\n";
         }
      }
   }
   cout << "Error - The account number was not found." << endl;
   return;
}
         
/*Saves client and account info.*/
void System::saveInfo(){

   //Names of files to be created.
   string clientFile = "client-info.txt";
   string accountFile = "account-info.txt";
     
   //Opens ofstream
   ofstream outStream(clientFile.c_str());
   //Deposits client info into text file.
   for (int i = 0; i < clients.size(); i++) {
      
      outStream << clients[i].getName() << "\n" << clients[i].getAddress() << "\n"
                   << clients[i].getSSN() << "\n" << clients[i].getEmployer() << "\n"
                   << clients[i].getAnnInc() << "\n";         
   }
   outStream.close();
       
   ofstream outStr(accountFile.c_str());
   //Deposits account info into text file.
   for (int i = 0; i < accounts.size(); i++) {
       
      outStr << accounts[i].getAcctNum() << "\n" << accounts[i].getAcctName() << "\n"
                   << accounts[i].getAcctType() << "\n" << accounts[i].getAcctBal() << endl;
   }
   outStr.close();
   
   cout << "Client information has been saved in the client-info file.\n"
           "Account information has been saved in the account-info file.\n\n";
       
   return;
}

/*Creates Auto Admin*/
void System::autoAdmin(){
   
   Staff autoAdmin;
   autoAdmin.setUserId("admin");
   autoAdmin.setPassword("0000");
   autoAdmin.setStaffType(1);
   staffMembers.push_back(autoAdmin);
   
   return;
}

      

   
                      
                                 
/*Exits system*/
void System::quit(){

   exit(0);

}



/**************************************************************
***************************************************************
Class Functions for Staff************************************
**************************************************************/

/*Constructor*/
Staff::Staff(){};
/*Sets the userId*/
void Staff::setUserId(string id){

   userId = id;
   return;
}   
/*Returns the userId*/
string Staff::getUserId(){

   return userId;
}
/*Sets the password*/
void Staff::setPassword(string word){

   password = word;
   return;
}
/*Returns the password*/
string Staff::getPassword(){

   return password;
}
/*Sets the staff type*/
void Staff::setStaffType(int type) {
   
   if (type == 1) {
      staffType = "Sys Admin";
      return;
   }
   if (type == 2) {
      staffType = "Branch Staff Member";
      return;
   }
   return;
}
/*Returns the staff type*/
string Staff::getStaffType(){

   return staffType;
}


/**************************************************************
***************************************************************
Class Functions for Clients************************************
**************************************************************/

 /*Constructor*/
Clients::Clients(){
 
   name = "-";
   address = "-";
   ssn = "-";
   employer = "-";
   annInc = 0;
    
}
    

 /*Gets client name.*/
string Clients::getName(){
   
   return name;
}
   /*Sets client name.*/
void Clients::setName(string input){
   
   name = input;
   return;
}
   /*Gets client address.*/
string Clients::getAddress(){
   
   return address;
}
   /*Sets client address.*/
void Clients::setAddress(string input){
   
   address = input;
   return;
}
   /*Gets client social security number*/
string Clients::getSSN(){
   
   return ssn;
}
   /*Sets client social security number*/
void Clients::setSSN(string input){
   
   ssn = input;
   return;
}
   /*Gets client employer.*/
string Clients::getEmployer(){
   
   return employer;
}
   /*Sets client employer.*/
void Clients::setEmployer(string input){
   
   employer = input;
   return;
}
   /*Gets client annual income.*/
int Clients::getAnnInc(){
      
   return annInc;
}
   /*Sets client annual income.*/
void Clients::setAnnInc(int input){
   
   annInc = input;
   return;
} 

 /*Displays all client information*/
void Clients::displayInfo(){
   
   cout << "Display " << name << "'s information." << endl;
   cout << "Address: " << address << endl;
   cout << "Social Security Number: " << ssn << endl;
   cout << "Employer: " << employer << endl;
   cout << "Annual income: " << annInc << endl;
      
   return;
}

   
  
/**************************************************************
***************************************************************
Class Functions for Accounts***********************************
**************************************************************/
 
   
   
    /*Constructor*/
Accounts::Accounts(){}
      /*Gets account number.*/
int Accounts::getAcctNum(){
      
   return acctNum;
}
      /*Sets account number.*/
void Accounts::setAcctNum(int input){
      
      
   acctNum = input;
   return;
} 
      /*Gets account name.*/
string Accounts::getAcctName(){
      
   return acctName;
}
      /*Sets account name.*/
void Accounts::setAcctName(string input){
      
   acctName = input;
   return;
}
/*Gets account type.*/
string Accounts::getAcctType(){
   
   return acctType;
}
      /*Sets account type.*/
void Accounts::setAcctType(string type){
   
   acctType = type;
   return;
}
      /*Gets account balance.*/
double Accounts::getAcctBal(){
         
   return acctBal;
}
      /*Sets accout balance.*/
void Accounts::setAcctBal(double input){
      
   acctBal = input;
   return;
}
      /*Adds a deposit.*/
void Accounts::addDeposit(double deposit){
      
   acctBal += deposit;
   return;
}
      /*Subtracts a withdraw.*/
void Accounts::subWithdraw(double withdraw){
      
   if(acctBal < withdraw){
      cout << "Not enough money in account.\n" << endl;
      return;
   }
   else {
      acctBal -= withdraw;
   }
   return;
}
            
