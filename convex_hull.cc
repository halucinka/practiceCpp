#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
  if (a.first < b.first){
    return true;
  }
  else if (a.first == b.first){
      return (a.second < b.second);
  }
  return false;
}

pair<int, int> top_second (stack <pair<int, int> > &s){
  pair <int, int> top = s.top();
  s.pop();
  pair <int, int> top_s = s.top();
  s.push(top);
  return top_s;
}

bool f(pair<int, int> a , pair<int, int> b, pair<int, int> c){
  return (b.first - a.first)*(c.second - b.second) - (c.first - b.first)*(b.second - a.second) > 0;
}

int main(){
  int N;
  cin >> N;
  vector<pair<int, int> > points;

  for (int i = 0; i < N; i++){
    int x, y;
    cin >> x >> y;
    points.push_back(make_pair(x, y));
  }
  sort(points.begin(), points.end(), compare);


  stack<pair<int, int> > s;

  for (int i = 0; i < N; i++){
    while ((s.size() > 1) && (f(points[i], s.top(), top_second(s)))) {
      s.pop();
    }
    s.push(points[i]);
  }

  for (int i = N-2; i >= 0; i--){
    while ((s.size() > 1) && (f(points[i], s.top(), top_second(s)))) {
      s.pop();
    }
    s.push(points[i]);
  }
  s.pop();
  while (!s.empty()){
    cout << s.top().first << " " << s.top().second << endl;
    s.pop();
  }

  return 0;

}
