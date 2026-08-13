#include <bits/stdc++.h>
using namespace std;

class Character{
    private:
        string Name;
        string Role;
        string Weapon;
        int Health;
    
    public:

    Character(string aName, string aRole, string aWeapon, int aHealth){
        SetName(aName);
        SetRole(aRole);
        SetWeapon(aWeapon);
        SetHealth(aHealth);
    }

    string GetName(){ return Name;}
    string GetRole(){ return Role;}
    string GetWeapon(){ return Weapon;}
    int GetHealth(){ return Health;}

    void SetName(string aName){
        Name = aName;
    }

    void SetRole(string aRole){
        Role = aRole;
    }

    void SetWeapon(string aWeapon){
        Weapon = aWeapon;
    }

    void SetHealth(int aHealth){
        Health = aHealth;
    }

    virtual void Attack(Character* enemy){
        cout << GetName() << " HAS BEEN ATTACKED!" << endl;
    }

    virtual void Heal(Character* enemy){
        cout << GetName() << " IS HEALING...";
    }

    virtual void Defense(){
        cout << GetName() << " DEFENSING...." << endl;
    }

    virtual void Showinfo(){
        cout << "NAME   : " << GetName() << endl;
        cout << "ROLE   : " << GetRole() << endl;
        cout << "HEALTH : " << GetHealth() << endl;
        cout << endl;
    }
};

class Warrior : public Character{
    private:

    public:
    Warrior(string aName) : Character(aName, "Warrior", "Sword", 100){}

    void Attack(Character* enemy) override {
        int damage = 10;
        int newHealth = enemy->GetHealth() - damage;
        enemy->SetHealth(newHealth);
        
        cout << GetName() << " HAS BEEN ATTACKED!" << endl;
    }

    void Heal(Character* enemy) override{
        int heal = 10;
        int newHeal = enemy->GetHealth() + heal;
        if(newHeal > 100){
            newHeal = 100;
        }
        enemy->SetHealth(newHeal);
        cout << GetName() << " IS HEALING...";
    }

    void Showinfo() override {
        cout << "NAME   : " << GetName() << endl;
        cout << "ROLE   : " << GetRole() << endl;
        cout << "HEALTH : " << GetHealth() << endl;
        cout << endl;
    }

};

class Enemy : public Character{
    private:

    public:
    Enemy(string aName) : Character(aName, "Enemy", "Bow", 100){}

    void Attack(Character* warrior) override {
        int damage = 10;
        int newHealth = warrior->GetHealth() - damage;
        warrior->SetHealth(newHealth);
        
        cout << GetName() << " HAS BEEN ATTACKED!" << endl;
    }

    void Heal(Character* enemy) override{
        int heal = 10;
        int newHeal = enemy->GetHealth() + heal;
        if(newHeal > 100){
            newHeal = 100;
        }
        enemy->SetHealth(newHeal);
        cout << GetName() << " IS HEALING..." << endl;
    }

    void Showinfo() override {
        cout << "NAME   : " << GetName() << endl;
        cout << "ROLE   : " << GetRole() << endl;
        cout << "HEALTH : " << GetHealth() << endl;
        cout << endl;
    }
};
int main()
{
    int select;
    Character* ptrWarrior = new Warrior("Garen");
    Character* ptrEnemy = new Enemy("Crips");
    
    ptrWarrior->Showinfo();
    ptrEnemy->Showinfo();

    while(ptrEnemy->GetHealth() > 0){
        cout << "(1)ATTACK (2)HEAL";
        cout << "PRESS: ";
        cin >> select;

        if(select == 1){
            ptrWarrior->Attack(ptrEnemy);
            ptrWarrior->Showinfo();
            ptrEnemy->Showinfo();
        } else if(select == 2){
            ptrEnemy->Heal(ptrEnemy);
            ptrEnemy->Showinfo();
        }
    }
    cout << "ENEMY KILL!" << endl;
    return 0;
}