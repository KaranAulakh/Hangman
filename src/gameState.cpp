#include "gameState.h"
#include <iostream>
#include <cstring>

GameState::GameState() : display(*this) {
    this->lives = 8;
    this->initializeWordList();
    this->word = this->getRandomWord();
    this->wordSize = this->word.size();
    this->guessedChars = 0;
    this->wordState = this->createWordState(this->word);
}

void GameState::initializeWordList() {
    wordList = loadWordList("words.txt");
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

std::string GameState::getRandomWord() {
    if (wordList.empty()) {
        std::cerr << "Word list is empty!" << std::endl;
        return "default";
    }
    int randomIndex = std::rand() % wordList.size();
    return wordList[randomIndex];
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

std::string GameState::getWord() const {
    return this->word;
}

void GameState::decreaseLife() {
    --lives;
}

std::string GameState::getWordState() const {
    return wordState;
}
