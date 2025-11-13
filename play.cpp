#include "play.h"

Play::Play(const std::string &animal)
: m_animal(animal)
{
}

bool Play::guess() const
{
    std::cout << "Enter your guess" << std::endl;

    std::string guess;

    std::cin >> guess;

    return guess.compare(m_animal);
}
