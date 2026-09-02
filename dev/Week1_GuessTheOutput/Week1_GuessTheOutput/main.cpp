#include <iostream>
#include <vector>
#include <string>

void Problem1()
{
    std::vector<int> scores; 
    scores.push_back(10); 
    scores.push_back(20); 
    scores.push_back(30); 
    std::cout << scores[0] << "\n"; 
    std::cout << scores[2] << "\n"; 
    std::cout << scores.size() << "\n";
    
    std::cin.get();
}

void Problem2()
{
    std::vector<int> original = { 5, 10, 15 }; 
    std::vector<int> copy = original; 
    copy[0] = 100; 
    std::cout << original[0] << "\n"; 
    std::cout << copy[0] << "\n";
    
    std::cin.get();
}
void Problem3()
{
    int health = 100; 
    int* healthPointer = &health; 
    *healthPointer = 75; 
    std::cout << health << "\n"; 
    std::cout << *healthPointer << "\n";
    
    std::cin.get();
}

void Problem4()
{
    int first = 10; 
    int second = 20; 
    int* number = &first; 
    std::cout << *number << "\n"; 
    number = &second; *number = 50; 
    std::cout << first << "\n"; 
    std::cout << second << "\n";

    std::cin.get();
}
class Player
{
private: 
    std::string name;
    int health;

public:
    Player(std::string newName, int newHealth)
    {
        name = newName;
        health = newHealth;

        std::cout << name << " created\n";
    }
    void TakeDamage(int damage)
    {
        health -= damage;
    } 
    void Display() const
    {
        std::cout << name << ": " << health << "\n";
    }
};
void Problem5() 
{
    Player player("Morrigan", 100);
    
    player.TakeDamage(25);
    player.Display();
    
    std::cin.get();
}

class Spell
{
private:
    std::string name;
public:
    Spell(std::string newName)
    {
        name = newName;
    }
    Spell(const Spell& other)
    {
        name = other.name;
        std::cout << "Copying " << name << "\n";
    }
    ~Spell()
    {
        std::cout << "Destroying " << name << "\n";
    }
    void Cast() const
    {
        std::cout << "Casting " << name << "\n";
    }
};
void UseSpell(Spell spell)
{
    spell.Cast();
}
void Problem6()
{
    Spell spell("Shadow Bolt");
    UseSpell(spell);
    std::cout << "Back in Problem 6\n";
    std::cin.get();
}

class Treasure
{
private:
    int* gold;
public:
    Treasure(int amount)
    {
        gold = new int(amount);
    }
    Treasure(const Treasure& other)
    {
        gold = new int(*other.gold);
        std::cout << "Deep copy created\n";
    }
    ~Treasure()
    {
        delete gold;
    }
    void SetGold(int amount)
    {
        *gold = amount;
    }
    int GetGold() const
    {
        return *gold;
    }
};
void Problem7()
{
    Treasure original(100);
    Treasure copy = original;

    copy.SetGold(500);
    std::cout << original.GetGold() << "\n";
    std::cout << copy.GetGold() << "\n";

    std::cin.get();
}

class Relic
{
private: 
    int* power;
public:
    Relic(int amount)
    {
        power = new int(amount);
    }
    Relic(const Relic& other)
    {
        power = new int(*other.power);
        std::cout << "Copy constructor";
    }
    Relic& operator=(const Relic& other)
    {
        std::cout << "Copy assignment\n";
        if (this != &other)
        {
            delete power;
            power = new int(*other.power);
        }
        return *this;
    }
    ~Relic()
    {
        delete power;
    }
    void SetPower(int amount)
    {
        *power = amount;
    }
    void GetPower() const
    {
        return *power;
    }
};
void Problem8()
{
    Relic first(25);
    Relic second(75);
    second = first;
    first.SetPower(100);
    std::cout << first.GetPower() << "\n";
    std::cout << second.GetPower() << "\n";

    std::cin.get();
}

class Creature
{
private:
    std::string name;
public:
    Creature(std::string newName)
    {
        name = newName;
        std::cout << "Entering: " << name << "\n";
    }
    ~Creature()
    {
        std::cout << "Leaving: " << name << "\n";
    }
};
void Problem9()
{
    Creature first("Raven");
    {
        Creature second("Moth");
        std::cout << "Inside the inner scope\n";
    }
    std::cout << "Back in Problem 9\n";
    
    std::cin.get();
}

class Enemy 
{
private:
    int health;
public:
    Enemy(int startingHealth)
    {
        health = startingHealth;
    }
    int GetHealth() const
    {
        return health;
    }
};
void Problem10()
{
    std::vector<Enemy*> enemies;
    enemies.push_back(new Enemy(50)); 
    enemies.push_back(new Enemy(75)); 
    enemies.push_back(new Enemy(100)); 
    for (Enemy* enemy : enemies) 
    { 
        std::cout << enemy->GetHealth() << "\n"; 
    } 
    for (Enemy* enemy : enemies) 
    { 
        delete enemy; 
    } 
    enemies.clear(); 
    std::cout << enemies.size() << "\n";
    
    std::cin.get();
}
int main()
{
    Problem1();
    //Problem2();
    //Problem3();
    //Problem4();
    //Problem5();
    //Problem6();
    //Problem7();
    //Problem8();
    //Problem9();
    //Problem10();
}
