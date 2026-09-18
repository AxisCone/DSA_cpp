#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        string temp;
        int index = 0;

        while(index < s.size()) {
            if(s[index] == ' ') {
                int pos = temp[temp.size() - 1] - '0';

                temp.pop_back();
                ans[pos] = temp;
                temp.clear();

                index++;   // move past the space
            }
            else {
                temp += s[index];
                index++;
            }
        }

        // Process the last word
        int pos = temp[temp.size() - 1] - '0';
        temp.pop_back();
        ans[pos] = temp;

        // Build final sentence
        string result;

        for(int i = 1; i < 10; i++) {
            if(ans[i] != "") {
                if(result != "")
                    result += " ";

                result += ans[i];
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    string input;
    
    cout << "Enter the shuffled sentence: ";
    // Using getline to read the entire line including spaces
    getline(cin, input);
    
    string result = sol.sortSentence(input);
    
    cout << "Sorted sentence: " << result << endl;
    
    return 0;
}