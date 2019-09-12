#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

class MinHeap
{
    public:
        int *arr;
        int n;
        MinHeap(int size)
        {
            arr = new int[size];
            n = 0;
        }

        int parent(int i)
        {
            return (i-1)/2;
        }

        int left(int i)
        {
            return (2*i + 1);
        }

        int right(int i)
        {
            return (2*i + 2);
        }

        void swap(int *x, int *y)
        {
            int temp = *x;
            *x = *y;
            *y = temp;
        }

        void insertKey(int k)
        {
            n++;
            int i = n - 1;
            arr[i] = k;
            while( i != 0 && arr[parent(i)] > arr[i] )
            {
                swap(&arr[i], &arr[parent(i)]);
                i = parent(i);
            }
        }

        void MinHeapify(int i)
        {
            int l = left(i);
            int r = right(i);
            int smallest = i;
            if( l < n && arr[l] < arr[i])
                smallest = l;
            if( r < n && arr[r] < arr[smallest])
                smallest = r;
            if( smallest != i)
            {
                swap(&arr[i], &arr[smallest]);
                MinHeapify(smallest);
            }
        }

        void decreaseKey(int i, int new_val)
        {
            arr[i] = new_val;
            while( i != 0 && arr[parent(i)] > arr[i])
            {
                swap(&arr[i], &arr[parent(i)]);
                i = parent(i);
            }
        }

        int extractMin()
        {
            if( n <= 0 )
                return INT_MAX;
            if( n == 1)
            {
                n--;
                return arr[0];
            }

            int root = arr[0];
            arr[0] = arr[n-1];
            n--;
            MinHeapify(0);

            return root;
        }

        void deleteKey(int i)
        {
            decreaseKey(i, INT_MIN);
            extractMin();
        }

        int getSize()
        {
            return n;
        }

        int getMin()
        {
            return arr[0];
        }
        
};


int cookies(int k, vector<int> A) {

    int n = A.size();
    MinHeap h(n);
    for(int i = 0; i < n; i++)
        h.insertKey(A[i]);
    
    //for(int i = 0; i < n; i++)
     //   cout<<h.arr[i]<<" ";
    int count = 0;
    while(h.getMin() < k  && h.getSize() > 1)
    {
        int smallest = h.extractMin();
        int next_smallest = h.extractMin();
        int special = smallest + 2*next_smallest;
        h.insertKey(special);
        count++;
    }
    if(h.getMin() < k)
        return -1;
  
  return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split_string(A_temp_temp);

    vector<int> A(n);

    for (int A_itr = 0; A_itr < n; A_itr++) {
        int A_item = stoi(A_temp[A_itr]);

        A[A_itr] = A_item;
    }

    int result = cookies(k, A);

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
