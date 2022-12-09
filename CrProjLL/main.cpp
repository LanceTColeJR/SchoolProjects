//
//  main.cpp
//  CrProjLL
//
//

#include <iostream>
#include <fstream>
#include "CarRatingService.hpp"
#include "CarRating.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
  //My own test case
//    CarRatingService service;
//    service += CarRating{"Jeep","Test",2001};
//    service += CarRating{"Jepp","Test1", 2011};
//
//    std::cout << service << std::endl << std::endl;

//    CarRating car("Toyota", "Prius", 2018);
//
//    cout << car << endl;
//
//    cout << "Give a rating for the car (-1 to stop):";
//    int rVal;
//    cin >> rVal;
//
//    while (rVal!=-1)
//      {
//        car+=rVal;
//        cout << car << endl;
//
//        cout << "Give a rating for the car (-1 to stop):";
//        cin >> rVal;
//      }
//
//    cout << endl
//         << "And the final tally:" << endl
//         << "Make:" << car.make() << endl
//         << "Model:" << car.model() << endl
//         << "Year:" << car.year() << endl
//         << "Rating:" << car.rating() << endl
//         << "Number of Ratings:" << car.numRatings() << endl;
//
//
//    cout << endl
//         << "Wait .. just one more ridiculous rating ..." << endl;
//
//    car.addNewRating(65535);
//    cout << car << endl;
    
//    if (argc!=2)
//      {
//        cerr << "ERROR - USAGE: " << argv[0] << " <input file name>" << endl;
//        return 1;
//      }
//
//    ifstream ifile(argv[1]);
//
//    CarRatingService  crs(ifile);
//
//    ifile.close();
//
//    cout << crs;
//
//    cout << "There were " << crs.numCars() << " cars rated" << endl << endl;
//
//    cout << "Now clearing the service ...." << endl;
//    crs.clear();
//    cout << "There are now " << crs.numCars() << " cars rated (should be 0)" << endl;
//    cout << "===== So there should be nothing between this line =====" << endl;
//    cout << crs;
//    cout << "===== and this line =====" << endl;
    
//    ifstream ifile;
//
//    if (argc==1)
//    {
//      ifile.open("input1.txt");
//      if (!ifile)
//      {
//        cerr <<"could not open default input file (input1.txt)" << endl;
//        return 1;
//      }
//    }
//    else if (argc==2)
//    {
//      ifile.open(argv[1]);
//      if (!ifile)
//      {
//        cerr <<"could not open input file (" << argv[1] << ")" << endl;
//        return 1;
//      }
//    }
//    else
//    {
//      cerr << "ERROR - USAGE: " << argv[0] << " <input file name>" << endl;
//      return 2;
//    }
//
//    CarRatingService  crs(ifile);
//
//    ifile.close();
//
//    cout << crs;
//
//    cout << "There were " << crs.numCars() << " cars ratings" << endl;
//
//    cout << endl << endl;
//    cout << "==== ratings after adding a Mustang (NOT in input1.txt) ====" << endl;
//    CarRating stang("Ford", "Mustang", 2020);
//    stang+=3;
//
//    crs+=stang;
//
//    cout << crs;
//
//    cout << endl << endl;
//    cout << "==== ratings after adding duplicate 2018 Prius (IN input1.txt) ====" << endl;
//    CarRating priusDup("Toyota", "Prius", 2018);
//    priusDup+=4;
//
//    crs+=priusDup;
//
//    cout << crs;
    
    
   
    return 0;
}
