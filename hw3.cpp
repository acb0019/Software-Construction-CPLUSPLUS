// name: Andrew Bradley, acb0019
// partner: none
//filename: hw3.cpp
//due date: 9/6/2018
//collaboration: We did not use any external sources for this assignment.
//problem: Create a 3 character game of chance.

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
#include <cstdlib>
using namespace std;

const int AARONACC = 333;
const int BOBACC = 500;
const int CHARLIEACC = 1000;
const int TOTRUNS = 10000;


//FUNCTION PROTOTYPES

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive); 
   
   /*Input: A indicates Aaron's status
            B_alive indicates Bob's status
            C indicates Charlie's status
     Return: true if at least two are alive
            otherwise returns false
            
    */
  
void Aaron_shoots1 (bool &B_alive, bool &C_alive); 
  
    /*Input:B_alive indicates Bob's status
            C indicates Charlie's status
     Return: No return. Potentially changes the status of Bob or Charlie.
            
    */

void Bob_shoots (bool &A_alive, bool &C_alive); 
   
   /*Input:A indicates Aaron's status
           C indicates Charlie's status
     Return: No return. Potentially changes the status of Aaron or Charlie.
            
    */


void Charlie_shoots (bool &A_alive, bool &B_alive); 

   /*Input:A indicates Aaron's status
           B_alive indicates Bob's status
     Return: No return. Potentially changes the status of Aaron or Bob.
            
    */

void Aaron_shoots2 (bool &B_alive, bool &C_alive, int shotNum); 

    /*Input:B_alive indicates Bob's status
            C indicates Charlie's status
            shotNum indicates the number of shots that have occured
     Return: No return. 
            
    */


void Press_Any_Key();

   /*Input: No input.
     Return: No return. 
   */
   
void duel1();

   /*Input:None.
     Return: No return.
   */
   
void duel2();

   /*Input:None.
     Return: No return.
   */

void test_at_least_two_alive(); 
  
  /*This is a test driver for at_least_two_alive() */
 
void test_Aaron_shoots1(void);

 /*This is a test driver for Aaron_shoots1()*/
 
void test_Bob_shoots(void);

/*This is a test driver for Bob_shoots()*/

void test_Charlie_shoots(void);

/*This is a test driver for Charlie_shoots()*/

void test_Aaron_shoots2(void);

/*This is a test driver for Aaron_shoots2*/ 

int main() {
  //Random time generator
   srand (time (0));
   
   int aWins = 0;
   int bWins = 0;
   int cWins = 0;
   
   
   cout << "*** Welcome to Puzzlevania's Duel Simulator ***\n";
   test_at_least_two_alive();
   test_Aaron_shoots1();
   test_Bob_shoots();
   test_Charlie_shoots();
   test_Aaron_shoots2();
   
   cout << "Ready to test strategy 1 (run 10000 times):\n";
   Press_Any_Key();
   cout << "...\n...\n...\n";
   duel1();
  
   cout << "Ready to test strategy 2 (run 10000 times):\n";
   Press_Any_Key();
   cout << "...\n...\n...\n";
   duel2();
  
   
   
   
   
   
}

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
   
   if (A_alive && B_alive || A_alive && C_alive || B_alive && C_alive) {
      return true;
   }
   return false;
}
  
void Aaron_shoots1 (bool &B_alive, bool &C_alive) {
  
   
   int randNum = rand() % 1001; 
  

   if (C_alive && randNum < AARONACC) {
      C_alive = false;
      return;
   }
   
   if (B_alive && randNum < AARONACC) {
      B_alive = false;
      return;
   }
   
   return;
}

void Bob_shoots (bool& A_alive, bool& C_alive) {
   
   
   int randNum = rand() % 1001;

   
   if (C_alive && randNum < BOBACC) {
      C_alive = false;
      return;
   }
   
   if (A_alive && randNum < BOBACC) {
      A_alive = false;
      return;
   }
   return;
}

void Charlie_shoots (bool &A_alive, bool &B_alive) {

   if (B_alive) {
      B_alive = false;
      return;
   }
   
   if (A_alive) { 
      A_alive = false;
   }
   return;
}

void Aaron_shoots2 (bool &B_alive, bool &C_alive, int shotNum) {

   if (shotNum == 1) {
      return;
   }
   int randNum = rand() % 1001;
   
   if (C_alive && randNum < AARONACC) {
      C_alive = false;
      return;
   }
   
   if (B_alive && randNum < AARONACC) {
      B_alive = false;
      return;
   }
   return;
}

