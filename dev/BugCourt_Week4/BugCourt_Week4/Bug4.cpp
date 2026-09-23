class Enemy
{
public:
    Enemy()
    {
        health = 100;
    }

    void TakeDamage(int damage)
    {
        health -= damage; 
    }

    int GetHealth()
    {
        return health;
    }

private:
    int health;
};