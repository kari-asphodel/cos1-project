#include <iostream>
#include <vector>

class Relic
{
public:
    int power;

    Relic(int p)
    {
        power = p;
    }
};

int main()
{
    std::vector<Relic> relics;

    relics.push_back(Relic(10));
    relics.push_back(Relic(20));
    relics.push_back(Relic(30));

    Relic* chosen = &relics[1];

    chosen->power += 5;

    std::cout << relics[1].power << " ";
    std::cout << chosen->power;

    return 0;
}

// A. 20 25
// B. 25 25
// C. 20 20
// D. Does not compile