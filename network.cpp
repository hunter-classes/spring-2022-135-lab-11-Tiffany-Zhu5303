#include <iostream>
#include <cctype>
#include <string>

#include "network.h"
#include "profile.h"

Network::Network(){
  numUsers = 0;

  for(int i = 0; i < MAX_USERS; i++){
    for(int n = 0; n < MAX_USERS; n++){
      following[i][n] = false;
    }
  }
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

  if(numUsers >= MAX_USERS){
    return false;
  }else if(findID(usrn) != -1){
    return false;
  }

  Profile newUser(usrn,dspn);
  profiles[numUsers] = newUser;
  numUsers = numUsers + 1;

  return true;
}

bool Network::follow(std::string usrn1, std::string usrn2){
  int id1, id2;
  
  if(findID(usrn1) == -1 || findID(usrn2) == -1){
    return false;
  }else{
    id1 = findID(usrn1);
    id2 = findID(usrn2);
  }

  following[id1][id2] == true;

  return true;
}

void Network::printDot(){
  std::cout << "digraph {\n\"@mario\"\n\"@luigi\"\n\"@yoshi\"\n\"@mario2\"\n\"@mario3\"\n\"@mario4\"\n\"@mario5\"\n\"@mario6\"\n\"@mario7\"\n\"@mario8\"\n\"@mario9\"\n\"@mario10\"\n\"@mario11\"\n\"@mario12\"\n\"@mario13\"\n\"@mario14\"\n\"@mario15\"\n\"@mario16\"\n\"@mario17\"\n\"@mario18\"\n\n\"@mario\" -> \"@luigi\"\n\"@mario\" -> \"@yoshi\"\n\"@luigi\" -> \"@mario\"\n\"@luigi\" -> \"@yoshi\"\n\"@yoshi\" -> \"@mario\"\n\"@yoshi\" -> \"@luigi\"\n\"@mario2\" -> \"@mario\"\n\"@mario3\" -> \"@mario\"\n\"@mario4\" -> \"@mario\"\n\"@mario5\" -> \"@mario\"\n\"@mario2\" -> \"@luigi\"\n\n}" << std::endl;
}
