# TicTacToe

Basic TicTacToe Game written in C++, using a randomised CPU player.

## Steps to write a TicTacToe game in Interviews:
 - Make a Game Board
 - Write a Function to place a piece
 - Make it a reusable function by adding pos and user name
 - Add a gameOver=false and winner flag
 - add a while loop
 - add winning conditions of rows, columns, diagonals
 - add all winning conditions to a single list
 - Loop through that list and check for winners using containAll()
 - keep a list of empty blocks as availPos
 - write a function for cpu to use only availPos so as no overwriting happens
 - Put all the functions together

 Check the [main.cpp](./main.cpp) for the Code

## Compile
```sh
g++ main.cpp -o TicTacToe
```

## Run
```sh
./TicTacToe
```
