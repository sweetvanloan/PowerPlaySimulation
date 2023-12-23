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

    def play_card(self):
        if self.hand:
            return self.hand.pop(0)
        else:
            print(f"{self.name} has no cards to play!")
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
        # Add more creatures here
    ]

    enhancements = [
        EnhancementCard("Mystic Forest", "+2 Defense to all creatures"),
        EnhancementCard("Volcanic Terrain", "+3 Attack to Fire creatures"),
        # Add more enhancements here
    ]

    deck = creatures * 3 + enhancements * 2  # Adjust proportions as needed
    random.shuffle(deck)
    return deck

def apply_enhancements(player, card):
    for enhancement in player.active_enhancements:
        # Define the logic to apply enhancement effects here
        print(f"Applying {enhancement.effect} to {card.name}")

def battle(card1, card2):
    print(f"{card1.name} battles {card2.name}!")
    if card1.attack > card2.defense:
        print(f"{card1.name} wins!")
    elif card1.attack < card2.defense:
        print(f"{card2.name} wins!")
    else:
        print("The battle is a draw!")

# Game Setup
player1 = Player("Player 1")
player2 = Player("Player 2")
player1.deck = create_deck()
player2.deck = create_deck()

# Game Loop (for one round)
for _ in range(5):
    player1.draw_card()
    player2.draw_card()

# Players play enhancement cards
enhancement1 = player1.play_card()
if isinstance(enhancement1, EnhancementCard):
    player1.active_enhancements.append(enhancement1)

enhancement2 = player2.play_card()
if isinstance(enhancement2, EnhancementCard):
    player2.active_enhancements.append(enhancement2)

# Players play creature cards and battle
card1 = player1.play_card()
card2 = player2.play_card()

if card1 and card2:
    apply_enhancements(player1, card1)
    apply_enhancements(player2, card2)
    battle(card1, card2)
