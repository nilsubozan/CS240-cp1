#include "Player.h"
using namespace std;


Player::Player(string firstname,string lastname, unsigned int jerseynumber,bool active) {

     this->firstname = firstname;
     this->lastname= lastname;
	 this->jerseynumber = jerseynumber;
     this->active = active;
	 
}
Player::Player() {
    this->firstname = "";
    this->lastname=" ";
    this->active=false;//ne yazcagimi bilemedim
    this->jerseynumber = 0;
   
}
string Player::activeornot(){
    string isactive=" ";
    if(active==true){
        isactive="[active]";
    }
    else if(active==false){
        isactive="[not active]";
    }
    return isactive;

}
void Player::print_player(){
    cout << lastname <<", "<<firstname<< " (#" << jerseynumber << ")  " << this->activeornot() <<endl;
}
