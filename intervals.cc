#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

struct classcomp {
  bool operator() (const pair<int, int>& x, const pair<int, int>& y) const
  {
    if (x.first != y.first){
      return (x.first < y.first);
    } else{
      return (x.second < y.second);
    }

  }
};

int main(){
  int N;
  cin >> N;
  cout << "N = " << N << endl;
  set<pair<int,int>, classcomp> intervals;

  for (int i = 0; i < N; i++){
    int x, y;
    cin >> x >> y;
    //cout << x << " " << y << endl;
    intervals.insert(make_pair(x, y));
  }
  //cout << "velkost setu " << intervals.size() << endl;
  int end = 0;
  for (pair<int, int> it : intervals){
    //cout << "it" << it.first << " "<<it.second << endl;
    if (end < it.first){
      if (end != 0) {
        cout << end << endl;
      }
      cout  << it.first << " ";
      end = it.second;
    }
    if (end < it.second) {
      end = it.second;
    }
  }
  cout << end << endl;
  return 0;
}
