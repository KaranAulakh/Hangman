#ifndef GAMEDISPLAY_H
#define GAMEDISPLAY_H

#include <string>
#include <vector>

class GameState;  // Forward declaration to avoid circular dependency

class GameDisplay {
public:
    // Constructor taking a GameState reference
    GameDisplay(const GameState& gameState);

    // Method to display the current state of the game
    void displayGame() const;

    // Method to prompt user for input
    char promptUserForInput() const;

    // Method to clear the terminal screen
    void clearTerminal() const;

private:
    const GameState& gameState;  // Reference to the GameState object
};

#endif
