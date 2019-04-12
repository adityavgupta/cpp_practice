//Program to find the maximum number of 0's in a binary representation of a number
#include <stdio.h>
#include <iostream>
using namespace std;

int BinaryGap (int n) {
	int setBit = 1;
	int prev = 0;
	int i;

	//if there are no 1's or just one 1 return -1 
	if(n == 0 || (n & (n-1)) == 0)
		return -1;

	//loop to find the rightmost 1
	for(i = 1; i <= sizeof(n)*8; i++) {
		prev++;

		//to find the rightmost bit
		if ((setBit & n) == setBit) {
			setBit = setBit << 1;
			break;
		}

		//to check next bit
		setBit = setBit << 1;
	}

	int max0 = -1;
	int cur = prev;

	for(int j = i+1; j <= sizeof(n)*8; j++) {
		cur++;
		//current bit set then compare difference of cur-prev-1 with prev number of maximum zeros
		if ((n & setBit) == setBit) { 
			if(max0 < (cur-prev-1)) {
				max0 = cur-prev-1;
			}
			//update prev
			prev = cur;
		}
		setBit = setBit << 1;
	}
	return max0;
}

int main() 
{ 
    int n = 560; 
    // Initially check that number must not 
    // be 0 and power of 2 
    std::cout << BinaryGap(n) << std::endl;
    return 0; 
} 
