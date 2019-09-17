// name: Andrew Bradley, acb0019
// partner: none
//filename: hw6.cpp
//due date: 10/18/2018
//collaboration: none
//problem: Create a Doctor class from which Doctor objects can be created. Create
//         methods that can edit or show these attributes. Test the methods for 
//         robustness.

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <assert.h>

using namespace std;
#define UNIT_TESTING_Methods



class Doctor {

   private:
   string name;
   unsigned int numPatients;
   string *patientList;
       
   public:
   //Initializes object.
   Doctor();
   
   //Initializes object and object's name and patient number attributes.
   Doctor(string docName, unsigned int patientNum);
  
   //Sets doctor's name.
   void setName();
   
   //Returns doctor's name.
   string getName();
   
   //Sets number of patients.
   void setPatientNum();
   
   //Returns number of patients.
   unsigned int getPatientNum();
   
   //Sets patient list.
   void setPatientList();
   
   //Returns patient list.
   void getPatientList();
   
   //Sets all the information for a doctor.
   void setAllInfo();
   
   //Returns all the information for a doctor.
   void getAllInfo();
   
   //Resets number of patients to 0 and clears patient list.
   void resetPatList();
   
   //Copies patient list of one doctor to another doctor.
   Doctor& operator =(const Doctor& doc);
   
   //Destructor.
   ~Doctor();    
       
 };
 
 //Tests constructor with no parameters passed in.
void test_constructorNoParams();
 
 //Tests constructor with the name and number of patients passed in.
void test_constructorParams();
 
//Tests SetAllInfo and GetAllInfo methods.
void test_setAndGetAllInfo();

//Tests resetPatList method.
void test_resetPatList();

//Tests assignment operator overload method.
void test_overload();
 
 
 
int main() {
  #ifdef UNIT_TESTING_Constructors
   
   test_constructorNoParams();
   test_constructorParams();


  #endif
  #ifdef UNIT_TESTING_Methods
  
   test_setAndGetAllInfo();
   test_resetPatList();
   test_overload();
   
   #endif
   
   
   return 0;
}
     


//Constructor. Initalizes attributes.
Doctor::Doctor() {
            
   name = "";
   numPatients = 0;
   patientList = new string[100];
}

//Constructor. Uses parameters to get Doctor name and number of patients.
Doctor::Doctor(string docName, unsigned int patientNum){

   name = docName;
   numPatients = patientNum;
   patientList = new string[100];
   
}
   
//Sets the Doctor's name.
void Doctor::setName() {

   cout << "Enter doctor's name: ";
   cin >> name;
   cout << endl;
   return;
}

//Returns the Doctor's name.
string Doctor::getName() {

   cout << "Doctor Name: " << name << endl;
   return name;
}

//Sets the number of patients.
void Doctor::setPatientNum() {

   cout << "Enter number of patients: ";
   cin >> numPatients;
   cout << endl;
   return;
}

//Returns the number of patients.
unsigned int Doctor::getPatientNum() {

   cout << "Number of patients: " << numPatients << endl;
   return numPatients;
}    

//Sets the patient list.
void Doctor::setPatientList() {

   cout << "Enter number of patients and press enter: " << endl;
   cin >> numPatients;
   
   patientList = new string[numPatients];
   for(int i = 0; i < numPatients; i++) {
   
      cout << "Enter patient name and press enter: ";
      cin >> patientList[i];
      
   }
   return;
}
   
 //Prints the patient list.
void Doctor::getPatientList() {

   for(int i = 0; i < numPatients; i++) {
      
      cout << "Patient: " << patientList[i] << endl;
   }
   
   return;
}  

//Sets the doctor's attributes through user input.
void Doctor::setAllInfo() {

   setName();
   setPatientNum();
   patientList = new string[numPatients];
   
   for(int i = 0; i < numPatients; i++) {
   
      cout << "Enter patient name and hit enter: ";
      cin >> patientList[i];
      cout << "\nPatient added." << endl;
      
   }
   
   return;
   
}

//Outputs all doctor attributes.
void Doctor::getAllInfo() {

   getName();
   getPatientNum();
   getPatientList();
   
   
   
   return;
}

