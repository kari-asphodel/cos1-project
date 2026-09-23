#include <string>

class Weapon
{
public:
    Weapon(std::string name, int damage);

    std::string GetName();
    int GetDamage();

private:
    std::string name;
    int damage;
};