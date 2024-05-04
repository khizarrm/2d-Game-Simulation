#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "MoveBehaviour.h"

/**
 * @class Participant
 * @brief Represents a participant in the game
 */
class Participant {
public:
    /**
     * @brief Constructor for Participant class
     * @param av Avatar character representing the participant
     * @param r Initial row position of the participant
     * @param c Initial column position of the participant
     * @param mb Pointer to the MoveBehaviour object defining the movement behavior of the participant
     */
    Participant(char av, int r, int c, MoveBehaviour* mb);

    /**
     * @brief Destructor for Participant class
     */
    virtual ~Participant();

    /**
     * @brief Function to perform the participant's movement
     */
    virtual void move();

    /**
     * @brief Function to handle damage incurred by the participant
     * @param attacker Pointer to the Participant causing the damage
     */
    virtual void incurDamage(Participant* attacker) = 0;

    /**
     * @brief Function to determine the amount of damage caused by the participant
     * @return The damage caused by the participant
     */
    virtual int causeDamage() = 0;

    /**
     * @brief Function to check if the participant is safe from harm
     * @return True if the participant is safe, false otherwise
     */
    virtual bool isSafe() = 0;

    /**
     * @brief Function to get the avatar character of the participant
     * @return The avatar character
     */
    char getAvatar() const;

    /**
     * @brief Function to get the row position of the participant
     * @return The row position
     */
    int getRow() const;

    /**
     * @brief Function to get the column position of the participant
     * @return The column position
     */
    int getCol() const;

    /**
     * @brief Function to check if the participant is dead
     * @return True if the participant is dead, false otherwise
     */
    bool isDead() const;

    /**
     * @brief Function to set the movement behavior of the participant
     * @param move Pointer to the MoveBehaviour object defining the movement behavior
     */
    void setMoveBehaviour(MoveBehaviour* move);

protected:
    char avatar; ///< Avatar character representing the participant
    int row;     ///< Row position of the participant
    int col;     ///< Column position of the participant
    bool dead;   ///< Flag indicating whether the participant is dead
    MoveBehaviour* moveBehaviour; ///< Pointer to the MoveBehaviour object defining the movement behavior
};

#endif
