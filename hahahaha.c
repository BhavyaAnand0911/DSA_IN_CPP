#include <bits/stdc++.h>

long long minimumCost(int k, int n, std::vector<int> &depots)
{
    std::sort(depots.begin(), depots.end()); // Sort the depots in ascending order

    long long totalCost = 0;
    int currentIndex = 0;

    while (currentIndex < n)
    {
        int remainingDepots = n - currentIndex;
        int packetsToCarry = std::min(k, remainingDepots);
        int startDepot = depots[currentIndex];
        int endDepot = depots[currentIndex + packetsToCarry - 1];

        long long distance = endDepot - startDepot;
        totalCost += (distance * 5);

        currentIndex += packetsToCarry;
    }

    return totalCost;
}

int main()
{
    int k, n;
    std::cin >> k >> n;

    std::vector<int> depots(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> depots[i];
    }

    long long cost = minimumCost(k, n, depots);
    std::cout << cost << std::endl;

    return 0;
}
