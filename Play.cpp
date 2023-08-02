#include <iostream>
#include <stdlib.h>
//#include "Player.h"
#include "Team.h"
#include <vector>

using namespace std;



int main(int argc, char *argv[]) {
  
   vector <Team> teams;
   Team team;
   string inpt=" ";
   //cout<<"\n";
   
  while(inpt!="Quit"){
    
     cout<<"\nEnter a command:"<<endl;
     cout <<"Choose from [\"Team\" \"Player\" \"League\" \"Roster\" \"Quit\"]"<< endl;
     cout<<": ";
     cin>>inpt; 
    if(inpt == "Quit") {break;}
     if(((inpt=="Team") ||(inpt=="Player") ||(inpt=="League")||(inpt=="Roster"))){
       if(inpt=="Team"){
         string lc;
         string nck;
         //nickname daha once kullanildiysa yeni takim yaratilamaz.
         cout<<"     Location: ";
         cin>>lc;
         cout<<"     Nickname: ";
         cin>>nck;
         bool dup = true;


        for(int i=0;i<(int)teams.size();i++){
          if(nck==teams.at(i).get_nickname()){
            dup=false;
            cout<< "Duplicate team nickname "<<nck<< " not added"<<endl;
            break;
          }
        }
        if(dup == true){
          cout<<endl;
          team = Team(lc,nck);
          teams.push_back(team);
        }
        

        
         



         
      }
      if(inpt=="Player"){
        //If the provided nickname does not match any current team’s nickname, the player cannot be added
        string frst;
         string lst;
         unsigned int nmb;
         string yesno;
         string teamnickname;

         cout<<"       First Name: ";
         cin>>frst;
         cout<<"        Last Name: ";
         cin>>lst;
         cout<<"           Number: ";
         cin>>nmb;
         cout<<"     Active (y/n): ";
         cin>>yesno;
         cout<<"             Team: "<<endl;
         cin>>teamnickname;

        bool ysn;
        Player p;
        for(int i=0; i<(int)teams.size();i++){
          if(teamnickname==teams.at(i).get_nickname()){
            if(teams.at(i).counter<12){
              if(yesno=="y"){
                ysn=true;
              }
              else{
                ysn=false;
              }
              teams.at(i).plyrs[teams.at(i).counter] = Player(frst,lst,nmb,ysn);
              teams.at(i).counter+=1;
            }
          }
        }
      }
      if(inpt=="League"){
        cout<<"Teams: "<< (int)teams.size() <<endl;
        for(int i=0; i<(int)teams.size();i++){
          cout<<teams.at(i).location<<" ";
          cout<<teams.at(i).get_nickname()<<endl;
        }
      
      }
      if(inpt=="Roster"){
        string nckn;
        cout<<"Team: ";
        cin>>nckn;
        for(int i=0;i<(int)teams.size();i++){
          if(nckn==teams.at(i).get_nickname()){
            cout <<teams.at(i).location << " "<<teams.at(i).get_nickname()<< endl;
            cout << "   Players:"<<endl;
            for(int o=0; o<teams.at(i).counter;o++){
              teams.at(i).plyrs[o].print_player();
            }
            break;
          }
        }
      }

     }

    else if(!((inpt=="Team") ||(inpt=="Player") ||(inpt=="League")||(inpt=="Roster"))){
      cout<<"Command "<<inpt<<" not recognized. Please try again.";
    }
    
     
  }
  return 0;  
}
