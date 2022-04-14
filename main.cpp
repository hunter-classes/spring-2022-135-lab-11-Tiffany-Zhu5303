#include <iostream>
#include <string>
#include <cctype>

#include "profile.h"
#include "network.h"

int main(){
  std::cout << "--------------Task A------------------" << std::endl;
  Profile p1("marco", "Marco");    
  std::cout << "the user name of the first user is: " << p1.getUsername() << std::endl; // marco
  std::cout << "the full name of the first user is: " << p1.getFullName() << std::endl; // Marco (@marco)

  p1.setDisplayName("Marco Rossi");
  std::cout << "\nthe first user made a change \n\nthe user name of the first user is still " << p1.getUsername() << std::endl; // marco
  std::cout << "the full name of the first user is now " << p1.getFullName() << std::endl; // Marco Rossi (@marco)
    
  Profile p2("tarma1", "Tarma Roving");    
  std::cout << "\nthe user name of the second user is: " << p2.getUsername() << std::endl; // tarma1
  std::cout << "the full name of the second user is: " << p2.getFullName() << std::endl; // Tarma Roving (@tarma1)

  std::cout << "\n--------------Task B------------------" << std::endl;
  Network nw;

  std::cout << "Accounts which are added to the network -> 1" << std::endl;
  std::cout << "mario: " << nw.addUser("mario", "Mario") << std::endl;     // true (1)
  std::cout << "luigi: " << nw.addUser("luigi", "Luigi") << std::endl;     // true (1)

  std::cout << "mario: " << nw.addUser("mario", "Mario2") << std::endl;    // false (0)
  std::cout << "mario 2: " << nw.addUser("mario 2", "Mario2") << std::endl;  // false (0)
  std::cout << "mario-2: " << nw.addUser("mario-2", "Mario2") << std::endl;  // false (0)

  for(int i = 2; i < 19; i++){
    std::cout << "mario" << std::to_string(i) << ": " << nw.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i)) << std::endl;   // true (1)
  }

  std::cout << "yoshi: " << nw.addUser("yoshi", "Yoshi") << std::endl;     // true (1)
  std::cout << "mario19: " << nw.addUser("mario19", "Mario19") << std::endl; // false(0)

  std::cout << "\n--------------Task C------------------" << std::endl;
  //mario, luigi, and yoshi are all following each other
  nw.follow("mario", "luigi");
  nw.follow("mario", "yoshi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");
  nw.follow("yoshi", "luigi");

  //mario has fake followers
  for(int i = 2; i < 6; i++){
    nw.follow("mario" + std::to_string(i), "mario");
  }

  nw.follow("mario2", "luigi");

  std::cout << "The code below, outputted in the terminal, is for the Online Graphviz app. Input the code on https://dreampuf.github.io/GraphvizOnline/\n" << std::endl;

  nw.printDot();

  return 0;
}
