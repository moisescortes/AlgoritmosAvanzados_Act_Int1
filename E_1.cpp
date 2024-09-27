#include "./Comun.h"
#include "Palindromo.h"

using namespace std;

string readFile(const string& filename) {
    ifstream file(filename);
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    return content;
}

bool isContained(const string& transmission, const string& mcode, int& position) {
    size_t found = transmission.find(mcode);
    if (found != string::npos) {
        position = found + 1;
        return true;
    }
    return false;
}


int main() {
    vector<string> transmissions = {"transmission1.txt", "transmission2.txt"};
    vector<string> mcodes = {"mcode1.txt", "mcode2.txt", "mcode3.txt"};
    

    // Part 1 - Check if mcode is contained in transmission and print the position 
    for (const auto& transmission : transmissions) {
        string trans_content = readFile(transmission);
        for (const auto& mcode : mcodes) {
            string mcode_content = readFile(mcode);
            int position;
            bool contained = isContained(trans_content, mcode_content, position);
            cout << (contained ? "true " + to_string(position) : "false") << endl;
        }
    }

    for (const auto& transmission : transmissions){
        pair<int, int> result = findLongestPalindrome(transmission);
        cout << result.first << " " << result.second << endl; // Imprimir las posiciones
    }




    string trans_line1 = readFileLines(transmissions[0]);
    vector<string> trans_lines2 = readFileLines(transmissions[1]);
    string lcs = "";
    string new_lcs = "";
    for (const auto& trans_line1 :trans_lines1){
        for (const auto& trans_line2 : trans_lines2){
            if (trans_line1 == trans_line2){
                lcs = trans_line1;
                if (lcs.size() > new_lcs.size()){
                    new_lcs = lcs;
                }
            }
        }
    }
    cout<<"Longest common string: "<< new_lcs;
        
    
    return 0;
}