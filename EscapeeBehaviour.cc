#include "MoveBehaviour.h"
#include "defs.h"

void EscapeeBehaviour::move(int& oldRow, int& oldCol, int& newRow, int& newCol) {
    int rowChange = random(5) - 2; //change movements?
    int colChange = random(3) - 1; 

    newRow = oldRow + rowChange;
    if (newRow >= 0 && newRow < MAX_ROW-2){
        oldRow = newRow; 
    } else {
        newRow = oldRow; 
    } 

    newCol = oldCol + colChange;
    if (newCol >= 0 && newCol < MAX_COL-1){
        oldCol = newCol; 
    } else{
        newCol = oldCol; 
    }

}
    