// Lukasz Rudnik

#include <iostream>
#include <string>

#define MAX_HUMAN_HP 150
#define MAX_BEAST_HP 200
#define MAX_BERSERKER_HP 200
#define uoid string

using namespace std;

class PLAYER_CLASS;
class CAESAR_CLASS;
class ARENA_CLASS;

class HUMAN_CLASS;
class BEAST_CLASS;
class BERSERKER_CLASS;
class SQUAD_CLASS;



class PLAYER_CLASS{
    friend class CAESAR_CLASS;
public:
    unsigned int maxHealth;
    unsigned int currentHealth;
    unsigned int attack;
    unsigned int agility;
public:
    virtual unsigned int getRemainingHealth() =0;
    virtual unsigned int getDamage() =0;
    virtual unsigned int getAgility() =0;
    virtual void takeDamage ( unsigned int ) =0;
    virtual void applyWinnerReward() =0;
    virtual void cure() =0;
    virtual uoid getId() {
    return "";
    };
    virtual void printParams() =0;
protected:
    virtual void die() =0;
    };


class CAESAR_CLASS{
public:
    unsigned int judgementCount;
    unsigned int currentFightAttacks;
public:
    void judgeDeathOrLife ( PLAYER_CLASS* );
    };


class ARENA_CLASS{
private:
    CAESAR_CLASS caesar;
public:
    ARENA_CLASS ( CAESAR_CLASS* );
    void fight ( PLAYER_CLASS*, PLAYER_CLASS* );
    };


class HUMAN_CLASS : public virtual PLAYER_CLASS{
public:
    string id;
    unsigned int defense;
public:
    HUMAN_CLASS ( string );
    unsigned int getRemainingHealth();
    unsigned int getAgility();
    unsigned int getDamage();
    void takeDamage( unsigned int );
    void die();
    void cure();
    void applyWinnerReward();
    void printParams();
    uoid getId();
    };

class BEAST_CLASS : public virtual PLAYER_CLASS{
public:
    string id;
public:
    BEAST_CLASS ( string );
    unsigned int getRemainingHealth();
    unsigned int getAgility();
    unsigned int getDamage();
    void takeDamage( unsigned int );
    void die();
    void cure();
    void applyWinnerReward();
    void printParams();
    uoid getId();
    };

class BERSERKER_CLASS : public HUMAN_CLASS, public BEAST_CLASS{
public:
    BERSERKER_CLASS ( string, string );
    unsigned int getRemainingHealth();
    unsigned int getAgility();
    unsigned int getDamage();
    void takeDamage( unsigned int );
    void die();
    void cure();
    void applyWinnerReward();
    void printParams();
    uoid getId();
    };

class SQUAD_CLASS : public PLAYER_CLASS{
public:
    struct NODE{
        PLAYER_CLASS* player = NULL;
        NODE* nextNode = NULL;
        bool wasPrinted = false;
        };
    NODE* memberList;
    string id;
public:
    SQUAD_CLASS ( string );
    void addPlayer ( PLAYER_CLASS* );
    unsigned int getRemainingHealth();
    unsigned int getAgility();
    unsigned int getDamage();
    void takeDamage( unsigned int );
    void printParams();
    uoid getId();
    void die();
    void cure();
    void applyWinnerReward();
    ~SQUAD_CLASS() {
    NODE* node = memberList;
    while (node) {
        NODE* temp = node;
        node = node->nextNode;
        delete temp;
        }
        }
    };


// PLAYER_CLASS
// wszystko jest virtual
///////////////

// CAESAR_CLASS
void CAESAR_CLASS::judgeDeathOrLife ( PLAYER_CLASS* player ){
    judgementCount++;
    if ( judgementCount % 3 == 0 && currentFightAttacks % 2 == 0 ){
        player->die();
        }
    }
///////////////

// ARENA_CLASS
ARENA_CLASS::ARENA_CLASS ( CAESAR_CLASS* caesarPtr ){
    this -> caesar = *caesarPtr;
    }
