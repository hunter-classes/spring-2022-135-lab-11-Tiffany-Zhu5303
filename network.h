#pragma once

#include "profile.h"

class Network {
private:
  static const int MAX_USERS = 20;
  int numUsers;
  Profile profiles[MAX_USERS]; //maps integer ID to profile
  int findID(std::string usrn); //index is the ID and returns the ID of user or -1 if not found
public:
  Network(); // constructor makes an empty network with 0 users
  
  bool addUser(std::string usrn, std::string dspn);
};
