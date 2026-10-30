#include<iostream>
using namespace std;
int main(){
int pages[] = {1, 2, 3, 1, 4, 2, 5};
int n = 7;
int capacity = 3;
int frames[3] = {-1, -1, -1};
int lastUsed[3] = {0, 0, 0};
int pageFaults = 0;
int time = 0;
for (int i = 0; i < n; i++){
    int page = pages[i];
    bool found = false;
    // Step 1: Check whether page is already present
    for (int j = 0; j < capacity; j++){
        if (frames[j] == page){
            found = true;
            lastUsed[j] = ++time;  // record the time 
            break;
        }
    }
    // Step 2: If page is not present, page fault
    if (!found) {
        pageFaults++;
        int replaceIndex = -1;
        // Step 3: Search for an empty frame
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == -1) {
                replaceIndex = j;
                break;
            }
        }
        // Step 4: If no empty frame, find LRU page
        if (replaceIndex == -1) {
            replaceIndex = 0;
            for (int j = 1; j < capacity; j++) {
                if (lastUsed[j] < lastUsed[replaceIndex]) {
                    replaceIndex = j;
                }
            }
        }
        // Step 5: Insert/replace page
        frames[replaceIndex] = page;
        lastUsed[replaceIndex] = ++time;
    }
    // Display frames
    cout << "Page " << page << " : ";
    for (int j = 0; j < capacity; j++) {
        cout << frames[j] << " ";
    }
    cout << endl;
}
cout << "\nTotal Page Faults: " << pageFaults;
    return 0;
}

// 1.init all page frames to -1
// 2.init a page fault counter with 0
// 3.read each page from the reference sequence
// 4.check whether the page is already present in the frames. if yes then it is a page hit
// 5.if not, then it is a page fault and increase page dafault counter by 1
// 6.search for a frame to assign this page to it
// 7.otherwise, search for a page which is least recently used in the memory frames and replace it with current page.
// 8.increment the time of the newly inserted page 
// 9.repeat until all pages are not processed.