void ARENA_CLASS::fight ( PLAYER_CLASS* fighterOne, PLAYER_CLASS* fighterTwo ){
    if ( fighterOne->getRemainingHealth() > 0 && fighterTwo->getRemainingHealth() > 0 ){
        PLAYER_CLASS* playerOne = fighterOne;
        PLAYER_CLASS* playerTwo = fighterTwo;
        if ( playerOne->getAgility() < playerTwo->getAgility() ){
            playerOne = fighterTwo;
            playerTwo = fighterOne;
            }
        playerOne->printParams();
        playerTwo->printParams();

        unsigned int attackCount = 0;
        while ( attackCount != 40 && playerOne->getRemainingHealth() >= 10 && playerTwo->getRemainingHealth() >= 10 ){
            if ( attackCount % 2 == 0 ){
                playerTwo->takeDamage(playerOne->getDamage());
                playerTwo->printParams();
                attackCount++;
                }
            else{
                playerOne->takeDamage(playerTwo->getDamage());
                playerOne->printParams();
                attackCount++;
                }
            }
        caesar.currentFightAttacks = attackCount;
        if ( playerOne->getRemainingHealth() > 0 ){
            caesar.judgeDeathOrLife ( playerOne );
            playerOne->printParams();
            }
        if ( playerTwo->getRemainingHealth() > 0 ){
            caesar.judgeDeathOrLife ( playerTwo );
            playerTwo->printParams();
            }




        if ( playerOne->getRemainingHealth() > 0 ){
                playerOne->applyWinnerReward();
                playerOne->cure();
            }
        if ( playerTwo->getRemainingHealth() > 0 ){
                playerTwo->applyWinnerReward();
                playerTwo->cure();
            }

        playerOne->printParams();
        playerTwo->printParams();
        }
    }
///////////////



// HUMAN_CLASS
HUMAN_CLASS::HUMAN_CLASS ( string id ){
    this->id = id;
    maxHealth = 200;
    currentHealth = 200;
    attack = 30;
    agility = 10;
    defense = 10;
    }
unsigned int HUMAN_CLASS::getRemainingHealth(){
    return currentHealth * 100 / maxHealth;
    }
unsigned int HUMAN_CLASS::getAgility(){
    return agility;
    }
unsigned int HUMAN_CLASS::getDamage(){
    return attack;
    }
void HUMAN_CLASS::takeDamage ( unsigned int damage ){
    if ( damage > defense )
        damage -= defense;
    else
        damage = 0;
    if ( damage > agility )
        damage -= agility;
    else
        damage = 0;

    if ( damage < currentHealth ){
        currentHealth -= damage;;
        }
    else
        currentHealth = 0;
    if ( getRemainingHealth() == 0 ){
            die();
        }
    }
void HUMAN_CLASS::die(){
    currentHealth = 0;
    }
void HUMAN_CLASS::cure(){
    currentHealth = maxHealth;
    }
void HUMAN_CLASS::applyWinnerReward(){
    attack += 2;
    agility += 2;
    }
uoid HUMAN_CLASS::getId(){
    return id;
    }
void HUMAN_CLASS::printParams(){
    if ( currentHealth == 0 ){
        cout << id << ":R.I.P." << endl;
        }
    else{
        cout << id << ":";
        cout << maxHealth << ":";
        cout << currentHealth << ":";
        cout << getRemainingHealth() << "%:";
        cout << attack << ":";
        cout << agility << ":";
        cout << defense << endl;
        }
    }
///////////////

// BEAST_CLASS
BEAST_CLASS::BEAST_CLASS ( string id ){
    this->id = id;
    maxHealth = 150;
    currentHealth = 150;
    attack = 40;
    agility = 20;
    }
unsigned int BEAST_CLASS::getRemainingHealth(){
    return currentHealth * 100 / maxHealth;
    }
unsigned int BEAST_CLASS::getAgility(){
    return agility;
    }
unsigned int BEAST_CLASS::getDamage(){
    if ( getRemainingHealth() < 25 )
        return attack * 2;
    else return attack;
    }
void BEAST_CLASS::takeDamage ( unsigned int damage ){
    if ( damage > agility/2 )
        damage -= agility/2;
    else
        damage = 0;
    if ( damage < currentHealth ){
        currentHealth -= damage;
        }
    else
        currentHealth = 0;
    if ( getRemainingHealth() == 0 ) die();
    }
void BEAST_CLASS::die(){
    currentHealth = 0;
    }
void BEAST_CLASS::cure(){
    currentHealth = maxHealth;
    }
