// 1079. Letter Tile Possibilities
// Medium

// 1736

// 48

// Add to List

// Share
// You have n  tiles, where each tile has one letter tiles[i] printed on it.

// Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

 

// Example 1:

// Input: tiles = "AAB"
// Output: 8
// Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
// Example 2:

// Input: tiles = "AAABBC"
// Output: 188
// Example 3:

// Input: tiles = "V"
// Output: 1
 
 class Solution {
public:
    set<string>result;
    map<int,int>flag;
    string s;
    int numTilePossibilities(string tiles) {
        solve(tiles);
        return result.size();
    }
    void solve(string tiles){
        for(int i=0;i<tiles.size();i++){
            if(flag[i] != 1){
                s.push_back(tiles[i]);
                flag[i] =1;
                result.insert(s);
                solve(tiles);
                flag[i] =0;
                s.pop_back();
            }
        }
    }
};