// Leetcode problem 3508 -> Implement Router
#include <bits/stdc++.h>
using namespace std;

struct Packet
{
    int source;
    int destination;
    int timestamp;

    bool operator<(const Packet &other) const
    {
        return source < other.source ||
               (source == other.source && destination < other.destination) ||
               (source == other.source && destination == other.destination &&
                timestamp < other.timestamp);
    }
};

class Router
{
public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp)
    {
        const Packet packet{source, destination, timestamp};
        if (uniquePackets.find(packet) != uniquePackets.end())
            return false;
        if ((int)packetQueue.size() == memoryLimit)
            forwardPacket();
        packetQueue.push(packet);
        uniquePackets.insert(packet);
        destinationTimestamps[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket()
    {
        if (packetQueue.empty())
            return {};
        const Packet nextPacket = packetQueue.front();
        packetQueue.pop();
        uniquePackets.erase(nextPacket);
        ++processedPacketIndex[nextPacket.destination];
        return {nextPacket.source, nextPacket.destination, nextPacket.timestamp};
    }

    int getCount(int destination, int startTime, int endTime)
    {
        if (destinationTimestamps.find(destination) == destinationTimestamps.end())
            return 0;
        const vector<int> &timestamps = destinationTimestamps[destination];
        const int startIndex = processedPacketIndex[destination];
        const auto lowerBound = lower_bound(timestamps.begin() + startIndex,
                                            timestamps.end(), startTime);
        const auto upperBound = upper_bound(timestamps.begin() + startIndex,
                                            timestamps.end(), endTime);
        return upperBound - lowerBound;
    }

private:
    const int memoryLimit;
    set<Packet> uniquePackets;
    queue<Packet> packetQueue;
    map<int, vector<int>> destinationTimestamps;
    map<int, int> processedPacketIndex;
};

int main()
{
    Router router(2); // memory limit 2 packets

    // Add packets
    router.addPacket(1, 100, 10);
    router.addPacket(2, 100, 12);
    router.addPacket(1, 101, 15); // triggers forward of first packet (memory full)

    // Forward a packet manually
    vector<int> fwd = router.forwardPacket();
    if (!fwd.empty())
        cout << "Forwarded Packet: " << fwd[0] << " -> " << fwd[1]
             << " at " << fwd[2] << endl;

    // Count packets to destination 100 between timestamp 10 and 15
    int count = router.getCount(100, 10, 15);
    cout << "Packets to destination 100 from t=10 to t=15: " << count << endl;

    // Count packets to destination 101
    count = router.getCount(101, 10, 20);
    cout << "Packets to destination 101 from t=10 to t=20: " << count << endl;

    return 0;
}

/*
TC: O(1)
SC: O(∣addPacket(source: int, destination: int, timestamp: int)∣)
*/