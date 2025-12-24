#include<bits/stdc++.h>
using namespace std;

class MedianFinder{
private:
    multiset<int> L , R;

public:
    void Add(int num){
        if(L.empty() == true || num <= *L.rbegin()) L.insert(num);
        else R.insert(num);
        Adjust();
    }

    void Remove(int num){
        if(L.count(num)) L.extract(num);
        else R.extract(num);
        Adjust();
    }

    void Adjust(){
        if(L.size() > 1 + R.size()){
            int maxNum = *L.rbegin();
            L.extract(maxNum);
            R.insert(maxNum);
        }
        else if(L.size() < R.size()){
            int minNum = *R.begin();
            R.extract(minNum);
            L.insert(minNum);
        }
    }

    int Median(){
        return *L.rbegin();
    }
};

int main(){
    int n , k ; cin >> n >> k;

    vector<int> x(n);
    for(int &xi : x) cin >> xi;

    MedianFinder MF;
    
    for(int i = 0 ; i < n ; i++){
        MF.Add(x[i]);
        if(i >= k - 1){
            cout << MF.Median() << " ";
            MF.Remove(x[i - k + 1]);
        }
    }

    return 0;
}