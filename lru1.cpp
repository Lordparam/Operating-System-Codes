#include<iostream>
using namespace std;
int main(){
    vector<int> page = {4,7,6,1,7,6,1,2,7,2};
    unordered_map<int,int> lastUsed;
    int capacity = 3;
    int frames[] = {-1,-1,-1};
    int n = page.size();
    int time = 0;
    int hits = 0;
    int miss = 0;

for(int i=0;i<n;i++) {
    int curPage = page[i];
    bool hit = false;
    time++;

        for(int j=0;j<capacity;j++) {
            if(frames[j]==curPage) { //if found
            hit = true;
            hits++;
            lastUsed[curPage]=time;
            break;
            }
        }

        if(!hit) {
            //search for empty frame
            miss++;
            int j;

            for(j=0;j<capacity;j++) {
                if(frames[j]==-1) {
                    frames[j]= curPage;
                    lastUsed[curPage] = time;
                    break;
                }
            }

            //no empty frame found now implement LRU
        if(j==capacity) {
                int least = time;
                int pos = 0;
                    for(int k = 0; k < capacity; k++) {
                        if(lastUsed[frames[k]] < least) {
                            least = lastUsed[frames[k]];
                            pos = k;
                        }
                    }
                frames[pos] = curPage;
                lastUsed[curPage] = time;
        }

    }
}
        for(int j = 0; j < capacity; j++) {
            cout << frames[j] << " ";
        }
        cout << "Number of hits : " << hits << endl;
        cout << "Number of misses : " << miss << endl;
    return 0;
}