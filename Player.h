//#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;


class Player{
    public:
        Player(string firstname,string lastname, unsigned int jerseynumber,bool active);
        Player();
        void print_player();
        bool active;
        unsigned int jerseynumber;
        string firstname;
        string lastname;
        string activeornot();
};



#endif