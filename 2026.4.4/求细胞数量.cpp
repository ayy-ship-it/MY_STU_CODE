#include<iostream>

using namespace std;
int n,m;
const int N = 110;
char a[N][N];
int ret = 0;
bool st[N][N];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

//从x行y列开始枚举

void dfs(int x,int y){


	st[x][y] = true; 
	for(int i = 0;i < 4;i++){
		int o = x + dx[i];
		int p = y + dy[i];
		if(o < 0 || o >= n || p < 0 || p >= m) continue;
		if(!st[o][p] && a[o][p] != '0'){ 
			dfs(o,p);//一条路走完了返回，连通数加1 
		}
	}
	
} 



int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(a[i][j] != '0' && !st[i][j]){
				dfs(i,j);
				ret++;//遍历完了一个块 
			}
		}
	}
	
	cout << ret;
	return 0;
}
