#ifndef MOVEBEHAVIOUR_H
#define MOVEBEHAVIOUR_H

/**
 * @class MoveBehaviour
 * @brief Abstract base class representing a move behavior
 */
class MoveBehaviour {
public:
    /**
     * @brief Destructor to ensure proper cleanup of derived class objects
     */
    virtual ~MoveBehaviour() {}

    /**
     * @brief Pure virtual function to perform a move operation
     * @param oldRow Current row position
     * @param oldCol Current column position
     * @param newRow New row position after the move
     * @param newCol New column position after the move
     */
    virtual void move(int& oldRow, int& oldCol, int& newRow, int& newCol) = 0;
};

/**
 * @class EscapeeBehaviour
 * @brief Represents the move behavior for an escapee
 */
class EscapeeBehaviour : public MoveBehaviour {
public:
    /**
     * @brief Implementation of the move function for an escapee
     * @param oldRow Current row position
     * @param oldCol Current column position
     * @param newRow New row position after the move
     * @param newCol New column position after the move
     */
    virtual void move(int& oldRow, int& oldCol, int& newRow, int& newCol);
};

/**
 * @class VillainBehaviour
 * @brief Represents the move behavior for a villain
 */
class VillainBehaviour : public MoveBehaviour {
public:
    /**
     * @brief Implementation of the move function for a villain
     * @param oldRow Current row position
     * @param oldCol Current column position
     * @param newRow New row position after the move
     * @param newCol New column position after the move
     */
    virtual void move(int& oldRow, int& oldCol, int& newRow, int& newCol);
};

/**
 * @class RescuerBehaviour
 * @brief Represents the move behavior for a rescuer
 */
class RescuerBehaviour : public MoveBehaviour {
public:
    /**
     * @brief Implementation of the move function for a rescuer
     * @param oldRow Current row position
     * @param oldCol Current column position
     * @param newRow New row position after the move
     * @param newCol New column position after the move
     */
    virtual void move(int& oldRow, int& oldCol, int& newRow, int& newCol);
};

/**
 * @class RescuedBehaviour
 * @brief Represents the move behavior for a rescued entity
 */
class RescuedBehaviour : public MoveBehaviour {
public:
    /**
     * @brief Implementation of the move function for a rescued entity
     * @param oldRow Current row position
     * @param oldCol Current column position
     * @param newRow New row position after the move
     * @param newCol New column position after the move
     */
    virtual void move(int& oldRow, int& oldCol, int& newRow, int& newCol);
};

#endif
