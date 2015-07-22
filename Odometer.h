#include <iostream>
#include <set>
#define SIZE_MIN 2
#define SIZE_MAX 8

typedef int Reading;

class Odometer{
private:
	std::set<int> oset[SIZE_MAX + 1];
	
	int get_size(int r);
public:
	
//	int diff_between_readings(Reading r1, Reading reading2);
//	void print_readings(Reading r);
//	int total_no_of_reading(Reading r);
	int next_reading(int r);
	int reading_after(int current, int n);
	int prev_reading(int current);

	void build();

	bool is_valid(int r);
};

