#include <iostream>
#include <string>
#include <unordered_map>
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

//  Item Categories
enum class ItemCategory {
    Food,
    Flower,
    Clothes,
    Other
};

// Item Structure
struct Item {
    std::string name;
    ItemCategory category;

    Item(const std::string& name, ItemCategory category) : name(name), category(category) {}
};

// Convert ItemCategory to String
std::string categoryToString(ItemCategory category) {
    switch (category) {
        case ItemCategory::Food: return "Food";
        case ItemCategory::Flower: return "Flower";
        case ItemCategory::Clothes: return "Clothes";
        default: return "Other";
    }
}

// Inventory 
class Inventory {
public:
    void addItem(const Item& item);
    bool hasItem(const std::string& itemName) const;
    bool removeItem(const std::string& itemName);
    void displayItems() const;

private:
    std::unordered_map<std::string, std::pair<Item, int>> items;  // Item names mapped to Item & quantity
};

void Inventory::addItem(const Item& item) {
    items[item.name].first = item;
    items[item.name].second++;
}

bool Inventory::hasItem(const std::string& itemName) const {
    return items.find(itemName) != items.end() && items.at(itemName).second > 0;
}

bool Inventory::removeItem(const std::string& itemName) {
    if (hasItem(itemName)) {
        items[itemName].second--;
        if (items[itemName].second == 0) {
            items.erase(itemName);
        }
        return true;
    }
    return false;
}

void Inventory::displayItems() const {
    std::cout << "Inventory:\n";
    for (const auto& pair : items) {
        std::cout << "- " << pair.first << " x" << pair.second.second << " (Category: " << categoryToString(pair.second.first.category) << ")\n";
    }
}

// MetaHuman Class
class MetaHuman {
public:
    MetaHuman(const std::string& firstName, const std::string& lastName, const std::string& nickname, const std::string& power, Gender gender, Alignment alignment);

    void activatePower() const;
    void marry(MetaHuman& partner);
    void divorce();
    void receiveGift(const Item& item);
    bool giveGift(const std::string& itemName, MetaHuman& receiver);
    void addItemToInventory(const Item& item);
    void showInventory() const;
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
    Inventory inventory;

    std::string genderToString() const;
    std::string alignmentToString() const;
};

// Constructor Implementation for MetaHuman
MetaHuman::MetaHuman(const std::string& firstName, const std::string& lastName, const std::string& nickname, const std::string& power, Gender gender, Alignment alignment)
    : firstName(firstName), lastName(lastName), nickname(nickname), power(power), gender(gender), alignment(alignment) {}

// Member Functions Implementation for MetaHuman
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

void MetaHuman::receiveGift(const Item& item) {
    inventory.addItem(item);
    std::cout << getName() << " received " << item.name << std::endl;
}

bool MetaHuman::giveGift(const std::string& itemName, MetaHuman& receiver) {
    if (inventory.removeItem(itemName)) {
        Item item(itemName, ItemCategory::Other);  // Assume default category for now
        receiver.receiveGift(item);
        std::cout << getName() << " gave " << itemName << " to " << receiver.getName() << std::endl;
        return true;
    }
    std::cout << getName() << " doesn't have " << itemName << " to give.\n";
    return false;
}

void MetaHuman::addItemToInventory(const Item& item) {
    inventory.addItem(item);
}

void MetaHuman::showInventory() const {
    std::cout << getName() << "'s ";
    inventory.displayItems();
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

// Main Function
int main() {
    MetaHuman hero("Morgan", "Blake", "Shadow", "Invisibility", Gender::Female, Alignment::Good);
    MetaHuman partner("Jordan", "Reed", "Phoenix", "Telepathy", Gender::NonBinary, Alignment::Neutral);

    // Demonstration
    Item apple("Apple", ItemCategory::Food);
    Item rose("Rose", ItemCategory::Flower);
    Item shirt("Shirt", ItemCategory::Clothes);

    hero.addItemToInventory(apple);
    hero.addItemToInventory(rose);
    hero.addItemToInventory(shirt);
    hero.showInventory();

    hero.giveGift("Apple", partner);
    hero.showInventory();
    partner.showInventory();

    // Additional functionality needs to be added below
    return 0;
}
