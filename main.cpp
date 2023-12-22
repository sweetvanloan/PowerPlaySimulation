#include <iostream>
#include <string>

//   Gender
enum class Gender {
    Male,
    Female,
    NonBinary
    Fluid
};

//   Alignment
enum class Alignment {
    Good,
    Neutral,
    Evil
};

// SuperpoweredIndividual Class
class SuperpoweredIndividual {
public:
    SuperpoweredIndividual(std::string firstName, std::string lastName, std::string power, Gender gender, Alignment alignment);

    void usePower() const;
    std::string getFullName() const;
    std::string getPower() const;
    Gender getGender() const;
    Alignment getAlignment() const;

private:
    std::string firstName;
    std::string lastName;
    std::string power;
    Gender gender;
    Alignment alignment;
};

// Constructor 
SuperpoweredIndividual::SuperpoweredIndividual(std::string firstName, std::string lastName, std::string power, Gender gender, Alignment alignment)
    : firstName(std::move(firstName)), lastName(std::move(lastName)), power(std::move(power)), gender(gender), alignment(alignment) {}

// Member Functions Implementation
void SuperpoweredIndividual::usePower() const {
    std::cout << getFullName() << " uses their power: " << getPower() << std::endl;
}

std::string SuperpoweredIndividual::getFullName() const {
    return firstName + " " + lastName;
}

std::string SuperpoweredIndividual::getPower() const {
    return power;
}

Gender SuperpoweredIndividual::getGender() const {
    return gender;
}

Alignment SuperpoweredIndividual::getAlignment() const {
    return alignment;
}

// Main 
int main() {
    SuperpoweredIndividual hero1("Jill", "Blake", "Invisibility", Gender::Female, Alignment::Good);
    SuperpoweredIndividual villain1("Jack", "Thorn", "Telekinesis", Gender::NonBinary, Alignment::Evil); 

    // EX: usage
    hero1.usePower();
    villain1.usePower();

    // more functionality needs to be added

    return 0;
}