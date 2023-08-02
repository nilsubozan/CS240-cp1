#include <iostream>
#include "Team.h"

using namespace std;

Team::Team(string loc, string nick){
    this->location = loc;
    this->nickname = nick;
}
Team::Team(){
    this->location = "";
    this->nickname ="";
}
string Team::get_nickname(){
    return this->nickname;
}
