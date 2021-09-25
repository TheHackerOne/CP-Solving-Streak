class Solution {
public:
  int countSquares(int N) {
    int i = 1;
    int count = 0;
    int currentSquare = 1;
    while (currentSquare < N) {
      i = i + 1;
      count++;
      currentSquare = i * i;
    }

    return count;

  }
};