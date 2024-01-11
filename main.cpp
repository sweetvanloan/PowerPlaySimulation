#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

// Enumeration for Gender
enum class Gender {
    Male,
    Female,
    NonBinary
};

// Enumeration for Alignment
enum class Alignment {
    Good,
    Neutral,
    Evil
};

// Item Structure and Category
enum class ItemCategory { Food, Flower, Clothes, Other };
enum class ItemEffect { Depower, BoostPower, BoostHealth, IncreaseMood };

struct Item {
    std::string name;
    ItemCategory category;
    ItemEffect effect;
    Item(const std::string& name, ItemCategory category, ItemEffect effect) : name(name), category(category), effect(effect) {}
};

// Inventory Class
class Inventory {
public:
    void addItem(const Item& item);
    bool hasItem(const std::string& itemName) const;
    bool removeItem(const std::string& itemName);
    void displayItems() const;
private:
    std::unordered_map<std::string, std::pair<Item, int>> items;  // Maps item names to item and quantity
};

// Pet Class
class Pet {
    std::string name;
    std::string type;
public:
    Pet(const std::string& name, const std::string& type) : name(name), type(type) {}
    void display() const;
};

// MetaHuman Class
class MetaHuman : public std::enable_shared_from_this<MetaHuman> {
    std::string firstName, lastName, nickname, power;
    Gender gender;
    Alignment alignment;
    int energy = 100, mood = 50;
    std::shared_ptr<Pet> pet;
    std::shared_ptr<MetaHuman> partner;
    std::vector<std::shared_ptr<MetaHuman>> children;
    std::weak_ptr<MetaHuman> mother, father;
    Inventory inventory;

public:
    MetaHuman(const std::string& firstName, const std::string& lastName, const std::string& nickname, const std::string& power, Gender gender, Alignment alignment);

    void activatePower() const;
    void rest();
    void drinkCoffee();
    void changeMood(int delta);
    void interact(MetaHuman& other);

    void adoptPet(const std::shared_ptr<Pet>& newPet);
    static std::shared_ptr<MetaHuman> reproduce(const MetaHuman& parent1, const MetaHuman& parent2);
    void displayFamilyTree() const;

    // Additional methods for inventory, items, etc.
};

// MetaHuman class member function implementations

// Main Function
int main() {
    // Need to create MetaHumans and Pets, demonstrate features
    return 0;
}
