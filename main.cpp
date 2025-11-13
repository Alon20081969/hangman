#include <random>
#include <fstream>
#include <iostream>

#include "play.h"

#define ANIMAL_FILE "animals.txt"
#define FAILED_LETTERS 6
#define WRONG_LETTER 0
#define RIGHT_LETTER 1
#define GUESSED_WORD 2
#define ALREADY_TRIED_LETTER 3


std::string get_animal();
int get_animal_amount(std::ifstream& file);
bool play_again();

int main()
{
    std::string animal = "";

    while(true)
    {

        animal = get_animal();

        if(animal.empty())
        {
            std::cout << "error with file" << std::endl;
            return 1;
        }
        
        int word_guessed = 0;
        int count = 0;
        Play play(animal);

        while(count != FAILED_LETTERS)
        {
            word_guessed = play.guess();

            if(word_guessed == GUESSED_WORD)
            {
                play.display_user_word();
                std::cout << "Congrats you won!!!" << std::endl;
                break;
            }

            if(!word_guessed)
            {
                count++;
                if(count == FAILED_LETTERS)
                {
                    std::cout << "Sorry you failed the word was: " << animal << std::endl;
                    break;
                }

                std::cout << "Wrong letter!!!" << std::endl;
                play.display_dummy(count);
            }

            else if (word_guessed == ALREADY_TRIED_LETTER)
            {
                std::cout << "You already tried this letter!!!" << std::endl;
            }

            play.display_user_word();
        }

        if(!play_again())
            break;
    }
    std::cout << "Okay bye bye!!!" << std::endl;
    return 0;
}

std::string get_animal()
{
    std::ifstream file(ANIMAL_FILE);

    if(!file)
    {
        return "";
    }

    std::vector<std::string> animals;
    std::string line;

    while(std::getline(file, line))
    {
        animals.push_back(line);
    }

    if(animals.empty())
        return "";

    int animals_count = animals.size(); 
    
    // we generate a random number that corresponds to the line of the animal that we will pick
    std::random_device rd;  // hardware-based seed
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<> dist(0, animals_count - 1);
    
    int randomNumber = dist(gen);


    
    return animals[randomNumber];
}

bool play_again()
{
    std::cout << "Would you like to play again? y/n" << std::endl;

    char answer;

    std::cin >> answer;

    return answer == 'y';
}
