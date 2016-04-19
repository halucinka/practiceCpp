#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main(){
  ifstream f("knapsack.txt", ifstream::in);
  int N, C;
  f >> N >> C;
  cout << "N = " << N << "   C = " << C <<endl;
  vector<int> values;
  vector<int> sizes;
  for (int i = 0; i < N; i++){
    int v, s;
    f >> v >> s;
    values.push_back(v);
    sizes.push_back(s);
  }

  vector<vector<int> > a(N+1, vector<int>(C + 1, 0));
  vector<vector<bool> > b(N+1, vector<bool>(C + 1, false));

  for (int i = 1; i < N+1; i++){
    for (int j = 0; j < C+1; j++){
      if (j < sizes[i-1]){
        a[i][j] = a[i-1][j];
        b[i][j] = false;
      }
      else{
        a[i][j]= max(a[i-1][j], a[i-1][j-sizes[i-1]] + values[i-1]);
        if (a[i][j] == a[i-1][j]){
          b[i][j] = false;
        }
        else{
          b[i][j] = true;
        }
      }
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

  cout << a[N][C] << endl;

  int i = N;
  int j = C;

  while (i > 0){
    //cout << "i " << i << " j " << j << endl;
    if (b[i][j]){
      //  cout << "i " << i << " j " << j << endl;
        cout << "[" << values[i-1] << ", " <<  sizes[i-1] << "]" << endl;
        j -= sizes[i-1];
        i--;
    }
    else{
      i--;
    }
  }


  cout << "Hello world" << endl;

}
