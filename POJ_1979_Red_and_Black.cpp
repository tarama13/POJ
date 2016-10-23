#include <iostream>
#include <queue>
using namespace std;

int w,h;
char rb[20][20];	//redblack
int n = 0;	//乗れる
void rob(int,int);	//red or black

int main(){

	int k = 0;
	queue<int> able;
	while(1){
		int x,y;
		cin >> w >> h ;
		if (w == 0 && h == 0){
			break;
		}

		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cin >> rb[j][i];
				if(rb[j][i] == '@'){
					x = j;
					y = i;
				}
			}
		}	//入力終了

	rob(x,y);
	able.push(n);
	n = 0;
	k++;
	}
	for(int i = 0; i < k; i++){
		cout << able.front() << endl;
		able.pop();
	}
	return 0;
}

	void rob(int x,int y){
		rb[x][y] = '#';
		n++;
		if(0 <= x-1 && rb[x-1][y] == '.'){
			rob(x-1,y);
		}
		if(x+1 < w && rb[x+1][y] == '.'){
			rob(x+1,y);
		}
		if(0 <= y-1 && rb[x][y-1] == '.'){
			rob(x,y-1);
		}
		if(y+1 < h && rb[x][y+1] == '.'){
			rob(x,y+1);
		}

		return ;
	}