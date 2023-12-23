import random

class CreatureCard:
    def __init__(self, name, attack, defense, type):
        self.name = name
        self.attack = attack
        self.defense = defense
        self.type = type

    def __str__(self):
        return f"{self.name} (Attack: {self.attack}, Defense: {self.defense}, Type: {self.type})"

class EnhancementCard:
    def __init__(self, name, effect):
        self.name = name
        self.effect = effect

    def __str__(self):
        return f"{self.name} (Effect: {self.effect})"

class Player:
    def __init__(self, name):
        self.name = name
        self.deck = []
        self.hand = []
        self.active_enhancements = []

    def draw_card(self):
        if self.deck:
            card = self.deck.pop(0)
            self.hand.append(card)
            print(f"{self.name} drew {card}")

    def play_creature(self):
        creature_cards = [card for card in self.hand if isinstance(card, CreatureCard)]
        if creature_cards:
            return creature_cards.pop(0)
        return None

    def play_enhancement(self):
        enhancement_cards = [card for card in self.hand if isinstance(card, EnhancementCard)]
        if enhancement_cards:
            enhancement = enhancement_cards.pop(0)
            self.active_enhancements.append(enhancement)
            print(f"{self.name} played {enhancement}")
            return enhancement
        return None

def create_deck():
    creatures = [
        CreatureCard("Phoenix", 5, 4, "Fire"),
        CreatureCard("Leviathan", 8, 7, "Water"),
        CreatureCard("Dracula", 6, 5, "Dark"),
        CreatureCard("Goliath", 7, 6, "Earth"),
        CreatureCard("Kraken", 7, 6, "Water"),
        CreatureCard("Dragon", 9, 7, "Fire"),
        CreatureCard("Unicorn", 6, 5, "Light"),
        CreatureCard("Wizard", 5, 4, "Arcane"),
        CreatureCard("Werewolf", 7, 6, "Dark"),
    ]
    enhancements = [
        EnhancementCard("Mystic Forest", "+2 Defense to all creatures"),
        EnhancementCard("Volcanic Terrain", "+3 Attack to Fire creatures"),
    ]
    deck = creatures * 3 + enhancements * 2
    random.shuffle(deck)
    return deck

def battle(players):
    for player in players:
        player.draw_card()
        player.play_enhancement()
        creature = player.play_creature()
        if creature:
            print(f"{player.name} plays {creature.name}!")

    # Implement battle logic here
    print("Battle phase...")

# Game Setup for up to 4 players
player_names = ["Player 1", "Player 2", "Player 3", "Player 4"]
players = [Player(name) for name in player_names]
for player in players:
    player.deck = create_deck()

# Game Loop (one round)
for _ in range(5):
    for player in players:
        player.draw_card()

# Each player plays an enhancement and a creature
battle(players)
