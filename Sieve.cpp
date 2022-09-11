#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<bool>marked(N,false);

void seive(){
    for(int i=3;i*i<=N;i+=2){
        if(!marked[i]){
            for(int j=i*i;j<=N;j+=i+i){
                marked[j]=true;
            }
        }
    }
    puts("2");
    for(int i=3;i<=N;i+=2) if(!marked[i]) cout<<i<<endl; 
}

int main(){
    fastio;
    seive();
    return 0;
}