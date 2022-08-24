#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<bool>marked(N,false);
vector<ll>highest_prime(N,0),lowest_prime(N,0);

bool is_prime(int n){
    return marked[n]==false;
}

void sieve(){
    marked[0]=marked[1]=true;
    for(int i=2;i<N;i++){
        if(!marked[i]){
            for(int j=2*i;j<N;j+=i){
                marked[j]=true;
                if(lowest_prime[j]==0) lowest_prime[j]=i;
                highest_prime[j]=i;
            }
        }
    }
}

int main(){
    fastio;
    sieve();
    for(int i=0;i<=50;i++){
        if(is_prime(i)) cout<<i<<" is a prime itself."<<endl;
        else cout<<"Lowest prime of "<<i<<" is -> "<<lowest_prime[i]<<" & Highest prime is -> "<<highest_prime[i]<<endl;
    }
    return 0;
}