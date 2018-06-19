#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include <algorithm>

#include "customer.h"

using namespace std;

using std::string;
using std::ifstream;
using std::vector;
using std::stringstream;
using std::getline;
using std::stoi;
using std::sort;
using std::cout;
using std::endl;

// Sort customers in ascending order (by name) and output them.
void SortByNameAndPrint(vector<Customer>& customers)
{
  
  cout << std::fixed;
  cout << std::setprecision(2);
  
  
  // Sort customers.
  sort(customers.begin(),
       customers.end(),
       [](Customer c1, Customer c2)
       {
         if (c1.getName() < c2.getName())
         {
           return true;
         }
         
         else if (c1.getName() > c2.getName())
         {
           return false;
         }
         
       }
  );
  
  cout << ">> Customers before:" << endl;
  
  // Display customers.
  for (Customer& c : customers) {
    cout << " " << c.getName() << " (" << c.getID() << "): $" << c.getBalance() << endl;
  }
  
}

// Sort the customers by balance and output them.
void SortByBalanceAndPrint(vector<Customer>& customers)
{
  cout << std::fixed;
  cout << std::setprecision(2);
  
  
  // Sort customers by balance in descending order. If 2 customers have the same balance, then they are sorted by ascending order by name.
  sort(customers.begin(),
       customers.end(),
       [](Customer c1, Customer c2)
       {
         if (c1.getBalance() > c2.getBalance())
         {
           return true;
         }
         
         else if (c1.getBalance() < c2.getBalance())
         {
           return false;
         }
         
         else 
         {
           if (c1.getName() < c2.getName())
           {
             return true;
           }
           
           else if (c1.getName() > c2.getName())
           {
             return false;
           }
         }
       }
  );
  
  cout << ">> Customers after:" << endl;
  
  for (Customer& c : customers) {
    cout << " " << c.getName() << " (" << c.getID() << "): $" << c.getBalance() << endl;
  }
  
}

int main()
{
  string  customerFilename, transactionsFilename;
  
  // Input both of the csv files.
  cin >> customerFilename;
  cin >> transactionsFilename;
  
  cout << customerFilename << endl;
  cout << transactionsFilename << endl;

  // Open/close both of the input files.
  ifstream  custFile(customerFilename);
  ifstream  txFile(transactionsFilename);

  cout << std::fixed;
  cout << std::setprecision(2);
  
  // Check if both of the input files are opened successfully.
  if (!custFile.good())
  {
    cout << "**ERROR: cannot open customers file: '" << customerFilename << "'" << endl;
    return -1;
  }
  
  if (!txFile.good())
  {
    cout << "**ERROR: cannot open transactions file: '" << transactionsFilename << "'" << endl;
    return -1;
  }
  
  
  
  //------------------------------------------------------------------------------
 
  // 
  // TODO
  //
  
  /*
  // PART 1: INPUT THE NAME OF TWO FILES, THE FIRST CONTAINING CUSTOMER DATA AND THE SECOND CONTAINING BANKING TRANSACTIONS.
  */
  
  // Create a vector of Customer objects.
  vector<Customer> customers;
  
  // Input parsing of custFile.
  string line, name, id, bal;
  
  while (getline(custFile, line)) {
    stringstream ss(line);
    
    getline(ss, name, ',');
    getline(ss, id, ',');
    getline(ss, bal);
    
    Customer C(name, stoi(id), stod(bal));
    
    customers.push_back(C);
  }
  
  
  
  
  /*
  // PART 2: OUTPUT THE CUSTOMER DATA IN ASCENDING ORDER BY NAME.
  */
  
  // Call the following function with the <customers> vector.
  SortByNameAndPrint(customers);
  
  
  
  
  
  /*
  // PART 3: PROCESSING OF TRANSACTIONS 
  */
  
  cout << ">> Processing..." << endl;
  
  // Input parsing of the txFile.
  string amt;
  
  double NewBalance;
  
  while (getline(txFile, line)) {
    stringstream tt(line);
    
    getline(tt, id, ',');
    getline(tt, amt);
    
    int ID = stoi(id);
    double amount = stod(amt);
   
    // Traverse through the vector of customers and check if the IDs for each customer exist.
    bool doesIDExist = false;
    
    for (Customer& c : customers) {
      if (c.getID() == ID) {
        doesIDExist = true;
        break;
      }
    }
    
    // Update the balance for each customer if their respective IDs exist.
    if (doesIDExist == true) {
      for (Customer& c : customers) {
        if (c.getID() == ID) {
          double NewBalance = c.getBalance() + amount;
          if (NewBalance < 0.00) {
            cout << " **Rejected Tx: " << c.getID() << "," << amount << endl;
          }
          else {
            c.updateBalance(amount);
          }
        }
      }
    }
    
    // Flag the invalid transaction and display an error message.
    else if (doesIDExist == false) {
      cout << " **Invalid Tx: " << ID << "," << amount << endl;
    }
  }
  
  
  
  
  /*
  // PART 4: updateBalance
  */
  
  // Sort the customers in descending order by account balance and output them.
  SortByBalanceAndPrint(customers);
  
  return 0;
}
