/*
while (cin >> n && n != -1)
{
    prev_t = 0
    total_dist = 0

    for i = 1 to n:
        cin >> s >> t
        total_dist += s * (t - prev_t)
        prev_t = t

    cout << total_dist << " miles\n"
}

*/

#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main()
{
    while(cin >> n && n != -1)
    {
        
        int prev_t = 0;
        int total_dist = 0;

        for(int i=0;i<n;i++)
        {
            int s, t;
            cin >> s >> t;

            total_dist += s * (t - prev_t);
            prev_t = t;
        }
          cout << total_dist << " miles\n";
    }
  
}
