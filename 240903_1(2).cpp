// Do it! 알고리즘 코딩테스트
// 자료구조 - 구간합 챕터
// 45p

//수 N개가 주어졌을 때 i번째 수에서 j번째 수까지의 합을 구하는 프로그램을 작성하시오.


//입력
//1번째 줄에 수의 개수 N, 합을 구해야 하는 횟수 M , 2번째 줄에 N개의 수가 주어진다. 
//각 수는 1,000보다 작거나 같은 자연수다. 3번째 줄부터는 M개의 줄에 합을 구해야하는 구간과 j가주어진다


//출력
//총 M개의 줄에 입력으로 주어진 i번째 수까지의 합을 출력한다.

#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    ios::sync_with_stdio(false); 
    cin.tie (NULL);
    cout.tie(NULL);

    
    int N, M;
    cin>>N>>M;
    vector<int> sum(N);

    for(int i = 1; i<= N; i++){
        int temp;
        cin>> temp;
        if(i > 0){
            sum[i] = sum[i-1] + temp;
        }
        else sum[i] = temp;
    }

    for(int i = 0; i< M; i++){
        int start, end;
        cin>>start>>end;
        if(start > 0){
            cout<< sum[end] - sum[start-1]<<"\n";
        }
        else{
            cout<<sum[end]<<"\n";
        }
    }
    
    return 0;
}