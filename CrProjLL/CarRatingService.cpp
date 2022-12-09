//
//  CarRatingService.cpp
//  CarRatingproj
//
//
#include "CarRating.hpp"
#include "CarRatingService.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//a default constructor that takes no arguments. Holds zero types.
CarRatingService::CarRatingService() {
    _head = NULL;
    _tail = NULL;
    curIndex = 0;
}
// Constructor to read in files
CarRatingService::CarRatingService(std::istream& stream){
    //Loop through file and copy over the stored CarRating info.
    CarRating cr;
    stream >> cr;
    while(stream) {
        this->operator+=(cr);
        stream >> cr;
    }
}

// Return the rating of cars
int CarRatingService::numCars()
{
    return curIndex;
}
//Clear the collection
void CarRatingService::clear()
{
    Link* node = _head;
    Link* next;
    
    _head = NULL;
    _tail = NULL;
    curIndex = 0;
    
    while (node) {
        next = node->next;
        delete node;
        node = next;
    }
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
CarRatingService& CarRatingService::operator=(const CarRatingService& car)
{
    this->clear();

    const Link* node = car._head;
    while(node){
        this->operator+=(node->data);
        node = node->next;
    }
    return *this;
}
// Appends the ratings to the list
CarRatingService& CarRatingService::operator+=(const CarRating& car)
{
    Link* link  = new Link(car);
    if (_tail) {
        _tail->next = link;
        _tail = link;
    }
    else
    {
        _head = link;
        _tail = link;
    }
    curIndex++;
    
    return *this;
}
//Updating the Car Rating index
CarRatingService& CarRatingService::operator+=(const CarRatingService& car)
{
    Link* cur = car._head;
    while(cur){
        this->operator+=(cur->data);
        cur = cur->next;
    }
    
    return *this;
}
//Remove the Car Rating and updates it
CarRatingService& CarRatingService::operator-=(const std::string& crs)
{
    Link* prv = NULL;
    Link* cur = this->_head;
    while(cur){
        //comparison
        // +-> if true, remove block
        if (cur->data.make()==crs) {
            if (prv) {
                prv->next = cur->next;
            }
            else {
                //Interacting with HEAD
                _head = cur->next;
            }
            if (cur->next == NULL) {
                _tail = prv;
            }
            // delete the current node
            delete cur;
            curIndex--;
            break;
        }
        //prev node is = to the cur so update the cur node with the next one
        prv = cur;
        cur = cur->next;
    }
   

    return *this;
        
}
//Print out car ratings
std::ostream& operator<<(std::ostream& os, const CarRatingService& crs) {
    //Loop through and print out each item.
    const CarRatingService::Link* link = crs._head;
    while(link) {
        os << link->data << std::endl;
        link = link->next;
    }
    return os;
}
