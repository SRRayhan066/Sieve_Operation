#include<bits/stdc++.h>
using namespace std;
const int N=10000000+10;
int marked[(N/32)+10];

bool check_bit(int n,int pos){
    return (bool)(n&(1<<pos));
}

int set_bit(int n,int pos){
    return n|=(1<<pos);
}

void bitwise_sieve(){
    for(int i=3;i*i<=N;i+=2){
        if(!check_bit(marked[i/32],i%32)){
            for(int j=i*i;j<=N;j+=i+i){
                marked[j/32]=set_bit(marked[j/32],j%32);
            }
        }
    }

    //printing all prime numbers from 1 to n
    puts("2");
    for(int i=3;i<=N;i+=2) if(!check_bit(marked[i/32],i%32)) cout<<i<<endl;
}

int main(){
    bitwise_sieve();
}