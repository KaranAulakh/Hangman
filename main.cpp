#include "gameState.h"
#include <iostream>
#include <unordered_set>

int main() {
    GameState game;
    std::unordered_set<char> guessedChars;

    game.display.clearTerminal();
    while (true) {
        game.display.displayGame();

        // Get valid input
        bool validGuess = false;
        char guess = '\0';
        while (!validGuess) {
            guess = game.display.promptUserForInput();
            if (guessedChars.find(guess) != guessedChars.end()) {
                std::cout << "'" << guess << "' has already been guessed" << std::endl;
            } else {
                validGuess = true;
            }
        }
        guessedChars.insert(guess);
        if (game.playChar(guess)) {
            std::cout << "Congrats!\n\n\n\n";
            break;
        }
        if (game.getLives() < 1) {
            std::cout << "Game Over\n\n\n\n";
            break;
        }
    }

    return 0;
}
