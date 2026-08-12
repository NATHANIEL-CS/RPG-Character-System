#include <bits/stdc++.h>
using namespace std;

class Character{
    private:
        string Name;
        int Level;
        int Health;
        int Damage;
        string Weapon;
        string Type;

    public:
    virtual ~Character() = default;

    Character(string aName, int aLevel, int aHealth, int aDamage, string aWeapon, string aType){
        SetName(aName);
        SetLevel(aLevel);
        SetHealth(aHealth);
        SetDamage(aDamage);
        SetWeapon(aWeapon);
        SetType(aType);
    }

    string GetName(){ return Name; }
    int GetLevel(){ return Level; }
    int GetHealth(){ return Health; }
    int GetDamage(){ return Damage; }
    string GetWeapon(){ return Weapon; }
    string GetType(){ return Type; }

    void SetName(string aName){
        Name = aName;
    }

    void SetLevel(int aLevel){
        Level = aLevel;
    }

    void SetHealth(int aHealth){
        Health = aHealth;
    }

    void SetDamage(int aDamage){
        Damage = aDamage;
    }

    void SetWeapon(string aWeapon){
        Weapon = aWeapon;
    }

    void SetType(string aType){
        Type = aType;
    }

    virtual void ShowInfo(){
        cout << "||----------------CHARACTER INFORMATION-----------------|" << endl;
        cout << "NAME    : " << GetName() << endl;
        cout << "LEVEL   : " << GetLevel() << endl;
        cout << "HEALTH  : " << GetHealth() << endl;
        cout << "DAMAGE  : " << GetDamage() << endl;
        cout << "WEAPON  : " << GetWeapon() << endl;
        cout << "TYPE    : " << GetType() << endl;
    }

    virtual void Attack(){
        cout << GetName() << " ATTACKING..." << endl;
    }

    virtual void Defend(){
        cout << GetName() << " DEFENDING..." << endl;
    }

    virtual void Heal(){
        cout << GetName() << " HEALING..." << endl;
    }

    virtual void LevelUp(){
        cout << GetName() << " LEVEL UP..." << endl;
    }
};

class Warrior : public Character{
    private:

    public:

    Warrior(string aName) : Character(aName, 1, 100, 50, "Sword", "Warrior"){}

    void Attack() override{
        cout << GetName() << " Warrior swings his sword!..." << endl;
    }

    void Defend() override{
        cout << GetName() << " Warrior raises his shield!..." << endl;
    }

    void Heal() override{
        cout << GetName() << " Warrior drinks a healing potion!..." << endl;
    }

    void LevelUp() override{
        cout << GetName() << " Warrior has leveled up!..." << endl;
    }
};

class Mage : public Character{
    private:

    public:

    Mage(string aName) : Character(aName, 1, 100, 50, "Magic", "Mage"){}
    void Attack() override{
        cout << GetName() << " Mage casts a powerful spell!..." << endl;
    }

    void Defend() override{
        cout << GetName() << " Mage creates a magical barrier!..." << endl;
    }

    void Heal() override{
        cout << GetName() << " Mage casts a healing spell!..." << endl;
    }

    void LevelUp() override{
        cout << GetName() << " Mage has leveled up!..." << endl;
    }
};

class Archer : public Character{
    private:

    public:
    Archer(string aName) : Character(aName, 1, 100, 50, "Bow", "Archer"){}

    void Attack() override{
        cout << GetName() << " Archer pulls the bow and fires!..." << endl;
    }

    void Defend() override{
        cout << GetName() << " Archer quickly moves away!..." << endl;
    }

    void Heal() override{
        cout << GetName() << " Archer uses a healing potion!..." << endl;
    }

    void LevelUp() override{
        cout << GetName() << " Archer has leveled up!..." << endl;
    }
};

int main()
{
    int characters;
    cout << "HOW MANY CHARCTERS: ";
    cin >> characters;

    Character** ptrChar = new Character*[characters];

    //TYPES OF CHARACTER
    cout << "(1)WARRIOR\n(2)MAGE\n(3)ARCHER" << endl;
    for(int i = 0; i < characters; i++){
        char characterType;
        string Name;
        cout << "\nCHOICE " << i + 1 << ": ";
        cin >> characterType;

        cout << "NAME: ";
        cin.ignore();
        getline(cin, Name);

        if(characterType == '1'){
            ptrChar[i] = new Warrior(Name);
        } else if(characterType == '2'){
            ptrChar[i] = new Mage(Name);
        } else if(characterType == '3'){
            ptrChar[i] = new Archer(Name);
        } else {
            cout << "INVALID CHOICE" << endl;
            i--;
        }
    }

    for(int i = 0; i < characters; i++){
        cout << endl;
        cout << "[" << i + 1 << "]" << endl;
        ptrChar[i] -> ShowInfo();
    }

    cout << "=======================================" << endl;
    cout << "       SELECT CHARACTER" << endl;
    cout << "=======================================" << endl;

    // SELECT CHARACTER
    for(int i = 0; i < characters; i++){
        cout << "(" << i + 1 << ")" << ptrChar[i]->GetName() << endl;
        // for example:
        // (1) Garen
        // (2) Nana
    }

    int select;
    int choice;
    cout << "SELECT: ";
    cin >> select;

    int index = select -1;

    cout << "ACTION MENU" << endl;
    cout << "(1) ATTACK\n(2) DEFEND\n(3) HEAL\n(4) LEVEL UP" << endl;
    cout << "CHOICE: ";
    cin >> choice;

    if(choice == 1){
        ptrChar[index]->Attack();
    } else if(choice == 2){
        ptrChar[index]->Defend();
    } else if(choice == 3){
        ptrChar[index]->Heal();
    } else if(choice == 4){
        ptrChar[index]->LevelUp();
    } else {
        cout << "INVALID CHOICE!" << endl;
    }
    for(int i = 0; i < characters; i++){
        delete ptrChar[i];
    }

    delete[] ptrChar;
    return 0;
}