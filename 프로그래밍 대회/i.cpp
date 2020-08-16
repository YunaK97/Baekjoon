#include<iostream>
#include<vector>
using namespace std;
#define PN 1000000
 
bool isprime[PN+5];
vector<long long> prime;
void primechk(){
    for(int i=2;i<=PN;i++) isprime[i] = true;
    for(long long i=2;i<=PN;i++)
        if(isprime[i]){
            prime.push_back(i);
            for(long long j=i*i;j<=PN;j+=i)
                isprime[j] = false;
        }
}
// 오일러 파이 함수 = v 와 서로소인 수의 갯수 return
long long euler(long long v){
    long long ret=1;
    for(auto now: prime){
        long long p=1;
        while(v%now==0){
            v/=now;
            p*=now;
        }
        if(p!=0){
            ret*=(p-(p/now));
        }
    }
    if(v!=1) ret*=(v-1);
    return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin>>n;
	
	long long i=2;
	while(0){
		long long tmp=i*euler(i);
		if(tmp>n){
			printf("-1");
			return 0;
		}
		if(tmp==n){
			printf("%ll",i);
			return 0;
		}
		i++;
	}
}

