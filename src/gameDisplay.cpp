#include "gameDisplay.h"
#include "gameState.h"
#include <iostream>
#include <limits>
#include <vector>
#include <string>

GameDisplay::GameDisplay(const GameState& gameState) : gameState(gameState) {}

void GameDisplay::displayGame() const {
    static const std::vector<std::string> hangmanLogos = {
        "       +\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "=========\n",

        "   +---+\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "=========\n",

        "   +---+\n"
        "   |   |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "=========\n",

        "   +---+\n"
        "   |   |\n"
        "   O   |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "=========\n",

        "   +---+\n"
        "   |   |\n"
        "   O   |\n"
        "   |   |\n"
        "       |\n"
        "       |\n"
        "=========\n",

        "   +---+\n"
        "   |   |\n"
        "   O   |\n"
        "  /|   |\n"
        "       |\n"
        "       |\n"
        "=========\n",

        "   +---+\n"
        "   |   |\n"
        "   O   |\n"
        "  /|\\  |\n"
        "       |\n"
        "       |\n"
        "=========\n",

        "   +---+\n"
        "   |   |\n"
        "   O   |\n"
        "  /|\\  |\n"
        "  /    |\n"
        "       |\n"
        "=========\n",

        "   +---+\n"
        "   |   |\n"
        "   O   |\n"
        "  /|\\  |\n"
        "  / \\  |\n"
        "       |\n"
        "=========\n"
    };

    // Determine which stage to display
    int stage = 8 - gameState.getLives();
    std::cout << "\n" << hangmanLogos[stage] << "\n";
    std::cout << "Lives remaining: " << gameState.getLives() << "\n";
    std::cout << "Word: ";
    for (char c : gameState.getWordState()) {
        std::cout << c << ' ';
    }
    std::cout << "\n";
}

char GameDisplay::promptUserForInput() const {
    char guess;
    while (true) {
        std::cout << "\nPlease type your guess: ";
        std::cin >> guess;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a single character." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return guess;
        }
    }
}

void GameDisplay::clearTerminal() const {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}
