#include <random>
#include <fstream>
#include <iostream>

#define ANIMAL_FILE "animals.txt"

std::string get_animal();
int get_animal_amount(std::ifstream& file);

int main()
{
    std::string animal = "";

    while(true)
    {

        animal = get_animal();

        if(animal.empty())
        {
            std::cout << "error with file" << std::endl;
        }

        
    }
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


