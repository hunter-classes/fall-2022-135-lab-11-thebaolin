#include <iostream>
#include <algorithm>
#include <cctype>
#include "network.h"
using namespace std;

Network::Network(){
    numUsers = 0;
    for(int i = 0; i < MAX_USERS; i++){
        for(int j = 0; j < MAX_USERS; j++){
            following[i][j] = false;
        }
    }
}

int Network::findID (const string &usrn){
    for(int id = 0; id < numUsers; id++){
        if(profiles[id].getUsername() == usrn){
            return id;
        }
    }
return -1;
}

bool Network::isAlphaNumeric(const string &str){
    auto it = find_if(str.begin(), str.end(), [](char const &c) {
            return !isalnum(c);
        });
 
    return it == str.end();
}

bool Network::addUser(const string &usrn, const string &dspn){
//
    // for(int i = 0; i < usrn.length(); i++){
    //     if(!isalnum(usrn[i]))
    //         return false;
    // }
    if(findID(usrn) == -1 && numUsers < MAX_USERS && usrn.length() != 0 && isAlphaNumeric(usrn)){
        profiles[numUsers] = Profile(usrn, dspn);
        numUsers++;
        return true;
    }
return false;
}

bool Network::follow(string usrn1, string usrn2){
    if(findID(usrn1) != -1 && findID(usrn2) != -1){
        following[findID(usrn1)][findID(usrn2)] = true;
        return true;
    }
    return false;
}
void Network::printDot(){
    cout<<"digraph {"<<endl;
    for(int i = 0; i < numUsers; i++){
        cout<<" \"@" << profiles[i].getUsername() << "\""<<endl;
    }
    cout<<endl;
    for(int i = 0; i < numUsers; i++){
        for(int j = 0; j < numUsers; j++){
            if(following[i][j]){
                cout<<" \"@" << profiles[i].getUsername() << "\" -> " << "\"@" << profiles[j].getUsername() << "\""<<endl;
            }
        }
    }
    cout<< "}"<<endl;
}

bool Network::isfollowing(const std::string &usrn1, const std::string &usrn2) {
  if (findID(usrn1) != -1 && findID(usrn2) != -1) {
    return following[findID(usrn1)][findID(usrn2)];
  }
  return false;
}
