struct Coordinate {
  int row, col;
  Coordinate (int r, c): row(r), col(c){}
  bool isValid (int a[], int m, int n);
};

bool Coordinate::isValid (int a[], int m, int n) {
  if (row >= 0 && col >= 0 && row < m && col < n) return true;
  return false;
}

bool findElement (int a[][], int m, int n, Coordinate UpLeft, Coordinate DownRight, int x) {
  if (!UpLeft.isValid(a, m, n) || !DownRight.isValid(a, m, n)) return false;
  
}