class SuperpoweredIndividual {
public:
    SuperpoweredIndividual(std::string firstName, std::string lastName, std::string power);
    void usePower();
    std::string getFullName() const;
    // Add additional functions...

private:
    std::string firstName;
    std::string lastName;
    std::string power;
    // NEED: Other attributes
};

SuperpoweredIndividual::SuperpoweredIndividual(std::string firstName, std::string lastName, std::string power)
    : firstName(firstName), lastName(lastName), power(power) {
    // NEED: Constructor implementation
}

std::string SuperpoweredIndividual::getFullName() const {
    return firstName + " " + lastName;
}

void SuperpoweredIndividual::usePower() {
    // NEED: Implement power usage logic
}

#include <fstream>

void saveGame(const SuperpoweredIndividual& character) {
    std::ofstream file("savegame.txt");
    if (file.is_open()) {
        file << character.getFullName() << "\n";
        file << character.getPower() << "\n";
        //  other attributes saved here...
        file.close();
    }
}

// NEED: We'll have  to add a function in our class to get the power.

SuperpoweredIndividual loadGame() {
    std::ifstream file("savegame.txt");
    std::string firstName, lastName, power;

    if (file.is_open()) {
        std::getline(file, firstName, ' ');
        std::getline(file, lastName);
        std::getline(file, power);
        // Load other attributes...
        file.close();
    }

    return SuperpoweredIndividual(firstName, lastName, power);
}


