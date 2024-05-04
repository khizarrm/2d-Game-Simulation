#include "Participant.h"
#include "MoveBehaviour.h"
#include "defs.h" 

Participant::Participant(char av, int r, int c, MoveBehaviour* move) : avatar(av), row(r), col(c), dead(false), moveBehaviour(move) {}

Participant::~Participant() {
    delete moveBehaviour;
}

char Participant::getAvatar() const {
    return avatar;
}

int Participant::getRow() const {
    return row;
}

int Participant::getCol() const {
    return col;
}

bool Participant::isDead() const {
    return dead;
}

void Participant::move() {
    if (moveBehaviour && !isDead() && !isSafe()) { 
        int newRow, newCol; 

        moveBehaviour->move(row, col, newRow, newCol); 

        row = newRow;
        col = newCol;
    }
}

void Participant::setMoveBehaviour(MoveBehaviour* m) {
    delete moveBehaviour; 
    moveBehaviour = m; 
}
