#include<iostream>
#include<cstring>
using namespace std;
int n,k;
const int N = 10;
char s[N][N];
bool st[N];//用于排列型枚举，表示每一列是否下过棋子 
int ret = 0;




//x表示枚举的行，cnt表示使用的棋子数目 
void dfs(int x,int cnt){
	
	if(cnt == k){
		ret++;
		return ;
	}
	
	if(x >= n) return ;
	//枚举列 
	for(int i = 0;i < n;i++){
		if(!st[i] && s[x][i] == '#'){
			st[i] = true;
			dfs(x+1,cnt+1);
			st[i] = false;
		} 
	} 
	dfs(x + 1,cnt);
	
	
}

int main(){
	while(cin >> n >> k && n != -1 && k != -1){
		for(int i = 0;i < n;i++){
			scanf("%s",s[i]); 
		} 
		ret = 0;
		dfs(0,0);
		cout << ret << endl;
		
	}
	
	
	return 0;
}
