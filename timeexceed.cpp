#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

struct ob {
	int price;
	int weight;
}ob[1000];

int dp[1000][30];

int people[100];


int maxV(int n,int m,int p){
	for (int i = 1; i <= m; i++) {
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 0;
		
		for (int j = 1; j <= m; j++) {

			if (ob[i].weight <= j) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - ob[i].weight] + ob[i].price);
				
			}
			else
				dp[i][j] = dp[i-1][j];
		}

	}
	int sum = 0;

	for (int i = 0; i < p; i++) {
		sum += dp[n][people[i]];
	}
	return sum;
}


int main() {
	int c;
	cin >> c;
	int n,m;
	for (int i = 0; i < c; i++) {
		cin >> n;
		for (int j = 1; j < n+1; j++) {
			cin >> ob[j].price >> ob[j].weight;
		}
		cin >> m;
		;
		int w = 0;
		
		for (int j = 0; j < m; j++) {
			cin >> people[j];
			w = max(w, people[j]);
		}
		cout <<maxV(n,w,m) << endl;
	}

	return 0;
}
