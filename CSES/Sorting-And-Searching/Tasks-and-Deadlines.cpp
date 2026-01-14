#include<bits/stdc++.h>
using namespace std;


/*

reward = summation(deadline - finishTime)
       = summation(deadline) - sum(finishTime)
       = constant - sum(finishTime)


In order to maximize reward,
we need to minimize finishTime of every task,
and to do that start with tasks that complete early(minimal durartion)

*/

int main(){
    int totalTasks  ; cin >> totalTasks;

    vector<array<int , 2>> tasks(totalTasks);
    for(auto &[duration , deadline]: tasks) cin >> duration >> deadline;

    sort(tasks.begin() , tasks.end());

    long long reward = 0 , finishTime = 0;

    for(auto &[durartion , deadline] : tasks){
        finishTime += durartion;
        reward += deadline - finishTime;
    }

    cout << reward;

    return 0;
}