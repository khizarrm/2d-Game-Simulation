#ifndef ESCAPE_H
#define ESCAPE_H

#include "Participant.h" // Include Participant header for using Participant class
#include "Hero.h"        // Include Hero header for using Hero class
#include "Ninja.h"       // Include Ninja header for using Ninja class
#include "Snorc.h"       // Include Snorc header for using Snorc class
#include "List.h"        // Include List header for using List class

/**
 * @class Escape
 * @brief Represents the control object for the simulation
 */
class Escape {
public:
    /**
     * @brief Constructor to initialize Escape object
     */
    Escape();
    
    /**
     * @brief Destructor to deallocate memory
     */
    ~Escape();
    
    /**
     * @brief Function to run the escape simulation
     */
    void runEscape();
    
    /**
     * @brief Static function to check if a position is within bounds of the Snorc Pit
     * @param row The row position to check
     * @param col The column position to check
     * @return True if within bounds, false otherwise
     */
    static bool withinBounds(int row, int col);

private:
    int numSnorcs;                // Number of snorcs in the escape
    List<Participant> participants; // List of participants in the escape
    Hero* timmy;                  // Pointer to Timmy hero
    Hero* harold;                 // Pointer to Harold hero
    
    /**
     * @brief Function to spawn a snorc
     */
    void spawnSnorc();
    
    /**
     * @brief Function to spawn a ninja
     */
    void spawnNinja();
    
    /**
     * @brief Function to check for collisions between participants
     * @param p Pointer to the participant to check for collision
     * @return Pointer to the colliding participant, nullptr if no collision
     */
    Participant* checkForCollision(Participant* p);
    
    /**
     * @brief Function to move participants
     */
    void moveParticipants();
    
    /**
     * @brief Function to print the Snorc Pit
     */
    void printPit();
    
    /**
     * @brief Function to print outcome for a hero
     * @param hero Pointer to the hero to print outcome for
     */
    void printOutcome(Hero* hero);
    
    /**
     * @brief Function to check if the escape is over
     * @return True if escape is over, false otherwise
     */
    bool isOver();
};

#endif
