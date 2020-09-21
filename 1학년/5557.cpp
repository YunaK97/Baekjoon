#include<iostream>
#include<vector>
using namespace std;
int n;
long long dp[101][21];
int main(){
	freopen("5557.txt","r",stdin);
	cin>>n;
	vector<int> v(n);
	int ans;
	for(int i=0;i<n-1;i++)
		cin>>v[i];
		
	cin>>ans;
	dp[1][v[0]]=1;
	for(int i=1;i<n-1;i++){
		for(int j=0;j<=20;j++){
			if(j-v[i]>=0)
				dp[i+1][j-v[i]]+=dp[i][j];
			if(j+v[i]<=20)
				dp[i+1][j+v[i]]+=dp[i][j];
		}
	}
	cout<<dp[n-1][ans];
}