void BEAST_CLASS::applyWinnerReward(){
    attack += 2;
    agility += 2;
    }
uoid BEAST_CLASS::getId(){
    return id;
    }
void BEAST_CLASS::printParams(){
    if ( currentHealth == 0 ){
        cout << id << ":R.I.P." << endl;
        }
    else{
        cout << id << ":";
        cout << maxHealth << ":";
        cout << currentHealth << ":";
        cout << getRemainingHealth() << "%:";
        cout << getDamage() << ":";
        cout << agility << endl;
        }
    }
///////////////

// BERSERKER_CLASS
BERSERKER_CLASS::BERSERKER_CLASS ( string idHuman, string idBeast ) : HUMAN_CLASS(idHuman), BEAST_CLASS(idBeast){
    this->HUMAN_CLASS::id = idHuman;
    this->BEAST_CLASS::id = idBeast;
    maxHealth = 200;
    currentHealth = 200;
    attack = 35;
    agility = 5;
    defense = 15;
    }
unsigned int BERSERKER_CLASS::getRemainingHealth(){
    return currentHealth * 100 / maxHealth;
    }
unsigned int BERSERKER_CLASS::getAgility(){
    if ( getRemainingHealth() < 25 && getRemainingHealth() > 0 )
        return BEAST_CLASS::getAgility();
    else return HUMAN_CLASS::getAgility();
    }
unsigned int BERSERKER_CLASS::getDamage(){
    if ( getRemainingHealth() < 25 && getRemainingHealth() > 0 )
        return BEAST_CLASS::getDamage();
    else return HUMAN_CLASS::getDamage();
    }
void BERSERKER_CLASS::takeDamage ( unsigned int damage ){
    if ( getRemainingHealth() < 25 && getRemainingHealth() > 0 )
        BEAST_CLASS::takeDamage(damage);
    else
        HUMAN_CLASS::takeDamage(damage);
    }
void BERSERKER_CLASS::die(){
    currentHealth = 0;
    }
void BERSERKER_CLASS::cure(){
    currentHealth = maxHealth;
    }
void BERSERKER_CLASS::applyWinnerReward(){
    attack += 2;
    agility += 2;
    }
uoid BERSERKER_CLASS::getId(){
    if ( getRemainingHealth() < 25 && getRemainingHealth() > 0 )
        return BEAST_CLASS::getId();
    else return HUMAN_CLASS::getId();
    }
void BERSERKER_CLASS::printParams(){
    if ( getRemainingHealth() < 25 && getRemainingHealth() > 0 )
        BEAST_CLASS::printParams();
    else
        HUMAN_CLASS::printParams();

    }
///////////////


// SQUAD_CLASS
SQUAD_CLASS::SQUAD_CLASS ( string id ){
    this->id = id;
    memberList = NULL;
    }
void SQUAD_CLASS::addPlayer ( PLAYER_CLASS* player ){
    if ( player->getRemainingHealth() == 0 ) return;
    NODE* node = memberList;
    while ( node ){
        if ( node->player == player ) return;
        node = node->nextNode;
        }
    node = memberList;
    if ( !memberList ){ // add first element
        memberList = new NODE;
        memberList->player = player;
        }
    else{
        while ( node->nextNode ){
            node = node->nextNode;
            }
        node->nextNode = new NODE;
        (node->nextNode)->player = player;
        }
    }
unsigned int SQUAD_CLASS::getRemainingHealth(){
    if (!memberList) return 0;
    NODE* node = memberList;
    unsigned int maxRemainingHealth = 0;
    while ( node ){
        if ( node->player->getRemainingHealth() > maxRemainingHealth )
            maxRemainingHealth = node->player->getRemainingHealth();
        node = node->nextNode;
        }
    return maxRemainingHealth;
    }
unsigned int SQUAD_CLASS::getAgility(){
    if (!memberList) return 0;
    NODE* node = memberList;
    unsigned int minAgility = node->player->getAgility();
    while ( node ){
        if ( node->player->getAgility() < minAgility )
            minAgility = node->player->getAgility();
        node = node->nextNode;
        }
    return minAgility;
    }
