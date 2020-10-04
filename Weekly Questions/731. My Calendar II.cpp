// Question Link ---> https://leetcode.com/problems/my-calendar-ii/

class MyCalendarTwo {
private:
    vector<vector<int>> singleBookings, doubleBookings;
public:
    MyCalendarTwo() {}
    bool book(int start, int end) {
        vector<int> currentPair = {start, end - 1};
        // If current overlaps within double booked, return false directly 
        for (vector<int> &doubleBooking : doubleBookings) {
            if (doesOverlap(doubleBooking, currentPair)) {
                return false;
            }
        }
        // Update single and double bookings
        for (vector<int> &singleBooking : singleBookings) {
            if (doesOverlap(singleBooking, currentPair)) {
                doubleBookings.push_back({max(singleBooking[0], currentPair[0]), min(singleBooking[1], currentPair[1])});
            }
        }
        singleBookings.push_back({currentPair[0], currentPair[1]});
        return true;
    }
 
    // Check if two ranges overlap
    bool doesOverlap(vector<int> &existedPair, vector<int> &incomingPair) {
        return (incomingPair[0] <= existedPair[1] && incomingPair[1] >= existedPair[0]);
    }
};