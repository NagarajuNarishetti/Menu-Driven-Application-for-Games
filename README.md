# Menu-Driven-Application-for-Games
The given code is a text-based menu-driven program that allows users to play various games: Number Guessing Game, Rock Paper Scissors, Cricket, and Snake Water Gun. The program utilizes functions to implement each game and includes options to play a game, learn about a game, or quit the program.

The main function presents a menu with three options: play a game, learn about a game, or quit. Upon selecting the play option, the user is prompted to choose a game. Depending on the selection, the corresponding game function is called.

The Number Guessing Game requires the player to guess a randomly generated number within a specified range. The player's score is recorded, and the best score is saved. The option to check the high score is also available.

Rock Paper Scissors is a classic game where the player chooses a throw (Rock, Paper, or Scissors), and the computer randomly selects its throw. The winner is determined based on the game rules, and the result is displayed.

Cricket is a simplified version of the sport where the player and computer take turns selecting numbers. The sum of the chosen numbers determines the toss winner. The toss winner then chooses to bat or bowl. The batting player accumulates a score based on their number choices until they match the computer's choice. The computer also bats, and the scores are compared to determine the winner.

Snake Water Gun is a game where the player and computer select one of three options: Water, Snake, or Gun. The winner is determined based on the rules (e.g., Water beats Fire). The game continues until there is a winner.

The aboutGame function allows users to learn about each game by selecting an option. A short description of each game is displayed.

The code utilizes file handling to save and display high scores for the Number Guessing Game. It also uses structures to store player information.

The program runs in a loop, allowing the user to play multiple games or return to the main menu. It terminates upon selecting the quit option.
