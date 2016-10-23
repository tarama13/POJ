#include <iostream>
#define N 30
using namespace std;
int main(){
  int ans[N+1] = {1,0,3};
  for(int i = 3; i <= N; ++i){
    if(i % 2 == 1){
      ans[i] = 0;
    }else{
      ans[i] = 4 * ans[i - 2] - ans[i - 4];
    }
  }
  int n;
  while(cin >> n){
    if(n < 0) break;
    cout << ans[n] << endl;
  }
  return 0;
}
