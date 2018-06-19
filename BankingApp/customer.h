/*customer.h*/

//
// Customer class for banking program in modern C++.
//
// <<Saikrishna Yadavalli>>
// U. of Illinois, Chicago
// CS 341: Spring 2018
// Project 01
//

#pragma once

#include <iostream>
#include <string>

using namespace std;


class Customer
{

  // 
  // TODO
  //
  private:
    string Name;
    int ID;
    double Balance;
  
  public:
    Customer(string name, int ID, double balance)
      : Name(name), ID(ID), Balance(balance) {}
      
    string getName() 
    {
      return Name;
    }
    
    int getID()
    {
      return ID;
    }
    
    double getBalance()
    {
      return Balance;
    }
    
    double updateBalance(double amt)
    {
      Balance = Balance + amt;
      return Balance;
    }
  
};
