#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

//implementation 1
std::vector<int> symmetric_diff(std::vector<int> a, std::vector<int> b) {
	//sort the two vectors
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	//initialize the return vector
	std::vector<int> c;
	int i = 0;
	int j = 0;

	//traverse both
	while(i < a.size() && j < b.size()) {
		if(a[i] < b[j]) {
			c.push_back(a[i]);
			i++;
		}
		else if(b[j] < a[i]) {
			c.push_back(b[j]);
			j++;
		}
		else {
			i++;
			j++;
		}
	}

	return c;
}

//implementation 2
std::vector<int> symmetric_diff_hash(std::vector<int> a, std::vector<int> b) {
	std::vector<int> c;
	std::set<int> s1;
	std::set<int> s2;

	//insert every element of 'a' into set 1
	for(int i = 0; i < a.size(); ++i) {
		s1.insert(a[i]);
	}
	//insert every element of 'b' into set 2
	for(int i = 0; i < b.size(); ++i) {
		s2.insert(b[i]);
	}
	//for every element in 'b' check membership in 'a' by looking at s1
	for(auto elem2 : b) {
		if(s1.find(elem2) == s1.end()){
			c.push_back(elem2);
		}
	}
	//for every element in 'a' check membership in 'b' by looking at s2
	for(auto elem : a) {
		if(s2.find(elem) == s2.end()) {
			c.push_back(elem);
		}
	}
	return c;
}


//other useful functions
std::vector<int> custom_union(std::vector<int> a, std::vector<int> b) {
	std::vector<int> c;
	std::set<int> union_hash;
	for(int i = 0; i < a.size(); ++i) {
		union_hash.insert(a[i]);
	}
	for(int i = 0; i < b.size(); ++i) {
		union_hash.insert(b[i]);
	}
	for(auto it = union_hash.begin(); it != union_hash.end(); ++it) {
		c.push_back(*it);
	}
	return c;
}

std::vector<int> custom_intersection(std::vector<int> a, std::vector<int> b) {
	std::vector<int> c;
	std::set<int> intersection_hash;
	for(int i = 0; i < a.size(); ++i) {
		intersection_hash.insert(a[i]);
	}
	for(int i = 0; i < b.size(); ++i) {
		if (intersection_hash.find(b[i]) != intersection_hash.end()) {
			c.push_back(b[i]);
		}
	}
	return c;
}


int main() {
	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	std::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(5);

	std::vector<int> ret = symmetric_diff(v1, v2);
	std::vector<int> ret2 = custom_union(v1, v2);
	std::vector<int> ret3 = custom_intersection(v1, v2);
	std::vector<int> ret4 = symmetric_diff_hash(v1, v2);

	std::cout<< "symmetric diff: " << std::endl;
	for(int i = 0; i < ret.size(); i++) {
		std::cout << ret[i] << " ";
	}
	std::cout <<"" <<std::endl;

	std::cout<< "symmetric diff using hashing: " << std::endl;
	for(int i = 0; i < ret4.size(); i++) {
		std::cout << ret4[i] << " ";
	}
	std::cout <<"" <<std::endl;

	std::cout<< "union: " << std::endl;
	for(int i = 0; i < ret2.size(); i++) {
		std::cout << ret2[i] << " ";
	}
	std::cout <<"" <<std::endl;

	std::cout<< "intersection: " << std::endl;
	for(int i = 0; i < ret3.size(); i++) {
		std::cout << ret3[i] << " ";
	}
	std::cout <<"" <<std::endl;
}
