#include <bits/stdc++.h>
using namespace std;

bool isPossible(int numTests, int numQuestions, vector<int>& timeArr, long long int maxDuration) {
    int dayCount = 1;
    long long int timeCount = 0;

    for (int i = 0; i < numQuestions; i++)
        if (timeCount + timeArr[i] <= maxDuration)
            timeCount += timeArr[i];
        else {
            dayCount++;
            if (dayCount > numTests || timeArr[i] > maxDuration)
                return false;
            else
                timeCount = timeArr[i];
        }
    return true;
}

long long int ayushGivesNinjatest(int numTests, int numQuestions, vector<int>& timeArr) {
    long long int startDuration = 0;
    long long int totalDuration = accumulate(timeArr.begin(), timeArr.end(), 0LL);

    long long int endDuration = totalDuration;
    long long int minPossibleDuration = -1;

    while (startDuration <= endDuration) {
        long long int midDuration = startDuration + (endDuration - startDuration) / 2;
        if (isPossible(numTests, numQuestions, timeArr, midDuration)) {
            minPossibleDuration = midDuration;
            endDuration = midDuration - 1;
        } else
            startDuration = midDuration + 1;
    }
    return minPossibleDuration;
}
