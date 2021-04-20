#include "lands.h"

using namespace std;

Land* getRandomLand() {
    LandTypes selection = (LandTypes)(rand() % MAX_NUM_LANDS);

    switch (selection) {
    case LAKE:
        return new Lake;
        break;
    case FOREST:
        return new Forest;
        break;
    case DESERT:
        return new Desert;
        break;
    case GLACIER:
        return new Glacier;
        break;
    case VOLCANO:
        return new Volcano;
        break;
    case MARSH:
        return new Marsh;
        break;
    case CAVE:
        return new Cave;
        break;
    case JUNGLE:
        return new Jungle;
        break;
    default:
        return new Lake;
        break;
    }

}

string Lake::getShortDescription() {
    return "lake";
}

string Lake::getLongDescription() {
    return "You arrive at a large lake filled with clear sparkling water.";
}

string Lake::visit(Player& p) {
    string description = "You drink from the lake, replenishing your thirst";
    p.setThirst(Player::DEFAULT_THIRST);
    return description;
}

string Forest::getShortDescription() {

    return "forest";
}

string Forest::getLongDescription() {
    return "You arrive in dense forest filled with trees and foliage.";
}

string Forest::visit(Player& p) {
    string description = "You forage for berries but find nothing.";

    int chance = rand() % 100;

    // Chance to find berries
    if (chance > 50) {
        description = "You foraged for berries in the forest and found some!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }

    // Chance to get mauled by bear
    if (chance < 10 && chance > 5) {
        description = "You are attacked by a hungry bear in the woods!";
        p.setHealth(p.getHealth() - 1);
    }

    // Chance to get double mauled
    if (chance < 5) {
        description = "You are attacked by two very large bears!";
        int newHealth = (int)p.getHealth() - 2;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
    }


    return description;
}

string Desert::getShortDescription() {

    return "desert";
}

string Desert::getLongDescription() {
    return "You arrive in a extremely hot, dry desert";
}

string Desert::visit(Player& p) {
    string description = "The heat of the desert makes you dehydrated.";

    p.setThirst(p.getThirst() - 1);

    return description;
}

string Volcano::getShortDescription() {
    return "volcano";
}

string Volcano::getLongDescription() {
    return "You arrive at a volcano filled with lava. Yikes!";
}

string Volcano::visit(Player& p) {
    string description = "You stayed away far enough away from the lava to not get hurt, but not close enough to get warm.";

    int chance = rand() % 100;

    // Chance to warm up
    if (chance > 50) {
        description = "You were warmed up by the lava! Health increases.";
        p.setHealth(p.getHealth() + 2);
        return description;
    }

    // Chance to get burnt
    if (chance < 10 && chance > 5) {
        description = "The volcano erupts and you get burnt. Ouch!";
        p.setHealth(p.getHealth() - 2);
    }
}

string Glacier::getShortDescription() {
    return "glacier";
}

string Glacier::getLongDescription() {
    return "You arrive at a glacier. It's cold here.";
}

string Glacier::visit(Player& p) {
    string description = "It's a nice day. Nothing happens.";

    int chance = rand() % 100;

    // Chance to find water
    if (chance > 50) {
        description = "Part of the glacier has melted into drinkable water. Thirst decreases!";
        p.setThirst(p.getThirst() + 1);
        return description;
    }

    // Chance to fall in
    if (chance < 10 && chance > 5) {
        description = "You slip on the ice and fall inS!";
        p.setHealth(p.getHealth() - 1);
    }
}

string Marsh::getShortDescription() {
    return "marsh";
}

string Marsh::getLongDescription() {
    return "You arrive at a marsh. It smells salty and there is tall grass everywhere";
}

string Marsh::visit(Player& p) {
    string description = "You hunt for fish but are unsucessful.";

    int chance = rand() % 100;

    // Chance to catch fish
    if (chance > 50) {
        description = "You grabbed a fish with your bare hands! Great job.";
        p.setHunger(p.getHunger() + 1);
        return description;
    }

    // Chance to get bitten by an alligator
    if (chance < 10 && chance > 5) {
        description = "You are bitten by an alligator!";
        p.setHealth(p.getHealth() - 1);
        return description;
    }
}

string Cave::getShortDescription() {
    return "cave";
}

string Cave::getLongDescription() {
    return "You arrive at a cave. It's dark, but may be a good place to rest.";
}

string Cave::visit(Player& p) {
    string description = "Upon entering, you notice a strange sound. You leave, unharmed.";

    int chance = rand() % 100;

    // Chance to find good shelter
    if (chance > 50) {
        description = "You found a suitible place to rest and take a nap.";
        p.setHealth(p.getHealth() + 1);
        return description;
    }

    // Chance to be crushed by a rock
    if (chance < 10 && chance > 5) {
        description = "You hear rock falling, and get pinned under one. After a few hours, you are able to free yourself.";
        p.setHealth(p.getHealth() - 1);
        return description;
    }
}

string Jungle::getShortDescription() {
    return "jungle";
}

string Jungle::getLongDescription() {
    return "You arrive at a jungle. It's alive with the sounds of animals, and dense with greenery.";
}

string Jungle::visit(Player& p) {
    string description = "You wander through the jungle but find nothing of use.";

    int chance = rand() % 100;

    // Chance for a toucan to help out
    if (chance > 50) {
        description = "A toucan comes along and drops a lizard for you to eat!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }

    // Chance to get too warm
    if (chance < 10 && chance > 5) {
        description = "You wander around the forest for hours but find nothing. You are too warm, and thirsty.";
        p.setThirst(p.getThirst() - 1);
        return description;
    }
}