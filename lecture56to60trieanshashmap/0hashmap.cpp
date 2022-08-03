#include<iostream>
#include<unordered_map>
using namespace std;



int main() {

    //creation
    unordered_map<char, int> m;

    string name = "babbar" ;

    //insertion
    pair<char,int> p = make_pair('a', 3);
    m.insert(p);

    m['b'] = 2;

    //m.insert({'c', 5});

    //access
    cout << m['b'] << endl;
    cout << m['z'] << endl;

    cout << m.size() << endl;

    cout << m.empty() << endl;

    cout << m.count('a') << endl;
    cout << m.count('j') << endl;

    cout << m['j'] << endl;
    cout << m.count('j') << endl;

    unordered_map<char, int> :: iterator i = m.find('a');
    cout << "value at iterator is " << (*i).second << endl;
    if(i != m.end()) {
        cout << "element found" << endl;
    }
    else {
        cout << "element not found" << endl;
    }

    return 0;
}