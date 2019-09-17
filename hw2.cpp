// name: Andrew Bradley, acb0019
// partner: none
//filename: hw2.cpp
//due date: 9/6/2018
//collaboration: We did not use any external sources for this assignment.
//problem: build a loan calculator to determine monthly payments on a loan

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   double loanAmt, intRate, monthPaymts, monthlyIntRate, balance; 
   double interest, principal, totInt;
   int month;
   
   //Sets decimal number format. 
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
      //Loan details.
   cout << "Loan Amount: ";
   cin >> loanAmt;
   cout << "Interest Rate (% per year): ";
   cin >> intRate;
   cout << "Monthly Payments: ";
   cin >> monthPaymts;
   
   monthlyIntRate = intRate / 12.0;
   
   
  
      
      
   
   cout << "******************************************************\n"
           "         Amortization Table                           \n"
           "******************************************************\n"
           "Month    Balance  Payment  Rate   Interest   Principal\n"
           "0        " << loanAmt << "   N/A      N/A    N/A        N/A\n"; 
           
   balance = loanAmt;
   month = 0;
   totInt = 0;
   //interest check
   interest = balance * monthlyIntRate / 100;
   if (interest > monthPaymts) {
      cout << "Error: monthly payment is less than interest.";
      return 0;
   }

   
   while (balance > 0) {
      
      month++;
      interest = balance * monthlyIntRate / 100;
      if (interest > monthPaymts) {
         cout << "Error: monthly payment is less than interest.";
         break;
      }
      totInt += interest;
      principal = monthPaymts - interest;
      if (principal > balance) {
         balance = 0;
      }
      else {
         balance = balance - principal;
      }
      cout << left << setw(10) << month << setw(8) << balance << setw(10) 
           << monthPaymts << setw(8) <<  monthlyIntRate  << setw(10) 
           << interest << principal << endl;
   }
      
      
   cout << "******************************************************\n\n"
          "It takes " << month << " months to pay off the loan.\n"
          "Total interest paid is: " << totInt << endl;         
}