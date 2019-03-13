#include "Global.h"
#include "Sprite.h"
#include <vector>

class Game {
public:
  Game();
  void run();
private:
  Pointa cp;
  void generateMaze();
  bool backTrack();
  void moveCP();
  bool contains(vector<Pointa> p, Pointa item);
  void printArray();
  int getCPIndex();
  void randomCP();
  vector<Pointa> usedPointas;
  const static int mazeSize = 31;
  const int move = 2;
  const int blockSize = 900/mazeSize;
  bool mazeRunning = true;
  Sprite *squares[mazeSize][mazeSize];
  bool maze[mazeSize][mazeSize] = {0};
};
