#include <string>
#include <fstream>

enum class Gender {
    Male,
    Female,
    NonBinary
};

class SuperpoweredIndividual {
public:
    SuperpoweredIndividual(std::string firstName, std::string lastName, std::string power, Gender gender);
    void usePower();
    std::string getFullName() const;
    Gender getGender() const;
    // Other methods...

private:
    std::string firstName;
    std::string lastName;
    std::string power;
    Gender gender;
    // Add attributes...
};

SuperpoweredIndividual::SuperpoweredIndividual(std::string firstName, std::string lastName, std::string power, Gender gender)
    : firstName(firstName), lastName(lastName), power(power), gender(gender) {
    // Con implementation...
}

std::string SuperpoweredIndividual::getFullName() const {
    return firstName + " " + lastName;
}

Gender SuperpoweredIndividual::getGender() const {
    return gender;
}

void SuperpoweredIndividual::usePower() {
    // NEED TO: implement power usage logic...
}




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


