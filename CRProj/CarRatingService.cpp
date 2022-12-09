//
//  CarRatingService.cpp
//  CarRatingproj
//
#include "CarRating.hpp"
#include "CarRatingService.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//a default constructor that takes no arguments. This should simply make the collection be capable of holding up to 5 car types, but initially holds zero types.
CarRatingService::CarRatingService() {
    _Cars = new CarRating[5];
    arrSize = 5;
    curIndex = 0;
}
// Constructor to read in files
CarRatingService::CarRatingService(std::istream& stream){
    //Loop through file and copy over the stored CarRating info.
    //CarRating cr; stream >> cr; Insert cr to PFA;
    CarRating cr;
    stream >> cr;
    while(stream) {
        this->operator+=(cr);
        stream >> cr;
    }
}
// resize function to change size of array when needed
bool CarRatingService::resize()
{
    // if statement to allocate new memory
    if (arrSize >= curIndex) return true;
   
    CarRating *temp = new CarRating[2*arrSize];
        for (int i=0; i<arrSize; i++) {
          temp[i] = _Cars[i];
        }
    //Store resize in temp
    _Cars = temp;
    //Update array size
    arrSize = arrSize * 2;
      return true;
}

// Return the rating of cars
int CarRatingService::numCars()
{
    return curIndex;
}
//Clear the collection
void CarRatingService::clear()
{
    curIndex = 0;
}
// Cout the make
void CarRatingService::printMake(const std::string& _make)
{
    cout << "What is the make of car? " << _make << endl;
}
//cout the model
void CarRatingService::printModel(const std::string& _model)
{
    cout << "What is the model of car? " << _model << endl;
}
//cout the year
void CarRatingService::printYear(int _year)
{
    cout << "What is the year of car? " << _year << endl;
}
// Set the CarRatingService to equal
CarRatingService& CarRatingService::operator=(const CarRatingService& other)
{
    _Cars = new CarRating[other.arrSize];
    
    //loop through the list and copy the array
    for (int i = 0; i < other.curIndex; i++) {
        _Cars[i] = other._Cars[i];
    }
    
    curIndex = other.curIndex;
    arrSize = other.arrSize;
    
    return *this;
}
//
CarRatingService& CarRatingService::operator+=(const CarRating& car)
{
    CarRating* existing = NULL;
    for(int i = 0; i < curIndex; i++)
        if(_Cars[i] == car){
            existing = &_Cars[i];
            break;
        }
    
    //We need to check for an existing entry in the array
    if(existing){
        existing->addNewRating(car.rating());
    }else{
        //We dont exist.
        if (curIndex==arrSize) {
            //We've excceded the bounds the array so resize
            resize();
        }
        //We have room to insert our object now.
        _Cars[curIndex] = car;
        //Insert into the PFA at curIndex.
        curIndex++;
    }
    return *this;
}
//Updating the Car Rating index
CarRatingService& CarRatingService::operator+=(const CarRatingService& name)
{
    for (int i = 0; i < name.curIndex; i++) {
        this->operator+=(name._Cars[i]);
    }
    
    return *this;
}
//Remove the Car Rating and updates it
CarRatingService& CarRatingService::operator-=(const std::string& name)
{
    for(int i=0; i<curIndex; i++)
        if(_Cars[i].model() == name ) {
            curIndex--;
            for (int x = i; x <curIndex; x++) {
                _Cars[x] =_Cars[x+1];
            }
        }
    return *this;
        
}
//Print out car ratings
std::ostream& operator<<(std::ostream& os, const CarRatingService& o) {
    for(int i=0; i < o.curIndex; i++)
    {
        os << o._Cars[i] << endl;
    }
    return os;
}
