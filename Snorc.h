#ifndef SNORC_H
#define SNORC_H

#include "Participant.h"

/**
 * @class Snorc
 * @brief Represents a Snorc participant in the game
 */
class Snorc : public Participant {
public:
    /**
     * @brief Constructor for Snorc class
     * @param r Initial row position of the Snorc
     * @param c Initial column position of the Snorc
     * @param st Strength of the Snorc
     */
    Snorc(int r = 0, int c = 0, int st = 0);

    /**
     * @brief Function to handle damage incurred by the Snorc
     * @param attacker Pointer to the Participant causing the damage
     */
    virtual void incurDamage(Participant* attacker);

    /**
     * @brief Function to determine the amount of damage caused by the Snorc
     * @return The damage caused by the Snorc
     */
    virtual int causeDamage();

    /**
     * @brief Function to check if the Snorc is safe from harm
     * @return True if the Snorc is safe, false otherwise
     */
    virtual bool isSafe();

private:
    int strength; ///< Strength of the Snorc
};

#endif
