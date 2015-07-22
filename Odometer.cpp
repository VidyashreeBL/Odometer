#include "Odometer.h"

using namespace std;

typedef int Reading;

//int Odometer::reading_length(Reading r) {
//	int length = 0;
//	while(r) {
//		length++;
//		r = r/10;
//	}
//	return length;
//}

bool Odometer::is_valid(int r) {
	int prev_digit = 10;
	int len = 0;
	for(len = 0; r > 0; ++len, r = r/10) {
		int cur_digit = r%10;
		if (cur_digit >= prev_digit || cur_digit == 0)
			return false;
		prev_digit = cur_digit;
	}
	return (len >= SIZE_MIN && len <= SIZE_MAX);
}

int Odometer::get_size(int r) {
	int size = 0;
	while(r) {
		size++;
		r = r/10;
	}
}

int Odometer::next_reading(int current){
	if(!is_valid(current))
		return -1;
	set<int>::iterator it;
	int size = get_size(current);
	it = oset[size].find(current);
	it++;
	if(it == oset[size].end())
		return *(oset[size].begin());
	else
		return *it;
}

int Odometer::prev_reading(int current){
	if(!is_valid(current))
		return -1;
	set<int>::iterator it;
	int size = get_size(current);
	it = oset[size].find(current);
	if(it == oset[size].begin())
		return *(--oset[size].end());
	else
		return *(++it);
}

int Odometer::reading_after(int current, int steps){
	if(!is_valid(current))
		return -1;
	set<int>::iterator it;
	int size = get_size(current);
	it = oset[size].find(current);
	for (int i = 0; i < steps%oset[size].size(); ++i) {
		it++;
		if(it == oset[size].end())
			it = oset[size].begin();
	}
	return *it;
}

void Odometer::build() {
	for (int size = 8; size <= SIZE_MAX; ++size) {
		int first_elem = 0;
		int last_elem = 0;
		for(int j = 0; j < size; ++j) {
			first_elem = first_elem*10 + j + 1;
			last_elem = last_elem*10 + 9;
		}
		
		for(int i = first_elem; i <= last_elem; ++i) {
			if(is_valid(i) ){
				oset[size].insert(i);
				cout << i << endl; 
			}
		}
		
	}
}


int main(){
   Odometer o;
   o.build();
}

