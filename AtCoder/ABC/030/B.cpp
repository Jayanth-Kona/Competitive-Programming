#include <bits/stdc++.h>
using namespace std;

/*

Source: DeepSeek
Reason: No knowledge on angle calculations

*/

int main(){
    int n , m ; cin >> n >> m;
    
    double minute_angle = m * 6.0;
    double hour_angle = (n % 12) * 30.0 + m * 0.5;

    double diff = abs(hour_angle - minute_angle);
    double ans = min(diff , 360.0 - diff);
    
    cout << fixed << setprecision(6) << ans << "\n";
    
    return 0;
}