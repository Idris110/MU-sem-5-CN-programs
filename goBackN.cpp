#include <bits/stdc++.h>
#include <ctime>
#define ll long long int
using namespace std;

void printWind(ll k, ll winSize, ll frames){
    for(int i=k; i<k+winSize && i<frames; i++)
        cout << "Sending Frame " << i+1 << "..." << endl;
}

int  transmission(ll &winSize, ll &frames)
{
    int i = 0, totalFramesSent= winSize;
    printWind(0, winSize, frames);

    while (i < frames)
    {
        int z = 0;
        for (int k = i; k < i + winSize && k < frames; k++)
        {
            int f = rand() % 4;
            bool rand = (f<1) ? false : true;
            
            if (rand) // 75% chance
            {
                cout << "-Acknowledgment for Frame " << k+1 << "..." << endl;
                
                if(k+winSize <frames)
                cout << "Sending Frame " << k+1+winSize << "..." << endl;
                totalFramesSent++;
                z++;
            }
            else
            {
                cout << "#Timeout!! Frame Number : " << k+1 << " Not Received" << endl;
                cout << "#Retransmitting Window..." << endl;
                printWind(k, winSize, frames); //go back N
                totalFramesSent += winSize;
                break;
            }
        }
        cout << "\n";
        i = i + z;
    }
    return totalFramesSent;
}

int main()
{
    ll frames, winSize;
    srand(time(NULL));
    cout << "Enter the Total number of frames : ";
    cin >> frames;
    cout << "Enter the Window Size : ";
    cin >> winSize;
    int totalFramesSent= transmission(winSize, frames);
    cout << "Total number of frames which were sent and resent are : " << totalFramesSent << endl;
    return 0;
}