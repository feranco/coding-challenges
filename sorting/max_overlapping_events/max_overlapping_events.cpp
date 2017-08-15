//algorithm to find the maximum number ov everlapping events in a time slot
//Assumptions:
//start and end time are given for each interval

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Event {
	int start_time, end_time;
};

struct EventBoundary {
	int time;
	bool is_start;
	bool operator<(const EventBoundary& rhs) const{
		if (time != rhs.time) return time < rhs.time;
		if (time == rhs.time && is_start) return true;
		else return false;
	}
};

int findMaxOverlappingEvents (const vector<Event>& events) {
	vector<EventBoundary> boundaries;
	for (auto event : events) {
		boundaries.emplace_back(EventBoundary{event.start_time, true});
		boundaries.emplace_back(EventBoundary{event.end_time, false});
	}
	
	sort(boundaries.begin(), boundaries.end());
	int max_events = 0, cnt_events = 0;
	
	for (auto boundary : boundaries) {
		if (boundary.is_start) ++cnt_events;
		else --cnt_events;
		max_events = max(max_events,cnt_events);
	}
	
	return max_events;
}

int main (void) {
  vector<Event> events{{1,15},{6,10},{11,13},{14,15},{3,7},{8,9},{12,15},{4,5},{9,17}};
  cout << findMaxOverlappingEvents(events);
}
