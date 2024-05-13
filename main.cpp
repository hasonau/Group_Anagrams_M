#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <string>
#include<cstring>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> MyMap;
        int count=0;
        for (auto s: strs) {
            auto s_temp=s;
            sort(s_temp.begin(),s_temp.end());
            if(MyMap.find(s_temp)!=MyMap.end()){
                continue;
            }
            MyMap.insert({s_temp,count});
            count++;
        }
        vector<vector<string>>vecOfVectors(MyMap.size());

        for (auto s: strs) {
            auto s_temp=s;
            sort(s_temp.begin(),s_temp.end());
            int value=MyMap[s_temp];
            vecOfVectors[value].push_back(s);
        }
        return vecOfVectors;

    }
};

int main() {
    // Input vector of strings
    std::vector<std::string> strs = {"eat","f","ed","de", "tea", "tan", "ate", "nat", "bat"};

    // Create an instance of the Solution class
    Solution solution;

    // Call the groupAnagrams function
    std::vector<std::vector<std::string>> result = solution.groupAnagrams(strs);

    // Output the result
    std::cout << "Result:" << std::endl;
    for (const auto &group: result) {
        std::cout << "[ ";
        for (const std::string &str: group) {
            std::cout << str << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}