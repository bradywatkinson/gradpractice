// given an unsorted array of pairs of entry times
// and exit times, find the period of time when the most
// people are in the room, and the amount of people in the
// room at that time

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Range
{
	public:
		double entry,exit;
};

class Occupancy
{
	public:
		int people;
		Range range;
};

vector<Range> ranges;

Occupancy find_max () {


	vector<Range> entries(ranges);
	sort(entries.begin(),entries.end(),[](const Range &a, const Range &b){ return a.entry < b.entry; });

	vector<Range> exits(ranges);
	sort(exits.begin(),exits.end(),[](const Range &a, const Range &b){ return a.exit < b.exit; });

	int max=0;
	int j=0;
	int earliest_entrant = 0;
	int count = 0;

	Occupancy o;

	for (int i=0;i<exits.size();++i) {

		while (entries[j].entry < exits[i].exit) {
			++count;
			++j;
		}

		if (count > max) {
			o.range.entry = entries[earliest_entrant].entry;
			o.range.exit  = exits[i].exit;
			o.people 	  = count;
		}

		if (exits[i].entry == earliest_entrant) {
			// ++earliest_entrant;
			while (exits[earliest_entrant].exit < exits[i].exit) {
				++earliest_entrant;
			}
		} 
		--count;
	}


	return o;
}

int main () {

	Range p1,p2,p3,p4,p5,p6,p7,p8;
	p1.entry = 3.5;
	p1.exit  = 7.6;

	p2.entry = 1.1111;
	p2.exit  = 2.5;

	p3.entry = 3.4;
	p3.exit  = 6.777;

	p4.entry = 2.446;
	p4.exit  = 4.567;

	p5.entry = 3.4;
	p5.exit  = 5.7777;

	p6.entry = 3.00001;
	p6.exit  = 5.111;

	p7.entry = 4;
	p7.exit  = 6;

	p8.entry = 2;
	p8.exit  = 2.7;

	ranges.push_back(p1);
	ranges.push_back(p2);
	ranges.push_back(p3);
	ranges.push_back(p4);
	ranges.push_back(p5);
	ranges.push_back(p6);
	ranges.push_back(p7);
	ranges.push_back(p8);

	Occupancy o = find_max();

	cout << o.range.entry << " " << o.range.exit << " " << o.people << endl;

	return 0;
}