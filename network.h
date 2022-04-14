#pragma once

#include "profile.h"

class Network {
private:
  static const int MAX_USERS = 20;
  int numUsers;
  
  Profile profiles[MAX_USERS]; //maps integer ID to profile
  int findID(std::string usrn); //index is the ID and returns the ID of user or -1 if not found

  bool following[MAX_USERS][MAX_USERS]; //friendship matrix
  //following[id1][id2] == true when id1 is followeing id2
public:
  Network(); // constructor makes an empty network with 0 users
  
  bool addUser(std::string usrn, std::string dspn);

  // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
 // return true if success (if both usernames exist), otherwise return false
  bool follow(std::string usrn1, std::string usrn2);
  //Print Dot file (graphical representation of the network)
  void printDot();
};
