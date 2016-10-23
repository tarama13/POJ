#include <iostream>
using namespace std;

void solve(int n){
	bool ans = 0;
	int i = 1;
	while(i < n){
		if(!ans){
			i *= 9;
			ans = 1;
		}else{
			i *= 2;
			ans = 0;
		}
	}
	if(ans){
		cout << "Stan wins." << endl;
	}else{
		cout << "Ollie wins." << endl;
	}
}

int main(){
	int n;
	while(cin >> n){
		solve(n);
	}
	return 0;
}