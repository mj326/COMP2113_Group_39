# BlackJack project

## Team Members
1. Min Jun Kim (3035829450) 
2. Kyoung Min Park (3035666528)
3. Dong Chan Shin (3035550169)
4. Si Woo Kim (3035661243)
5. Yoo Jin Kang (3035745623)

## Code Requirement
1. Generation of random game sets or events
    - The game contains a random generation of drawing cards from the deck.
    - The deck is shuffled for random drawn cards from including the random library.
2. Data structures for storing game status
    - The game saves and updates player info(balance) after each round is over.
    - Classes, 'this' pointers, and vectors are used as data structures for storing game status.
3. Dynamic memory management
    - Iterators and pointers are used for dynamic memory management.
    - The game includes functions to make player take one card the deck each turn. It removes the card from the player’s arraylist(hand) and adds it back to deck which includes the resizing function.
4. File input/output (e.g., for loading/saving game status)
    - The directory contains "players.txt" file in order to save player.
    - fstream library is used to open file and store name, final balance of the player.
5. Program codes in multiple files
    - card.cpp, card.h for card related functions
    - player.cpp, player.h for player related functions
    - game.cpp, game.h for game related functions
    - main.cpp for main function
    - Makefile for making main, and cleaning the directory(deleting *.o, main)
6. Proper indentation and naming styles/In-code documentation
    - Every function and code has proper indentation, names related to its function and purpose.

## Features Implemented
- Classes(public, protected, private) for storing player information
- Namespace(namespace Card_namespace) for displaying calculating cards to integer
- Template(typename T) for simplified and concise code
- Various types of functions(void, int, double) for running the game
- Exceptions(try, catch, throw, default) for dynamic work flow

## To start the game 
- The player has to register his name 
- To register a new player, current player needs to end his game.
- If not registered, player cannot start the game.

We HIGHLY RECOMMEND to increase the terminal size for a better view of cards and for a smooth play.

## Game Description

1. Shuffle the cards.
2. Player bets.($10, $20, $30) -> Show Starting_Balance and subtract betting amount from balance.
      a) Starting balance is $100
         - Player LOSES if balance < 10. -> End Game
3. Player and dealer each draws two cards.
4. Show each cards except dealer's hidden card. (Total 3 cards shown)
5. BLACKJACK == sum of cards is 21.
      1. Player is BLACKJACK, player automatically WINS -> player receives bet_money*3 -> Round over
      2. Dealer is BLACKJACK, player automatically LOSES -> Round over
      3. If no BLACKJACK, move on.
      
6. Player's turn. Print two choices and select one:
      1. STAY
         - Player's turn is over and dealer shows hidden card.
            1. If player's card sum < dealer's card sum, player LOSES -> Round over
            2. If player's card sum > dealer's card sum OR dealer's card sum > 21, player WINS -> player receives
            bet_money*2 -> Round over
      2. HIT
         - Player draws another card. (If the player's card sum < 21, player goes back to step 5.)
            1. If player card sum > 21 OR player card sum < dealer card sum, player LOSES -> Round over
            2. If player card sum > dealer card sum, player WINS -> player receives bet_money*2 -> Round over

7. Dealer's turn.
    1. If card sum of dealer <= 16
        - dealer automatically draws another card. -> print the card
    2. If card sum of dealer > 21
        - dealer bursts and player WINS -> player receives bet_money*2 -> Round over
    3. If card sum of dealer > 16 and less than 22 -> compare card sum
        - if dealer card sum > player card sum -> player LOSE -> Round over
        - if dealer card sum < player card sum -> player WINS -> player receives bet_money*2 -> Round over

      
8. Player decided which amount to bet from the options($10, $20, $30)
   - if player LOSE: balance -= bet_money
   - if player WINS: balance += bet_money * 2
   - if player WINS by BLACKJACK: balance += bet_money * 3


## Game Example

Let's assume that the player chose bet_money as $10. 

1. If dealer's card sum > 21,
    - If player's card sum <= 21 (Player wins)
        1. Show dealer's hidden card.
        2. Get win money($20). -> Round over
    - If player's card sum > 21: (It's a tie)
        1. Show dealer's hidden card.
        2. Get initial betting amount -> Round over

2. If player's card sum > 2,
    - If dealer's card sum <= 21: (Player loses)
        1. Show dealer's hidden card.
        2. Lose betting amount(-$10) -> Round over
    - If dealer's card sum > 21:  (It's a tie)
        1. Show dealer's hidden card.
        2. Get initial betting amount -> Round over

    - If player's card sum <=21 (and dealer's card <21)  :
        1. Player takes turn
            -> Show dealer's hidden card after player has chosen either stand or hit
            - If dealer's card sum == 21 -> Lose betting amount -> Round over
            - Calculate card sums and show who wins -> Round over

7. Ask to play again after each round ends
8. Play again -> Go to step 1.
9. End game -> Print ending message, use updatePlayer() to update currentPlayer on Players.txt and return

## How to start the game (Makefile)
1. Use makefile to run the game: make main -> ./main
2. Use makefile to clean directory: make clean
