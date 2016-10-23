#include <iostream>
#include <bitset>
#define N 250000
#define M 1000001
using namespace std;
int main(){
	bitset <N> si;
	bitset <N> si2;
	int ans[N] = {};
	si[0] = 0;
	for(int i = 0; i < N; i++){
		for(int j = 5; j*j <= i*4+5; j += 4){
			if(!si[(j-5)/4] && (i*4+5) % j == 0){
				si[i] = 1;
				break;
			}
		}
	}

	for(int i = 5; i <= M; i += 4){
		for(int j = 5; j <= i && i*j <= M; j += 4){
			if(!si[(i-5)/4] && !si[(j-5)/4]){
				si2[(i*j-5)/4] = 1;
			}
		}
	}

	ans[0] = 0;
	for(int i = 9; i <= M; i += 4){
		ans[(i-5)/4] = ans[(i-9)/4];
		ans[(i-5)/4] += si2[(i-5)/4];
	}
	ios::sync_with_stdio(false);
	int h;
	while(cin >> h,h){
		cout << h << " " << ans[(h-5)/4] << endl;
	}
	return 0;
}