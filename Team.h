#ifndef TEAM_H
#define TEAM_H
#include <string.h>
#include <iostream>
#include "Player.h"
using namespace std;

class Team{
    public:
        string location;
        string nickname;
        Team(string loc, string nick);
        Team();
        string get_nickname();
        Player plyrs[12];
        int counter=0;
        


};







#endif