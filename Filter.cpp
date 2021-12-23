#include "Filter.h"
using namespace std;

bool Filter::setBit_pairs(int bit_position_1, int bit_position_2) {
	int max_bit_position = 8 * sizeof(int) - 1;

	//if either value exceeds the max_bit_position, the program returns
	//false because the pair has not been set
	if (bit_position_1 > max_bit_position || bit_position_2 > max_bit_position ||
		bit_position_1 < 0 || bit_position_2 < 0) {
		return false;
	}

	//if both values are within the max_bit_position, they are added to the 
	//bit_pairs vector
	bit_pairs.push_back(pair<int, int>(bit_position_1, bit_position_2));
	return true;
}

void Filter::removeBit_pairs(int bit_position_1, int bit_position_2) {
	pair<int, int> pair_a = { bit_position_1, bit_position_2 },
		pair_b = { bit_position_2, bit_position_1 };
	auto it = this->bit_pairs.begin();
	for (; it < bit_pairs.end(); it++) {
		if (*it == pair_a || *it == pair_b) {
			break;
		}
	}
	this->bit_pairs.erase(it);
}

int Filter::swapBits(int value, int bit_index_1, int bit_index_2) {
	int new_value, mask1, mask2;
	int max_bit_index = 8 * sizeof(int) - 1;
	//use the console's int 

	if (bit_index_1<0 || bit_index_1>max_bit_index ||
		bit_index_2<0 || bit_index_2>max_bit_index)
		return value;

	mask1 = (1 << bit_index_1);
	mask2 = (1 << bit_index_2);

	new_value = value & ~(mask1 | mask2);

	if (value & mask1) new_value |= mask2;
	if (value & mask2) new_value |= mask1;

	return new_value;
}

char Filter::encrypt(char c) {
	int x = c;
	for (pair<int, int>bit_pair : getBit_pairs()) {
		x = swapBits(x, bit_pair.first, bit_pair.second);
	}
	c = x;
	return c;
}