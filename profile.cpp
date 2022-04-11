#include <iostream>

#include "profile.h"

Profile::Profile(std::string usrn, std::string dspn){
  username = usrn;
  displayname = dspn;
}

void Profile::setDisplayName(std::string dspn){
  displayname = dspn + " (@" + username + ")";
}

std::string Profile::getUsername(){
  return username;
}

std::string Profile::getFullName(){
  setDisplayName(displayname);
  
  return displayname;
}
  
