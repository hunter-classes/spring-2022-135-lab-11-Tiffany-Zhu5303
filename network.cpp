#include <iostream>
#include <cctype>

#include "network.h"
#include "profile.h"

Network::Network(){
  numUsers = 0;
}

int Network::findID(std::string usrn){
  for(int i = 0; i < MAX_USERS; i++){
    if(profiles[i].getUsername() == usrn){
      return i;
    }
  }
  
  return -1;
}

bool Network::addUser(std::string usrn, std::string dspn){
  if(usrn == ""){
    return false;
  }

  //is it alphanumeric
  for(int i = 0; i < usrn.length(); i++){
    if(!isalnum(usrn[i])){
      return false;
    }
  }

  if(numUsers > MAX_USERS){
    return false;
  }else if(findID(usrn) != -1){
    return false;
  }

  Profile newUser(usrn,dspn);
  profiles[numUsers] = newUser;
  numUsers ++;

  return true;
}

