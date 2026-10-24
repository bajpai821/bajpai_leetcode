#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    // Days in each month for a non-leap year
    const std::vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Helper function to convert "MM-DD" to the absolute day of the year (1-365)
    int dateToDayOfYear(const std::string& date) {
        int month = std::stoi(date.substr(0, 2));
        int day = std::stoi(date.substr(3, 2));
        
        // Sum up the days of all previous months
        int dayCount = 0;
        for (int i = 0; i < month - 1; ++i) {
            dayCount += months[i];
        }
        
        return dayCount + day;
    }

public:
    int countDaysTogether(std::string arriveAlice, std::string leaveAlice, std::string arriveBob, std::string leaveBob) {
        // Convert all input dates to absolute day numbers
        int aliceStart = dateToDayOfYear(arriveAlice);
        int aliceEnd = dateToDayOfYear(leaveAlice);
        int bobStart = dateToDayOfYear(arriveBob);
        int bobEnd = dateToDayOfYear(leaveBob);
        
        // Find the intersection window
        int overlapStart = std::max(aliceStart, bobStart);
        int overlapEnd = std::min(aliceEnd, bobEnd);
        
        // Calculate overlapping days
        if (overlapStart <= overlapEnd) {
            return overlapEnd - overlapStart + 1;
        }
        
        return 0;
    }
};
