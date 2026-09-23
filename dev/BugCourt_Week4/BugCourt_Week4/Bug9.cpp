#include <vector>
#include <string>
class Inventory
{
public:
    void AddItem(std::string item)
    {
        items.push_back(item);
    }

private:
    std::vector<std::string> Items;
};