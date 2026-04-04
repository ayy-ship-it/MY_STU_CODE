#include<iostream>

using namespace std;
const int N = 1010;
int r;
int a[N][N];

int mem[N][N];

//表示从第i行j列枚举到最后得到的最大值 
int dfs(int x,int y){
	
	int sum = 0;
	if(mem[x][y]) return mem[x][y]; 
	
	if(x > r || x < 1 || y > r || y < 1) sum = 0;
	
	else sum = max(dfs(x+1,y)+a[x][y],dfs(x+1,y+1) + a[x][y]); 
	
	mem[x][y] = sum;
	
	return sum;
	
}

int main(){
	cin >> r;
	for(int i = 1;i <= r;i++){
		for(int j = 1;j <= i;j++){
			cin >> a[i][j];
		}
	}
	
	
	
	/*
	//表示从第一行第一列开始枚举 
	int ret = dfs(1,1); 
	cout << ret;
	*/
	int ret = 0;
	for(int i = 1;i <= r;i++){
		for(int j = 1;j <= i;j++){
			ret += max(a[i+1][j] + a[i][j],a[i+1][j+1] + a[i][j]);
		}
	} 
	
	cout << ret;
	return 0;
}
