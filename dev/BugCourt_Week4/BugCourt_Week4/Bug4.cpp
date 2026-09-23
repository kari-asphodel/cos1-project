class Enemy
{
public:
    Enemy()
    {
        health = 100;
    }

    void TakeDamage(int damage)
    {
        int health = health - damage;
    }

    int GetHealth()
    {
        return health;
    }

private:
    int health;
};