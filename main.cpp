#include <iostream>
#include <string>

// Gender
enum class Gender {
    Male,
    Female,
    NonBinary
};

// Alignment
enum class Alignment {
    Good,
    Neutral,
    Evil
};

// MetaHuman Class Def
class MetaHuman {
public:
    MetaHuman(const std::string& firstName, const std::string& lastName, const std::string& power, Gender gender, Alignment alignment);

    void activatePower() const;
    std::string getName() const;
    std::string describe() const;

private:
    std::string firstName;
    std::string lastName;
    std::string power;
    Gender gender;
    Alignment alignment;

    std::string genderToString() const;
    std::string alignmentToString() const;
};

// Constructor Implementation
MetaHuman::MetaHuman(const std::string& firstName, const std::string& lastName, const std::string& power, Gender gender, Alignment alignment)
    : firstName(firstName), lastName(lastName), power(power), gender(gender), alignment(alignment) {}

// Member Functions Implementation
void MetaHuman::activatePower() const {
    std::cout << getName() << " uses their power: " << power << std::endl;
}

std::string MetaHuman::getName() const {
    return firstName + " " + lastName;
}

std::string MetaHuman::describe() const {
    return getName() + " | Power: " + power + " | Gender: " + genderToString() + " | Alignment: " + alignmentToString();
}

std::string MetaHuman::genderToString() const {
    switch (gender) {
        case Gender::Male: return "Male";
        case Gender::Female: return "Female";
        case Gender::NonBinary: return "Non-Binary";
        default: return "Unknown";
    }
}

std::string MetaHuman::alignmentToString() const {
    switch (alignment) {
        case Alignment::Good: return "Good";
        case Alignment::Neutral: return "Neutral";
        case Alignment::Evil: return "Evil";
        default: return "Unknown";
    }
}

// Main Function
int main() {
    MetaHuman hero("Morgan", "Blake", "Invisibility", Gender::Female, Alignment::Good);
    MetaHuman villain("Alex", "Thorn", "Telekinesis", Gender::NonBinary, Alignment::Evil);

    // Demo
    std::cout << hero.describe() << std::endl;
    hero.activatePower();

    std::cout << villain.describe() << std::endl;
    villain.activatePower();

    return 0;
}
