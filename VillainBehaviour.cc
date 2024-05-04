#include "MoveBehaviour.h"
#include "defs.h"
#include <iomanip>

void VillainBehaviour::move(int& oldRow, int& oldCol, int& newRow, int& newCol) {
    int row = random(3)-1; 
    newRow = oldRow + row; 
    if (newRow >= MAX_ROW-7 && newRow < MAX_ROW-2){
        oldRow = newRow; 
    } else {
        newRow = oldRow; 
    }

    int col = random(3) - 1; 
    newCol = oldCol + col;
    if (newCol > 0 && newCol < MAX_COL-1){
        oldCol = newCol; 
    } else{
        newCol = oldCol; 
    }
}