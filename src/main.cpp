#include "gameState.h"
#include <iostream>
#include <unordered_set>

// Displays menu in between game rounds
void displayMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Press Enter to play\n";
    std::cout << "2. Press 'x' to quit\n";
}

// Plays one round of hangman with a random word
void playGame() {
    GameState game;
    std::set<char> guessedChars;

    game.display.clearTerminal();
    while (true) {
        game.display.displayGame();

        char guess = game.getValidGuess();
        if (game.playChar(guess)) {
            std::cout << "Congrats!\n\n\n\n";
            break;
        }
        if (game.getLives() < 1) {
            std::cout << "Game Over\nCorrect word was: " << game.getWord() << "\n\n\n\n";
            break;
        }
    }
}

// Main method, controls navigating menu and gameplay
int main() {
    std::string choice;
    while (true) {
        displayMenu();
        std::getline(std::cin, choice);

        if (choice == "x" || choice == "X") {
            std::cout << "Thanks for hanging around!" << std::endl;
            break;
        } else if (choice.empty()) {
            playGame();
        } else {
            std::cout << "Invalid option, please try again.\n";
        }
    }

    return 0;
}
