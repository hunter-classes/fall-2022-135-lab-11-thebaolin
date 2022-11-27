#include "profile.h"
#include <iostream>
using namespace std;

Profile::Profile(){
    username = "";
    displayname = "";
}
Profile::Profile(string usrn, string dspn){
    username = usrn;
    setDisplayName(dspn);
}

string Profile::getUsername(){
    return username;
}

string Profile::getFullName(){
    return displayname + " (@" + username + ")";
}

void Profile::setDisplayName(string dspn){
    this->displayname = dspn;
}