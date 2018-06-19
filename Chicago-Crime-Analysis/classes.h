/*classes.h*/

//
// Classes for use with Chicago Crime Analysis program, e.g. "CrimeReport" 
// and "CrimeCode".
//
// << SAIKRISHNA YADAVALLI >>
// U. of Illinois, Chicago
// CS 341: Spring 2018
// Project 02
//

#pragma once

#include <iostream>
#include <string>

using namespace std;

// Class creation for each crime code.
class CrimeCode
{
  // Private members of the CrimeCode class.
  private:
    string IUCR;
    string primaryDescription;
    string secondaryDescription;
    int member;
    
  public:
    // Default constructor.
    CrimeCode(string iucr, string primaryDesc, string secondaryDesc)
      : IUCR(iucr), primaryDescription(primaryDesc), secondaryDescription(secondaryDesc)
    { }
    
    string getIUCR()
    {
      return IUCR;
    }
    
    string getPrimaryDescription()
    {
      return primaryDescription;
    }
    
    string getSecondaryDescription()
    {
      return secondaryDescription;
    }
    
    int getNumMembers()
    {
      return member;
    }
    
    void NumMembers()
    {
      member++;
    }
};

// Class creation for each crime.
class CrimeReport
{
  // Private members of the CrimeReport class.
  private:
    string dateAndTime;
    string IUCR;
    string Arrest;
    string DomesticViolence;
    int Beat;
    int District;
    int Ward;
    int Community;
    int Year;
  
  public:
    // Default constructor.
    CrimeReport(string dtTime, string iucr, string arrest, string domesticViolence, int beat, int district, int ward, int community, int year)
      : dateAndTime(dtTime), IUCR(iucr), Arrest(arrest), DomesticViolence(domesticViolence), Beat(beat), District(district), Ward(ward), Community(community), Year(year)
    { }
    
    string getDateAndTime()
    {
      return dateAndTime;
    }
    
    string getIUCR()
    {
      return IUCR;
    }
    
    bool isArrested()
    {
      if (Arrest == "TRUE" || Arrest == "true")
        return true;
      else
        return false;
    }
    
    bool isDomesticViolence()
    {
      if (DomesticViolence == "TRUE" || DomesticViolence == "true")
        return true;
      else
        return false;
    }
    
    int getBeat()
    {
      return Beat;
    }
    
    int getDistrict()
    {
      return District;
    }
    
    int getWard()
    {
      return Ward;
    }
    
    int getCommunity()
    {
      return Community;
    }
    
    int getYear()
    {
      return Year;
    }
};
