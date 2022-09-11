#include<bits/stdc++.h>
using namespace std;
const int N=32000;
bool marked[N+10];
vector<int>primes;

void sieve(){
    for(int i=3;i*i<=N;i+=2){
        if(!marked[i]){
            for(int j=i*i;j<=N;j+=i+i){
                marked[j]=true;
            }
        }
    }
    primes.push_back(2);
    for(int i=3;i<=N;i+=2) if(!marked[i]) primes.push_back(i);
}

void segmented_sieve(int l,int r){
    bool status[r-l+1];
    for(int i=0;primes[i]*primes[i]<=r;i++){
        if(l==1) status[0]=true;
        int current=primes[i];
        int base=(l/current)*current;
        if(base<current) base+=current;
        for(int j=base;j<=r;j+=current){
            status[j-l]=true;
        }
        if(base==current) status[base-l]=false;
    }

    for(int i=0;i<=r-l+1;i++){
        if(!status[i]) cout<<i+l<<endl;
    }cout<<endl;
}

int main(){
    sieve();
    int t=10;
    while(t--){
        int l,r;
        cin>>l>>r;
        segmented_sieve(l,r);
    }
    return 0;
}