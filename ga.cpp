#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Creature {
public:
    string name;
    int health;
    int attack;
    int magicAttack;
    int defense;
    int physicalResistance;
    int magicalResistance;
};

int main() {
    Creature player = { "Hero", 100, 20, 25, 10, 0, 0 };

    vector<Creature> monsters;
    monsters.push_back({ "Goblin", 50, 15, 0, 5, 0, 0 });
    monsters.push_back({ "Golem", 150, 18, 0, 15, 40, 0 });
    monsters.push_back({ "Slime", 70, 10, 0, 8, 0, 30 });

    cout << "--- Monster Selection ---" << endl;
    for (int i = 0; i < monsters.size(); ++i) {
        cout << i + 1 << ". " << monsters[i].name << endl;
    }
    cout << "Enter the number of the monster you want to fight: ";
    int monsterChoice;
    cin >> monsterChoice;

    if (monsterChoice < 1 || monsterChoice > monsters.size()) {
        cout << "Invalid choice. Exiting game." << endl;
        exit(0);
    }
    Creature monster = monsters[monsterChoice - 1];

    while (player.health > 0 && monster.health > 0) {
        cout << "\n--- Combat ---" << endl;
        cout << player.name << " Health: " << player.health << endl;
        cout << monster.name << " Health: " << monster.health << endl;
        cout << "------------------" << endl;

        cout << "What do you want to do?" << endl;
        cout << "1. Physical Attack" << endl;
        cout << "2. Magic Attack" << endl;
        cout << "3. Flee" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                float damage = static_cast<float>(player.attack - monster.defense);
                damage *= (1.0f - static_cast<float>(monster.physicalResistance) / 100.0f);
                int finalDamage = static_cast<int>(damage);
                if (finalDamage < 1) finalDamage = 1;
                monster.health -= finalDamage;
                cout << "\nYou physically attack the " << monster.name << " for " << finalDamage << " damage!" << endl;
                
                if (monster.name == "Golem") {
                    cout << "It wasn't effective." << endl;
                }

                if (monster.health < 0) {
                    monster.health = 0;
                }

                if (monster.health > 0) {
                    int monsterDamage = monster.attack - player.defense;
                    if (monsterDamage < 1) monsterDamage = 1;
                    player.health -= monsterDamage;
                    cout << "The " << monster.name << " attacks you for " << monsterDamage << " damage!" << endl;
                    
                    if (player.health < 0) {
                        player.health = 0;
                    }
                }
                break;
            }
            case 2: {
                float damage = static_cast<float>(player.magicAttack - monster.defense);
                damage *= (1.0f - static_cast<float>(monster.magicalResistance) / 100.0f);
                int finalDamage = static_cast<int>(damage);
                if (finalDamage < 1) finalDamage = 1;
                monster.health -= finalDamage;
                cout << "\nYou use magic on the " << monster.name << " for " << finalDamage << " damage!" << endl;
                
                if (monster.name == "Slime") {
                    cout << "It wasn't effective." << endl;
                }

                if (monster.health < 0) {
                    monster.health = 0;
                }

                if (monster.health > 0) {
                    int monsterDamage = monster.attack - player.defense;
                    if (monsterDamage < 1) monsterDamage = 1;
                    player.health -= monsterDamage;
                    cout << "The " << monster.name << " attacks you for " << monsterDamage << " damage!" << endl;
                    
                    if (player.health < 0) {
                        player.health = 0;
                    }
                }
                break;
            }
            case 3: {
                cout << "\nYou successfully flee from the battle." << endl;
                player.health = 0;
                break;
            }
            case 4: {
                cout << "Exiting the game." << endl;
                exit(0);
                break;
            }
            default: {
                cout << "\nInvalid choice. Try again." << endl;
                break;
            }
        }
    }

    cout << "\n--- End of Game ---" << endl;
    if (player.health > 0) {
        cout << "You defeated the " << monster.name << "! You win!" << endl;
    } else {
        cout << "You were defeated by the " << monster.name << ". Game Over!" << endl;
    }

    return 0;
}
