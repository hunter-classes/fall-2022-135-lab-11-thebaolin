#pragma once
#include <string>
using namespace std;

class Profile {

private:
    string username;
    string displayname;

public:
    Profile(string usrn, string dspn);

    Profile();
    // Return username
    string getUsername();

    string getFullName();

    void setDisplayName(string dspn);
};