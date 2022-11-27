#pragma once
#include "profile.h"
using namespace std;

class Network {
private:

    static const int MAX_USERS = 20; // max number of user profiles
    int numUsers;                    // number of registered users
    Profile profiles[MAX_USERS];     // user profiles array:
    bool following[MAX_USERS][MAX_USERS];

    int findID (const string &usrn);

public:
    Network();

    bool isAlphaNumeric(const string &str);
    bool addUser(const string &usrn, const string &dspn);
    bool follow(string usrn1, string usrn2);
    void printDot();
    bool isfollowing(const std::string &usrn1, const std::string &usrn2);

};