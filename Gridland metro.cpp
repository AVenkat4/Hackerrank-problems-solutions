#include <bits/stdc++.h>

using namespace std;

typedef long long int llint;

struct interval
{
    int start, end;
};

vector<string> split_string(string);

bool comparator(interval a, interval b)
{
    return a.start < b.start;
}

// Complete the gridlandMetro function below.
llint gridlandMetro(llint n, llint col, llint k, vector<vector<llint>> track) {

    map<llint, vector<interval> > m;
    //map<llint, stack<interval> > m;
    vector<interval> v;
    llint total_sum = (llint)n*(llint)col;
    for(llint i = 0; i < k; i++)
    {
        interval inter;
        inter.start = track[i][1];
        inter.end = track[i][2];
        m[track[i][0]].push_back(inter);
        /*if( m[track[i][0]].empty() )
        {
            m[track[i][0]].push(inter);
        }
        else
        {
            interval top = m[track[i][0]].top();
            interval t;
            if( top.end >= inter.start)
            {   top.end = max(top.end, inter.end);
                m[track[i][0]].pop();
                m[track[i][0]].push(top);
            }
            else
                m[track[i][0]].push(inter);
        }*/
    }

    /*
    //cout<<endl<<"map size::"<<m.size();
    map<llint, stack<interval> >::iterator it;
    interval inter;
    int sum = 0;
    for(it = m.begin(); it != m.end(); it++)
    {
        sum = 0;
        llint row = it->first;
        //cout<<endl << row;
        while(!m[row].empty())
        {
            inter = m[row].top();
            sum += (inter.end - inter.start + 1);
            cout<<endl<<row<<" "<<inter.end<<" "<<inter.start<<" "<<sum;
            m[row].pop();
        }
        //cout<<endl << row<<" "<<sum;
        total_sum -= sum;
        cout << endl << total_sum << " " << sum;
    }*/

    map<llint, vector<interval> >::iterator it;

    for(it = m.begin(); it != m.end(); it++)
    {
        sort(it->second.begin(), it->second.end(), comparator);
        llint row = (it->first) - 1;
        //cout<< endl<< "row "<<row;
        vector<interval> inters = it->second;
        llint size = inters.size();

        stack<interval> s;        
        s.push(inters[0]);
        for(llint i = 1; i < size; i++)
        {
            interval top = s.top();

            if( top.end < inters[i].start)
                s.push(inters[i]);
            else if( top.end <= inters[i].end )
            {
                top.end = inters[i].end;
                s.pop();
                s.push(top);
            }
        }
        
        llint sum = 0;
        interval p;
        while(!s.empty())
        {
            p = s.top();
            sum += (p.end - p.start + 1);
            s.pop();
        }
        //cout<<endl<<row<<" "<<sum;
        total_sum -= sum;
        //if(row > 397843197)
        //cout << endl << total_sum <<" " << sum << " " <<row; 
    }

    return total_sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nmk_temp;
    getline(cin, nmk_temp);

    vector<string> nmk = split_string(nmk_temp);

    llint n = stol(nmk[0]);

    llint m = stol(nmk[1]);

    llint k = stol(nmk[2]);

    vector<vector<llint>> track(k);
    for (llint i = 0; i < k; i++) {
        track[i].resize(3);

        for (llint j = 0; j < 3; j++) {
            cin >> track[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    llint result = gridlandMetro(n, m, k, track);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
