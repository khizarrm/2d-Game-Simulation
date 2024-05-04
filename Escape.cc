#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <unistd.h>
#include "Escape.h"
#include "Snorc.h"
#include "defs.h"
#include "random"
#include "Hero.h"
#include "Ninja.h"
#include "Participant.h"
#include <iostream>
using namespace std; 

Escape::Escape()
{
  srand ( (unsigned)time(NULL) );
  numSnorcs = 0;
  int tCol = random(10) + 7; 
  int hCol = random(10) + 7;
  timmy = new Hero('T', MAX_ROW-2, tCol, "Timmy");
  harold = new Hero('H', MAX_ROW-2, hCol, "Harold");
  participants += timmy; 
  participants += harold; 
}

Escape::~Escape(){
  timmy = nullptr;
  harold = nullptr; 
}

void Escape::runEscape(){
  while (!isOver()){
    int n = random(MAX_ARR);
    moveParticipants();
    if (n < 90){spawnSnorc();} 
    if (n < 33){spawnNinja();}
    usleep(200000);
    printPit();
  }
  printOutcome(timmy);
  printOutcome(harold);
}

void Escape::printPit(){
    char templateGrid[MAX_ROW+1][MAX_COL+1]={
      "-------------------------",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "-------------------------"
    };
    
    int size = 0; 
    Participant* primArr[MAX_ARR];
    participants.convertToArray(primArr, size);
    for (int i = 0; i < size; i++){
      Participant* curr = primArr[i];
      if (curr->isSafe()){continue;}
      templateGrid[curr->getRow()][curr->getCol()] = curr->getAvatar();
    }
    
    for (int i = 0; i < MAX_ROW+1; i++){
        for (int j = 0; j < MAX_COL+1; j++){
            cout << templateGrid[i][j];
        }

        if (i == MAX_ROW-2){
            cout << "  Timmy: " << timmy->getHealth();
            }

        if (i == MAX_ROW-1){
            cout << "  Harold: " << harold->getHealth();
        }
        cout << endl;
    }

}

bool Escape::withinBounds(int r, int c){
  return (r <= MAX_ROW - 2 && r > 0) && (c <= MAX_COL-1 && c > 0);
}

bool Escape::isOver(){
  return (harold->isDead() || harold->isSafe()) && (timmy->isDead() || timmy->isSafe());
}

void Escape::spawnSnorc(){
  if (numSnorcs >= MAX_SNORCS){
    return;
  }
  int row = MAX_ROW-7 + random(5);
  int col = random(MAX_COL);
  int strength = 2 + random(3);
  if (withinBounds(row, col)){
    Participant* newSnorc = new Snorc(row, col, strength);
    participants += newSnorc; 
    numSnorcs++;
  }
}

void Escape::moveParticipants(){
  int size; 
  Participant* primArr[MAX_ARR] = {}; 
  participants.convertToArray(primArr, size);
  for (int i = 0; i < size; i++){
    Participant* p = primArr[i];
    if (p->isDead() || p->isSafe()){
      continue;
    }
    p->move();
    Participant * p1 = checkForCollision(p);
    if (p1 != nullptr){
        p1->incurDamage(p);
        p->incurDamage(p1);
    }
  }
}

Participant* Escape::checkForCollision(Participant* p){
  int size; 
  Participant* primArr[MAX_ARR] = {}; 
  participants.convertToArray(primArr, size);
  for (int i = 0; i < size; i++){
    Participant* other = primArr[i];
    if (p == other && p){continue;}
    if (p->getRow() == other->getRow() && p->getCol() == other->getCol()){
      return other; 
    }
  }
  return nullptr;
}

void Escape::spawnNinja(){
  int randomCol = random(MAX_COL-1);
  if (withinBounds(1, randomCol)){
    Participant* newNinja = new Ninja(1, random(MAX_COL-2) + 1);
    participants += newNinja;
  }
}

void Escape::printOutcome(Hero* h){
  if (h->isRescued()){
    cout << h->getName() << " HAS BEEN RESCUED!!" << endl;
  } else if (h->isDead()){
    cout << h->getName() << " IS DEAD!!" << endl;
  } else if (h->isSafe()){
    cout << h->getName() << " HAS ESCAPED!!" << endl;
  }
}