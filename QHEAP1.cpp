#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

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

int BSearch(int val, MinHeap h)
{
    int l = 0;
    int n = h.n;
    while(l <= n)
    {
        int mid = (l + (n-l))/2;
        if(h.arr[mid] == val)
            return mid;
        else if( h.arr[mid] > val )
            n = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}

int Search(int val, MinHeap h)
{
    int n = h.n;
    for(int i = 0; i < n; i++)
        if(h.arr[i] == val)
            return i;
    return -1;
}


int main() {
    
    int q, n, val;
    cin >> q;

    MinHeap h(q);
    int ind;
    vector<int> last_del;
    while( q-- )
    {
        cin >> n;
        if( n == 1)
        {
            cin >> val;
            h.insertKey(val);
        }
        else if( n == 2 )
        {
            cin >> val;
            //last_del.push_back(val);
            ind = Search(val, h);
            //cout<<"ind:"<<ind;
            if(ind != -1)
                h.deleteKey(ind);
        }
        else
        {
            /*for(int i = 0; i < last_del.size(); )
            {
                if(last_del[i] == h.getMin())
                {
                    h.extractMin();
                    last_del.erase(last_del.begin() + i);
                    continue;
                }
                i++;
            }*/
            cout<<h.getMin()<<endl;
        }
        /*cout<<endl<<"n::"<<n<<endl;
        for(int i = 0; i < h.n; i++)
            cout<<h.arr[i]<<" ";
        cout<<endl;*/
    }

    return 0;
}
