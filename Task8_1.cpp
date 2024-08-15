#include <iostream>
using namespace std;

class Character {
public:
    float health = 100;
    int energy = 500;
};

class Weapon {
public:
    int energy;
    float damage;
    int uses;
};

class Shield {
public:
    int energy;
    float protection;
    int uses;
};

bool canAttack(Character& character, Weapon weapons[], int numWeapons) {
    for (int i = 0; i < numWeapons; ++i) {
        if (character.energy >= weapons[i].energy && weapons[i].uses != 0) {
            return true;
        }
    }
    return false;
}

int main() {
    Character Batman, Joker;

    // Batman's Gadgets
    Weapon Batarang{50, 11, -1};       // Infinite uses
    Weapon GrappleGun{88, 18, 5};
    Weapon ExplosiveGel{92, 10, 3};
    Weapon Batclaw{120, 20, 1};

    Shield CapeGlide{20, 0.4f, -1};    // Infinite uses
    Shield SmokePellet{50, 0.9f, 3};

    // Joker's Gadgets
    Weapon JoyBuzzer{40, 8, -1};       // Infinite uses
    Weapon LaughingGas{56, 13, 8};
    Weapon AcidFlower{100, 22, 3};

    Shield TrickShield{15, 0.32f, -1}; // Infinite uses
    Shield RubberChicken{40, 0.8f, 3};

    int turn = 0;
    int selectedWeapon = 0;
    int selectedShield = 0;
    bool explosiveGelUsed = false;

    cout << "Welcome to Clash of Shadows!" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "1. Batman\n2. Joker" << endl;
    cout << "Choose the player to start: ";
    cin >> turn;

    Weapon batmanWeapons[] = { Batarang, GrappleGun, ExplosiveGel, Batclaw };
    Weapon jokerWeapons[] = { JoyBuzzer, LaughingGas, AcidFlower };

    while (Batman.health > 0 && Joker.health > 0) {
        selectedWeapon = 0;
        selectedShield = 0;

        // Check if both characters can attack
        if (!canAttack(Batman, batmanWeapons, 4) && !canAttack(Joker, jokerWeapons, 3)) {
            cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Both Batman and Joker have run out of energy to attack!" << endl;
            cout << (Batman.health > Joker.health ? "Batman is the winner!" : "Joker is the winner!") << endl;
            cout << "Final state:" << endl;
            cout << "Batman - Health: " << Batman.health << ", Energy: " << Batman.energy << endl;
            cout << "Joker - Health: " << Joker.health << ", Energy: " << Joker.energy << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
            break;
        }

        if (turn == 1) {  // Batman's turn
            cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Batman Weapons:\n";
            cout << "1. Batarang (remaining uses: infinite)\n";
            cout << "2. GrappleGun (remaining uses: " << GrappleGun.uses << ")\n";
            cout << "3. ExplosiveGel (remaining uses: " << ExplosiveGel.uses << ")\n";
            cout << "4. Batclaw (remaining uses: " << Batclaw.uses << ")\n";
            cout << "Batman remaining energy: " << Batman.energy << endl;
            cout << "Choose Batman's Weapon: ";
            cin >> selectedWeapon;

            Weapon* selected = nullptr;
            switch (selectedWeapon) {
                case 1: selected = &Batarang; break;
                case 2: selected = &GrappleGun; break;
                case 3: selected = &ExplosiveGel; break;
                case 4: selected = &Batclaw; break;
                default:
                    cout << "Invalid weapon choice, please try again." << endl;
                    continue;
            }

            if (Batman.energy >= selected->energy && selected->uses != 0) {
                Batman.energy -= selected->energy;
                if (selected->uses > 0) selected->uses--;

                if (selectedWeapon == 3) explosiveGelUsed = true;

                Shield* jokerShield = nullptr;
                if (Joker.energy < 0) {
                    cout << "Joker doesn't have enough energy to use a shield and takes full damage." << endl;
                    Joker.health -= selected->damage;
                } else {
                    while (true) {
                        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                        cout << "Joker Shields:\n";
                        cout << "1. TrickShield (remaining uses: infinite)\n";
                        cout << "2. RubberChicken (remaining uses: " << RubberChicken.uses << ")\n";
                        cout << "Joker remaining energy: " << Joker.energy << endl;
                        cout << "Choose Joker's Shield: ";
                        cin >> selectedShield;

                        switch (selectedShield) {
                            case 1: jokerShield = &TrickShield; break;
                            case 2: jokerShield = &RubberChicken; break;
                            default:
                                cout << "Invalid shield choice, please try again." << endl;
                                continue;
                        }

                        if (Joker.energy >= jokerShield->energy && jokerShield->uses != 0) {
                            Joker.energy -= jokerShield->energy;
                            if (jokerShield->uses > 0) jokerShield->uses--;
                            Joker.health -= (1 - jokerShield->protection) * selected->damage;
                        } else {
                            cout << "Joker doesn't have enough energy to use the shield and takes full damage." << endl;
                            Joker.health -= selected->damage;
                        }
                        break;
                    }
                }

                cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "Batman attacks with ";
                switch (selectedWeapon) {
                    case 1: cout << "Batarang"; break;
                    case 2: cout << "GrappleGun"; break;
                    case 3: cout << "ExplosiveGel"; break;
                    case 4: cout << "Batclaw"; break;
                }
                cout << " and Joker uses ";
                switch (selectedShield) {
                    case 1: cout << "TrickShield"; break;
                    case 2: cout << "RubberChicken"; break;
                    default: cout << "no shield"; break;
                }
                cout << "." << endl;
                cout << "Joker's remaining health: " << Joker.health << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                turn = 2;
            } else {
                cout << "Not enough energy or no remaining uses for this weapon. Turn skipped." << endl;
                turn = 2;
            }

        } else if (turn == 2) {  // Joker's turn
            if (explosiveGelUsed) {
                JoyBuzzer.damage *= 0.8f;
                LaughingGas.damage *= 0.8f;
                AcidFlower.damage *= 0.8f;
                explosiveGelUsed = false;
            } else {
                JoyBuzzer.damage = 8;
                LaughingGas.damage = 13;
                AcidFlower.damage = 22;
            }

            cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Joker Weapons:\n";
            cout << "1. JoyBuzzer (remaining uses: infinite)\n";
            cout << "2. LaughingGas (remaining uses: " << LaughingGas.uses << ")\n";
            cout << "3. AcidFlower (remaining uses: " << AcidFlower.uses << ")\n";
            cout << "Joker remaining energy: " << Joker.energy << endl;
            cout << "Choose Joker's Weapon: ";
            cin >> selectedWeapon;

            Weapon* selected = nullptr;
            switch (selectedWeapon) {
                case 1: selected = &JoyBuzzer; break;
                case 2: selected = &LaughingGas; break;
                case 3: selected = &AcidFlower; break;
                default:
                    cout << "Invalid weapon choice, please try again." << endl;
                    continue;
            }

            if (Joker.energy >= selected->energy && selected->uses != 0) {
                Joker.energy -= selected->energy;
                if (selected->uses > 0) selected->uses--;

                Shield* batmanShield = nullptr;
                if (Batman.energy < 0) {
                    cout << "Batman doesn't have enough energy to use a shield and takes full damage." << endl;
                    Batman.health -= selected->damage;
                } else {
                    while (true) {
                        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                        cout << "Batman Shields:\n";
                        cout << "1. CapeGlide (remaining uses: infinite)\n";
                        cout << "2. SmokePellet (remaining uses: " << SmokePellet.uses << ")\n";
                        cout << "Batman remaining energy: " << Batman.energy << endl;
                        cout << "Choose Batman's Shield: ";
                        cin >> selectedShield;

                        switch (selectedShield) {
                            case 1: batmanShield = &CapeGlide; break;
                            case 2: batmanShield = &SmokePellet; break;
                            default:
                                cout << "Invalid shield choice, please try again." << endl;
                                continue;
                        }

                        if (Batman.energy >= batmanShield->energy && batmanShield->uses != 0) {
                            Batman.energy -= batmanShield->energy;
                            if (batmanShield->uses > 0) batmanShield->uses--;
                            Batman.health -= (1 - batmanShield->protection) * selected->damage;
                        } else {
                            cout << "Batman doesn't have enough energy to use the shield and takes full damage." << endl;
                            Batman.health -= selected->damage;
                        }
                        break;
                    }
                }

                cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "Joker attacks with ";
                switch (selectedWeapon) {
                    case 1: cout << "JoyBuzzer"; break;
                    case 2: cout << "LaughingGas"; break;
                    case 3: cout << "AcidFlower"; break;
                }
                cout << " and Batman uses ";
                switch (selectedShield) {
                    case 1: cout << "CapeGlide"; break;
                    case 2: cout << "SmokePellet"; break;
                    default: cout << "no shield"; break;
                }
                cout << "." << endl;
                cout << "Batman's remaining health: " << Batman.health << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                turn = 1;
            } else {
                cout << "Not enough energy or no remaining uses for this weapon. Turn skipped." << endl;
                turn = 1;
            }
        } else {
            cout << "Invalid choice. Please choose 1 for Batman or 2 for Joker." << endl;
            cin >> turn;
        }
    }

    if (Batman.health <= 0 || Joker.health <= 0) {
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << (Batman.health > 0 ? "Batman is the winner!" : "Joker is the winner!") << endl;
        cout << "Final state:" << endl;
        cout << "Batman - Health: " << Batman.health << ", Energy: " << Batman.energy << endl;
        cout << "Joker - Health: " << Joker.health << ", Energy: " << Joker.energy << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    }

    return 0;
}
