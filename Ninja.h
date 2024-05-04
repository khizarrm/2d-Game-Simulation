#ifndef NINJA_H
#define NINJA_H

#include "Participant.h"
#include "MoveBehaviour.h"

/**
 * @class Ninja
 * @brief Represents a Ninja participant in the game
 */
class Ninja : public Participant {
public:
    /**
     * @brief Constructor for Ninja class
     * @param row Initial row position of the Ninja
     * @param col Initial column position of the Ninja
     */
    Ninja(int row, int col);

    /**
     * @brief Destructor for Ninja class
     */
    virtual ~Ninja();

    /**
     * @brief Function to handle damage incurred by the Ninja
     * @param attacker Pointer to the Participant causing the damage
     */
    virtual void incurDamage(Participant* attacker);

    /**
     * @brief Function to determine the amount of damage caused by the Ninja
     * @return The damage caused by the Ninja
     */
    virtual int causeDamage();

    /**
     * @brief Function to check if the Ninja is safe from harm
     * @return True if the Ninja is safe, false otherwise
     */
    virtual bool isSafe();

private:
    int strength; ///< Strength of the Ninja
    bool poisoned; ///< Flag indicating whether the Ninja is poisoned
};

#endif
