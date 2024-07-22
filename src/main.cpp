#include "gameState.h"
#include <iostream>
#include <unordered_set>
#include <set>

void displayMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Press Enter to play\n";
    std::cout << "2. Press 'x' to quit\n";
}

void playGame() {
    GameState game;
    std::set<char> guessedChars;
    const std::unordered_set<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    game.display.clearTerminal();
    while (true) {
        game.display.displayGame();

        // Get valid input
        bool validGuess = false;
        char guess = '\0';
        while (!validGuess) {
            // print previous guesses
            std::cout << "Guessed Characters: ";
            for (char c : guessedChars) {
                std::cout << c << ' ';
            }
            std::cout << std::endl;

            guess = std::tolower(game.display.promptUserForInput());
            if (guessedChars.find(guess) != guessedChars.end()) {
                std::cout << "'" << guess << "' has already been guessed" << std::endl;
            } else if (alphabet.find(guess) == alphabet.end()){
                std::cout << "'" << guess << "' is not a valid letter" << std::endl;
            } 
            else {
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
