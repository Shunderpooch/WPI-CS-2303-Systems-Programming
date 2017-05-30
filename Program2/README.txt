README FILE
Arthur Dooner, ajdooner@wpi.edu
CS 2303, Section C02
Program 2, Smashball
In this program, the game smashball is played on a field of arbitrary size. With smashball, players (anywhere from 1-9) are randomly placed on the field, with
random directions and positions. Each team then proceeds to gain a player for each cycle of addition, I.E. The first player of team one is added, then the first
player from team 2, and so on and so forth.

After players are placed on the field, they begin to play every round in the same movement mechanic used for placement: Team 1, Player 1 moves, then Team 2, Player 1,
and Team 1, Player 2, and so on and so forth for each round. For each player motion, they move in their provided direction, until they hit the wall, whereupon their
direction is inverted. Each round, a player could move onto an empty space, an enemy player (whereupon the enemy player is SMASHED and removed from the field),
or jump over an allied player. The game ends when the maximum amount of turns is reached, or when one team is completely eliminated.

To compile the program, I have simplified it enough for you to merely have to run
	make
and the program will be compiled, and the object files cleaned. All you have to do is run main in such a way:
	./Program2
And the program will function as intended for the preset 100 rounds.
