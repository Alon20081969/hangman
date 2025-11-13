#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define WRONG_LETTER 0
#define RIGHT_LETTER 1
#define GUESSED_WORD 2
#define ALREADY_TRIED_LETTER 3

class Play
{
public:
    Play(const std::string& animal);
    int guess();
    void display_dummy(int attempt) const;
    void display_user_word() const;


private:
    std::string m_animal;
    std::string m_user_word;
    std::vector<char> m_guessed_letters;
    static const std::vector<std::string> m_hangman;
};