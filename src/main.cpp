#include "gameState.h"
#include <iostream>
#include <unordered_set>

void displayMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Press Enter to play\n";
    std::cout << "2. Press 'x' to quit\n";
}

void playGame() {
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
            std::cout << "Game Over\nCorrect word was: " << game.getWord() << "\n\n\n\n";
            break;
        }
    }
}

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
