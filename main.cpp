#include "gameState.h"
#include <iostream>
#include <unordered_set>

int main() {
    // Create a GameState object
    GameState game;
    std::unordered_set<char> guessedChars;

    while (game.getLives() > 0) {
        game.displayGame();

        // Get valid input
        bool validGuess = false;
        char guess = '\0';
        while(!validGuess){
          guess = game.promptUserForInput();
          if (guessedChars.find(guess) != guessedChars.end()) {
            std::cout << guess << " has already been guessed" << std::endl;
          } else {
            validGuess = true;
          }
        }
        guessedChars.insert(guess);
        game.playChar(guess);
    }

    // Cleanup memory
    return 0;
}
