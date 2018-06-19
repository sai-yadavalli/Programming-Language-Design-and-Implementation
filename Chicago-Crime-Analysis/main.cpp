#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

#include "classes.h"

using namespace std;

// Sort the crime codes and output the first 3 AND last 3 crime codes.
void SortByCrimeCodeAndPrint(vector<CrimeCode>& codes, int numCrimeCodes)
{
  cout << std::fixed;
  cout << std::setprecision(2);
  
  // Sort crime codes by IUCR.
  sort(codes.begin(),
       codes.end(),
       [](CrimeCode c1, CrimeCode c2)
       {
         if (c1.getIUCR() < c2.getIUCR())
         {
           return true;
         }
         
         else if (c1.getIUCR() > c2.getIUCR())
         {
           return false;
         }
       }
  );
  
  // Output first 3 crime codes.
  int count = 0;
  for (CrimeCode& c : codes) {
    cout << c.getIUCR() << ":   " << c.getPrimaryDescription() << ":" << c.getSecondaryDescription() << endl;
    count++;
    if (count == 3)
      break;
  }
  
  cout << "..." << endl;
  
  // Output last 3 crime codes.
  for (auto i = numCrimeCodes - 3; i < numCrimeCodes; ++i) {
    cout << codes[i].getIUCR() << ":   " << codes[i].getPrimaryDescription() << ":" << codes[i].getSecondaryDescription() << endl;
  }
}

// Display the first 3 and last 3 crimes.
void PrintCrimes(vector<CrimeReport>& crimes, int numCrimes)
{
  
  cout << std::fixed;
  cout << std::setprecision(2);
  
   // Output first 3 crimes. Create 4 cases to check if either 1) an arrest is made, 2) there is domestic violence, 3) BOTH an arrest and domestic violence are true, or 4) NEITHER, for each crime.
   
  for (auto i = 0; i < 3; ++i) {
    if (crimes[i].isArrested() == true && crimes[i].isDomesticViolence() == false) {
      cout << crimes[i].getIUCR() << ":   " << crimes[i].getDateAndTime() << ", " << crimes[i].getBeat() << ", " << crimes[i].getDistrict() << ", " << crimes[i].getWard() << ", " << crimes[i].getCommunity() << ", arrested" << ", "<< endl;
    }
    else if (crimes[i].isDomesticViolence() == true && crimes[i].isArrested() == false) {
       cout << crimes[i].getIUCR() << ":   " << crimes[i].getDateAndTime() << ", " << crimes[i].getBeat() << ", " << crimes[i].getDistrict() << ", " << crimes[i].getWard() << ", " << crimes[i].getCommunity() << ", domestic violence" << endl;
    }
    else if (crimes[i].isArrested() == true && crimes[i].isDomesticViolence() == true) {
      cout << crimes[i].getIUCR() << ":   " << crimes[i].getDateAndTime() << ", " << crimes[i].getBeat() << ", " << crimes[i].getDistrict() << ", " << crimes[i].getWard() << ", " << crimes[i].getCommunity() << ", arrested" << ", domestic violence" << endl;
    }
    else {
      cout << crimes[i].getIUCR() << ":   " << crimes[i].getDateAndTime() << ", " << crimes[i].getBeat() << ", " << crimes[i].getDistrict() << ", " << crimes[i].getWard() << ", " << crimes[i].getCommunity() << endl;
    }
  }
   
  
  cout << "..." << endl;
  
  
   // Output last 3 crimes. Create 4 cases to check if either 1) an arrest is made, 2) there is domestic violence, 3) BOTH an arrest and domestic violence, or 4) NEITHER, for each crime.
   
  for (auto i = numCrimes - 3; i < numCrimes; ++i) {
    
    if (crimes[i].isArrested() == true && crimes[i].isDomesticViolence() == false) {
      cout << crimes[i].getIUCR() << ":   " << crimes[i].getDateAndTime() << ", " << crimes[i].getBeat() << ", " << crimes[i].getDistrict() << ", " << crimes[i].getWard() << ", " << crimes[i].getCommunity() << ", arrested" << endl;
    }
    
    else if (crimes[i].isDomesticViolence() == true && crimes[i].isArrested() == false) {
       cout << crimes[i].getIUCR() << ":   " << crimes[i].getDateAndTime() << ", " << crimes[i].getBeat() << ", " << crimes[i].getDistrict() << ", " << crimes[i].getWard() << ", " << crimes[i].getCommunity() << ", domestic violence" << endl;
    }
    
    else if (crimes[i].isArrested() == true && crimes[i].isDomesticViolence() == true) {
      cout << crimes[i].getIUCR() << ":   " << crimes[i].getDateAndTime() << ", " << crimes[i].getBeat() << ", " << crimes[i].getDistrict() << ", " << crimes[i].getWard() << ", " << crimes[i].getCommunity() << ", arrested" << ", domestic violence" << endl;
    }
    
    else {
      cout << crimes[i].getIUCR() << ":   " << crimes[i].getDateAndTime() << ", " << crimes[i].getBeat() << ", " << crimes[i].getDistrict() << ", " << crimes[i].getWard() << ", " << crimes[i].getCommunity() << endl;
    }
  }
}

