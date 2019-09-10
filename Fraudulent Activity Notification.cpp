#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
int main() {
    int n, d;
    cin >> n >> d;
    vector<int> nums (n,0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    deque<int> win(nums.begin(), nums.begin()+d);
    sort (win.begin(), win.end());
    bool isodd = (d%2 != 0);
    int alerts = 0;
    
    for (int i=d; i < n; i++) {
        double median;
        if (isodd) {
            median = win[win.size()/2];
        } else {
            median = (double) (win[(win.size()/2)-1] + win[win.size()/2])/2.0f;
        }
        if (nums[i] >= 2.0f*median) {
            alerts++;
        }
        auto old = lower_bound (win.begin(), win.end(), nums[i-d]);
        win.erase(old);
        auto cur = upper_bound (win.begin(), win.end(), nums[i]);
        win.insert (cur, nums[i]);
    }
    
    cout << alerts << endl;
    
    return 0;
}
// Complete the activityNotifications function below.
/*int activityNotifications(vector<int> a, int d) {

    long notif = 0;
    long beg = 0;
    int ind1, ind2;
    if(d%2 != 0)
        ind1 = d/2;
    else
    {   ind1 = d/2; ind2 = ind1 -1;
    }
    float val;
    for(int i = d; i<a.size(); i++)
    {
        vector<int> b(a.begin()+beg, a.begin()+beg+d);
        sort(b.begin(), b.end());
        if(d%2 != 0)
        {   val = b[ind1];
        }
        else
            val = (b[ind1]+b[ind2])/2.0;
        if(a[i] >= 2*val){
            notif++;}
        beg++;
    }
    return notif;
}

int activityNotifications(vector<int> a, int d)
{
    long notif = 0;
    deque<int> q(a.begin(), a.end());
    sort(q.begin(), q.end());
    int ind1, ind2;
    int isOdd = (d%2 != 0);
    if(isOdd)
        ind1 = d/2;
    else
    {   ind1 = d/2; ind2 = ind1 -1;
    }
    float median;
    deque<int>::iterator lb, ub;
    for(int i=d; i<a.size();i++)
    {
        if(isOdd)
            median = q[ind1];
        else
            median = (q[ind1]+q[ind2])/2.0;
        
        if(a[i] >= 2*median)
            notif++;
        lb = lower_bound(q.begin(), q.end(), a[i-d]);
        q.erase(lb);
        ub = lower_bound(q.begin(), q.end(), a[i]);
        q.insert(ub, a[i]);
    }
    return notif;
}*/

/*
float getMedian(queue<int> q, int freq[201],int  d)
{
    int cnt = 0;
    if(d%2 != 0)
    {
        for(int i=0;i<201;i++)
        {
            cnt += freq[i];
            if(cnt > d/2)
                return i;
            //cout<<endl<<i;
        }
        //cout<<endl<<cnt<<"::"<<d;
    }
    else
    {
        int f = -1, s;
        for(int i = 0;i<201; i++)
        {
            cnt += freq[i];
            if(cnt == d/2)
                f = i;
            else if(cnt > d/2)
            {
                if(f<0) f = i;
                s = i;
                return (f+s)/2.0;
            }
        }
    }
    return 0;
}

int activityNotifications(vector<int> a, int d) {
    
    long notif = 0;
    int freq[201] = {0};
    queue<int> q;
    for(int i=0;i<a.size();i++)
    {
        while(i<d)
        {
            q.push(a[i]);
            freq[a[i]] += 1;
            i++;
        }
        
        float median = getMedian(q, freq, d);
        
        if(a[i] >= 2*median)
        {
            //cout<<endl<<a[i]<<" "<<median;
            notif++;
        }
        
        int elem = q.front(); q.pop();
        freq[elem] -= 1;
        
        q.push(a[i]);
        freq[a[i]] += 1;
    }
    return notif;
}*/

/*
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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
*/