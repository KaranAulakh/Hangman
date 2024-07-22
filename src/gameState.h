#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>
#include <unordered_set>
#include "gameDisplay.h"
#include "wordList.h"

class GameState {
private:
    std::string word;
    std::string wordState;
    int guessedChars;
    int wordSize;
    int lives;
    std::vector<std::string> wordList;

    void initializeWordList();
    std::string getRandomWord();
    std::string createWordState(const std::string& word);

public:
    GameState();
    int getLives() const;
    std::string getWord() const;
    void decreaseLife();
    std::string getWordState() const;
    bool playChar(char guess);

    void clearTerminal() const; // This might be removed if GameDisplay handles it

    // Add a GameDisplay instance
    GameDisplay display;
};

#endif
