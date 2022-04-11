#include <iostream>

#include "profile.h"

int main(){
  std::cout << "--------------Task A------------------" << std::endl;
  Profile p1("marco", "Marco");    
  std::cout << "the user name of the first user is: " << p1.getUsername() << std::endl; // marco
  std::cout << "the full name of the first user is: " << p1.getFullName() << std::endl; // Marco (@marco)

  p1.setDisplayName("Marco Rossi"); 
  std::cout << p1.getUsername() << std::endl; // marco
  std::cout << p1.getFullName() << std::endl; // Marco Rossi (@marco)
    
  Profile p2("tarma1", "Tarma Roving");    
  std::cout << p2.getUsername() << std::endl; // tarma1
  std::cout << p2.getFullName() << std::endl; // Tarma Roving (@tarma1)
  
  return 0;
}
