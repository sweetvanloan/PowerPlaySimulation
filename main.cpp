#include <iostream>
#include <string>
#include <optional>

//  Gender
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

// MetaHuman Class 
class MetaHuman {
public:
    MetaHuman(const std::string& firstName, const std::string& lastName, const std::string& nickname, const std::string& power, Gender gender, Alignment alignment);

    void activatePower() const;
    void marry(MetaHuman& partner);
    void divorce();
    std::string getName() const;
    std::string getNickname() const;
    std::string describe() const;
    bool isMarried() const;

private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string power;
    Gender gender;
    Alignment alignment;
    std::optional<std::string> spouseName;

    std::string genderToString() const;
    std::string alignmentToString() const;
};

//  Implementation
MetaHuman::MetaHuman(const std::string& firstName, const std::string& lastName, const std::string& nickname, const std::string& power, Gender gender, Alignment alignment)
    : firstName(firstName), lastName(lastName), nickname(nickname), power(power), gender(gender), alignment(alignment) {}

// Member Functions 
void MetaHuman::activatePower() const {
    std::cout << getName() << " (" << nickname << ") uses their power: " << power << std::endl;
}

void MetaHuman::marry(MetaHuman& partner) {
    if (!isMarried() && !partner.isMarried()) {
        spouseName = partner.getName();
        partner.spouseName = getName();
    }
}

void MetaHuman::divorce() {
    if (isMarried()) {
        spouseName.reset();
    }
}

std::string MetaHuman::getName() const {
    return firstName + " " + lastName;
}

std::string MetaHuman::getNickname() const {
    return nickname;
}

std::string MetaHuman::describe() const {
    std::string description = getName() + " (" + nickname + ") | Power: " + power + " | Gender: " + genderToString() + " | Alignment: " + alignmentToString();
    if (isMarried()) {
        description += " | Married to: " + *spouseName;
    }
    return description;
}

bool MetaHuman::isMarried() const {
    return spouseName.has_value();
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

// Main 
int main() {
    MetaHuman hero("Morgan", "Blake", "Shadow", "Invisibility", Gender::Female, Alignment::Good);
    MetaHuman partner("Jordan", "Reed", "Phoenix", "Telepathy", Gender::NonBinary, Alignment::Neutral);

    // Demo
    std::cout << hero.describe() << std::endl;
    std::cout << partner.describe() << std::endl;

    hero.marry(partner);
    std::cout << "\nAfter marriage:\n";
    std::cout << hero.describe() << std::endl;
    std::cout << partner.describe() << std::endl;

    hero.divorce();
    std::cout << "\nAfter divorce:\n";
    std::cout << hero.describe() << std::endl;
    std::cout << partner.describe() << std::endl;

    return 0;
}
