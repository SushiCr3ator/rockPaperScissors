#include <chrono>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <thread>
/*RPS has only 3 ways to win
* R>S, S>P, P>R
     * Goal: is to at least get it done for 2players and maybe a simple random play to play against for lonely ppl
     * Extra-Development: maybe save the matches into a filestream to keep score
     */

int player,wins,movep1, movep2,_1w,_2w;
std::string result, player1, player2;
bool multi = true;
bool p1,p2,win;

void winner() {
     if (_1w > _2w) {
          std::cout << player1 << " is the winner!!!!" << "\n";
     }else {
          std::cout << player2 << " is the winner!!!!" << "\n";
     }
}
void saveGame(int savedp1,int savedp2, std::string resulting) {
     // file found in 'rockPaperScissors\cmake-build-debug'
     std::string p1Move,p2Move;
     switch (savedp1) {
          case(1):
               p1Move = "Rock";
               break;
          case(2):
               p1Move = "Paper";
               break;
          case(3):
               p1Move = "Scissors";
               break;
     }
     switch (savedp2) {
          case(1):
               p2Move = "Rock";
               break;
          case(2):
               p2Move = "Paper";
               break;
          case(3):
               p2Move = "Scissors";
               break;
     }
     std::ofstream myFile ("savedHistory.txt", std::ios::app);
          if (myFile.is_open()) {
               myFile << player1 << " " << p1Move << "\n";
               myFile << player2 << " " << p2Move << "\n";
               myFile << resulting << "\n";
               myFile << "-------------------------\n";
          }
     myFile.close();
}
void _2p() {
     printf("%s", "Would you like to play with another person or alone? \n");
     printf("%s", "0 for multi player game \n");
     printf("%s", "1 for single player game \n");
     scanf("%d", &player);

     switch (player) {
          case(0):
               printf("Please enter P1 name: \n");
               scanf("%s",&player1);
               printf("Please enter P2 name: \n");
               scanf("%s",&player2);
               std::cout << "Welcome " << player1 << "&& " << player2 <<"! \n";
               printf("%s", "you are now playing a multi player game GL! :) \n");
               std::this_thread::sleep_for(std::chrono::seconds(2));
               break;
          case(1):
               printf("%s", "you are now playing a single player game GL! :) \n");
               std::this_thread::sleep_for(std::chrono::seconds(2));
               multi = false;
               break;
     }
}
void _gameLogic(int move1, int move2) {
     if (move1 < move2 ) {
          if (move2 == 3 && move1 == 1) {
               printf("%s","Player 1 won!!! \n");
               result = "Player 1 won!!! \n";
               wins++;
               _1w++;
          }else {
               printf("%s","Player 2 won!!! \n");
               result = "Player 2 won!!! \n";
               wins++;
               _2w++;
          }
     }else if (move1 > move2) {
          if (move1 == 3 && move2 == 1) {
               printf("%s","Player 2 won!!! \n");
               result = "Player 2 won!!! \n";
               wins++;
               _2w++;
          }else {
               printf("%s","Player 1 won!!! \n");
               result = "Player 1 won!!! \n";
               wins++;
               _1w++;
          }
     }else {
          printf("%s", "We have a tie!!! \n");
          result = "We have a tie!!! \n";
     }
}
void _play() {
     if (multi == true) {
          while (wins < 3) {
               if (_1w == 2 || _2w == 2)
                    break;
               p1 = true;
               if (p1 == true) {
                    std::cout <<"what would you like to play?" << player1 << ": \n";
                    printf("%s", "write '1' for rock \n");
                    printf("%s", "write '2' for paper \n");
                    printf("%s", "write '3' for scissors \n");
                    scanf("%d", &movep1);

                    p2 = true;
                    p1 = false;
               }
               if (p2 == true) {
                    std::cout <<"what would you like to play?" << player2 << ": \n";
                    printf("%s", "write '1' for rock \n");
                    printf("%s", "write '2' for paper \n");
                    printf("%s", "write '3' for scissors \n");
                    scanf("%d", &movep2);
                    p1 = true;
                    p2 = false;
               }
               _gameLogic(movep1,movep2);
               saveGame(movep1,movep2, result);
          }
     }
}
int main() {
     _2p();
     _play();
     winner();
     return 0;
}