void Press_Any_Key () {
   
   cout << "Press any key to continue..."; 
   cin.ignore().get(); //Pause Command for Linux Terminal 
}

void duel1 (){
   
   int aWins = 0; int bWins = 0; int cWins = 0; int i = 0;
   
  
   while (i < TOTRUNS) {
   
      bool A = true, B = true, C = true;
      while(at_least_two_alive(A, B, C)) {
      
         if(A) {
            Aaron_shoots1(B, C);
         
         }
         if(B) {
            Bob_shoots(A, C);
         
         }
         if(C) {
            Charlie_shoots(A, B);
         }
      }
   
      if (A){
         aWins++;
      }
      if (B){
         bWins++;
      }
      if (C){
         cWins++;
      }
      i++;
   }
   cout << "Aaron won " << aWins << "/1000 duels or " << aWins / (double) 100 << "%\n";
   cout << "Bob won " << bWins << "/1000 duels or " << bWins / (double) 100 << "%\n";
   cout << "Charlie won "<< cWins << "/1000 duels or " << cWins / (double) 100 << "%\n";
   return;
}
  


void duel2 (){
   
   int aWins = 0; int bWins = 0; int cWins = 0; int i = 0;
   
  
   while (i < TOTRUNS) {
   
      bool A = true, B = true, C = true;
      while(at_least_two_alive(A, B, C)) {
         int shots = 1;
         if(A) {
            Aaron_shoots2(B, C, shots);
            shots++;
         }
         if(B) {
            Bob_shoots(A, C);
            shots++;
         }
         if(C) {
            Charlie_shoots(A, B);
            shots++;
         }
      }
   
      if (A){
         aWins++;
      }
      if (B){
         bWins++;
      }
      if (C){
         cWins++;
      }
      i++;
   }
   cout << "Aaron won " << aWins << "/1000 duels or " << aWins / (double) 100 << "%\n";
   cout << "Bob won " << bWins << "/1000 duels or " << bWins / (double) 100 << "%\n";
   cout << "Charlie won "<< cWins << "/1000 duels or " << cWins / (double) 100 << "%\n";
   return;
}
   
   
   
   


   //Test Functions
void test_at_least_two_alive(void) {
   cout << "Unit Testing 1: Function - at_least_two_alive()\n";
   
   cout << "Case 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));      
   cout << "Case passed ...\n"; 
   
   cout << "Case 2: Aaron dead, Bob alive, Charlie alive\n";  
   assert(true == at_least_two_alive(false, true, true));      
   cout << "Case passed ...\n"; 
  
   cout << "Case 3: Aaron alive, Bob dead, Charlie alive\n";  
   assert(true == at_least_two_alive(true, false, true)); 
   cout << "Case passed ...\n"; 
      
   cout << "Case 4: Aaron alive, Bob alive, Charlie dead\n";  
   assert(true == at_least_two_alive(true, false, true)); 
   cout << "Case passed ...\n";
      
   cout << "Case 5: Aaron alive, Bob dead, Charlie dead\n";  
   assert(false == at_least_two_alive(true, false, false)); 
   cout << "Case passed ...\n";
      
   cout << "Case 6: Aaron dead, Bob alive, Charlie dead\n";  
   assert(false == at_least_two_alive(false, true, false)); 
   cout << "Case passed ...\n";
      
   cout << "Case 7: Aaron dead, Bob dead, Charlie alive\n";  
   assert(false == at_least_two_alive(false, false, true)); 
   cout << "Case passed ...\n";

   cout << "Case 8: Aaron dead, Bob dead, Charlie dead\n";  
   assert(false == at_least_two_alive(false, false, false)); 
   cout << "Case passed ...\n";
   
   Press_Any_Key();
   return;
}


