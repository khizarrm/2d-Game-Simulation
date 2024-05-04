#include "Ninja.h"
#include "defs.h"
#include "MoveBehaviour.h"

Ninja::Ninja(int r, int c) : Participant('N', r, c, new RescuerBehaviour()){
    strength = 0; 
    poisoned = false; 
}

Ninja::~Ninja(){
}

void Ninja::incurDamage(Participant* p){
    if (poisoned) return; 
    int damage = p->causeDamage();
        if (damage == 0) {
            setMoveBehaviour(new RescuedBehaviour());
        } else if (damage != -1){
            poisoned = true;
            avatar = 'S'; 
            strength = rand() % 3 + 6; 
            delete moveBehaviour; 
            this->moveBehaviour = new VillainBehaviour(); 
        }
}

int Ninja::causeDamage(){
        if (poisoned) {
            return strength; 
        } else {
            return RESCUE; 
        }
}

bool Ninja::isSafe(){
    return row < 1 || row >= MAX_ROW-1;
}

