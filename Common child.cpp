#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {

    int n1 = s1.length(), n2 = s2.length();
    int arr[2][n2+1];
    arr[1][0] = 0;
    for(int i = 0;i<n2+1;i++)
        arr[0][i] = 0;
    /*for(int i=0;i<n1+1;i++)
        arr[i][0] = 0;
    for(int i=1;i<n1+1;i++)
    {
        for(int j=1;j<n2+1;j++)
        {
            if(s1[i-1] == s2[j-1])
                arr[i][j] = arr[i-1][j-1] + 1;
            else
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            
        }
    }*/
    for(int i=1;i<n1+1;i++)
    {
        for(int j=1; j<n2+1;j++)
        {
            if(s1[i-1] == s2[j-1])
                arr[1][j] = arr[0][j-1]+1;
            else
                arr[1][j] = max(arr[0][j], arr[1][j-1]);
        }
        for(int k =1; k<n2+1;k++)
            arr[0][k] = arr[1][k];
    }
    return arr[1][n2];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
