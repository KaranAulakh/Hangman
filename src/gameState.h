#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>
#include <unordered_set>
#include <set>
#include "gameDisplay.h"
#include "wordList.h"

class GameState {
private:
    std::string word;
    std::string wordState;
    int incorrectGuessedChars;
    int wordSize;
    int lives;
    std::vector<std::string> wordList;
    std::set<char> guessedChars;
    const std::unordered_set<char> alphabet;

    void initializeWordList();
    std::string getRandomWord();
    std::string createWordState(const std::string& word);

public:
    GameState();
    int getLives() const;
    std::string getWord() const;
    std::string getWordState() const;
    std::set<char> getGuessedChars() const;
    
    void decreaseLife();
    bool playChar(char guess);
    char getValidGuess();
    void clearTerminal() const; // This might be removed if GameDisplay handles it

    // Add a GameDisplay instance
    GameDisplay display;
};

#endif
