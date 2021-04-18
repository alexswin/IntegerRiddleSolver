#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

/*
	Paul and steve are two perfect logicians. They have been told there are two integers x and y such that 1 < x < 1 and x + y < 100, but have not been told what x and y are exactly. Steve is given the value of x + y and Paul is given the value of xy. They then have the following conversation.

	Paul: I can't determine the two numbers.
	Steve: I knew that.
	Paul: Now I can determine them.
	Steve: So can I.

	What are the two numbers?
*/

set<int> makePrimes(int upToWhat);

int main() {
  set<int> primes = makePrimes(2500);

	map<int, set<int>> sumsWithProducts;
	for (int i = 5; i <= 99; ++i) {
		sumsWithProducts[i];
	}

	//Remove all sums of two primes
	for (set<int>::iterator i = primes.begin(); i != primes.end() && *i <= 97; ++i) {
		set<int>::iterator j = i;
		++j;
		while (j != primes.end() && *i + *j < 100) {
			sumsWithProducts.erase(*i + *j);
			++j;
		}
	}

	//Remove 6
	sumsWithProducts.erase(6);

	/*for (map<int, set<int>>::iterator i = sumsWithProducts.begin(); i != sumsWithProducts.end(); ++i) {
		cout << i->first << " ";
	}*/

	//Populate vector of possible products for each sum in sumsWithProducts
	for (map<int, set<int>>::iterator i = sumsWithProducts.begin(); i != sumsWithProducts.end(); ++i) {
		for (int j = 2; j <= (i->first / 2); ++j) {
			if (j != (i->first - j)) {
				i->second.insert(j * (i->first - j));
			}
		}
	}

	map<int, set<int>> productsWithSums;
	for (int i = 6; i <= 2352; ++i) {
		productsWithSums[i];
	}

	for (set<int>::iterator i = primes.begin(); i != primes.end(); ++i) {
		//Remove all primes
		productsWithSums.erase(*i);

		//Remove all products of 2 primes, including primes squared
		for (set<int>::iterator j = i; j != primes.end(); j++) {
			productsWithSums.erase(*i * *j);
		}
	}

	//Remove powers of 2
	for (int i = 1; i <= 14; ++i) {
		productsWithSums.erase(pow(2,i));
	}

	//Remove odd numbers
	vector<int> removeThese;
	for (map<int, set<int>>::iterator i = productsWithSums.begin(); i != productsWithSums.end(); ++i) {
		if (i->first % 2 == 1) {
			removeThese.push_back(i->first);
		}
	}
	for (int i = 0; i < removeThese.size(); ++i) {
		productsWithSums.erase(removeThese[i]);
	}

	/*for (map<int, set<int>>::iterator i = productsWithSums.begin(); i != productsWithSums.end(); ++i) {
		cout << i->first << " ";
	}*/

	removeThese.clear();
	for (map<int, set<int>>::iterator i = productsWithSums.begin(); i != productsWithSums.end(); ++i) {
		//If product doesn't have factors that sum to a sum in sums, remove
	}
}


set<int> makePrimes(int upToWhat) {
	vector<int> primesVector;
	primesVector.push_back(2);
	for (int i = 3; i <= upToWhat; i += 2) {
		int j = 0;
		bool isPrime = true;
		while (primesVector[j] <= sqrt(i)) {
			if (i % primesVector[j] == 0) {
				isPrime = false;
				break;
			}
			++j;
		}
		if (isPrime) {
			primesVector.push_back(i);
		}
	}
	set<int> primes;
	for (int i = 0; i < primesVector.size(); ++i) {
		primes.insert(primesVector[i]);
	}
	return primes;
}