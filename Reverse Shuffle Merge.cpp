#include <bits/stdc++.h>

using namespace std;

string reverseShuffleMerge(string text)
{
    int cnt[256] = {0};
    int n = text.size();
    for(int i = 0; i < n; i++)
        cnt[text[i]]++;
    
    int rem[256], used[256];
    for(int i = 0; i < 256; i++)
    {
        rem[i] = cnt[i];
        used[i] = 0;
    }

    string result = "0";
    for(int i = n-1; i >=0 ; i--)
    {
        if(2*used[text[i]] == cnt[text[i]])
        {   rem[text[i]]--;
            continue;
        }
        while(result.back() > text[i] && 2*(rem[result.back()]+used[result.back()]) > cnt[result.back()])
            {
                used[result.back()]--;
                result.pop_back();
            }

            result += text[i];
            used[text[i]]++;
            rem[text[i]]--;
    }
    

    //cout << endl << result;
    return result.substr(1);
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
