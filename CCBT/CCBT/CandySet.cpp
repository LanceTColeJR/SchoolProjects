//
//  CandySet.cpp
//  CCBT
//
//

#include "CandySet.hpp"
#include "Candy.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Initialize instance variables for the Node Constructor
Node::Node() {
    _parent = NULL;
    _left = NULL;
    _right = NULL;
    _data = NULL;
}

//Initialize instance variables for the Candyset Constructor
CandySet::CandySet() {
    _root = NULL;
    _nodeCount = 0;
    _maxDepth  = 0;
}


bool Node::isLeaf() const { return !(_left || _right); }

int Node::depth() const {
    int count = 0;
    const Node* parent = _parent;
    while(parent){
        count++;
        parent = parent->_parent;
    }
    return count;
}

//Acessors
Node*& Node::parent() { return _parent; }
Node*& Node::left() { return _left; }
Node*& Node::right() { return _right; }
Candy*& Node::data() { return _data; }

const Node* Node::parent() const { return _parent; }
const Node* Node::left() const { return _left; }
const Node* Node::right() const { return _right; }
const Candy* Node::data() const { return _data; }

//read in files
CandySet::CandySet(std::istream& stream) {
    stream >> *this; //call istream
}

//find the Candy Bars
Candy* CandySet::find(const std::string& _candyBar) const {
    Node *curr = _root; // Set the curr node as the root
    while ( curr && (curr->data()->name()) != _candyBar) // if the root has a value, pointer does not equal a new value
    {
        if ((curr->data()->name()) > _candyBar) { // if the root has data, curr is pointing to the left
            curr = curr->left();
        }
        else if ((curr->data()->name()) < _candyBar) // else, if the data is in the left, check if data is in the right.
        {
            curr = curr->right();
        }
    }
    return curr->data(); //return current data in the tree

}


//return the amount of CandyBars
int CandySet::size() {

    return _maxDepth;
}

// Insert Node into the tree
Node* CandySet::TreeInsert(const Candy& target, Node*& node) {
    if(!node) { //if no node is not in the tree, insert a new node
        node = new Node();
        node->data() = new Candy(target);
        _nodeCount++;
        return node;
    }
    
    if(*node > target) { //If the ndptr is greater than target, insert the node the left side of the tree
        Node* fNode = TreeInsert(target, node->left());
        if(fNode && !fNode->parent()) {
            //new node points to parent
            fNode->parent() = node;
            //point new node and insert into depth
            int depth = fNode->depth();
            if(depth > _maxDepth)
                _maxDepth = depth;
        }
        return fNode;
    }
    
    if(*node == target) //if the node is equal to the object, return the node
        return node;
    
    Node* fNode = TreeInsert(target, node->right()); //Same as inserting to the left, here just switch to right side.
    if(fNode && !fNode->parent()) {
        fNode->parent() = node;
        int depth = fNode->depth();
        if(depth > _maxDepth)
            _maxDepth = depth;
    }
    return fNode;
}

//Search the tree
Node* CandySet::TreeSearch(const std::string& target, Node* node) {
    if(!node) return NULL;
    
    if(node->data()->name() > target)
        return TreeSearch(target, node->left());
    if(node->data()->name() == target)
        return node;
    return TreeSearch(target, node->right());
}

//remove nodes from the tree
Node* CandySet::TreeRemove(const std::string& target) {
    Node* node = TreeSearch(target, _root);
    if(!node) return NULL;
    
    if(node->isLeaf()) {
        if(node == _root)
            _root=NULL;
        else {
            Node* parent = node->parent();
            if(parent->left() == node)
                parent->left() = NULL;
            else
                parent->right() = NULL;
        }
    } else {
        if(!node->left()){ //Have only right node.
            if(node->parent()->left() == node)
                node->parent()->left() = node->right();
            else
                node->parent()->right() = node->right();
        } else { //Have left node and possbly right node. TODO: Incomplete....
            
            //Examine the tree and retrieve the next largest value...
            Node* replacement = node->left();
            while(replacement->right())
                replacement = replacement->right();
                
            //Replace the node in the tree with the replacement node.
            if(node->parent()->left() == node)
                node->parent()->left() = replacement;
            else
                node->parent()->right() = replacement;
                
            //Copy over replacement
            replacement->left() = node->left();
            replacement->right() = node->right();
            
            //Clear the replacements parent before updating its parent.
            if(replacement->parent()){
                if(replacement->parent()->left() == replacement)
                    replacement->parent()->left() = NULL;
                else
                    replacement->parent()->right() = NULL;
            }
            replacement->parent() = node->parent();
        }
    }
    
    //Decrement count.
    _nodeCount--;
    
    //Clear node
    node->parent() = node->left() = node->right() = NULL;
    
    _maxDepth = TreeDepthCalc(_root);
    
    //Return removed node.
    return node;
}

