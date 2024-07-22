#include "gameState.h"
#include <iostream>
#include <unordered_set>

// Plays one round of hangman with a random word
void playGame(GameState &game) {
    game.start();
    while (true) {
        game.display.displayGame();
        char guess = game.getValidGuess();

        // Handle wining the game
        if (game.playChar(guess)) {
            std::cout << "Congrats!\n\n\n\n";
            break;
        }

        // Handle losing the game
        if (game.getLives() < 1) {
            std::cout << "Game Over\nCorrect word was: " << game.getWord() << "\n\n\n\n";
            break;
        }
    }

    return;
}

// main method: controls navigating menu and gameplay
int main() {
    GameState game;
    game.display.clearTerminal();
    std::cout << "Welcome to Hangman!\n";
    std::string choice;
    while (true) {
        std::cout << "Press ENTER to play or x to quit: ";
        std::getline(std::cin, choice);

        if (choice == "x" || choice == "X") {
            std::cout << "Thanks for hanging around!\n\n";
            break;
        } else if (choice.empty()) {
            game.display.clearTerminal();
            playGame(game);
        } else {
            std::cout << "Invalid option, please try again.\n";
        }
    }

    return 0;
}
