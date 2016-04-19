#include <iostream>
#include <cmath>
using namespace std;

struct coordinates {
  int x, y, z;
};

coordinates getCoordinates(int a) {
  coordinates corA = {0, 0, 0};
  if (a == 1){
    return corA;
  }
  //cout << "hello" << endl;
  int layer = ceil((-1 + sqrt(1+(4 * a - 4)/3))/2);
  int last = 1 + (layer-1)*layer * 3;
  int last2 = 1 + (layer+1)*layer * 3;
  int velkostStrany = (last2-last) / 6;
  int o = a - last -1;
  int side = o / velkostStrany;
  //cout << "velkostStrany = " << velkostStrany << endl;
  //cout << "o = " << o << endl;
  //cout << "last = " << last << endl;
  //cout << "layer = " << layer << endl;
  //cout << "side = " << side << endl;
  int onSide = o - side * velkostStrany;
  //cout << "onSide = " << onSide << endl;
  switch (side) {
    case 0:
              corA = (coordinates){-layer, -onSide-1, 0};
              break;
    case 1:
              corA = (coordinates) {onSide+1, 0, layer};
              break;
    case 2:
              corA = (coordinates){0,  -layer, -onSide-1};
              break;
    case 3:
              corA = (coordinates){layer, onSide+1, 0};
              break;
    case 4:
              corA = (coordinates){-onSide-1, 0, -layer};
              break;
    case 5:
              corA = (coordinates){0, layer, onSide+1};
              break;
  }
  //cout << corA.x << " " << corA.y << " " <<corA.z <<endl;
  return corA;
}

coordinates normalize(coordinates diff) {
  //cout << diff.x << " " << diff.y << " " <<diff.z <<endl;
  if (diff.x * diff.y > 0) {
    int d = 0;
    if (diff.x > 0) {
      d = min(diff.x, diff.y);
    }
    else {
      d = max(diff.x, diff.y);
    }
    diff.x -= d;
    diff.y -= d;
    diff.z -= d;
  }
  if (diff.y * diff.z > 0) {
    int d = 0;
    if (diff.y > 0) {
      d = min(diff.y, diff.z);
    }
    else {
      d = max(diff.y, diff.z);
    }
    diff.x -= d;
    diff.y -= d;
    diff.z -= d;
  }
  if (diff.x * diff.z > 0) {
    int d = 0;
    if (diff.x > 0) {
      d = min(diff.x, diff.z);
    }
    else {
      d = max(diff.x, diff.z);
    }
    diff.x -= d;
    diff.y -= d;
    diff.z -= d;
    //cout << "d " << d << endl;
    //cout << "diff " << diff.x << " " << diff.y << " " <<diff.z <<endl;
  }

  return diff;
}

void solve(int a, int b) {
  coordinates corA = getCoordinates(a);
  coordinates corB = getCoordinates(b);
  coordinates diff = {corA.x - corB.x, corA.y - corB.y, corA.z - corB.z};
  coordinates normalized = normalize(diff);
  int sum = abs(normalized.x) + abs(normalized.y) + abs(normalized.z);
  cout << "The distance between cells " << a << " and " << b
       << " is " << sum << "." << endl;
}



int main(){
  for(;;){
    int a, b;
    cin >> a >> b;
    if ((a == 0) && (b == 0)) {
      break;
    }
    solve(a, b);
  }

  return 0;
}
