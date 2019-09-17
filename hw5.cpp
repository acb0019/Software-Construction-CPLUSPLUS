// name: Andrew Bradley, acb0019
// partner: none
//filename: hw5.cpp
//due date: 10/04/2018
//collaboration: none
//problem: Create a linked list with nodes containing trivia questions, the answers to the questions,
//         and the score for answering the question correctly.
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <assert.h>
#include <climits>

using namespace std;
#define UNIT_TESTING



//Struct to define the data within a node. 
struct triviaNode {

   string inputQuest, ans;
   int points;
   triviaNode* next;
};
typedef triviaNode* pointer;
typedef unsigned int u_int;
//Number of questions in the list.
int quesCount;
//points to start of list
pointer head;



void hardCodeQs();
/*Creates a linked list with 3 questions.*/

int insert_question(pointer& list, string question, string answer, u_int points);
/*Creates a new node at the start of the list.*/

int add_question(pointer& list);
/*Adds a question input by the user to the list.*/

int askQuest(pointer list, int numOfQs);
/*Asks linked list questions. Evaluates answers. Produces score.*/

void test_askQuest();
/*Test driver for askQuest method*/




int main() {

  #ifdef UNIT_TESTING
   
   test_askQuest();
   
   #endif
   
   hardCodeQs();
   
   cout << "*** Welcome to Andrew Bradley's trivia quiz game ***" << endl;
   
   //Asks user to add additional questions.   
   string continueQ;
   string yes = "Yes";
   string no = "No";   
   do {
      
      
      add_question(head);
      quesCount++;
      
      cout << "Continue? (Yes/No): ";
      cin >> continueQ;
      
      
      while (continueQ != yes && continueQ != no) {
         cout << "Invalid answer. Must be exactly Yes or No." << endl;
         cout << "Continue? (Yes/No): ";
         cin >> continueQ;
      }
   
      cin.ignore();
   }
      while(continueQ != no);
   cout << endl; 
   
   //Asks questions in linked list.
   askQuest(head, quesCount);
   
   cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***";
    
    
      
      
      
   return 0;
}


void hardCodeQs() {

   quesCount = 3;
   
   insert_question(head, "How long was the shortest war on record? (Hint: How many" 
                " minutes)" , "38", 100);
                
   insert_question(head, "What was Bank of America's original name? (Hint: Bank of" 
                " Italy or Bank of Germany)" , "Bank of Italy", 50);
                
   insert_question(head, "What is the best-selling video game of all time? (Hint:"  
                " Call of Duty or Wii Sports)?" , "Wii Sports", 20);

}

int insert_question(pointer& list, string question, string answer, u_int pnts) {

   pointer cur_ptr;
   //Creates new node
   cur_ptr = new triviaNode;
   assert(cur_ptr != NULL);
   //Data in new node
   cur_ptr->inputQuest = question;
   cur_ptr->ans = answer;
   cur_ptr->points = pnts;
   cur_ptr->next = NULL;
   //keeps pointer at front of list
   if (list == NULL) {
      list = cur_ptr;
   }
   else {
      cur_ptr->next = list;
      list = cur_ptr;
   }
}


int add_question(pointer& list) {
   string question, answer;
   u_int points, error_code;
   //Asks user for data for a new node.
   cout << "Enter a question: ";
   getline(cin, question);
   
   cout << "Enter an answer: ";
   getline(cin, answer);
   
   cout << "Enter award points: ";
   cin >> points;
   
   cin.clear();
   cin.ignore(INT_MAX, '\n');
   
   cout << "Question: " << question << endl;
   cout << "Answer: " << answer << endl;
   cout << "Score: " << points << endl;
   
   
   //inserts data into node
   error_code = insert_question(list, question, answer, points);
   
   return error_code;
}

int askQuest(pointer head, int numOfQs) {

   string answer;
   u_int score;
   pointer temp = head;
   
   //Verifies that the number of questions to be asked is at least 1.
   if (numOfQs == 0) {
      cout << "Warning - The number of trivia to be asked must be equal to "
             "or larger than 1." << endl;
      return 1;
   }
   
   //Verifies the number of questions to be asked is no more than the number
   //of questions that are available.
   if (numOfQs > quesCount) {
      cout << "Warning - There are only " << quesCount << " trivia in the list." << endl;
      return 1;
   }
    
   //Asks question found in node. Reads and evaluates answer from user. 
   //If correct, adds points to point total.
   //If incorrect, prints correct answer.  
   for (int i = 0; i < numOfQs; i++) {
      cout << temp->inputQuest << endl;
      cout << "Answer: ";
      getline(cin, answer);
      
      if (answer == temp->ans) {
         cout << "Correct. You receive " << temp->points << " points." << endl;
         score += temp->points;
         cout << "Your total points: " << score << endl;
      }
      else {
         cout << "Incorrect. The correct answer is: " << temp->ans << endl;
         cout << "Your total points: " << score << endl;
      }
      temp = temp->next;
   } 
    
   
   
   return 0;
}

/********************Test driver**********************************/

void test_askQuest() {

   cout << "*** This is a debugging version ***" << endl;

   int returnResult;
   hardCodeQs();
   cout << "Unit Test Case 1: Ask no question. The program should give a "
           "warning\n message." << endl;
   returnResult = askQuest(head, 0);
   assert(returnResult == 1);
   cout << "Case 1 passed..." << endl;
           
   cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester\n"
           "enters an incorrect answer." << endl;
   returnResult = askQuest(head, 1);
   assert(returnResult == 0);
   cout << "Case 2.1 passed..." << endl;
   
   
   cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester\n"
           "enters the correct answer." << endl;
   returnResult = askQuest(head, 1);
   assert(returnResult == 0);
   cout << "Case 2.2 passed..." << endl;
   
   cout << "Unit Test Case 3: Ask all the questions in the linked list." << endl;
   returnResult = askQuest(head, 3);
   assert(returnResult == 0);
   cout << "Case 3 passed..." << endl;
   
   cout << "Unit Test Case 4: Ask five questions in the linked list." << endl;
   returnResult = askQuest(head, 5);
   assert(returnResult == 1);
   cout << "Case 4 passed..." << endl;

   cout << "\n *** End of the Debugging Version *** ";
}
   
           

           
           
           

