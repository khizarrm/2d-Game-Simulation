#ifndef HERO_H
#define HERO_H

#include "Participant.h"
#include <string>

using namespace std;

/**
 * @class Hero
 * @brief Represents a hero participant in the escape simulation
 */
class Hero : public Participant {
public:
    /**
     * @brief Constructor to initialize a hero
     * @param av The avatar character representing the hero
     * @param row The row position of the hero
     * @param col The column position of the hero
     * @param name The name of the hero
     */
    Hero(char av = ' ', int row = 0, int col = 0, string name = "");

    /**
     * @brief Function to incur damage to the hero
     * @param p Pointer to the participant causing the damage
     */
    virtual void incurDamage(Participant* p);

    /**
     * @brief Function to cause damage by the hero
     * @return The amount of damage caused
     */
    virtual int causeDamage();

    /**
     * @brief Function to check if the hero is safe
     * @return True if the hero is safe, false otherwise
     */
    virtual bool isSafe();

    /**
     * @brief Function to get the name of the hero
     * @return The name of the hero
     */
    string getName() const;

    /**
     * @brief Function to get the health of the hero
     * @return The health of the hero
     */
    int getHealth() const;

    /**
     * @brief Function to check if the hero is rescued
     * @return True if the hero is rescued, false otherwise
     */
    bool isRescued() const;

private:
    string name; // Name of the hero
    int health;  // Health of the hero
    bool rescued; // Status indicating if the hero is rescued
};

#endif
