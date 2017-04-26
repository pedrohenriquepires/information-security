#include <iostream>
#include <string>

using namespace std;

string readLine(string label) {
    string target;

    cout << label;
    getline(cin, target);
    
    return target;
}
