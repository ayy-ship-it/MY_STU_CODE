#include<iostream>
#include<cstring>
using namespace std;
const int N = 100; 
string s;
int start = 0;
int max_len = 1;
bool dp[N][N];

void f(string &s){
	
	int n = s.size();
	if(n < 2) return;
	
	for(int i = 0;i < n;i++){
		dp[i][i] = true;
	}
	
	
	for(int i = 0;i < n - 1;i++){
		if(s[i] == s[i+1]){
			dp[i][i+1] = true;
			start = i;
			max_len = 2;
		}
	}
	
	
	for(int len = 3;len <= n;len++){
		for(int i = 0;len + i - 1 < n;i++){
			int j = i + len - 1;
			if(s[i] == s[j] && dp[i+1][j-1]){
				dp[i][j] = true;
				start = i;
				max_len = len;
			}
		}
	}
}




int main(){
	cin >> s;
	f(s);
	string ret = s.substr(start,max_len);
	cout << ret;
	return 0;
	
	
}
