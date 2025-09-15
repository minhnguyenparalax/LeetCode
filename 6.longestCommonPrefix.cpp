// string::substr
#include <iostream>
#include<vector>
#include <string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++)
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        return prefix;
    }
};
void input_string(vector<string> &strs);
int main()
{ 
    Solution slt;
    vector<string> strs;
    input_string(strs);
    cout<<slt.longestCommonPrefix(strs);
}

void input_string(vector<string> &strs)
{
    cout<<"Nhap chuoi: (nhap ""Dung Khong them nhap nua"" de dung lai)"<<endl;
    int i = 0;
    string stop_string="Dung Khong them nhap nua";
    string tmp = "";
    while(true)
    {
        cout<<"string["<<i<<"]: ";
        getline(cin,tmp);
        if(tmp == "Dung Khong them nhap nua")   
            break;
        strs.push_back(tmp);
        i++;
    }
}
