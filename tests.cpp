#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

TEST_CASE("username display"){
  Profile p1("tiffanyzhu", "Tiffany Zhu");
  CHECK(p1.getUsername() == "tiffanyzhu");
  CHECK(p1.getFullName() == "Tiffany Zhu (@tiffanyzhu)");
}

TEST_CASE("added to network"){
  Network network;

  CHECK(network.addUser("tiffanyzhuuu", "Tiffany Zhu") == 1);
  CHECK(network.addUser("username", "Elton Chan") == 1);
  CHECK(network.addUser("r1sus@na", "Elton Chan") == 0);
  CHECK(network.addUser(" ", "Blank") == 0);
  
  for(int i = 2; i < 20; i++){
    network.addUser("tiffany" + std::to_string(i), "Tiffany" + std::to_string(i));
  }

  CHECK(network.addUser("halloooo", "random") == 0);
}
