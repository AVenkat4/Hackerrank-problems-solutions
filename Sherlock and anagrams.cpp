#include <bits/stdc++.h>
#include<ctype.h>
#include<string.h>
using namespace std;

int checkAnagram(string a, string b)
{
    int ca[26] = {0}, cb[26] = {0};
    for(int i=0;i<a.length();i++)
        ca[a[i] - 'a']++;
    for(int i=0;i<b.length();i++)
        cb[b[i] - 'a']++;
    int anag = 1;
    for(int i=0;i<26;i++)
        if(ca[i] != cb[i])
        {
            anag = 0;
            break;
        }
    return anag;
}

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {

    string sub1, sub2;
    int count = 0;
    for(int len=1;len<s.length();len++)
    {
        for(int i = 0; i< s.length() - len +1; i++)
        {   
            sub1.assign(s.substr(i, len));
            for(int j = i+1; j < s.length()-len+1;j++)
            {
                if((j+len) <= s.length()){
                sub2.assign(s.substr(j, len));
                //cout<<sub1<<" "<<sub2<<endl;
                if(checkAnagram(sub1, sub2)){
                    
                    count++; }
                }
            }
        }
    }
    cout<<count;
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
