#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class MedianFinder{
private:
    ll Lsum = 0;
    ll Rsum = 0;
    multiset<int> L , R;

public:
    void Add(int num){
        if(L.empty() == true || num <= *L.rbegin()) L.insert(num) , Lsum += num;
        else R.insert(num) , Rsum += num;
        Adjust();
    }

    void Remove(int num){
        if(L.count(num)) L.extract(num) , Lsum -= num;
        else R.extract(num) , Rsum -= num;
        Adjust();
    }

    void Adjust(){
        if(L.size() > 1 + R.size()){
            int maxNum = *L.rbegin();
            L.extract(maxNum) , Lsum -= maxNum;
            R.insert(maxNum) , Rsum += maxNum;
        }
        else if(L.size() < R.size()){
            int minNum = *R.begin();
            R.extract(minNum) , Rsum -= minNum;
            L.insert(minNum) , Lsum += minNum;
        }
    }

    int Median(){
        return *L.rbegin();
    }

    ll DistanceToMedian(){
        ll center = *L.rbegin();
        return (center * L.size() - Lsum) + (Rsum - center * R.size());

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
            cout << MF.DistanceToMedian() << " ";
            MF.Remove(x[i - k + 1]);
        }
    }

    return 0;
}