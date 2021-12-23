#ifndef FILTER_H
#define FILTER_H
#include<vector>
using namespace std;

class Filter {
	//This class stores pairs of bits positions
	//and using a for-each loop, uses each bit pair
	//to preform bitwise encryption
private:
	vector < pair<int, int>> bit_pairs;
public:
	Filter() {
		this->bit_pairs = vector < pair<int, int>>();
	};
	bool setBit_pairs(int, int);
	//returns true if the pair has been added to internal vector
	//returns false if the pair cannot be added

	void removeBit_pairs(int, int);
	//lacks return value because if the pair doesn't exist in the
	//vector: mission accomplished whether it was there to begin with

	vector<pair<int, int>> getBit_pairs() { return bit_pairs; };


	int swapBits(int, int, int);
	char encrypt(char);

};
#endif // !'FILTER_H'
