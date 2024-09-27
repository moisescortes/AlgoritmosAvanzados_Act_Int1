#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<string> readFileLines(const string& filename) {
    ifstream file(filename);
    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

string longestCommonSubstring(const string& s1, const string& s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLength = 0;
    int endIndex = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }

    // Si hay un substring común, lo retornamos
    if (maxLength > 0) {
        return s1.substr(endIndex - maxLength + 1, maxLength);
    } else {
        return "";  
    }
}