void test_Aaron_shoots1(void) {
   
   bool A, B, C;
   cout << "Unit Testing 2: Function - Aaron_shoots1(B_alive, C_alive)\n";
   
   cout << "Case 1: Bob, Charlie alive\n"
           "Aaron is shooting at Charlie\n";
   
   B = true; C = true;      
   Aaron_shoots1(B, C);
   if (C) {
      assert(true == C);
      cout << "Aaron misses.\n";
   }
   else  {
      assert(false == C);
      cout << "Charlie is dead.\n";
   }
   
   cout << "Case 2: Bob dead, Charlie alive\n"
           "Aaron is shooting at Charlie\n";
   B = false; C = true;
   Aaron_shoots1(B, C);
   if (C) {
      assert(true == C);
      cout << "Aaron misses.\n";
   }
   else {
      assert(false == C);
      cout << "Charlie is dead.\n";
   }  
   cout << "Case 3: Bob alive, Charlie dead.\n"
           "Aaron is shooting at Bob.\n";
   B = true; C = false;
   Aaron_shoots1(B, C);
   if (B) {
      assert(true == B);
      cout << "Aaron misses.\n";
   }
   else {
      assert(false == B);
      cout << "Bob is dead.\n";
   }     
      
   Press_Any_Key();
   return;
   
}

void test_Bob_shoots(void) {
   bool A, B, C;
   cout << "Unit Testing 3: Function - Bob_shoots(A_alive, C_alive)\n";
   
   cout << "Case 1: Aaron alive, Charlie alive\n"
           "Bob is shooting at Charlie\n";
   
   A = true; C = true;      
   Bob_shoots(A, C);
   if (C) {
      assert(true == C);
      cout << "Bob misses.\n";
   }
   else  {
      assert(false == C);
      cout << "Charlie is dead.\n";
   }
   
   cout << "Case 2: Aaron dead, Charlie alive\n"
           "Bob is shooting at Charlie\n";
   A = false; C = true;
   Bob_shoots(A, C);
   if (C) {
      assert(true == C);
      cout << "Bob misses.\n";
   }
   else {
      assert(false == C);
      cout << "Charlie is dead.\n";
   }  
   cout << "Case 3: Aaron alive, Charlie dead.\n"
           "Bob is shooting at Aaron.\n";
   A = true; C = false;
   Bob_shoots(A, C);
   if (A) {
      assert(true == A);
      cout << "Bob misses.\n";
   }
   else {
      assert(false == A);
      cout << "Aaron is dead.\n";
   }     
      
   Press_Any_Key();
   
}

void test_Charlie_shoots(void) {
 
   bool A, B, C;
   cout << "Unit Testing 4: Function - Charlie_shoots(A_alive, B_alive)\n";
   
   cout << "Case 1: Aaron alive, Bob alive\n"
           "Charlie is shooting at Bob\n";
   
   A = true; B = true;      
   Charlie_shoots(A, B);
   assert(false == B);
   cout << "Bob is dead.\n";
   
   
   cout << "Case 2: Aaron dead, Bob alive\n"
           "Charlie is shooting at Bob\n";
   A = false; B = true;
   Charlie_shoots(A, B);
      
   assert(false == B);
   cout << "Bob is dead.\n";
   
   cout << "Case 3: Aaron alive, Bob dead.\n"
           "Charlie is shooting at Aaron.\n";
   A = true; B = false;
   Charlie_shoots(A, B);
   assert(false == A);
   cout << "Aaron is dead.\n";
       
      
   Press_Any_Key();
   
}

void test_Aaron_shoots2(void) {
   
   bool A, B, C;
   int shotNum = 1;
   cout << "Unit Testing 5: Function - Aaron_shoots2(B_alive, C_alive, int shotNum)\n";
   
   cout << "Case 1: Bob, Charlie alive\n";
      
   B = true; C = true;       
   Aaron_shoots2(B, C, shotNum);
   
   assert(true == B && C);
   cout << "Aaron intentionally misses his first shot\n"
           "Both Bob and Charlie are alive.\n";
   
 
   
   cout << "Case 2: Bob dead, Charlie alive\n"
           "Aaron is shooting at Charlie\n";
   B = false; C = true; shotNum = 2;
   Aaron_shoots2(B, C, shotNum);
   if (C) {
      assert(true == C);
      cout << "Aaron misses.\n";
   }
   else {
      assert(false == C);
      cout << "Charlie is dead.\n";
   }  
   cout << "Case 3: Bob alive, Charlie dead.\n"
           "Aaron is shooting at Bob.\n";
   B = true; C = false;
   Aaron_shoots2(B, C, shotNum);
   if (B) {
      assert(true == B);
      cout << "Aaron misses.\n";
   }
   else {
      assert(false == B);
      cout << "Bob is dead.\n";
   }     
      
   Press_Any_Key();
   return;
   
}




    
            
   
   
