#include <iostream>
#define M_MAX = 1000000;
#define N_MAX = 1000;
#define COST_MAX = M_MAX * N_MAX + 1;
using namespace std;
struct road{
	int from,to,cost;
};

struct road way[M_MAX];

int main(){
	int n,m,x;
	cin >> n >> m >> x;
	for(int i = 0; i < m; i++){
		cin >> way[i].from >> way[i].to >> way[i].cost;
	}
	int forward[N_MAX],back[N_MAX];//往路復路
	for(int i = 0; i < N_MAX; i++){
		forward[i] = COST_MAX;
		back[i] = COST_MAX;
	}
	forward[x-1] = 0;
	back[x-1] = 0;
	while(true){	//往路
		bool flag = false;
		for(int i = 0; i < m; i++){
			road tmp = way[i];
			if(forward[tmp.to-1] != COST_MAX && forward[tmp.from-1] > forward[tmp.to-1] + tmp.cost){
				//距離が一度以上変更されている・迂回した道のほうが直接より早い
				//toが最終目的地のroadから埋まっていく
				forward[tmp.from-1] = forward[tmp.to-1] + tmp.cost;
				flag = true;
			}
		}

		if(!flag) break;
	}
	while(true){	//復路
		bool flag = false;
		for(int i = 0; i < m; i++){
			struct road tmp = way[i];
			if(back[tmp.from-1] != COST_MAX && back[tmp.to-1] > back[tmp.from-1] + tmp.cost){
				back[tmp.to-1] = back[tmp.from-1] + tmp.cost;
				flag = true;
			}
		}
		if(!flag) break;
	}
	int max = -1;
	for(int i = 0; i < n; i++){
		if(max < forward[i] + back[i]){
			max = forward[i] + back[i];
		}
	}
	cout << max << endl;
	return 0;
}