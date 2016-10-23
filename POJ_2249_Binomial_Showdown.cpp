#include <iostream>
using namespace std;
int gcd(int a, int b){
	while(1){
		if(a <= b) swap(a,b);
		if(b == 0) break;
		a %= b;
	}
	return a;
}
int main(){
	int n,r;
	while(cin >> n >> r, n){
		int m = min(n-r,r);
		long long int nu = 1, de = 1;
		for(int i = 0; i < m; i++){
			int a = gcd(n-i,m-i);
			int b = gcd(nu,(m-i)/a);
			int c = gcd(de,(n-i)/a);
			nu = nu*(n-i)/(a*b*c);
			de = de*(m-i)/(a*b*c);
		}
		cout << nu << endl;
	}
	return 0;
}