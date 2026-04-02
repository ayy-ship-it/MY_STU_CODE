#include<iostream>

using namespace std;
const int N = 110;
int n,m;
char s[N][N];
bool st[N][N]; 
int ret = 0;
int dx[] = {1,1,1,0,-1,-1,-1,0};
int dy[] = {1,0,-1,-1,-1,0,1,1};

void dfs(int i,int j){
	
	
	for(int k = 0;k < 8;k++){
		int a = i + dx[k];
		int b = j + dy[k];
		if(a < 0 || a >= n || b < 0 || b >= m) continue;
		if(s[a][b] != 'W')continue;
		if(st[a][b]) continue;
		st[a][b] = true; 
		dfs(a,b);
	}
	
}


int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		scanf("%s",s[i]);
	}
	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(s[i][j] == 'W'&&!st[i][j]){
				st[i][j] = true;
				dfs(i,j);
				ret++;
			}
		}
	}
	
	cout << ret;
	return 0;
}
