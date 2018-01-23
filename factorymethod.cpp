#include <iostream>
#include <string>
using namespace std;
class Player{
    string playerType_;
public:
    Player(string s){
        playerType_=s;
    }
    void print(){
        cout << playerType_ << endl;
    }
};
class PokerPlayer:public Player{
public:
    PokerPlayer():Player("poker player"){}
};
class GoFishPlayer:public Player{
public:
    GoFishPlayer():Player("Go Fish Player"){}
};
class CardGame{
protected:
    int numPlayers_;
    Player* players_[10];
    bool playerInit_;
public:

    CardGame(int numplayers){
        numPlayers_=numplayers;
        playerInit_=false;
    }
    void createPlayers(){
        for(int i=0;i<numPlayers_;i++){
            players_[i]=makePlayers();
        }
    }
//makePlayers is our factory method
//the type of players that we make are
//dependent on the the type of game this
//is
    virtual Player* makePlayers()=0;
    void print(){
        if(!playerInit_){
            createPlayers();
            playerInit_=true;
        }
        for(int i=0;i<numPlayers_;i++){
            players_[i]->print();
        }
    }
};

class PokerGame:public CardGame{
public:
    PokerGame():CardGame(5){
    }
    virtual Player* makePlayers(){
        return new PokerPlayer();
    }
};
class GoFishGame:public CardGame{
public:
    GoFishGame():CardGame(4){
    }
    virtual Player* makePlayers(){
        return new GoFishPlayer();
    }
};
int main(void){
    CardGame* p = new PokerGame();
    CardGame* g = new GoFishGame();
    cout << ".........Poker........"<< endl;
    p->print();
    cout << endl;
    cout << ".........Go Fish......" << endl;
    g->print();
    return 0;
}