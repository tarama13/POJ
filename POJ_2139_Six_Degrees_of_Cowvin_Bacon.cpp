#include <iostream>
#define MAX_N 300
#define MAX_M 10000
using namespace std;
int main(){
	int n,m;	//�S��, �S�f��
	int dp[MAX_N+1][MAX_N+1];
	for(int i = 0; i < MAX_N+1; i++){
		for(int j = 0; j < MAX_N+1; j++){
			dp[i][j] = MAX_N+1;
		}
		dp[i][i] = 0;
	}
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int mi;	//�f��ɏo�鋍
		cin >> mi;
		int tmp[MAX_N+1];
		for(int j = 0; j < mi; j++){
			cin >> tmp[j];
		}
		for(int j = 0; j < mi; j++){
			for(int k = 0; k < mi; k++){
				if(j != k){
					dp[tmp[j]-1][tmp[k]-1] = 1;
				}
			}
		}
	}
	//���[�V�����E�t���C�h
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
*/
	int tmpmin = MAX_M * MAX_N + 1, sum = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			sum += dp[i][j];
		}
		if(sum <= tmpmin){tmpmin = sum;}
		sum = 0;
	}
	//�����ȉ��؂�̂�
	double ans = (double)tmpmin/(double)(n-1)*100;
	cout << (int)ans << endl;

	return 0;
}