unsigned int SQUAD_CLASS::getDamage(){
    if (!memberList) return 0;
    NODE* node = memberList;
    unsigned int sumDamage = 0;
    while ( node ){
        sumDamage += node->player->getDamage();
        node = node->nextNode;
        }
    return sumDamage;
    }
void SQUAD_CLASS::takeDamage( unsigned int damage ){
    if (!memberList) return;
    NODE* node = memberList;
    NODE* prevNode = NULL;
    unsigned int memberCount = 0;
    while ( node ){
        memberCount++;
        node = node->nextNode;
        }
    damage = damage / memberCount;
    node = memberList;
    while ( node ){
        node->player->takeDamage(damage);
        if ( node->player->getRemainingHealth() == 0 ){
            node->player->currentHealth = 0;
            if ( prevNode ){
                prevNode->nextNode = node->nextNode;
                delete node;
                node = prevNode;
                prevNode = node;
                node = node->nextNode;
                }
            else{
                memberList = node->nextNode;
                delete node;
                node = memberList;
                prevNode = NULL;
                }
            }
        else{
        prevNode = node;
        node = node->nextNode;
        }
        }
    }
void SQUAD_CLASS::die(){
    if (!memberList) return;
    NODE* node = memberList;
    NODE* nextNode = memberList->nextNode;
    while ( node ){
        node->player->currentHealth = 0;
        nextNode = node->nextNode;
        delete node;
        node = nextNode;
        }
    }
void SQUAD_CLASS::cure(){
    if (!memberList) return;
    NODE* node = memberList;
    while ( node ){
        node->player->currentHealth = node->player->maxHealth;
        node = node->nextNode;
        }
    }
void SQUAD_CLASS::applyWinnerReward(){
    if (!memberList) return;
    NODE* node = memberList;
    while ( node ){
        node->player->attack += 2;
        node->player->agility += 2;
        node = node->nextNode;
        }
    }
uoid SQUAD_CLASS::getId(){
    return id;
    }
