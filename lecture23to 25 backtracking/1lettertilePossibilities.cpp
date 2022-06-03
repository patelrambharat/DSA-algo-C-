class Solution {
public:
    
    void solve(string tiles, string &output, set<string> &result, 
               map<int, bool> &vis) {
        
        //to check for each character in string
        for(int i=0 ;i<tiles.length(); i++) {
            
            //to track indexes
            if(vis[i] == 0) 
            {
                
                output.push_back( tiles[i]);
                vis[i] = 1;
                
                cout << "storing " << output << " in results " << endl;
                //store output string into results set
                result.insert(output);
                //recursive call
                solve(tiles, output, result, vis);
                
                //when u return from recursive call
                
                //backtracking
                output.pop_back();
                vis[i] = 0;
                
                
            }
        }
        
    }
    int numTilePossibilities(string tiles) {
        
        string output = "";
        
        //to store all different output strings
        set<string> result;
        
        //to track which has been included in the output string
        map<int, bool> flag;
        
        //function call
        solve(tiles, output, result, flag);
        
        return result.size();
    }
};