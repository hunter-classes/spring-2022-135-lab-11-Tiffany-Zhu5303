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

  std::cout << nw.addUser("mario", "Mario") << std::endl;     // true (1)
  std::cout << nw.addUser("luigi", "Luigi") << std::endl;     // true (1)

  std::cout << nw.addUser("mario", "Mario2") << std::endl;    // false (0)
  std::cout << nw.addUser("mario 2", "Mario2") << std::endl;  // false (0)
  std::cout << nw.addUser("mario-2", "Mario2") << std::endl;  // false (0)

  for(int i = 2; i < 20; i++){
     std::cout << nw.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i)) << std::endl;   // true (1)
  }

   std::cout << nw.addUser("yoshi", "Yoshi") << std::endl;     // false (0)

  return 0;
}
