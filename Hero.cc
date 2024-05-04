#include "Hero.h"
#include "Participant.h"
#include "MoveBehaviour.h"
#include "defs.h"

using namespace std; 

Hero::Hero(char av, int r, int c, string n) : Participant(av, r, c, new EscapeeBehaviour()), name(n), health(20){
}

void Hero::incurDamage(Participant * p){
    int damage = p->causeDamage();
    if (damage == RESCUE){
        rescued = true; 
        setMoveBehaviour(new RescuedBehaviour());
    } else {
    health -= damage; 
    if (health <= 0){
        avatar = '+';
        dead = true; 
        health = 0; 
        }
    }
}


int Hero::causeDamage(){
    return 0;
}

string Hero::getName() const{
    return name;
}

int Hero::getHealth() const{
    return health;
}

bool Hero::isRescued() const{
    return rescued; 
}

bool Hero::isSafe(){
    return row < 1; 
}