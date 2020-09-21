#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool gameOver = false;
string WinnerName = "";
vector<vector<string>> gameBoard;

vector<int> playerPos;
vector<int> cpuPos;
vector<int> availPos;


void printGameBoard();
void placePeice(int, string);
void init();
int indexOf(vector<int>&, int);
void wrongTurn();
void playerTurn();
void cpuTurn();
void checkWinner(vector<int>&, string);


int main() {
  init();
  cout<<"Welcome to TicTacToe in C++"<<endl;
  printGameBoard();

  while(!gameOver)
  {
    playerTurn();
    checkWinner(playerPos, "Player");
    cpuTurn();
    checkWinner(cpuPos, "CPU");
    printGameBoard();
  }
  cout<<"Game Over!"<<endl;
  cout<<"Winner: "<<WinnerName<<endl;
}
void init()
{
  for(auto i = 1; i<10; i++)
  {
    availPos.push_back(i);
  }
  vector<string> row = {" ", "|", " ", "|", " "};
  vector<string> sep = {"-", "+", "-", "+", "-"};
  gameBoard.push_back(row);
  gameBoard.push_back(sep);
  gameBoard.push_back(row);
  gameBoard.push_back(sep);
  gameBoard.push_back(row);
}
int indexOf(vector<int>& pos, int el)
{
  auto it = find(pos.begin(), pos.end(), el);
  if(it!=pos.end())
  {
    int index = distance(pos.begin(), it); 
    return index;
  }
  return -1;
}
void printGameBoard()
{
  for(auto i=0; i<5; i++)
  {
    for(auto j=0; j<5; j++)
    {
      cout<<gameBoard[i][j];
    }
    cout<<endl;
  }
}

void _place(int i, int j, char symbol)
{
  if(gameBoard[i][j] != "X" && gameBoard[i][j] != "O")
  {
    gameBoard[i][j] = symbol;
    return;
  }
  wrongTurn();
}

void placePeice(int pos, string user)
{
  char symbol = ' ';
  if(user == "Player" && pos>=1 && pos<=9)
  {
    cout<<"Player: "<<pos<<endl;
    playerPos.push_back(pos);
    symbol = 'X';
  } else if(user == "CPU" && pos>=1 && pos<=9)
  {
    cout<<"CPU: "<<pos<<endl;
    cpuPos.push_back(pos);
    symbol = 'O';
  }
  int index = indexOf(availPos, pos);
  if(index != -1)
  {
    availPos.erase(availPos.begin() + index);
  }

  switch(pos)
  {
    case 1:
      _place(0, 0, symbol);
    break;
    case 2:
      _place(0, 2, symbol);
    break;
    case 3:
      _place(0, 4, symbol);
    break;
    case 4:
      _place(2, 0, symbol);
    break;
    case 5:
      _place(2, 2, symbol);
    break;
    case 6:
      _place(2, 4, symbol);
    break;
    case 7:
      _place(4, 0, symbol);
    break;
    case 8:
      _place(4, 2, symbol);
    break;
    case 9:
      _place(4, 4, symbol);
    break;
    default:
    break;
  }
}

void wrongTurn()
{
  cout<<"Invalid Position, Please Try Again"<<endl;
  playerTurn();
}

void playerTurn()
{
  cout<<"Please Enter a Position [1-9]: ";
  int pos;
  cin>>pos;
  placePeice(pos, "Player");
}

void cpuTurn()
{
  int r = 1 + (rand() % availPos.size()); 
  int pos = availPos[r];
  placePeice(pos, "CPU");
}

void checkWinner(vector<int>& v, string user)
{
  if(gameOver)
    return;
  vector<int> topRow = {1,2,3};
  vector<int> midRow = {4,5,6};
  vector<int> botRow = {7,8,9};

  vector<int> leftCol = {1,4,7};
  vector<int> midCol =  {2,5,8};
  vector<int> rightCol= {3,6,9};

  vector<int> cross1 = {1,5,9};
  vector<int> cross2 = {3,5,7};

  vector<vector<int>> winning;
  winning.push_back(topRow);
  winning.push_back(midRow);
  winning.push_back(botRow);
  winning.push_back(leftCol);
  winning.push_back(midCol);
  winning.push_back(rightCol);
  winning.push_back(cross1);
  winning.push_back(cross2);

  for(auto i = 0; i < winning.size(); i++)
  {
    int c = 0;
    vector<int> con = winning[i];
    for(auto j = 0; j < con.size(); j++)
    {
      if(std::count(v.begin(), v.end(), con[j]))
      {
        c = 1;
      } else {
        c = 0;
        break;
      }
    }
    if(c==1)
    {
      gameOver = true;
      WinnerName = user;
      return;
    }
  }
  if(playerPos.size() + cpuPos.size() == 9)
  {
    gameOver = true;
    WinnerName = "Draw";
    return;
  }
}
