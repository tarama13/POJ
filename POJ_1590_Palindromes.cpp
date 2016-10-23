#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	char sym[13] = {'A','H','I','M','O','T','U','V','W','X','Y','1','8'};
	char mir[8] = {'E','J','S','Z','5','2','L','3'};
	while(cin >> str){
		bool flag[2] = {1,1};
		int l = str.length();
		for(int i = 0; i < (l + l % 2) / 2; i++){
			if(str[i] != str[l-1-i] && flag[0]){//Palindrome
				flag[0] = 0;
			}
			if(flag[1]){	//Mirror
				bool tmp = 0;
				for(int j = 0; j < 8 && !tmp; j++){	//Symmetry Letters
					if(str[i] == mir[j] && str[l-1-i] == mir[8-1-j]){
						tmp = 1;
					}
				}
				for(int j = 0; j < 13 && !tmp; j++){	//Mirror Letters
					if(str[i] == sym[j] && str[l-1-i] == sym[j]){
						tmp = 1;
					}
				}
				if(!tmp) flag[1] = 0;
			}
		}
		if(flag[0]){
			if(flag[1]){
				cout << str << " -- is a mirrored palindrome." << endl << endl;
			}else{
				cout << str << " -- is a regular palindrome." << endl << endl;
			}
		}else{
			if(flag[1]){
				cout << str << " -- is a mirrored string." << endl << endl;
			}else{
				cout << str << " -- is not a palindrome." << endl << endl;
			}
		}
	}
	return 0;
}