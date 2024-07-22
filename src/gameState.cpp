#include "gameState.h"
#include <iostream>
#include <cstring>

GameState::GameState() : display(*this) {
    this->lives = 8;
    this->initializeWordList();
    this->word = this->getRandomWord();
    this->wordSize = this->word.size();
    this->incorrectGuessedChars = 0;
    this->wordState = this->createWordState(this->word);
}

// Loads words.txt at the start of the round
void GameState::initializeWordList() {
    wordList = loadWordList("words.txt");
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

// grabs a random word from the wordList
std::string GameState::getRandomWord() {
    if (wordList.empty()) {
        std::cerr << "Word list is empty!" << std::endl;
        return "default";
    }
    int randomIndex = std::rand() % wordList.size();
    return wordList[randomIndex];
}

// creates the word guessed state initalized to _ for each letter
std::string GameState::createWordState(const std::string& word) {
    return std::string(word.size(), '_');
}

// plays a players guessed char and updates all game variables accordingly
// retun true if game is lost
bool GameState::playChar(char guess) {
    bool validGuess = false;
    for (size_t i = 0; i < wordSize; ++i) {
        if (word[i] == guess) {
            wordState[i] = guess;
            incorrectGuessedChars++;
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

    return incorrectGuessedChars == wordSize;
}

/*
 * Getter and Setter Methods
 */
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
