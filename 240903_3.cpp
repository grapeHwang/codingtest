// Do it! 알고리즘 코딩테스트
// 자료구조 - 구간합 챕터
// 48P

//N×N개의 수가 N×N 크기의 표에 채워져 있다. (x1, y1)부터 (x2, y2)까지 합을 구하는 프로그램을 작성하시오. (x, y)는 x행 y열을 의미한다.

//입력
//첫째 줄에 표의 크기 N과 합을 구해야 하는 횟수 M이 주어진다. (1 ≤ N ≤ 1024, 1 ≤ M ≤ 100,000) 둘째 줄부터 N개의 줄에는 표에 채워져 있는 수가 1행부터 차례대로 주어진다. 
//다음 M개의 줄에는 네 개의 정수 x1, y1, x2, y2 가 주어지며, 
//(x1, y1)부터 (x2, y2)의 합을 구해 출력해야 한다. 표에 채워져 있는 수는 1,000보다 작거나 같은 자연수이다. (x1 ≤ x2, y1 ≤ y2)

//출력
//총 M줄에 걸쳐 (x1, y1)부터 (x2, y2)까지 합을 구해 출력한다.

#include <iostream>
#include <vector>
using namespace std;

int main(){

    cin.tie(NULL);
    ios::sync_with_stdio(NULL);
    cout.tie(NULL);

    int N, M;

    cin>>N>>M;

    vector<vector<int>>array(N);
    
    //step1 원본 배열 생성
    for(int i = 0 ;i< N; i++){
        for(int j = 0; j< N; j++){
            int temp;
            cin>>temp;
            array[i].push_back(temp);
        }
    }


    //step 2 구간합 배열 생성
    vector<vector<int>>sum(N, vector<int>(N));
    sum[0][0] = array[0][0];

    for(int i = 1; i< N; i++){
        sum[i][0] = sum[i-1][0] + array[i][0];
        sum[0][i] = sum[0][i-1] + array[0][i];
    }

    for(int i = 1; i< N; i++){
        for(int j = 1; j< N; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + array[i][j]; 
        }
    }

    

    for(int i = 0 ; i< M; i++){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        x1--; x2--; y1--; y2--;

        if(x1 == 0 && y1 != 0){
            cout<<sum[x2][y2] - sum[x2][y1-1]<<"\n";
        }
        else if(x1 != 0 && y1 == 0){
            cout<<sum[x2][y2] - sum[x1-1][y2]<<"\n";
        }

        else if(x1 == 0 && y1 == 0){
            cout<<sum[x2][y2]<<"\n";
        }

        else cout<<sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1]<<"\n";
        
    }

    


    return 0;
}