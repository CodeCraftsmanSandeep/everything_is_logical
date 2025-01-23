#include <vector>
#include <iostream>
#include <stack>
using namespace std;

// solution from GFG, need to work out

void constructBalanceArray(int BOP[], int BCP[], const char* str, int n) {
    stack<int> stk;
    fill(BOP, BOP + n + 1, 0);
    fill(BCP, BCP + n + 1, 0);

    for (int i = 0; i < n; i++) {
        if (str[i] == '(') {
            stk.push(i);
        } else { // It's a ')'
            if (!stk.empty()) {
                int openIndex = stk.top();
                stk.pop();
                BOP[openIndex] = 1; // There's a valid '(' at openIndex
                BCP[i] = 1;         // There's a valid ')' at i
            }
        }
    }

    for(int i = 0; i <= n; i++) cout << BOP[i] << " ";
    cout << "\n";

    for(int i = 0; i <= n; i++) cout << BCP[i] << " ";
    cout << "\n";

    // Convert the BOP and BCP into prefix sums
    for (int i = 1; i <= n; i++) {
        BOP[i] += BOP[i - 1];
        BCP[i] += BCP[i - 1];
    }
}

int query(int BOP[], int BCP[], int s, int e) {
    if (s == 0) {
        return (BCP[e] - BOP[s]) * 2;
    } else {
        return ((BCP[e] - BCP[s - 1]) - (BOP[s] - BOP[s - 1])) * 2;
    }
}

int main() {
    const char str[] = "())(())(())(";
    int n = strlen(str);

    int BCP[n + 1], BOP[n + 1];

    constructBalanceArray(BOP, BCP, str, n);

    vector<pair<int, int>> queries = {{4, 11}, {3, 4}, {0, 2}, {0, 4}, {1, 2}};
    for (const auto& query_pair : queries) {
        int start = query_pair.first;
        int end = query_pair.second;
        cout << "Maximum Length Correct Bracket Subsequence between " << start + 1 << " and " << end + 1 << " = " << query(BOP, BCP, start, end) << endl;
    }

    return 0;
}
