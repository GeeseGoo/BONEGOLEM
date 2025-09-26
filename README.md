# BONEGOLEM

A 2 player, turn-based card game inspired by Hearthstone. Play minions, cast spells, attach enchantments, and manage rituals until your opponent runs out of health.

## Turn Structure
1. **Start of Turn**
   - Refresh each friendly minion to **1 action**
   - Gain magic; draw 1 card if possible
   - Resolve **StartTurn** triggers (see APNAP)
2. **Main Phase**
   - **Play** cards (minions, spells, enchantments, rituals)
   - **Attack** with minions (player or minion targets)
   - **Use** activated abilities
   - Each minion generally gets **one** action (attack **or** ability)
3. **End of Turn**
   - Resolve **EndTurn** triggers

**Combat & Death**
- Attacks reduce defence; if a minion’s defence ≤ 0, it dies (to Graveyard)
- Multiple deaths can cascade triggers and change outcomes mid-resolution

---

## Card Types
- **Minion** — Stays on the board, can attack or use abilities
- **Spell** — One-shot effect; does not stay on the board
- **Enchantment** — Attaches to a minion; decorator chain applies **oldest → newest**
- **Ritual** — Persistent effect with charges/activation cost
---

## Triggers & Abilities
- **Trigger types:** `StartTurn`, `EndTurn`, `MinionEnterPlay`, `MinionLeavePlay`, `UseAbility`
- **Separation of concerns:** Triggers decide **when**; Abilities decide **what**
- **Activated abilities** are modeled as triggers fired by a `UseAbility` action
- **Ability context:** (Game state, owning Card, optional target)

---

## Resolution Order (APNAP)
- **A**ctive **P**layer resolves triggers **first**, then **N**on-**A**ctive player
- Within each side, observers resolve **oldest → newest** to keep order stable
- Applies at start/end of turn, enter/leave play, and use ability events

---

## Playing & Targeting
- `play i` — play `i`-th card from hand (no target)
- `play i p t` — play with target: player `p`’s slot `t` (1–5) or `r` (ritual)
- Visitor-style dispatch: `card->play(game, player, action)` lets each card type handle its own placement/targets

---

## Enchantments (Decorator)
- Enchantment **is** a Minion that **wraps** another Minion (possibly another Enchantment)
- Overridden methods typically forward, modifying stats/abilities as needed
- **Silence**-style effects override `getTrigger()` to null the wrapped trigger
- `inspect` shows the chain **oldest → newest**

---

## In-Game Command Reference

help # list commands
end # end your turn
quit # quit game
hand # show your hand
board # show the board
inspect i # show your minion i (with enchantments)
play i # play card i (no target)
play i p t # play with target (player p’s slot t=1..5, or r for ritual)
attack i # minion i attacks opponent
attack i j # minion i attacks enemy minion j
use i [p t] # use activated ability (optional target)

---


---

## CLI / Testing Flags

-deck1 <file> -deck2 <file> # set decks (default: default.deck)
-init <file> # pre-feed names/commands before interactive play
-testing # deterministic mode: ignore costs, enable draw/discard, no shuffle

# Quick Start

```bash
make
./sorcery
```

# Architecture

<img width="912" height="1180" alt="image" src="https://github.com/user-attachments/assets/f85fdca3-185d-4dbe-96c8-a2c00f245a80" />

## Overview
Our game follows the MVC architecture. Here’s how it’s laid out:
### Main
The main function initializes the controller, which handles the view and the model. It also processes command line arguments like -init, -testing, and -deck and then passes those into the controller, which passes them into the view and the model. 
### Controller
In the controller we read from either the terminal or a file, which is specified by main. After reading in a command like playing a card, using enchantments, etc the controller makes an Action, which contains all the information in the command like the target player / minion, as well as logic about what the action will do. Examples of actions include attacking players/minions, start/end turn, playing cards, etc. The controller doesn’t know anything about the game when creating actions which reduces coupling. Actions get passed from the controller into the game, which will input the current game state into it and execute the action. 

### View
The view utilizes much of the provided ascii_graphics code. It is called on by the controller to display certain game states, including the player’s hand, board, and inspect certain minions. To do this, it queries the game to fetch the container types of Board, Hand, and Enemy. It is up to the view to interpret these datatypes and show them in a meaningful way to the user. To make this easy, all cards have a getCost(), getName(), getDescription(), and getType() which the view can however it wants. We have also implemented getTopLeft(), getBottomLeft(), getBottomRight() functions that can display useful information for each card (that will go in one of the corners of the cards description). The view has three functions which are overloaded by its children (displayHand(), displayBoard(), and displayMinion(int)), which will allow for easy changing of the display. For example, we currently used ascii art to display all the cards, but we could simply write a new view subclass that displays everything to the screen as an image if we desired.
### Model
Our game class handles actions from the controller. The game class owns players, which each own a separate board, graveyard, hand, and deck. We have 4 abstract subclasses from our abstract card class: minions, spells, enchantments (subclass of minion), and rituals. All cards in Sorcery are concrete implementations of one of these subclasses. Each card owns a trigger (which may do nothing).

