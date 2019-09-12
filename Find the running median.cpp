#include <bits/stdc++.h>

using namespace std;


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void runningMedian(vector<int> a) {
    
    int n = a.size();
    
    priority_queue<float> s; //max heap
    priority_queue<float, vector<float>, greater<float> > g;

    float elem = a[0];
    float median = elem, x;
    s.push(elem);

    printf("%0.1f\n", median);
    for(int i = 1; i < n; i++)
    {
        x = a[i];
        if( s.size() > g.size())
        {
            if(x < median)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);
            median = (s.top() + g.top())/2.0;
        }
        else if( s.size() == g.size())
        {
            if( x < median )
            {
                s.push(x);
                median = s.top();
            }
            else
            {
                g.push(x);
                median = g.top();
            }
        }
        else
        {
            if( x > median )
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
                s.push(x);
            median = (s.top() + g.top())/2.0;
        }

        printf("%0.1f\n", median);
    }
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }

    //vector<double> result = 
    runningMedian(a);

    /*
    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }
    */
    //fout << "\n";

    //fout.close();

    return 0;
}
