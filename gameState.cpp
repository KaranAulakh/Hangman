#include "gameState.h"
#include <iostream>
#include <cstring> 

// Constructor
GameState::GameState() {
    this->lives = 6;
    this->word = this->createWord();
    this->wordState = this->createWordState(this->word);
}

// Getters and Setters
int GameState::getLives(){
    return this->lives;
}

void GameState::decreaseLife(){
    this->lives--;
}

std::string GameState::getWordState(){
    return this->wordState;
}

// Logic Methods
const char* GameState::createWord() {
    static const char* word = "cat";
    return word;
}

std::string GameState::createWordState(const char* word) {
    const int wordSize = strlen(word);
    std::string wordState(wordSize, '_');

    return wordState;
}

void GameState::displayGame() {
    // Hangman logo for different stages
    const char* hangmanLogos[] = {
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

    // Determine which hangman stage to display based on lives remaining
    HangmanStageByLives stage;
    switch (lives) {
        case 6:
            stage = GameState::SIX;
            break;
        case 5:
            stage = GameState::FIVE;
            break;
        case 4:
            stage = GameState::FOUR;
            break;
        case 3:
            stage = GameState::THREE;
            break;
        case 2:
            stage = GameState::TWO;
            break;
        case 1:
            stage = GameState::ONE;
            break;
        default:
            stage = GameState::ZERO;
            break;
    }

    // Print the hangman logo for the current stage
    printf("\n");
    printf("%s", hangmanLogos[stage]);

    // Print lives remaining
    printf("Lives remaining: %d\n", this->lives);

    // Print the current state of the word with spaces
    int wordSize = this->wordState.size();
    printf("Word: ");
    for (int i = 0; i < wordSize; i++) {
        printf("%c ", this->wordState[i]);
    }
    printf("\n");
}

char GameState::promptUserForInput() {
    char guess;
    while (true) {
        printf("\nPlease type your guess: ");
        std::cin >> guess;

        // Check if the input stream is in a failed state
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a single character." << std::endl;
        } else {
            // Check if there are more characters left in the input buffer
            if (std::cin.get() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard remaining input
                std::cout << "You entered more than one character. Please enter a single character." << std::endl;
            } else {
                break; 
            }
        }
    }
    return guess;
}

void GameState::playChar(char guess) {
    bool validGuess = false;
    for (int i = 0; i < this->wordState.size(); i++) {
        if (this->word[i] == guess) {
            this->wordState[i] = guess;
            validGuess = true;
        }
    }

    if (!validGuess) {
        GameState::decreaseLife();
    }
}


