// This is an exmaple that just makes sure you know how to build 
// a program that uses the CarRating class. If you can't get this
// to compile and run, then you are missing something about
// compiling, and should see Dr. Blythe *immediately* ... you
// will be unable to proceed without being able to get this main
// method to run. 
#include <iostream>

#include "CarRating.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  CarRating car("Toyota", "Prius", 2018);

  cout << car << endl;

  cout << "Give a rating for the car (-1 to stop):";
  int rVal;
  cin >> rVal;

  while (rVal!=-1)
    {
      car+=rVal;
      cout << car << endl;
      
      cout << "Give a rating for the car (-1 to stop):";
      cin >> rVal;
    }

  cout << endl
       << "And the final tally:" << endl
       << "Make:" << car.make() << endl
       << "Model:" << car.model() << endl
       << "Year:" << car.year() << endl
       << "Rating:" << car.rating() << endl
       << "Number of Ratings:" << car.numRatings() << endl; 


  cout << endl
       << "Wait .. just one more ridiculous rating ..." << endl;

  car.addNewRating(65535);
  cout << car << endl;
  
  return 0;
}
