#include <iostream>
#include <vector>
#include <string> // Added string library
using namespace std;

int longest_palindrome(string s){

    vector<int> lowercase(26,0);
    vector<int> uppercase(26,0);

    // FIX: Both variables explicitly set to 0
    int count = 0, odd = 0; 

    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            lowercase[s[i] - 'a']++;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            uppercase[s[i] - 'A']++;
        }
    }

    for(int i = 0; i < 26; i++){
        if(lowercase[i] % 2 == 0){
            count += lowercase[i];
        }
        else{ 
            count += lowercase[i] - 1;
            odd = 1;
        }
        
        if(uppercase[i] % 2 == 0){
            count += uppercase[i];
        }
        else{ 
            count += uppercase[i] - 1;
            odd = 1;
        }
    }
  
    return count + odd;
}

int main(){

    string s;
    cout << "Enter the string(mixed): ";
    getline(cin, s);

    int result = longest_palindrome(s);

    cout << "Longest possible palindrome of " << s << " is " << result << endl;
    
    return 0; // Good practice in C++
}