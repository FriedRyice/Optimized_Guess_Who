//THIS ENDED UP BEING REDUNDANT. PLEASE IGNORE UNLESS YOU WANTED TO SEE THE INITIAL THOUGHT PROCESS.


#include <iostream>
using namespace std;

void gamestart();

void gamestart()
{
  int game = 0;
  cout << "Time to begin the game!/nPlease choose a character for the opponent to guess!"
//Provide list of characters here
//cin >> (character name);
//cout << "You have chosen" << (character name) << "!/nThe opponent will now choose a character for you to guess!/nThe opponent has chosen!/nThe player goes first!";

  while (game == 0)
    cout << "Make a guess using the following template: ATTRIBUTE, TYPE (i.e. Hair, blonde)";
    cin >> guess;
//check validity of guess
//return true or false
//remove approriate characters from player roster
    cout << "Now it's the opponents turn!";
//run sorting algorithm to determine best question
    cout << "Does your character have" << ATTRIBUTE, TYPE << "?";
    cin >> guess_answer_player;
//remove appropriate charaters from program roster
    if (program_roster_length == 1)
      game = 1;
    else if (player_roster_length == 1)
      game = 2;

  cout << "The game is over!"
  if (game = 1)
      cout << "The program has won! Your character was" << player_character << "!";
  else if (game = 2)
      cout << "The player has won! The programs character was" << program_character << "!";

//ask to play again or quit
}
