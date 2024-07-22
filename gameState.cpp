#include "gameState.h"
#include <iostream>
#include <cstring>

GameState::GameState()
    : lives(6), word(createWord()), wordSize(word.size()), guessedChars(0), wordState(createWordState(word)), display(*this) {}

std::string GameState::createWord() {
    return "cat";
}

std::string GameState::createWordState(const std::string& word) {
    return std::string(word.size(), '_');
}

bool GameState::playChar(char guess) {
    bool validGuess = false;
    for (size_t i = 0; i < wordSize; ++i) {
        if (word[i] == guess) {
            wordState[i] = guess;
            guessedChars++;
            validGuess = true;
        }
    }

    display.clearTerminal();
    if (!validGuess) {
        std::cout << "Sorry '" << guess << "' is incorrect\n\n\n\n";
        decreaseLife();
    } else {
        std::cout << "Great Guess\n\n\n\n";
    }

    return guessedChars == wordSize;
}

int GameState::getLives() const {
    return lives;
}

void GameState::decreaseLife() {
    --lives;
}

std::string GameState::getWordState() const {
    return wordState;
}
