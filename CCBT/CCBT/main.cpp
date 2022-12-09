//
//  main.cpp
//  CCBT
//
//  Created by Lance Cole on 11/21/22.
//

#include <iostream>
#include <fstream>
#include <iostream>
#include "Candy.hpp"
#include "CandySet.hpp"
using namespace std;

//Uncomment void function to test, test case 10
//void compileTest(const CandySet &tester)
//{
//  // if a line in this function does not compile, you have something
//  // that is not properly declared to be const.
//  // NOTE: warnings are OK.
//  tester.size();
//  CandySet dummy(tester);
//  if (tester == dummy)
//    ;
//  if (dummy == tester)
//    ;
//  if (tester != dummy)
//    ;
//  if (dummy != tester)
//    ;
//  dummy = tester;
//}

int main(int argc, char *argv[])
{
    //1st test case
//    CandySet empty; // default constructor
//      cout << "CandySet's size should be 0 ... it is actually "
//           << empty.size() << endl;
      
      //cout << "CandySet's space left should be 5 ... it is actually "
      //     << empty.spaceLeft() << endl;
    
//    //2nd test case
//    ifstream ifile1("input1.txt");
//      if (!ifile1)
//        {
//          cout << "Could not open \"input1.txt\". Is it in your working directory?"
//       << endl;
//          return 1;
//        }
//      CandySet someCandy(ifile1);
//      cout << "The following should have 4 candy bars in it "
//           << "(see \"input1.txt\" for details)"
//           << endl;
//      cout << "=== begin input1.txt based ===" << endl;
//      cout << someCandy;
//      cout << "=== end input1.txt based ===" << endl;
//      ifstream ifile2("input2.txt");
//      if (!ifile2)
//        {
//          cout << "Could not open \"input2.txt\". Is it in your working directory?"
//       << endl;
//          return 1;
//        }
//      CandySet otherCandy;
//      ifile2 >> otherCandy;
//      cout << "The following should have 8 candy bars in it "
//           << "(see \"input2.txt\" for details)"
//           << endl;
//      cout << "=== begin input2.txt based ===" << endl;
//      cout << otherCandy;
//      cout << "=== end input2.txt based ===" << endl;
    
    //3rd test case
    Candy c1("sucker", 120),
        c2("Chocolate", 150),
        c3("Apple", 80),
        c4("Milkshake", 490),
        c5("FrostedFlakes",95),
        c6("Gobstopper", 199);
      CandySet bag;
      bag+=c1;
      cout << "===== Bag with 1 candy in it =======" << endl << bag << endl;

      bag+=c2;
      cout << "===== Bag with 2 candies in it =======" << endl << bag << endl;

      bag+=c3;
      cout << "===== Bag with 3 candies in it =======" << endl << bag << endl;

      bag+=c4;
      cout << "===== Bag with 4 candies in it =======" << endl << bag << endl;

      bag+=c5;
      cout << "===== Bag with 5 candies in it =======" << endl << bag << endl;
      bag+=c6;
      cout << "===== Bag with 6 candies in it =======" << endl << bag << endl;
      cout << "The set's size should be 6. You got: " << bag.size() << endl;
      Candy tricky("Apple", 80);
      bag+=tricky;
      cout << "===== Bag with attempted duplicate  =======" << endl << bag << endl;
      cout << "The set's size should still be 6. You got: " << bag.size() << endl;
      Candy mean("AppleOfMyEye", 1);
      cout << "===== Bag should now have 7 items in it====" << endl
           << (bag+=mean);
      cout << "The set's size should now be 7. You got: " << bag.size() << endl;

    
    //4th test case
//    ifstream ifile2("input2.txt");
//      if (!ifile2)
//        {
//          cout << "Could not open \"input2.txt\". Is it in your working directory?"
//               << endl;
//          return 1;
//        }
//      CandySet testing(ifile2);
//      cout << "The following should have 8 candy bars in it:" << endl
//           << testing;
//
//      cout << "The set's size should be 8, it is: " << testing.size() << endl;
//
//      Candy removeMe("AlmondJoy", 1);
//      testing-=removeMe;
//      cout << "The following should have 7 candy bars in it:" << endl
//           << testing;
//
//      cout << "The set's size should be 7, it is: " << testing.size() << endl;
//      Candy first("Crunch", 1);
//      testing-=first;
//      cout << "The following should have 6 candy bars in it:" << endl
//           << testing;
//
//      cout << "The set's size should be 6, it is: " << testing.size() << endl;
//      Candy last("OhHenry!", 1);
//      testing-=last;
//      cout << "The following should have 5 candy bars in it:" << endl
//           << testing;
//
//      cout << "The set's size should be 5, it is: " << testing.size() << endl;
//      testing -=  "Goobers";
//      testing -= "MilkyWay";
//      cout << "The following should have 3 candy bars in it:" << endl
//           << testing;
//
//      cout << "The set's size should be 3, it is: " << testing.size() << endl;
//      Candy bad("notThere", 100);
//      testing -= bad;
//      cout << "The set's size should still be 3, it is: " << testing.size() << endl;
//      testing -= "MeanTrick";
//      cout << "The set's size should still be 3, it is: " << testing.size() << endl;
//      CandySet empty;
//      empty -= "Raisinets";
//      cout << "Removing from an empty set should have size 0, it is: "
//           << empty.size() << endl;
    
    //5th test case
//    CandySet initSet;
//      Candy c1("first", 1);
//      Candy c2("second", 2);
//      Candy c3("third", 3);
//      Candy c4("fourth", 4);
//      initSet += c1;
//      initSet += c2;
//      initSet += c3;
//      initSet += c4;
//      cout << "The following should display 4 candies:" << endl << initSet
//           << "Size should be 4, it is: " << initSet.size() << endl;
//
//      CandySet duplicate(initSet);
//      cout << "This duplicate should display 4 candies:" << endl << duplicate
//           << "Size should be 4, it is: " << duplicate.size() << endl;
//      initSet-=c2;
//      cout << endl << "AFTER REMOVING FROM INITIAL SET" << endl
//           << "The initial set should display 3 candies:" << endl << initSet
//           << "initial set size should be 3, it is: " << initSet.size() << endl
//           << "The duplicate should still display 4 candies:" << endl << duplicate
//           << "Duplicate's size should be 4, it is: " << duplicate.size() << endl;
//      duplicate-=c3;
//      cout << endl << "AFTER REMOVING FROM COPY CONSTRUCTED SET" << endl
//           << "The initial set should display 3 candies:" << endl << initSet
//           << "initial set size should be 3, it is: " << initSet.size() << endl
//           << "The duplicate should display 3 candies:" << endl << duplicate
//           << "Duplicate's size should be 3, it is: " << duplicate.size() << endl;
    
    //6th test case
//    CandySet bag;
//      Candy c1("first", 1);
//      Candy c2("second", 2);
//      Candy c3("third", 3);
//      Candy c4("fourth", 4);
//      bag += c1;
//      bag += c2;
//      bag += c3;
//      bag += c4;
//      cout << "The following should display 4 candies:" << endl << bag
//           << "Size should be 4, it is: " << bag.size() << endl;
//      bag.clear();
//      cout << "The following should display 0 candies:" << endl << bag
//           << "Size should be 0, it is: " << bag.size() << endl;
    
    //7th test case
//    CandySet bag;
//      Candy c1("first", 1);
//      Candy c2("second", 2);
//      Candy c3("third", 3);
//      Candy c4("fourth", 4);
//      bag += c1;
//      bag += c2;
//      bag += c3;
//      bag += c4;
//      if (bag.find("third") != NULL)
//        cout << "Correctly found \"third\" ." << endl;
//      else
//        cout << "INCORRECT: Could not find \"third\" ." << endl;
//      Candy *ptrToCandy = bag.find("third");
//      // utilize Candy's += operator.
//      ptrToCandy->operator+=(3);
//      (*ptrToCandy)+=4;
//
//      cout << "In following 4 candies, \"third\" sould have rating of 3.5"
//           << " with 2 ratings:" << endl << bag;
    
    //8th test case
//    CandySet bag1, bag2;
//      Candy c1("first", 1);
//      Candy c2("second", 2);
//      Candy c3("third", 3);
//      Candy c4("fourth", 4);
//      bag1 += c1;
//      bag1 += c2;
//      bag1 += c3;
//      bag1 += c4;
//      bag2 += c3;
//      bag2 += c1;
//      bag2 += c4;
//      cout << "1) ";
//      if (bag1==bag2)
//        cout << "INcorrect: The two bags should not be equal!" << endl;
//      else
//        cout << "CORRECT: The two bags are not equal!" << endl;
//      cout << "2) ";
//      if (bag2==bag1)
//        cout << "INcorrect: The two bags should not be equal!" << endl;
//      else
//        cout << "CORRECT: The two bags are not equal!" << endl;
//      cout << "3) ";
//      if (bag1!=bag2)
//        cout << "CORRECT: The two bags are not equal!" << endl;
//      else
//        cout << "INcorrect: The two bags should not be equal!" << endl;
//      cout << "4) ";
//      if (bag2!=bag1)
//        cout << "CORRECT: The two bags are not equal!" << endl;
//      else
//        cout << "INcorrect: The two bags should not be equal!" << endl;
//      bag2 += c2;
//
//      cout << "5) ";
//      if (bag1==bag2)
//        cout << "CORRECT: The two bags are equal!" << endl;
//      else
//        cout << "INcorrect: The two bags should be equal!" << endl;
//      cout << "6) ";
//      if (bag2==bag1)
//        cout << "CORRECT: The two bags are equal!" << endl;
//      else
//        cout << "INcorrect: The two bags should be equal!" << endl;
//      cout << "7) ";
//      if (bag1!=bag2)
//        cout << "INcorrect: The two bags should be equal!" << endl;
//      else
//        cout << "CORRECT: The two bags are equal!" << endl;
//      cout << "8) ";
//      if (bag2!=bag1)
//        cout << "INcorrect: The two bags should be equal!" << endl;
//      else
//        cout << "CORRECT: The two bags are equal!" << endl;
    
    //9th test case
//    CandySet bag1;
//      ifstream ifile1("input1.txt");
//      if (!ifile1)
//        {
//          cout << "Could not open \"input1.txt\". Is it in your working directory?"
//               << endl;
//          return 1;
//        }
//      ifile1 >> bag1;
//      ifstream ifile2("input2.txt");
//      if (!ifile2)
//        {
//          cout << "Could not open \"input2.txt\". Is it in your working directory?"
//               << endl;
//          return 1;
//        }
//
//      ifile2 >> bag1;
//      cout << "The following should have 8 (*not* 12) Candy objects in it :"
//           << endl << bag1;
//      cout << "Size should be 8. It is: " << bag1.size() << endl;
    
    //10th test case
//    CandySet halloween;
//    CompileTest(halloween);
    
  return 0;
}
