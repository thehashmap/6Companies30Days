class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0, movesA = 0, movesB = 0;
        for(auto s : colors){
            if(s == 'A'){
                if(b >= 3) movesB += (b - 2);
                b = 0;
                a++;
            }
            else{
                if(a >= 3) movesA += (a - 2);
                a = 0;
                b++;
            }
        }
        if(a >= 3) movesA += (a - 2);
        if(b >= 3) movesB += (b - 2);
        return movesA > movesB;
    }
};
