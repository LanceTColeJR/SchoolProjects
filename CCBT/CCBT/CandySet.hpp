//
//  CandySet.hpp
//  CCBT
//
//
#ifndef CandySet_hpp
#define CandySet_hpp


#include "Candy.hpp"
#include <fstream>
#include <ostream>
#include <string>

//node class
class Node
{
private:
    Candy* _data;
    Node* _parent;
    Node* _left;
    Node* _right;

public:
    Node();
    bool isLeaf() const;
    int depth() const;

    Node*& parent();
    Node*& left();
    Node*& right();
    Candy*& data();
    
    const Node* parent() const;
    const Node* left() const;
    const Node* right() const;
    const Candy* data() const;

    void getHeight(Node* node);
    bool operator<(const Candy&);
    bool operator==(const Candy&);
    bool operator>(const Candy&);
    void print(std::ostream& os, int tabs) const;
    friend std::ostream& operator<<(std::ostream&, const Node&);
};

//Buid CandySet class
class CandySet
{
private:
    Node* _root;
    int _nodeCount;
    int _maxDepth;
    int TreeDepthCalc(Node*);
    
    Node* TreeInsert(const Candy&,Node*&);
    Node* TreeSearch(const std::string&,Node*);
    Node* TreeRemove(const std::string&);
    
public:
    
    bool insert(const Candy&);
    bool input(const std::string&);
    bool remove(const std::string&);
    bool operator==(const CandySet& other);
    bool operator!=(const CandySet& other);
    bool findsearchset(const Node& other) const;
    
    //Candy Constructor
    CandySet();
    CandySet(std::istream &stream);
    Candy* find(const std::string &_candyBar) const;

    int size();
    void clear();
    
    CandySet& operator+=(const Candy &c);
    CandySet& operator-=(const Candy &c);
    CandySet& operator-=(const CandySet &c);
    CandySet& operator-=(const std::string &cn);
    const CandySet& operator=(const CandySet& cr);
    
    friend std::ostream& operator<<(std::ostream& os, const CandySet& bt);
    friend std::istream& operator>>(std::istream& is, CandySet& bt);
};
#endif /* CandySet_hpp */

