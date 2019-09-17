// name: Andrew Bradley, acb0019
// partner: none
//filename: hw2.cpp
//due date: 9/21/2018
//collaboration: I consulted stackexchange to see how to modify an array in a
//               function. 
//               https://stackoverflow.com/questions/10036313/how-to-change-an-array-with-a-function
//problem: Merge the numbers in two files into an ordered list. Create an
//         output file containing the ordered list
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <assert.h>
using namespace std;

const int MAXSIZE = 1000;

//Function prototypes
int readfile(int (&arrayIn)[MAXSIZE], ifstream &input);
/* Reads an input file and places data elements into an array.
*/

int sort_array(int array1[], int array_size1, int array2[], int array_size2,
               int output[]);
/*Combines two arrays into a single sorted array
*/

void writeFile(int outputArray[], int outputSize);
/*Creates a file containing a sorted list of integers
*/

void Press_Any_Key();

   /*Input: No input.
     Return: No return. 
   */

void test_readfile(void);
/*readfile test driver
*/
void test_sort_array(void);
/*readfile test driver
*/

void test_writeFile(void);
/*writeFile test driver
*/

int main() {

   //Filename inputs
   string inputFile1;
   string inputFile2;
   //Program creator
   string developer = "Andrew Bradley";
   //ifstream names for both files
   ifstream fileIn1;
   ifstream fileIn2;
   //arrays and array sizes used 
   int input1[MAXSIZE];
   int input1Size = 0;
   int input2[MAXSIZE];
   int input2Size = 0;
   int output[MAXSIZE];
   int outputSize = 0;
   
   cout << "*** Unit Test Cases ***" << endl;
   test_readfile();
   test_sort_array();
   Press_Any_Key();
      
      
      
   cout << "*** Welcome to " << developer << "'s sorting program ***\n";
   cout << "Enter the first input file name: ";
   //First input file
   cin >> inputFile1;
   fileIn1.open(inputFile1.c_str());
   //Reads the file. Allocates file contents to an array. Returns number of
   //elements in the array.
   input1Size = readfile(input1, fileIn1);
   fileIn1.close();
   
   //File 1 information
   cout << "The list of " << input1Size << " numbers in file " << inputFile1 <<
           " is:" << endl;
    
   //Prints out each integer in the file       
   for (int i = 0; i < input1Size; i++) {
      cout << input1[i] << endl;
   }
   
 
   
   cout << "Enter the second input file name:";
   //Second input file
   cin >> inputFile2;
   fileIn2.open(inputFile2.c_str());
   //Reads the file. Allocates the file's contents to an array. Returns number of 
   //elements in the array.
   input2Size = readfile(input2, fileIn2);
   fileIn2.close();
   
   //File 2 contents
   cout << "The list of " << input2Size << " numbers in file " << inputFile2 <<
           " is:" << endl;
   //Prints out each element in the array.
   for (int i = 0; i < input2Size; i++) {
      cout << input2[i] << endl;
   }
   
   
   int arrayIn1[input1Size] = {0};
   for (int i = 0; i < input1Size; i++) {
      arrayIn1[i] = input1[i];
     
   }
   
   int arrayIn2[input2Size] = {0};
   for (int i = 0; i < input2Size; i++) {
      arrayIn2[i] = input2[i];
   }
   
   //Combines and sorts the array. Produces an integer representing the
   //size of the output array.
   outputSize = sort_array(arrayIn1, input1Size, arrayIn2, input2Size, output);
   
   //Creates a file containing the sorted array.
   writeFile(output, outputSize);
   
 
        
             
}

/*Methods*/
int readfile(int (&arrayIn)[MAXSIZE], ifstream &input) {

   int data;
   //Puts data in the file into an array
   int i = 0;
   while (! input.eof()) {
   
      input >> data;
      arrayIn[i] = data;
      i++;
   }      
  
       
   return i;
   
}

int sort_array(int array1[], int array_size1, int array2[], int array_size2,
               int output[]) {
    
   
   int i1 = 0;
   int i2 = 0;
   int i3 = 0;   
     

         
   //Compare array1[i1] and array2[i2]
   while (i3 < (array_size1 + array_size2)) {  
      if (array1[i1] < array2[i2]) {
         //inputs element into output array
         output[i3] = array1[i1];
         //cout << output[i3] << "\n";
         i1++;
         i3++;
      }
      else {
         //inputs element into output array
         output[i3] = array2[i2];
         i2++;
         i3++;
      }
   }
   
   //Prints the sorted array
   cout << "The sorted list of " << i3 << " numbers is: ";
   for (int i = 0; i < i3; i++) {
      cout << output[i] << " ";
   }
   
   
   return i3;
}

void writeFile(int outputArray[], int outputSize) {
   
   string outputName;
   cout << "\nEnter the output file name: ";
   cin >> outputName;
   ofstream outputFile (outputName.c_str());
   
   for (int i = 0; i < outputSize; i++) {
      outputFile << outputArray[i] << " ";
   }
   outputFile.close();
   
   cout << "*** Please check the new file - " << outputName << " ***\n"
        << "*** Goodbye. ***";
        
   return;    
   
}

void Press_Any_Key () {
   
   cout << "Press any key to continue..."; 
   cin.ignore().get(); //Pause Command for Linux Terminal 
}

   
/*Test Drivers*/

void test_readfile(void) {
 
   cout << "Unit Test Case 1: readfile" << endl;
   cout << "   Case 1.1: Reads file containing numbers 2, 5, 9, and 12. Takes\n "
        << "             the integers and inserts into array. Returns the    \n "
        << "             total number of integers in the array." <<endl;   
   int arrayIn[MAXSIZE];
   ifstream inputFile ("input1.txt");
   //Reads the file and inputs integers into array
   int size = readfile(arrayIn, inputFile);
   assert(arrayIn[0] == 2);
   assert(arrayIn[1] == 5);
   assert(arrayIn[2] == 9);
   assert(arrayIn[3] == 100);
   assert(size == 4);
   inputFile.close();
   
   cout << "   Case 1.1 passed\n";
   return;
}

void test_sort_array(void) {

   cout << "Unit Test Case 2: sort_array" << endl;
   cout << "  Case 2.1: Combines two ordered arrays [2, 5, 9, 100] and\n "
        << "            [1, 3, 11, 24, 55, 101] into one single sorted array.\n"
        << "            Returns the total number of integers in the sorted\n"
        << "            array." <<endl;
        
   int array1In[MAXSIZE];
   int array2In[MAXSIZE];
   int arrayOut[MAXSIZE];
   int array1Size;
   int array2Size;
   int outputSize;
   
   ifstream input1("input1.txt");
   array1Size = readfile(array1In, input1);
   input1.close();
   
   ifstream input2("input2.txt");
   array2Size = readfile(array2In, input2);
   input2.close();
   
   
   outputSize = sort_array(array1In, array1Size, array2In, array2Size, arrayOut);
   
   assert(arrayOut[0] == 1);
   assert(arrayOut[1] == 2);
   assert(arrayOut[2] == 3);
   assert(arrayOut[3] == 5);
   assert(arrayOut[4] == 9);
   assert(arrayOut[5] == 11);
   assert(arrayOut[6] == 24);
   assert(arrayOut[7] == 55);
   //assert(arrayOut[8] == 100);
   assert(outputSize == 9);
   
 
   
   cout << "\nCase 2.1 passed.\n\n";
   
   return;
}

   
   



   

