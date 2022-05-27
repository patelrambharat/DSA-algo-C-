#include<bits/stdc++.h>
using namespace std;

void reverseWords(string s){
   // temporary vector to store all words
    vector<string> v;
    string str = "";
    for (int i = 0; i < s.length(); i++)
    {
        
        if (s[i] == ' ')  //check if encounter word have any space
        {
            tmp.push_back(str);
            str = "";
        }
        else    //if not any space encounter then add into to the string and form a word 
            str += s[i];
    }
    tmp.push_back(str);    //last word remaining push it into the vector
    // Now print from last to first in vector
    int i;
    for (i = tmp.size() - 1; i > 0; i--)
        cout << tmp[i] << " ";
    // Last word remaining,print it
    cout << tmp[0] << endl;
}
int main(){
     string s = "i like this program very much";
    reverseWords(s);
    return 0;
}