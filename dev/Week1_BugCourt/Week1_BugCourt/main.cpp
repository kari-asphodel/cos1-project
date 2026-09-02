#include <iostream>
#include <vector>

class Player
{
public:
    void Print()
    {
        std::cout << "Player\n";
    }
};
void Problem1()
{
    Player player;
    player.Print();
    std::cin.get();
}

void Problem2()
{
    std::vector<int> scores;

    scores.push_back(100);

    std::cout << scores[0];
    std::cin.get();
}

void Problem3()
{
    int number = 5;

    int* value = &number;

    cout << *number;
    std::cin.get();
}

void Problem4()
{
    int* data = new int;
    delete data;
    data = new int;

    delete data;
    data = nullptr;
    std::cin.get();
}

class Inventory
{
private:
    int* items;

public:
    Inventory(int count = 0)
    {
        items = new int(count);
    }
    Inventory(const Inventory& other)
    {
        items = new int(*other.items);
    }
    ~Inventory()
    {
        delete items;
    }
};
void Problem5()
{
    Inventory a;
    Inventory b = a;
    std::cin.get();
}
class GhostInventory
{
private:
    int* items;

public:
    GhostInventory(int amount = 0)
    {
        items = new int(amount);
    }
    GhostInventory(const GhostInventory& other)
    {
        ites = new int(*other.items);
    }
    GhostInventory& operator=(const GhostInventory& other)
    {
        if (this != &other)
        {
            int* newItems = new int(*other.items);
            delete items;
            items = newItems;
        }
        return *this;
    }
    ~GhostInventory()
    {
        delete items;
    }
};
void Problem6()
{
    GhostInventory a;

    GhostInventory b = a;
    std::cin.get();
}

class MonsterProblem7
{
private:
    int* health;

public:
    MonsterProblem7()
    {
        health = new int(100);
    }
    MonsterProblem7(const MonsterProblem7& other)
    {
        health = new int(*other.health);
    }
    MonsterProblem7& operator=(const MonsterProblem7& other)
    {
        if (this != &other)
        {
            int* newHealth = new int(*other.health);
            delete health;
            health = newHealth;
        }
        return *this;
    }

    ~MonsterProblem7()
    {
        delete health;
    }
};

int Problem8()
{
    int number = 42;

    return number;
}

void Problem9()
{
    Player* player = new Player();

    if (player != nullptr)
    {
        player->Print();
    }
    delete player;
    player = nullptr;

    std::cin.get();
}

class MonsterInventory
{
private:
    int* data;

public:
    MonsterInventory()
    {
        data = new int(5);
    }
    MonsterInventory& operator=(const MonsterInventory& other)
    {
        if (this != &other)
        {
            int* newItems = new int(*other.data);
            delete data;
            data = newItems;
        }
        return *this;
    }

    ~MonsterInventory()
    {
        delete data;
    }
};

void Problem10()
{
    MonsterInventory a;

    MonsterInventory b;

    b = a;
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
