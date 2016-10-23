#include <iostream>
#include <string>
using namespace std;
string tree(string pre, string in, string post){
	if(in.length() == 0){
		return post;
	}else{
		int cut = in.find(pre[0]);
		string in1 = in.substr(0,cut), in2 = in.substr(cut+1);
		string pre1 = pre.substr(1,in1.size()), pre2 = pre.substr(1 + pre1.size());
		post = tree(pre1, in1, post) + tree(pre2, in2, post);
		post += pre[0];
		return post;
	}
}
int main(){
	string pre, in, post;
	while(cin >> pre >> in){
		post = "";
		cout << tree(pre, in, post) << endl;
	}
	return 0;
}