// Compute and output top-5 crimes.
void Vector2CrimeCodeMap(const vector<CrimeCode>& codes, const vector<CrimeReport>& crimes)
{
  
  // Declare a map-container.
  map<string, CrimeCode> M;
  
  // Store the crime codes into the map.
  for (CrimeCode c : codes) {
    auto keyvaluepair = pair<string, CrimeCode>(c.getIUCR(), c);
    M.insert(keyvaluepair);
  }
  
  // Loop through the crimes, search for the IUCRs, and count the # of occurrences for each such crime-code.
  for (CrimeReport cr : crimes) {
    auto iter = M.find(cr.getIUCR());
    iter->second.NumMembers();
  }
  
  // Declare another vector container.
  vector<pair<string, CrimeCode>> V;
  
  
  // Copy the contents of the map into the new vector.
  for (auto& cc: M) {
    V.push_back(cc);
  }
  
  // Sort the top-5 crimes in descending order by the total number of crimes for each unique IUCR.
  sort(V.begin(),
       V.end(),
       [=](pair<string, CrimeCode>& c1, pair<string, CrimeCode>& c2)
       {
         if (c1.second.getNumMembers() > c2.second.getNumMembers())
         {
           return true;
         }
         
         else if (c1.second.getNumMembers() < c2.second.getNumMembers())
         {
           return false;
         }
       }
  );

  // Output the top-5 crimes.
  for (int i = 0; i < 5; ++i) {
    cout << V[i].second.getIUCR() << ":   " << V[i].second.getNumMembers() << ", " << V[i].second.getPrimaryDescription() << ": " << V[i].second.getSecondaryDescription() << endl;
  }
}


int main()
{
  string  crimeCodesFilename, crimesFilename;

  // Input the file names.
  cin >> crimeCodesFilename;
  cin >> crimesFilename;
  
  cout << crimeCodesFilename << endl;
  cout << crimesFilename << endl;
  
  // Use ifstream to open/close both of the .csv files.
  ifstream  codesFile(crimeCodesFilename);
  ifstream  crimesFile(crimesFilename);

  cout << std::fixed;
  cout << std::setprecision(2);

  // Check if the crime codes file was opened successfully.
  if (!codesFile.good())
  {
    cout << "**ERROR: cannot open crime codes file: '" << crimeCodesFilename << "'" << endl;
    return -1;
  }
  
  // Check if the crimes file was opened successfully.
  if (!crimesFile.good())
  {
    cout << "**ERROR: cannot open crimes file: '" << crimesFilename << "'" << endl;
    return -1;
  }
    
    
  //--------------------------------------------------------------------
  
  // 
  // TODO
  //
  
  
  
  cout << "** Crime Analysis **" << endl << endl;
 
 
  //--------------------------------------------------------------------
  
  // Input data from crime codes file.
  string line, iucr, pmryDesc, scndryDesc;
  
  // Input data into a vector of CrimeCode objects.
  vector<CrimeCode> codes;
  
  getline(codesFile, line);       // skip header.
  
  int numCrimeCodes = 0;              
  
  while (getline(codesFile, line))
  {
    // Use stringstream to help parse the .csv file.
    stringstream cc(line);
    
    // Parse line.
    getline(cc, iucr, ',');
    getline(cc, pmryDesc, ',');
    getline(cc, scndryDesc);
    
    // Increment the total number of crime codes.
    numCrimeCodes++;
    
    CrimeCode CC(iucr, pmryDesc, scndryDesc);
    
    // insert @ end.
    codes.push_back(CC);
  }
  
  
  //--------------------------------------------------------------------
  
  // Input data from the crimes file.
  
  string dtAndTime, arrest, domesViolence, beat, dstrct, ward, community, year;
  
  // Input data into a vector of Crime objects.
  vector<CrimeReport> crimes;
  
  getline(crimesFile, line);       // skip header.
  
  int numCrimes = 0;              
  
  while (getline(crimesFile, line))
  {
    // Use stringstream to help parse the .csv file.
    stringstream cr(line);
    
    // Parse line.
    getline(cr, dtAndTime, ',');
    getline(cr, iucr, ',');
    getline(cr, arrest, ',');
    getline(cr, domesViolence, ',');
    getline(cr, beat, ',');
    getline(cr, dstrct, ',');
    getline(cr, ward, ',');
    getline(cr, community, ',');
    getline(cr, year);
    
    // Increment the total number of crimes.
    numCrimes++;
    
    CrimeReport CR(dtAndTime, iucr, arrest, domesViolence, stoi(beat), stoi(dstrct), stoi(ward), stoi(community), stoi(year));
    
    // insert @ end.
    crimes.push_back(CR);
  }
  
  
  //--------------------------------------------------------------------
  // Output the date range.
  
  for (auto i = 0; i < 1; ++i)
    cout << "Date range: " << crimes[i].getDateAndTime() << " - ";
  
  for (auto i = numCrimes - 1; i < numCrimes; ++i) 
    cout << crimes[i].getDateAndTime() << endl << endl;

  
  //--------------------------------------------------------------------
  
  // Output the total # of crime codes.
  
  // Display the total number of crime codes.
  cout << "# of crime codes: " << numCrimeCodes << endl;
  
  
  //--------------------------------------------------------------------
  
  // Sort by crime code and output first 3 and last 3 crime codes.
  
  SortByCrimeCodeAndPrint(codes, numCrimeCodes);
  
  
  //--------------------------------------------------------------------
  
  //Output the total # of crimes.
  
  cout << endl << "# of crimes: " << numCrimes << endl;
  
  
  //--------------------------------------------------------------------
  
  // Output first 3 and last 3 crimes.
  PrintCrimes(crimes, numCrimes);
  
  cout << endl << "** Top-5 Crimes **" << endl;
  
  cout << "Code:   " << "Total, " << "Description" << endl;
  
  
  //--------------------------------------------------------------------
  
  // Compute and output the top-5 crimes using a map.
  Vector2CrimeCodeMap(codes, crimes);
  
  cout << endl << "** Done **";
  return 0;
}
