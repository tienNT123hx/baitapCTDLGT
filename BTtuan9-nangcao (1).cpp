#include <iostream>
#include <vector>

using namespace std;

int josephus(int n, int k, int start = 0, bool clockwise = true) {
    if (n <= 0 || k <= 0) {
        throw invalid_argument("Invalid parameters: n and k must be positive integers");
    }

    vector<int> people(n);
    for (int i = 0; i < n; i++) {
        people[i] = i;
    }

    int position = start;
    while (people.size() > 1) {
        for (int i = 0; i < k - 1; i++) {
            if (clockwise) {
                position = (position + 1) % people.size();
            } else {
                position = (position - 1 + people.size()) % people.size();
            }
        }

        people.erase(people.begin() + position);
    }

    return people[0];
}

int main() {
    int n;  
    int k;  
    int start = 0;  
    bool clockwise = true; 

    cout << "Enter the total number of people: ";
    cin >> n;

    cout << "Enter the counting interval (every k-th person is removed): ";
    cin >> k;

    cout << "Enter the starting position (optional, default: 0): ";
    cin.ignore();  
    if (cin >> start) {
        cout << "Enter the direction of execution (clockwise or counterclockwise, optional, default: clockwise): ";
        cin >> clockwise;
    }

    int victorPosition = josephus(n, k, start, clockwise);
    cout << "The victor is at position " << victorPosition << endl;

    return 0;
}
