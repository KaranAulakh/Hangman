#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>

class GameState {
    private:
        const char* word;
        std::string wordState;
        int lives;

        static const char* createWord();
        std::string createWordState(const char* word);

    public:
        // Enum to represent different hangman stages by remaining lives
        enum HangmanStageByLives {
            ZERO,    // No hangman figure
            ONE,     // Head
            TWO,     // Head and Body
            THREE,   // Head, Body, and One Arm
            FOUR,    // Head, Body, Both Arms
            FIVE,    // Head, Body, Both Arms, One Leg
            SIX     // Full Hangman
        };

        // Constructor
        GameState();

        // Setters and Getters
        int getLives();
        void decreaseLife();
        std::string getWordState();

        // Logic Methods
        void displayGame();
        char promptUserForInput();
        void playChar(char guess);
};

#endif