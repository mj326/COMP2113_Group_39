# BlackJack project

1. Shuffle the cards.
2. Player bets.($10, $20, $30) -> Show Starting_Balance and subtract betting amount from balance.
   a) Starting balance is $100
   - Player LOSES if balance < 10. -> End Game
3. Player and dealer each draws two cards.
4. Show each cards except dealer's hidden card. (Total 3 cards shown)
5. BLACKJACK == sum of cards is 21.
    1. Player is BLACKJACK, player automatically WINS -> Round over
    2. Dealer is BLACKJACK, player automatically LOSES -> Round over
    3. If no BLACKJACK, move on.

6. Player's turn. Print two choices and select one:
    1. STAY
        - Player's turn is over and dealer shows hidden card.
            1. If player's card sum < dealer's card sum, player LOSES -> Round over
            2. If player's card sum > dealer's card sum OR dealer's card sum > 21, player WINS -> Round over
    2. HIT
        - Player draws another card. (If the player's card sum < 21, player goes back to step 5.)
            1. If player card sum > 21 OR player card sum < dealer card sum, player LOSES -> Round over
            2. If player card sum > dealer card sum, player WINS -> Round over

7. Player decided which amount to bet from the options($10, $20, $30)
    - if player LOSE: balance -= bet_money
    - if player WINS: balance += bet_money * 2


Use makefile to run the game: make main ./main