void SQUAD_CLASS::printParams(){
    if (!memberList){
        cout << id << ":nemo" << endl;
        }
    else{
        unsigned int memberCount = 0;
        NODE* node = memberList;
        while ( node ){
            memberCount++;
            node = node->nextNode;
            }
        node = memberList;
        cout << id << ":";
        cout << memberCount << ":";
        cout << getRemainingHealth() << "%:";
        cout << getDamage() << ":";
        cout << getAgility() << endl;


        for ( int i = 0; i < memberCount; i++ ){
            node = memberList->nextNode;
            NODE* minNode = memberList;
            while ( minNode->wasPrinted )
                minNode = minNode->nextNode;
            while ( node ){
                if ( ! node->wasPrinted ){
                    if ( node->player->getId() < minNode->player->getId() ){
                        minNode = node;
                        }
                    else if ( node->player->getId() == minNode->player->getId() ){
                        if ( node->player->maxHealth < minNode->player->maxHealth ){
                            minNode = node;
                            }
                        else if ( node->player->maxHealth == minNode->player->maxHealth ){
                            if ( node->player->currentHealth < minNode->player->currentHealth ){
                                minNode = node;
                                }
                            else if ( node->player->currentHealth == minNode->player->currentHealth ){
                                if ( node->player->getRemainingHealth() < minNode->player->getRemainingHealth() ){
                                    minNode = node;
                                    }
                                else if ( node->player->getRemainingHealth() == minNode->player->getRemainingHealth() ){
                                    if ( node->player->getDamage() < minNode->player->getDamage() ){
                                        minNode = node;
                                        }
                                    else if ( node->player->getDamage() == minNode->player->getDamage() ){
                                        if ( node->player->agility < minNode->player->agility ){
                                            minNode = node;
                                            }
                                        else if ( node->player->agility == minNode->player->agility ){
                                            if ( node->player->agility == 150 ){
                                                minNode = node;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                    }
                node = node->nextNode;
                }
            minNode->player->printParams();
            minNode->wasPrinted = true;
            }
        node = memberList;
        while (node){
            node->wasPrinted = false;
            node = node->nextNode;
            }
        }
    }
///////////////










int main(){

//ARENA_CLASS arenka;

HUMAN_CLASS human1("warrior");
HUMAN_CLASS human2("warrior");
HUMAN_CLASS human3("warrior");
HUMAN_CLASS human4("warrior");
HUMAN_CLASS human5("warrior");
HUMAN_CLASS human6("warrior");
HUMAN_CLASS human7("warrior");
HUMAN_CLASS human8("warrior");
HUMAN_CLASS human9("awarrior");
HUMAN_CLASS human10("warrio");

SQUAD_CLASS avengers("avengers");
avengers.addPlayer(&human1);
avengers.addPlayer(&human2);
avengers.addPlayer(&human3);
avengers.addPlayer(&human4);
avengers.addPlayer(&human5);
avengers.addPlayer(&human6);
avengers.addPlayer(&human7);
avengers.addPlayer(&human8);
avengers.addPlayer(&human9);
avengers.addPlayer(&human10);

avengers.printParams();

human1.takeDamage(50);
human2.takeDamage(50);
human3.takeDamage(50);
human4.takeDamage(50);
human5.takeDamage(50);
human6.takeDamage(50);
human7.takeDamage(60);
human10.takeDamage(10);

avengers.printParams();

human1.applyWinnerReward();
human2.applyWinnerReward();
human3.applyWinnerReward();
human4.applyWinnerReward();

avengers.printParams();

BERSERKER_CLASS berserker1("warrior", "warrior");
BERSERKER_CLASS berserker2("warrior", "warrior");
BERSERKER_CLASS berserker3("warrior", "warrior");
BERSERKER_CLASS berserker4("warrior", "warrior");
BERSERKER_CLASS berserker5("warrior", "warrior");
BERSERKER_CLASS berserker6("warrior", "warrior");
BERSERKER_CLASS berserker7("warrior", "warrior");
BERSERKER_CLASS berserker8("warrior", "warrior");
BERSERKER_CLASS berserker9("warrior", "warrior");
BERSERKER_CLASS berserker10("warrior", "warrior");

avengers.addPlayer(&berserker1);
avengers.addPlayer(&berserker2);
avengers.addPlayer(&berserker3);
avengers.addPlayer(&berserker4);
avengers.addPlayer(&berserker5);
avengers.addPlayer(&berserker6);
avengers.addPlayer(&berserker7);
avengers.addPlayer(&berserker8);
avengers.addPlayer(&berserker9);
avengers.addPlayer(&berserker10);

avengers.printParams();

berserker1.takeDamage(190);
berserker2.takeDamage(190);
berserker3.takeDamage(195);
berserker4.takeDamage(170);
berserker5.takeDamage(175);
berserker6.takeDamage(10);
berserker10.takeDamage(10);

avengers.printParams();

berserker1.applyWinnerReward();
berserker2.applyWinnerReward();
berserker3.applyWinnerReward();
berserker4.applyWinnerReward();
berserker6.applyWinnerReward();
berserker7.applyWinnerReward();

avengers.printParams();

BEAST_CLASS beast1("warrior");
BEAST_CLASS beast2("warrior");
BEAST_CLASS beast3("warrior");
BEAST_CLASS beast4("warrior");
BEAST_CLASS beast5("warrior");
BEAST_CLASS beast6("warrior");
BEAST_CLASS beast7("warrior");
BEAST_CLASS beast8("warrior");
BEAST_CLASS beast9("awarrior");
BEAST_CLASS beast10("warrio");

avengers.addPlayer(&beast1);
avengers.addPlayer(&beast2);
avengers.addPlayer(&beast3);
avengers.addPlayer(&beast4);
avengers.addPlayer(&beast5);
avengers.addPlayer(&beast6);
avengers.addPlayer(&beast7);
avengers.addPlayer(&beast8);
avengers.addPlayer(&beast9);
avengers.addPlayer(&beast10);

avengers.printParams();

beast1.takeDamage(130);
beast2.takeDamage(145);
beast3.takeDamage(155);
beast4.takeDamage(100);
beast5.takeDamage(149);
beast10.takeDamage(10);

avengers.printParams();

beast1.applyWinnerReward();
beast3.applyWinnerReward();
beast4.applyWinnerReward();
beast5.applyWinnerReward();
beast6.applyWinnerReward();
beast10.applyWinnerReward();

avengers.printParams();

human1.cure();
berserker1.cure();
beast1.cure();

avengers.printParams();

avengers.takeDamage(1000);

avengers.printParams();
}
