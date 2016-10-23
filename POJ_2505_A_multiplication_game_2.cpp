#include <iostream>
using namespace std;

void solve(int n){
	int i = 1;
	while(1){
		i *= 9;
		if(i >= n){
			cout << "Stan wins." << endl;
			return;
		}
		i *= 2;
		if(i >= n){
			cout << "Ollie wins." << endl;
			return;
		}
	}
}

int main(){
	int n;
	while(cin >> n){
		solve(n);
	}
	return 0;
}