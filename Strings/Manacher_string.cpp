class Manacher{
private:
    string s , t;
    vector<int> p;

public:
    Manacher(string str){
        s = str;
        t = "#";

        for(char c : s){
            t += c;
            t += '#';
        }

        int N = t.size();
        p.resize(N);

        for(int i = 0 , L = 0 , R = 0 ; i < N ; i++){
            if(i < R){
                p[i] = min(R - i , p[L + R - i]);
            }
            while(i - p[i] - 1 >= 0 && i + p[i] + 1 < N && t[i - p[i] - 1] == t[i + p[i] + 1]){
                p[i]++;
            }
            if(i + p[i] > R){
                L = i - p[i] , R = i + p[i];
            }
        }
    }

    bool isPalindrome(int L , int R){
        return p[L + R + 1] >= R - L + 1;
    }

    vector<array<int , 2>> allPalindromes(){
        vector<array<int , 2>> palindromes;

        for(int L = 0 ; L < s.size() ; L++){
            for(int R = L ; R < s.size() ; R++){
                if(isPalindrome(L , R)){
                    palindromes.push_back({L, R});
                }
            }
        }

        return palindromes;
    }
};