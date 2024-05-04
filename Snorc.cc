#include "Snorc.h"
#include "defs.h"

Snorc::Snorc(int r, int c, int st) : Participant('s', r, c, new VillainBehaviour()), strength(st){
    //add move behaviour here
}

void Snorc::incurDamage(Participant*p){return;}

int Snorc::causeDamage(){
    return strength;
}

bool Snorc::isSafe(){
    return false; 
}