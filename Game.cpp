#include "Game.h"

Game::Game() {
  generateMaze();
  for(int i = 0; i < mazeSize; i++) {
    for(int j = 0; j < mazeSize; j++) {
      string path;
      if(maze[i][j]) {path = "res/black.png";}
      else {path = "res/white.png";}
      squares[i][j] = new Sprite(path, i*blockSize, j*blockSize, blockSize, blockSize);
    }
  }
}

void Game::run() {
  for(int spriteCnt = 0; spriteCnt < mazeSize; spriteCnt++) {
    for(Sprite *s : squares[spriteCnt]) s->Draw();
  }
}

void Game::generateMaze() {
  cp.x = 0;
  cp.y = 0;
  usedPointas.push_back(cp);
  while(mazeRunning) {
    moveCP();
    maze[cp.x][cp.y] = true;
    if(cp.x == mazeSize - 1 && cp.y == mazeSize - 1) {
      if(!backTrack()) mazeRunning = false;
    }
  }
}

//needs a LOT of cleaning up
void Game::moveCP() {
  int dir = rand() % 5 + 1;
  Pointa tp;
  if(!backTrack()) mazeRunning = false;
  switch (dir) {
    case 1:
      tp.x = cp.x;
      tp.y = cp.y-move;
      if(!contains(usedPointas, tp) && cp.y-move >= 0 && cp.y-move<mazeSize+1) {
        for(int i = 1; i <= move; i++) maze[cp.x][cp.y-i] = true;
        cp.y-=move;
        printArray();
      } else if(!backTrack()) mazeRunning = false;
      break;
    case 2:
      tp.x = cp.x+move;
      tp.y = cp.y;
      if(!contains(usedPointas, tp) && cp.x+move >= 0 && cp.x+move<mazeSize+1) {
        for(int i = 1; i <= move; i++) maze[cp.x+i][cp.y] = true;
        cp.x+=move;
        printArray();
      } else if(!backTrack()) mazeRunning = false;
      break;
    case 3:
      tp.x = cp.x;
      tp.y = cp.y+move;
      if(!contains(usedPointas, tp) && cp.y+move >= 0 && cp.y+move<mazeSize+1) {
        for(int i = 1; i <= move; i++) maze[cp.x][cp.y+i] = true;
        cp.y+=move;
        printArray();
      } else if(!backTrack()) mazeRunning = false;
      break;
    case 4:
      tp.x = cp.x-move;
      tp.y = cp.y;
      if(!contains(usedPointas, tp) && cp.x-move >= 0 && cp.x-move<mazeSize+1) {
        for(int i = 1; i <= move; i++) maze[cp.x-i][cp.y] = true;
        cp.x-=move;
        printArray();
      } else if(!backTrack()) mazeRunning = false;
      break;
    case 5:
      randomCP();
      break;
  }
  usedPointas.push_back(cp);
}

bool Game::contains(vector<Pointa> p, Pointa item) {
  for(int i = 0; i < p.size(); i++) {
    if(item.x==p.at(i).x && item.y==p.at(i).y) return true;
  }
  return false;
}

void Game::printArray() {
  system("CLS");
  cout << "__";
  for(int p = 0; p < mazeSize; p++) {
    cout << p%10 << " ";
  }
  cout << "\n";
  for(int i = 0; i < mazeSize; i++) {
    cout << i%10 << " ";
    for(int j = 0; j < mazeSize; j++) {
      if(maze[j][i]) cout << "W ";
      else cout << "_ ";
    }
    cout << "\n";
  }
  cout << "\n " << cp.x << ", " << cp.y << "\n";
}

bool Game::backTrack() {
  Pointa tcp1, tcp2, tcp3, tcp4;
  for(int i = usedPointas.size() - 1; i >= 0; i--) {
    Pointa usdp = usedPointas.at(i);
    tcp1.x = usdp.x-move; tcp1.y = usdp.y;
    tcp2.x = usdp.x+move; tcp2.y = usdp.y;
    tcp3.x = usdp.x; tcp3.y = usdp.y-move;
    tcp4.x = usdp.x; tcp4.y = usdp.y+move;
    if((!contains(usedPointas, tcp1) && tcp1.x >= 0 && tcp1.y >= 0 && tcp1.x <= mazeSize - 1 && tcp1.y <= mazeSize - 1 )||(!contains(usedPointas, tcp2) && tcp2.x >= 0 && tcp2.y >= 0 && tcp2.x <= mazeSize - 1 && tcp2.y <= mazeSize - 1 )||(!contains(usedPointas, tcp3) && tcp3.x >= 0 && tcp3.y >= 0 && tcp3.x <= mazeSize - 1 && tcp3.y <= mazeSize - 1 )||(!contains(usedPointas, tcp4) && tcp4.x >= 0 && tcp4.y >= 0 && tcp4.x <= mazeSize - 1 && tcp4.y <= mazeSize - 1)) {
      cp = usedPointas.at(i);
      return true;
    }
  }
  return false;
}

void Game::randomCP() {
    int randomIndex = rand() % usedPointas.size();
    cp = usedPointas.at(randomIndex);
}

int Game::getCPIndex() {
  for(int i = 0; i < usedPointas.size(); i++) {
    if(usedPointas.at(i).x == cp.x && usedPointas.at(i).y == cp.y) return i;
  }
  return 0;
}
