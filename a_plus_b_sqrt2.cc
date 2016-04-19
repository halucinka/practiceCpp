#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

class mycomparison
{
public:
  mycomparison() {}

  bool operator()(const pair<int, int>& x, const pair<int, int>& y){
      return (x.first + x.second * sqrt(2) > y.first + y.second * sqrt(2));
  }
};

int main(){
  int N;
  cin >> N;
  cout << "N = " << N << endl;

  priority_queue<pair<int, int>, vector<pair<int,int> >, mycomparison> halda;
  set<pair<int, int> > strom;

  halda.push(make_pair(0,0));
  strom.insert(make_pair(0,0));
  for (int i = 0; i < N; i++){
    pair<int, int> par = halda.top();
    int a = par.first;
    int b = par.second;
    halda.pop();
    strom.erase(par);
    cout << a << " " << b << " " << a + b*sqrt(2)<< endl;
    if (strom.find(make_pair(a + 1, b)) == strom.end()) {
      halda.push(make_pair(a + 1, b));
      strom.insert(make_pair(a + 1, b));
    }
    if (strom.find(make_pair(a, b + 1)) == strom.end()) {
      halda.push(make_pair(a, b + 1));
      strom.insert(make_pair(a, b + 1));
    }
  }
  return 0;
}
