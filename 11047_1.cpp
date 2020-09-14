#include<iostream>
using namespace std;
int coin[10];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>coin[i];
	}
	int tmp=k;
	int cnt=0;
	for(int i=n-1;i>=0;i--){
		if(coin[i]<=tmp){
			int a=tmp/coin[i];
			cnt+=a;
			tmp=tmp-coin[i]*a;
		}
	}
	cout<<cnt;
}
