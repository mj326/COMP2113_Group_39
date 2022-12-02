# blackjack project

1. Shuffle the cards.
2. Player bets. -> Show Starting_Balance and subtract betting amount.
3. Player and dealer each draws two cards.
4. Show each cards except dealer's hidden card.
5(a). If dealer's card sum > 21 and 
    i) If player's card sum <= 21
        (1) Show dealer's hidden card.
        (2) Get win money($20). -> Round over
    ii) If player's card sum > 21:
        (1) Show dealer's hidden card.
        (2) Get initial betting amount($10) -> Round over

5(b). If player's card sum > 21:
    i) If dealer's card sum <= 21
        (1) Show dealer's hidden card.
        (2) Lose betting amount(-$10) -> Round over
    ii) If dealer's card sum > 21
        (1) Show dealer's hidden card.
        (2) Get initial betting amount($10) -> Round over

    iii) If player's card sum <=21 :
        (1) Player takes turn -> Show dealer's hidden card after player has done everything
            (a) If dealer's card sum == 21 -> Lose betting amount -> Round over
            (b) Calculate card sums and show who wins -> Round over

6. Ask to play again after round ends
7. Play again -> Go to 1.
8. End game -> Print game status, use updatePlayer() to update currentPlayer on Players.txt and return

Player's turn :(플레이어가 블랙잭인 경우는 이미 다뤄졌음) ** Print choices -> Select a move 
(1) STAY -> Player's turn ends.
(2) HIT -> input additional betting amount -> draw a card -> show the card
    (a) card sum > 21 -> Lose betting amount and end round.
    (b) card sum <= 21 -> go back to 1 -> SURRENDER 비활성화
(3) SURRENDER -> 베팅금액의 1/2만 다시 Balance에 충전되고 게임 끝

Dealer's turn :(딜러의 오픈카드가 에이스인 경우, 딜러가 블랙잭인 경우는 이미 다뤄졌음) ** Show hidden card.
(1) Card sum <= 16 -> Draw a card -> Show the card -> Go back to Dealer's turn
(2) Card sum > 21 -> Dealer bursts and player wins, receives initial bet money($20) -> Round over
(3) Card sum <= 21> -> Compare with player's card sum
    (a) Player's card sum is larger -> Player wins, receives win money -> Round over
    (b) Dealer's card sum is larger -> Player loses betting money -> Round over
    (c) Card sums are same -> Draw -> Receive only the betting money -> Round over


Use makefile to run the game: make main ./main