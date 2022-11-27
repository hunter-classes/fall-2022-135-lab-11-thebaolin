#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"
using namespace std;

TEST_CASE("Task A"){
//These test cases are given to us in the Lab Example
    Profile p1("marco", "Marco");
    CHECK_EQ(p1.getUsername(), "marco");
    CHECK_EQ(p1.getFullName(), "Marco (@marco)");

    p1.setDisplayName("Marco Rossi");
    CHECK_EQ(p1.getUsername(), "marco");
    CHECK_EQ(p1.getFullName(), "Marco Rossi (@marco)");

    Profile p2("tarma1", "Tarma Roving");
    CHECK_EQ(p2.getUsername(), "tarma1");
    CHECK_EQ(p2.getFullName(), "Tarma Roving (@tarma1)");
}

TEST_CASE("TASK B"){
//These test cases are given to us in the Lab Example
    Network nw;

    CHECK(nw.addUser("mario", "Mario"));
    CHECK(nw.addUser("luigi", "Luigi"));

    CHECK_FALSE(nw.addUser("mario", "Mario2"));
    CHECK_FALSE(nw.addUser("mario 2", "Mario2"));
    CHECK_FALSE(nw.addUser("mario-2", "Mario2"));

    for (int i = 2; i < 20; i++) {
    CHECK(nw.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i)));
    }

    CHECK_FALSE(nw.addUser("yoshi", "Yoshi"));
}

TEST_CASE("TASK C"){
//These test cases are given to us in the Lab Example
    Network nw;

    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    CHECK_FALSE(nw.isfollowing("mario", "mario"));
    CHECK(nw.isfollowing("mario", "yoshi"));
    CHECK(nw.isfollowing("luigi", "mario"));
    CHECK(nw.isfollowing("luigi", "yoshi"));
    CHECK(nw.isfollowing("yoshi", "mario"));
    CHECK(nw.isfollowing("yoshi", "luigi"));

    CHECK_FALSE(nw.isfollowing("luigi", "luigi"));
    CHECK_FALSE(nw.isfollowing("yoshi", "yoshi"));

    nw.addUser("wario", "Wario");
    //wario shouldnt be following anyone else
    CHECK_FALSE(nw.isfollowing("wario", "mario"));
    CHECK_FALSE(nw.isfollowing("wario", "yoshi"));
    CHECK_FALSE(nw.isfollowing("wario", "luigi"));

}