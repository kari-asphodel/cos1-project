#include <iostream>

int main()
{
    int enemyHealth = 30;

    while (enemyHealth > 0)
    {
        std::cout << "You attack!\n";
        std::cout << "Enemy health: "
            << enemyHealth << '\n';
    }

    std::cout << "Enemy defeated!\n";

    return 0;
}