#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Activity {
    int start;
    int finish;
};

bool activityCompare(Activity a, Activity b) {
    return (a.finish < b.finish);
}

void generateRandomActivities(Activity activities[], int n) {
    srand(time(0)); 

    for (int i = 0; i < n; ++i) {
        activities[i].start = rand() % 24;
        activities[i].finish = activities[i].start + rand() % (24 - activities[i].start); // Random finish time after start time
    }
}

void printMaxActivities(Activity activities[], int n) {
    sort(activities, activities + n, activityCompare);

    cout << "The following activities are selected:\n";

    int i = 0;
    cout << "(" << activities[i].start << ", " << activities[i].finish << "), ";

    for (int j = 1; j < n; j++) {
        if (activities[j].start >= activities[i].finish) {
            cout << "(" << activities[j].start << ", " << activities[j].finish << "), ";
            i = j;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    Activity activities[n]; 

    generateRandomActivities(activities, n); 

    cout << "Randomly generated activities:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Activity " << i + 1 << ": (" << activities[i].start << ", " << activities[i].finish << ")\n";
    }

    printMaxActivities(activities, n); 
    return 0;
}