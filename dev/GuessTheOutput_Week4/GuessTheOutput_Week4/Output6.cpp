#include <string>
#include <iostream>
class Character
{
public:
    Character(std::string name)
    {
        this->name = name;
    }

    std::string GetName()
    {
        return name;
    }

private:
    std::string name;
};
void Output6()
{
    Character player("Morticia");

    std::cout << player.GetName();
}

//A Character
//B name
//C Morticia
//D Compile Error
