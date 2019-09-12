#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the truckTour function below.
 */
int truckTour(vector<vector<int>> petrolpumps) {
    
    /*int n = petrolpumps.size(), flag, index, sum;
    for(int i = 0; i < n; i++)
    {
        flag = 0;
        sum = 0;
        for(int j = 0; j < n; j++ )
        {
            index = (i+j)%n;
            if(petrolpumps[index][0] - petrolpumps[index][1] + sum < 0 )
            {   flag = 1;
                break;
            }
            sum += petrolpumps[index][0] - petrolpumps[index][1];
        }
        if(flag == 0)
            return i;
    }*/

    int start = 0, passed = 0, gas = 0;
    int n = petrolpumps.size(), i = 0;
    vector<int> pump;
    while( passed < n )
    {
        gas += petrolpumps[i][0];
        pump = petrolpumps[i];
        if(gas >= petrolpumps[i][1])
        {   passed += 1;
            gas -= petrolpumps[i][1];
        }
        else
        {   start += (passed + 1);
            gas = 0;
            passed = 0;
        }
        //petrolpumps.push_back(pump);
        //petrolpumps.erase(petrolpumps.begin());
        i = (i+1)%n;
    }

    return start;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> petrolpumps(n);
    for (int petrolpumps_row_itr = 0; petrolpumps_row_itr < n; petrolpumps_row_itr++) {
        petrolpumps[petrolpumps_row_itr].resize(2);

        for (int petrolpumps_column_itr = 0; petrolpumps_column_itr < 2; petrolpumps_column_itr++) {
            cin >> petrolpumps[petrolpumps_row_itr][petrolpumps_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = truckTour(petrolpumps);

    fout << result << "\n";

    fout.close();

    return 0;
}
