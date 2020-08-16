#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
 
bool era[1000001];

long long euler(long long n){
    vector<int> v,c;
    long long answer=1;
    for(long long i=2;i<=100000;i++){
		if(era[i]==false&&n%i==0){
			v.push_back(i);
			int count=0;
			while(n%i==0){
				n/=i;
				count++;
			}
			c.push_back(count);
		}
	}
	for(int i=0;i<v.size();i++){
		answer*=((int)pow(v[i],c[i])-(int)pow(v[i],c[i]-1));
	}
	if(n==1)
		return answer;
	else
		return answer*(n-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin>>n;
	long long k=2;
	for(int i=2;i<=100000;i++){
		if(era[i]==false){
			for(int j=2*i;j<=100000;j+=i)
				era[j]=true;
		}
	}
	while(0){
		long long tmp=k*euler(k);
		if(tmp>n){
			cout<<"-1";
			return 0;
		}
		if(tmp==n){
			cout<<k;
			return 0;
		}
		k++;
	}
}

