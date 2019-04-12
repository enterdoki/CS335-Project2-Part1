/******************************************************************************
  Title          : _hash_item.cpp
  Author         : Yu Tong Chen
  Created on     : 4/7/2019
  Description    : The implementation _hash_item.h provided by Professor Stewart Weiss.
  Purpose        : To implement the item type to be hashed.
  Usage          :
  Build with     :
  Modifications  :

******************************************************************************/

#include "_hash_item.h"

__ItemType::__ItemType():name(""),position(0) {}

__ItemType::~__ItemType() {}

void __ItemType::set(string s, int pos) {
    name = s;
    position = pos;
}

void __ItemType::get(string &s, int &pos) {
    s = name;
    pos = position;
}

// Case insensitive comparison
bool __ItemType::operator==(__ItemType rhs) const {
    string temp1 = toLower(rhs.name);
    string temp2 = toLower(name);
    return temp1 == temp2;
}

unsigned int __ItemType::code() {
    unsigned int hash = 0;
    for(int i = 0; i < name.length(); i++) {
        hash += (unsigned int) name[i];
    }

    return hash;
}

ostream &  operator<<( ostream & os, __ItemType item ) {
    os << item.name << " " << item.position << endl;
    return os;
}

// Function to turn string into all lowercase
string __ItemType::toLower(string s) const{
    string new_string;
    for(int i = 0; i < s.length(); i++) {
         new_string[i] = tolower(s[i]);
    }
    return new_string;
}

