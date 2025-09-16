#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

void input_s(vector<char> &s)
{
    cout<<"Nhap ki tu: "<<endl;
    int i = 0;
    char char_stop = '.';
    char tmp;
    while(true)
    {
        cout<<"s["<<i<<"] = ";
        cin.get(tmp);
        cin.ignore();
        if(tmp == '.')
            break;
        s.push_back(tmp);
        i++;
    }
}
int main()
{
    Solution slt;
    vector<char> s;
    input_s(s);
    slt.reverseString(s);

    cout<<"Chuoi sau khi dao nguoc la: "<<endl;
    for(char c:s)
    {
        cout<<c;
    }
    
}