We’ve defined 5 types of triggers. The ones in the spec: StartTurnTrigger, EndTurnTrigger, MinionEnterPlay, MinionLeavePlay, as well as UseAbility, which is triggered whenever the player uses an ability. Triggers only handle the logic for when they activate. What happens when they do activate is decided by the ability they own. 

Abilities have access to the game state, the card they are attached to, and optionally the card that they target. Triggers will execute abilities when they trigger, which will make changes to the game state. 

Cards are created by combining triggers and abilities. These can be composed together in any combination leading to many different numbers of possible cards even with the few triggers and abilities we have. 



## Design (challenges)
How does the controller communicate with the model?
We used the command pattern. The controller creates actions which get passed to the game to be executed. The controller knows nothing about the game state. The game keeps a history of actions executed in a vector. This could be extended in the future to undo player commands.


### How do triggers know when to activate?
We used a combination of the observer pattern, the template method pattern, double dispatch in order to activate triggers. When cards get played onto the board they register to receive notifications from it. When the game sees an action that could possibly activate a trigger, it notifies the players it owns. These players notify their boards, which pass down the action object into the minions and rituals, which alert their triggers. Here we use double dispatch. Each subclass of trigger takes in a specific action. Since we wish to execute a specific subclass of trigger, we use our action object in order to call the specific subclass’ execute function. 

We use the template method pattern in Action::act(), which is called by Game as a double dispatch when it passes in this (see action.cc). Act() calls a pure virtual execute function, and then notifies all the triggers of game.
How are activated abilities and triggered abilities implemented?
We’ve made no distinction between activated and triggered abilities. Activated abilities are simply triggered abilities that get triggered when the controller creates a UseAbility action. When a trigger gets triggered, it activates the ability it owns and passes in the game state, the card it’s attached to, and optionally the target card. 

### How do enchantments work?
Enchantments use the decorator pattern to equip onto minions. Each enchantment is a subclass of Minion, which allows it to fit nicely onto the board the same way an unenchanted minion would. As well, each enchantment will store the minion it is attached to (which may also be another enchantment) By doing this, we can implement enchantment functionality by overloading certain minion methods. Most of the overloads will be calling the same function on the minion it is attached to, however, for enchantments such as Silence, we overload the getTrigger function and return a nullptr instead of where the minion's ability would usually be.

### How did we enforce APNAP order?
We used the observer pattern and had triggers observing notifications from each player’s board. Since the game passes down actions into each player’s board, we can first notify the active player and then the inactive player. The observers are stored in a vector which stores then in oldest to newest order, and we iterate through them from beginning to last, properly following APNAP order.

### How are cards played onto the board?
Cards do different things when played. Minions must get placed in minion slots, spells don’t get played onto the board at all, some cards have targets, etc. We use the visitor pattern here to solve this problem. To play a card, the controller passes a playcard action to the game. In this action, we first extract the card’s unique pointer. We then apply double dispatch by calling card->play(game, player, this), passing in a reference to the action. This allows each type of card to do different things.	







# Ways We're Resilience to Change
Improved graphics / other types of inputs
The MVC pattern we used reduces the coupling between the view and the game, meaning it would be very easy to swap out the current ascii based display for a more advanced graphical one. 

### Cards with multiple abilities
Right now our spells already support multiple abilities since they store a vector of abilities.

We implemented cards as having one trigger, with each trigger owning one ability. However, nothing in our implementation restricts it to just this. If we swap out these for vectors of unique pointers instead, then we would very easily be able to support multiple abilities, multiple triggers, and combinations of the two. This is because of the observer pattern we use. As long as when we create each card we register all of its triggers with the board, it doesn’t matter how many we have, the board will notify all of them when the corresponding action gets processed by the game.


### Extra players
Our players are stored in a vector. Right now all of our operations involving players either use game.getActivePlayer(), or use the player index passed in from the user. For example when the player uses a targeted command like play 1 1 1, we pass the index of the player and minion into our action which gets processed by the game. We then get the corresponding player from the vector. Only in the attackPlayer action, since the user doesn’t specify which player to attack, do we call game.getInactivePlayer(). Everything in our game would work with multiple players except for attacking another player. So we would modify the command to take in a target and pass this in with the action.

### Changing abilities of cards (random generation??)
We implemented abilities separately from cards in order to allow composition of abilities, triggers, and cards. When we create a card, we specify which trigger it uses by instantiating the corresponding concrete trigger class, and also construct the trigger with an ability class. This means that any new card can use a previously implemented ability, and if we support multiple abilities / triggers we could reuse old abilities and extend them to save work on creating new abilities. Since all 4 card subclasses share the same abilities there are endless possibilities.

