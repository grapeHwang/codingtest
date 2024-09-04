#include <iostream>
#include <vector>
using namespace std;


int main(){
    int N;
    cin>>N;

    int start, end = 1;
    int count = 0;
    int sum = 1;

    while(start <= end && end < N+1){
        if(sum < N){
            end++;
            sum += end;
        }
        else if(sum > N){
            sum -= start;
            start++;
        }
        
        else{
            count++;
            sum -= start;
            start++; end++;
            sum += end;
        }
    }

    cout<<count<<endl;
}