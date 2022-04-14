#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

TEST_CASE("username display"){
  Profile p1("tiffanyzhu", "Tiffany Zhu");
  CHECK(p1.getUsername() == "tiffanyzhu");
  CHECK(p1.getFullName() == "Tiffany Zhu (@tiffanyzhu)");
}
