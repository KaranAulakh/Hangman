#include "gameState.h"
#include <iostream>
#include <cstring>

// Constructor definition
GameState::GameState()
    : guessedChars(),
      alphabet({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}),
      display(*this) // Ensure display is initialized after guessedChars and alphabet
{
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

char GameState::getValidGuess() {
    bool validGuess = false;
    char guess = '\0';
    while (!validGuess) {
        guess = std::tolower(display.promptUserForInput());
        if (guessedChars.find(guess) != guessedChars.end()) {
            std::cout << "'" << guess << "' has already been guessed" << std::endl;
        } else if (this->alphabet.find(guess) == this->alphabet.end()){
            std::cout << "'" << guess << "' is not a valid letter" << std::endl;
        } 
        else {
            validGuess = true;
        }
    }

    return guess;
}

// plays a players guessed char and updates all game variables accordingly
// retun true if game is lost
bool GameState::playChar(char guess) {
    guessedChars.insert(guess);
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

std::set<char> GameState::getGuessedChars() const {
    return this->guessedChars;
}
