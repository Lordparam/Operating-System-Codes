#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> pages = {4,7,6,1,7,6,1,2,7,2};

    int n = pages.size();
    int hits = 0;
    int miss = 0;

    int frames[3] = {-1,-1,-1};
    int capacity = 3;

    for(int i = 0; i < n; i++) {

        int curPage = pages[i];
        bool hit = false;

        // Check page hit
        for(int j = 0; j < capacity; j++) {
            if(frames[j] == curPage) {
                hit = true;
                hits++;
                break;
            }
        }

        if(!hit) {
            miss++;

            int j;

            // Check for empty frame
            for(j = 0; j < capacity; j++) {
                if(frames[j] == -1) {
                    frames[j] = curPage;
                    break;
                }
            }

            // If no empty frame, apply Optimal
            if(j == capacity) {

                int pos = 0;
                int farthest = 0;

                for(int k = 0; k < capacity; k++) {

                    int cur = i + 1;

                    // Search for the page in future
                    while(cur < n && pages[cur] != frames[k]) {
                        cur++;
                    }

                    // Page will never be used again
                    if(cur == n) {
                        pos = k;
                        break;
                    }

                    // Find the farthest future occurrence
                    if(cur > farthest) {
                        farthest = cur;
                        pos = k;
                    }
                }

                // Replace the selected page
                frames[pos] = curPage;
            }
        }

        // Print frames after each iteration
        cout << "Page " << curPage << " : ";

        for(int j = 0; j < capacity; j++) {
            cout << frames[j] << " ";
        }

        if(hit)
            cout << "  Hit";
        else
            cout << "  Miss";

        cout << endl;
    }

    cout << "\nTotal Hits = " << hits << endl;
    cout << "Total Page Faults = " << miss << endl;

    return 0;
}