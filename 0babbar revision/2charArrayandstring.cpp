```
#include<iostream>
#include<map>
using namespace std;


int getLength(char arr[]) {

    int length = 0;
    int index = 0;
    while(arr[index] != '\0') {
        length++;
        index++;
    }
    return length;
} 

void reverse(char arr[]) {
    int n = strlen(arr);
    int s = 0, e = n-1;

    while(s < e) {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

bool checkAnagram(string a, string b) {
    map<char, int> m;

    //inc count for string a
    for(int i=0; i<a.length(); i++) {
        char ch = a[i];
        m[ch]++;
    }

    //decrement for string b
    for(int i=0; i<b.length(); i++) {
        char ch = b[i]; 
        m[ch]--;
    }
    
    for(char i = 'a'; i<='z'; i++) {
        if(m[i] != 0)
            return false;
    }

    return true;
}

char flip(char expected) {
    if(expected == '0')
        return '1';
    else
        return '0';
}

int getFlips(string str, char expected) {

    int cntFlips = 0;

    for(int i=0; i<str.length(); i++) {

        if(str[i] != expected)
            cntFlips++;

        expected = flip(expected);
    }
    return cntFlips;
}

void dummy(char arr[10]) {
    cout << strlen(arr) << endl;
}

int main() {
    /*
    //creation
    char name[10] = "babbar";
    char name2[10] = "BABBAR";

    //input 
    //cin >> name ;

    //print
    cout<< "name is -> " << name << endl;
    cout << "length is -> "<< strlen(name) << endl;
    cout << strcmp(name, name2 ) << endl;
    reverse(name);
    cout << "reversed name is -> " << name << endl;

    cout << "Starting starts from here " << endl;

    //creation
    string str;

    //input 
    //cin >> str;
    getline(cin, str);

    //print
    cout << "str is " << str << endl;


    //string a = "babbar";
    //string b = "ramesh";
    //cout << "answer is " << checkAnagram(a,b) << endl;

    string str = "0010";

    //if ans starts with 0
    int ans0 = getFlips(str, '0');
    // if ans starts with 1
    int ans1 = getFlips(str, '1');

    int ans = min(ans0, ans1);
    cout << "answer is " << ans << endl;
    */

    return 0;

}
```