#include "MoveBehaviour.h"
#include "defs.h"

void RescuerBehaviour::move(int& oldRow, int& oldCol, int& newRow, int& newCol) {
    newRow = oldRow + 1;
    if (newRow >= MAX_ROW){
        newRow = oldRow; 
    }
    newCol = oldCol; 
}