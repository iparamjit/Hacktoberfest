#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int calPoints(vector<string>& operations) {
    stack<int> stk;
    for (int i = 0; i < operations.size(); i++) {
        if (operations[i] == "+") {
            int f = stk.top();      stk.pop();
            int s = stk.top();      stk.pop();
            stk.push(s);
            stk.push(f);
            stk.push(f + s);
        } else if (operations[i] == "D") {
            int f = stk.top();      stk.pop();
            stk.push(f);
            stk.push(2 * f);
        } else if (operations[i] == "C") {
            stk.pop();
        } else {
            stk.push(stoi(operations[i]));
        }
    }
    int sum = 0;
    while (!stk.empty()) {
        sum += stk.top();
        stk.pop();
    }
    return sum;
}
