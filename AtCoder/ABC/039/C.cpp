#include <bits/stdc++.h>
using namespace std;

// Source: Deepseek
// Reason: Chinese Problem Statement was not clear, yet solvable.

int main() {
    string S;
    cin >> S;
    
    string colors = "WBWBWWBWBWBW";
    vector<string> notes = {"Do", "Do#", "Re", "Re#", "Mi", "Fa", "Fa#", "So", "So#", "La", "La#", "Si"};
    
    for (int start = 0; start < 12; start++) {
        if (colors[start] != 'W') continue;
        
        bool match = true;
        for (int i = 0; i < 20; i++) {
            int pos = (start + i) % 12;
            if (colors[pos] != S[i]) {
                match = false;
                break;
            }
        }
        
        if (match) {
            cout << notes[start] << "\n";
            return 0;
        }
    }
    
    return 0;
}