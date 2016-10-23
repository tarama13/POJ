#include <iostream>
#include <algorithm>
#define MAX_N 100000
using namespace std;
struct cow{
	int t,d;
};
bool operator<(const cow& left, const cow& right){
	return left.t * right.d < left.d * right.t;
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cow mow[MAX_N];
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> mow[i].t >> mow[i].d;
	}
	sort(mow,mow+n);
	unsigned long long int ans = 0, sum = 0;
	for(int i = 0; i < n; i++){
		ans += mow[i].d * sum;
		sum += mow[i].t * 2;
	}
	cout << ans << endl;
	return 0;
}