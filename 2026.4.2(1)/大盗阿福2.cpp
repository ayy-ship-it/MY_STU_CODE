#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int t;
int n;
const int N = 10010;
int m[N];//存储每一家店铺的现金数 
int mem[N];//记忆化搜索 


//遍历每一家店铺，每家店铺有两种状态（选或不选） 
int dfs(int x){
	if(mem[x]) return mem[x];//不用重复搜索，存储了直接返 
	int sum = 0;
	if(x > n) return 0; 
	else{
		for(int i = 1;i <= n;i++){
			sum = max(dfs(x+1),dfs(x+2)+m[x]);//dfs(x+1)表示当前位置不洗劫，dfs(x+2)+m[i]表示当前位置洗劫 
		}
	}
	mem[x] = sum;//存储从x位置开始到最后满足条件的最大洗劫金钱 (记忆化搜索)
	return sum; 
	
}

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> m[i];
		memset(mem,0,sizeof mem); //不要忘记多组数据每次要将记忆数组重新初始化 
		int ret = dfs(1);
		cout << ret << endl;
	} 
	return 0;
}
