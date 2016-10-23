#include <iostream>
#include <algorithm>
using namespace std;

	struct mow{
		int start,end,milk;
	};
//startの昇順でソートする場合
	bool operator<(const mow &left, const mow &right){
		return left.start < right.start;
    }

int main(){
	int n,m,r;
	struct mow caw[1000];
	//pair<int,int> milk[1000];
	//pair<int,int> mow[1000];
	cin >> n >> m >> r;
	n += r;	//+rest
	int max = 0;
	for(int i = 0; i < m; i++){
		cin >> caw[i].start >> caw[i].end >> caw[i].milk;
		caw[i].end += r;
	}	//input
	sort(caw,caw+m);
	int sum[1001];
	for(int i = 0; i < 1000; i++){
		sum[i] = 0;
	}
	sum[0] = 0;
	for(int i = 1; i <= m; i++){
		for(int j = i; j >= 0; j--){
			if(caw[i-1].start >= caw[j-1].end && sum[i] < (sum[j] + caw[i-1].milk)){
				sum[i] = sum[j] + caw[i-1].milk;
				if(max <= sum[i]){max = sum[i];}
			}
		}
	}
	cout << max << endl;
	return 0;
}