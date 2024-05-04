#include "MoveBehaviour.h"
#include "defs.h"

void RescuedBehaviour::move(int& oldRow, int& oldCol, int& newRow, int& newCol) {
    newRow = oldRow - 1; 
    if (newRow < 0){
        newRow = oldRow; 
    }
    newCol = oldCol; 
}