//Function the calculates the depth of the tree
int CandySet::TreeDepthCalc(Node* n) {
    if(!n) return 0;
    // int depth and set to 0
    int depth = 0;
    //if the object is point to left, set it equal to the left node
    if(n->left()) depth = TreeDepthCalc(n->left());
    if(n->right()) {
        int temp = TreeDepthCalc(n->right());
        if(temp > depth) depth = temp;
    }
    if(depth == 0) depth = n->depth();
    return depth;
}

//bool to remove data, return TreeRemove
bool CandySet::remove(const std::string& data){
    return this->TreeRemove(data);
}

//Clears the CandySet
void CandySet::clear() {
    _root = NULL;
    _nodeCount = 0;
    _maxDepth = 0;
}

//Print out the tree
void Node::print(std::ostream& os, int tabs) const {
    if(_right){
        _right->print(os, tabs+1);
    }
    
    const char* id = (_left || _right ? "+> " : "> ");
    
    for(int i = 0; i < tabs-1; i++) os << "| ";
    os << (_parent ? "|-" : "") << id << *_data << std::endl;
    
    if(_left){
        _left->print(os, tabs+1);
    }
    
}

// Check for existing candy bars and add if not found
CandySet& CandySet::operator+=(const Candy& c) {

    return *this;
}

//Checks for duplicate candy and subtract from set
CandySet& CandySet::operator-=(const Candy& c) {
 
    //since -= is wrote we just call it here
    return this->operator-=(c.name());
}

//Check if the name of the candy is in the set and delete it
CandySet& CandySet::operator-=(const std::string& name) {
    
    this->remove(name);
    return *this;
}

// return the name on the rightside of the tree
bool Node::operator<(const Candy& c){
    return _data->name() < c.name();
}

//return the name if its equal to the name in Candy
bool Node::operator==(const Candy& c){
    return _data->name() == c.name();
}

//return the name on the left side of tree
bool Node::operator>(const Candy& c){
    return _data->name() > c.name();
}

//Bool that calls find if there are objects in the left and right
bool CandySet::findsearchset(const Node &other) const{
    if(other.left() && !findsearchset(*other.left()))
        return false;
    //Same for right side
    if(other.right() && !findsearchset(*other.right()))
      return false;
    //Call find here and invert it. Call Candy, data
    return !this->find(other.data()->name());
}
//Bool that checks equal candy names
bool CandySet::operator==(const CandySet& set) {
    //call findseachset return this pointer to the root
    return set.findsearchset(*this->_root);
}

//Bool that checks if the name is not equal to to the name in the candy set
bool CandySet::operator!=(const CandySet& ne) {
    // return this and invert the operator to call the ==
    return !this->operator==(ne);
}

//Set the candy set to equal
const CandySet& CandySet::operator=(const CandySet& c) {
    //Call clear
    this->clear();
    
    return *this;
}

//Output the candy set
std::ostream& operator<<(std::ostream& os, const Node& node){
    node.print(os,0);
    return os;
}

//Output the root of the tree
std::ostream& operator<<(std::ostream& os, const CandySet& bt) {
    if(bt._root)
        os << *bt._root;
    else
        os << "Empty Candy Set " << endl;
    return os;
}

//read in the candyset
std::istream& operator>>(std::istream& is, CandySet& bt) {
    Candy _candy;
    while (is) {
        is >> _candy;
        bt.operator+=(_candy);
    }
    return is;
}

