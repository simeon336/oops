#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
class Character
{
public:
    char* pvalue  = NULL;         // Pointer initialized with null
    pvalue  = new char[20];
    
    delete [] pvalue;             // Delete array pointed to by pvalue       // Request memory for the variable
    Character(string name, float health, float defense){
        if(health < 0){
            throw invalid_argument("Health can't be a negative number");
        }
        if(defense < 0){
            throw invalid_argument("Defense can't be a negative number");
        }

        this->health = health;
        this->name = name;
        this->defense = defense;
    }

    
    float getHealth() const{
        return health;
    };
    
    float getDefense() const{
        return defense;
    };
    
    const string& getName() const{
        return name;
    };

    void setHealth(const float health){
        this->health = health;
    };

    void setDefense(const float defense){
        this->defense = defense;
    };
    
    void setName(const string& name){
        this->name = name;
    };

protected:
    float health;
    float defense;
    string name;
};

class Enemy : public Character
{
public:
    Enemy(const string& name, float health, float defense, float damage) : Character(name, health, defense){
        this->damage = damage;
    };
    float getDamage() const{
        return damage;
    };
    void setDamage(const float damage){
        this->damage = damage;
    };

private:
    float damage;
};

class Ability
{
public:
    Ability(const string& name, const float damage){
        this->name = name;
        this->damage = damage;
    };

    float getDamage() const{
        return damage;
    };
    
    void setDamage(const float damage){
        this->damage = damage;
    };
    
    const string& getName() const{
        return name;
    };
    
    void setName(const string& name){
        this->name = name;
    };

private:
    string name;
    float damage;

};

class Player : public Character
{
public:
    Player(const string& name, float health, float defense, const vector<Ability>& abilities) : Character(name, health, defense) {
        this->abilities = abilities;
    };

    Player& addAbility(const Ability& ability){
        this->abilities.push_back(ability);
        return *this;
    };
    const vector<Ability>& getAbilities() const{
        return abilities;
    };

private:
    vector<Ability> abilities;
};

class PlayerHelper
{
public:
    static float getTotalPlayerDamage(const Player& player)
    {
        float dmg = 0;
        for(int i = 0; i < player.getAbilities().size(); ++i){
            dmg += player.getAbilities()[i].getDamage();
        }

        return dmg;
    }
};

class Arena
{
public:
    static int currentEnemyIndex;

    static bool fight(Player& player, vector<Enemy>& enemies)
    {
        int enemyCount = enemies.size();
        float currentCharecterHealth;
        float currentCharecterDefense;
        float currentEnemyHealth;
        float currenEnemyHealth;

        for(int i; i < enemyCount; ++i){
            currentCharecterDefense = player.getDefense() - enemies[i].getDamage();
            
            if(currentCharecterDefense <= 0){
                currentCharecterHealth = player.getHealth() + currentCharecterDefense;

                if(currentCharecterHealth == 0){
                    return 0;
                }
            }

            
        }
    }

};

int Arena::currentEnemyIndex = 0;

int main()
{
    
    
    return 0;
}