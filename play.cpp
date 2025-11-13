#include "play.h"

const std::vector<std::string> Play::m_hangman = {
        // Stage 0
        "  +---+\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        // Stage 1
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        // Stage 2
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        // Stage 3
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|   |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        // Stage 4
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        // Stage 5
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " /    |\n"
        "      |\n"
        "=========\n",

        // Stage 6 (final)
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " / \\  |\n"
        "      |\n"
        "=========\n"
    };


Play::Play(const std::string &animal)
: m_animal(animal)
{
    std::cout << "Welcome to Alon's hangman" << std::endl;
    std::cout << "-----------------------------" << std::endl << std::endl;
    display_dummy(0);
    for(const auto c : m_animal)
    {
        m_user_word += "_";
    }

    display_user_word();
}

int Play::guess() 
{
    std::cout << "Enter your guess:" << std::endl;

    char guess;
    std::cin >> guess;

    bool good_guess = false;

    auto used_letter = find(m_guessed_letters.begin(), m_guessed_letters.end(), guess);

    if(used_letter != m_guessed_letters.end())
        return ALREADY_TRIED_LETTER;

    for(int i = 0; i < m_animal.size(); i++)
    {
        if(m_animal[i] == guess && m_user_word[i] == '_')
        {
            m_user_word[i] = guess;
            good_guess = RIGHT_LETTER;
        }
    }

    if(good_guess)
    {
        m_guessed_letters.push_back(guess);
    }

    if(!m_user_word.compare(m_animal))
    {
        return GUESSED_WORD;
    }

    return good_guess;
}

void Play::display_dummy(int attempt) const
{
    std::cout << m_hangman[attempt] << std::endl;
}

void Play::display_user_word() const
{
    std::cout << "The animal: ";
    for(const auto c : m_user_word)
    {
        std::cout << c << " ";
    }

    std::cout << std::endl;
}
