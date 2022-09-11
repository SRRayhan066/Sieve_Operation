#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<bool>marked(N,false);

bool is_prime(int n){
    if(n==2) return true;
    else if(n%2==0) return false;
    else if(n<2) return false;
    else return marked[n]==false;
}

void seive(){
    for(int i=3;i*i<=N;i+=2){
        if(!marked[i]){
            for(int j=i*i;j<=N;j+=i+i){
                marked[j]=true;
            }
        }
    }
}

int main(){
    fastio;
    seive();
    for(int i=0;i<=100;i++) if(is_prime(i)) cout<<i<<endl;
    return 0;
}