//Resets the patient list to empty and the number of patients to zero.
void Doctor::resetPatList() {

   numPatients = 0;
   patientList = new string[numPatients];
   
   cout << "Patient list reset to 0." << endl;
   
   return;
}

//Overloads the assignment operator so that it copies the patient list of
//one doctor to another.
Doctor& Doctor:: operator =(const Doctor &doc) {
   
   //Check to make sure the objects are not the same.
   if (this != &doc) {
      delete [] patientList;
      //Sets the length of the copy list.
      numPatients = doc.numPatients;
      //Initializes the copy of the list.
      patientList = new string[numPatients];
      //Copies the list from one Doctor to another Doctor.
      patientList = doc.patientList;
   }
   return *this;
} 

//Deconstructor
Doctor::~Doctor() {
    
   delete []patientList;
}

   

 /*********************************************************************
 **********************************************************************
 *******************Test Methods***************************************/ 
 
void test_constructorNoParams() {
 
   cout << "Constructor Test 1: No parameters passed in. " << endl;
   Doctor roberts;
   assert(roberts.getName() == "");
   assert(roberts.getPatientNum() == 0);
   cout << "Constructor Test 1 passed." << endl;
}
 
void test_constructorParams() {
 
   cout << "Constructor Test 2: Parameters passed in. " << endl;
   Doctor Bob("Bob", 5);
   assert(Bob.getName() == "Bob");
   assert(Bob.getPatientNum() == 5);
   cout << "Constructor Test 2 passed." << endl;
}
 
void test_setAndGetAllInfo(){
 
   //Test Case 1: Tests the setAllInfo method.
   cout << "Unit Test Case 1.1: Doctor name is correctly set." << endl;
   Doctor roberts;
   cout << "Enter the following information for the doctor's attributes." << endl;
   cout << "name: Roberts\nNumber of Patients: 2\nPatient Names: AJ\nBJ" << endl;
   //name: Roberts
   //number of patients:2
   //patients names: AJ, BJ
   roberts.setAllInfo();
   assert("Roberts" == roberts.getName());
   cout << "Test Case 1.1 passed." << endl;
   
   cout << "Test Case 1.2: Number of patients is correctly set." << endl;
   assert(2 == roberts.getPatientNum());
   cout << "Test Case 1.2 Passed." << endl;
   
   cout << "Test Case 1.3: Patient list is correctly set." << endl;
   roberts.getPatientList();
   cout << "Test Case 1.3 passed." << endl;
   cout << "All information correctly set." << endl;
   
   //Test Case 2: Tests the getAllInfo method. The method should return the exact
   //             same attributes entered in Test Case 1.
   cout << "Unit Test Case 2: All information is correctly returned. The information\n"
           "should be the same as the input." << endl;
   roberts.getAllInfo();
   
   
}
 
void test_resetPatList() {

  //Test Case 3: Tests the resetPatList method. 
   cout << "Unit Test Case 3. Patient list should be reset. Number of patients\n"
           "reset to zero." << endl;
   Doctor roberts("Roberts", 2);
   roberts.resetPatList();
   assert(roberts.getPatientNum() == 0);
   cout << "Unit Test Case 3 passed." << endl;
   
   return;
}
         
   
void test_overload() {

  //Test Case 4. Tests the assignment operator overload.
   cout << "User Test Case 4. Assignment operator copies the patient list of one\n"
          "doctor to another." << endl;
   Doctor roberts;
   cout << "Enter the following information for the doctor's attributes." << endl;
   cout << "name: Roberts\nNumber of Patients: 2\nPatient Names: AJ\nBJ" << endl;
   roberts.setAllInfo();
   Doctor allen;
   cout << "Enter the following information for the 2nd doctor's attributes." << endl;
   cout << "name: Allen\nNumber of Patients: 1\nPatient Name: Carl" << endl;
   allen.setAllInfo();
   allen = roberts;
   cout << "Doctor Allen should now have the same list as Doctor Roberts." << endl;
   allen.getPatientList();
   return;
}


   




      
        