### Dynamically generating cards
We’ve implemented our abilities with any stats necessary (like atk / def buffs, number of allies spawned, etc) as private variables that get initialized in the ctor. In the future, we could possibly dynamically generate cards with random values that get decided when the card is created. If we support multiple abilities like mentioned above, it could be possible to completely randomly generate a card with random abilities, triggers, stats, with randomized stats for each ability as well. To do this we could, for each card being made, instead of instantiating just one card that has been drawn from the deck, create all of our cards and put them in a vector. Then we instantiate all our triggers and all our abilities into their respective vectors, and then randomly pull them to create a completely random card.

### Undo / Redo
Since we use the command pattern in our game it would be very easy to implement undo / redo actions. For each game action right now we would have to give it a reverse() function, which undos whatever effect it had on the game. We already store a history of all actions in our game, so we could step back through its linked list and call reverse() on each action in order to implement rewinding. 


## Questions We Asked Ourselves

### Question: How could you design activated abilities in your code to maximize code reuse?
Most of the core of our game runs on the command pattern using the action class which will be invoked by the Game class. All abilities use these action classes, which will minimize the amount of code we have to write for each card. As well, we will not distinguish between activated and triggered abilities within the Card or Ability classes. Instead, we have all cards act as triggered abilities, and have a Trigger class that will be able to detect when an ability should do its action. Activated abilities work with this by having their trigger be its own card use while the player has the sufficient amount of magic. By doing this, we can limit the amount of classes we have and allow for more flexibility in our abilities.
### Question: What design pattern would be ideal for implementing enchantments? Why?
We should use a decorator design pattern because we can combine each enchantment with any other enchantment. This pattern doesn’t work well with normal inheritance, since then it requires a new subclass for each combination of enchantments. Also, the oldest to newest ordering of enchantments works well with the decorator’s linked list since we can start our decorator linked list at the oldest enchantment and traverse through the linked list to calculate the effects of our enchantments.
### Question: Suppose we found a solution to the space limitations of the current user interface and wanted to allow minions to have any number and combination of activated and triggered abilities. What design patterns might help us achieve this while maximizing code reuse?
Having multiple abilities is a feature that would already work with our current architecture. This is because we have utilized the command design pattern to trigger any ability we have. We designed all abilities as triggered abilities, with activated abilities being triggered by their own use. Currently, when an action occurs (which can be any change in the state of the board, or any operation called by a user), Game will go through all cards on the board and notify them about the current action. For Minions, they will also pass the action to their Ability, and each Ability will have a Trigger that will detect if the Ability should do anything. To increase the number of abilities a Minion can have, we simply need to change the single Ability each one has into a vector of abilities and override the action() method (which calls all the triggers of a card’s abilities) to work with a vector of abilities. 

One difference between DD2 and DD3 is that we have implemented the observer pattern for this. Our triggers now observe notifications from each player’s board, and get registered when the card that they are attached to gets played on the board.



## Advanced Features we made
We implemented the project without explicitly managing our own memory. All memory was handled via vectors and unique pointers. Raw pointers are passed between classes to reference cards, actions, etc. One challenging aspect of using unique pointers is that it’s really weird handling deletion of objects. For example, when moving a card from the hand to the board, hand.extractCard() returns a unique_ptr<card>, and you couldn’t  tell what subclass of card it was. One solution I thought of was having board.addCard take in a unique_ptr<Card> and then using dynamic cast to see what subclass it is, but this seems awkward. Another solution I thought of was using the visitor pattern, with minion having haveToBoard(board) { board.addCard(*this)}, but *this is a pointer to the minion, not the unique_ptr. I couldn’t access the unique_ptr of the minion from inside of the class, so I wasn't sure how to get a minion to transfer ownership of itself. My solution (thanks to ross evans) was to release the unique pointer in the hand before handing it off to the board, which would make the raw pointer into another unique pointer.
Final Questions

## Lessons Learnt
1. What lessons did this project teach you about developing software in teams? If you worked alone, what lessons did you learn about writing large programs?

Charles: 
Dividing up tasks is something that I didn’t think was so difficult and so important. We had a lot of issues with merge conflicts because the tasks we assigned to each other were not separate enough and touched the same files.

Jack
It is very important to make sure that everyone has a clear vision of how the end product will work before programming actually begins. When we first started working together, I found that I had not explained myself as well as I had hoped, and took some implementations for granted, which caused us to have to rewrite much of our original code.

3. What would you have done differently if you had the chance to start over?

Charles:
I would have tried to implement a scaffold of the code while we were making the UML diagram. It’s easy to gloss over details in implementation when making the diagram, and we made some design choices that were impractical or impossible to do in C++. Some of these could only be fixed using dynamic casting, which we plan to refactor in the future.

Jack:
Plan better, start earlier, ask more questions.

