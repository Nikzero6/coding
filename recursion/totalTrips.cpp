#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define ll long long

long long minimumTime(vector<int> &time, int totalTrips)
{
    sort(time.begin(), time.end());
    vector<ll> time_copy(time.size());
    for (int i = 0; i < time.size(); i++)
        time_copy[i] = time[i];

    ll curr_sum = 0;
    ll i = 0;
    ll minTime = 0;
    while (curr_sum < totalTrips)
    {
        while (i == time.size() - 1 || time_copy[i] <= time_copy[i + 1])
        {
            int minTime_copy = minTime;
            minTime = max(minTime, time_copy[i]);
            curr_sum += 1;
            if (curr_sum >= totalTrips)
                break;
            time_copy[i] += time[i];
            if (minTime_copy != minTime)
                i = 0;
        }
        i++;
    }
    return time_copy[0];
}
int main()
{
    int n;
    cin >> n;
    vector<int> time(n);
    for (int i = 0; i < n; i++)
        cin >> time[i];

    int totaltrips;
    cin >> totaltrips;

    cout << minimumTime(time, totaltrips);

    return 0;
}
