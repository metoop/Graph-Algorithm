class Solution {
  public:
    int numIslands(vector < vector < char >> & grid) {
      int islands = 0;
      for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
          if (isIsland(grid, i, j)) {
            islands++;
          }
        }
      }
      return islands;
    }

  bool isIsland(vector < vector < char >> & grid, int x, int y) {
    bool retVal = false;
    if (grid[x][y] == '1') {
      retVal = true;
      helper(grid, x, y);
      //printf("in helper at x:%d y:%d",x,y);
    }
    return retVal;
  }

  void helper(vector < vector < char >> & grid, int x, int y) {
    if (grid[x][y] == '1') {
      grid[x][y] = '0';
      if (y + 1 < grid[0].size()) {
        helper(grid, x, y + 1);
      }
      if (y - 1 >= 0) {
        helper(grid, x, y - 1);
      }
      if (x - 1 >= 0) {
        helper(grid, x - 1, y);
      }
      if (x + 1 < grid.size()) {
        helper(grid, x + 1, y);
      }
    }
  }
};
