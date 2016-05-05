#include "baseset.h"
#include <cstring>
#include <cmath>
#include <iostream>
#include <cstdlib>

namespace ct {
	
	const char itoc(unsigned n) {
		if(n < 10)
			return char(n + 48);
		else if(n >= 10 && n < 36) 
			return char(n + 55);
		else if(n >= 36 && n < 62)
			return char(n + 61);
		else
			return 0;
	}
	
	const unsigned ctoi(char c) {
		if(c > 47 && c < 58)
			return unsigned(c) - 48;
		else if(c > 64 && c < 91)
			return unsigned(c) - 65 + 10;
		else if(c > 96 && c < 123)
			return unsigned(c) - 97 + 36;
		else
			return UINT_MAX;
	}
	
	const int digitsForBase(baset n, baset base) {
		int a = 0;
		baset c = baset(pow(base, a))-1;
		while(c < n) {
			a++;
			c = baset(pow(base, a))-1;
		}
		return a;
	}
	
	// Private Member Functions
	
	char* Baseset::numberToBase(baset number, int base) {
		// Input checking
		bool ok = true;
		
		if(number >= MAXDEC) {
			std::cout << "\n[\\] Warning: number exceded MAXDEC. Set to 0." << std::endl;
			ok = false;
		}
		
		if(base > MAXB) {
			std::cout << "\n[\\] Warning: base exceded MAXB. Set to 10." << std::endl;
			ok = false;
		}
		else if(base < MINB) {
			std::cout << "\n[\\] Warning: base below MINB. Set to 10." << std::endl;
			ok = false;
		}
		
		char* digits;
		if(ok) {
			baset length = digitsForBase(number, base);
			digits = new char[length];
			baset m = number;
		
			for(int i = length - 1; i > -1; i--) {
				baset y = baset(pow(base, i));

				if(y <= m) {
					int j = m / y;
					baset s = j * y;
					digits[length-1-i] = itoc(j);
					m -= s;
				}
				else
					digits[length-1-i] = '0';
			}
		}
		else {
			digits = 0;
		}
		
		return digits;
	}
	
	// Constructors
	
	Baseset::Baseset(baset number, int base) {
		
		mNumberBase = base;
		mDigits = numberToBase(number, mNumberBase);
		if(mDigits) {
			mLength = digitsForBase(number, mNumberBase);
		}
		else {
			mNumberBase = 0;
			mLength = 0;			
		}
		
		mReDigits = 0;
		mRaws = 0;
		
		for(baset i = 0; i < mLength; i++) 
			std::cout << mDigits[i];
		std::cout << std::endl;
	}
	
	Baseset::Baseset(const std::string & s, int base) {
		// Check digits in s < base
		bool ok = true;
		for(baset i = 0; i < s.size(); i++) {
			int digit = ctoi( s.at(i) );
			if(digit >= base) {
				bool ok = false;
				break;
			}
		}
		
		if(base > MAXB) {
			std::cout << "\n[\\] Warning: base exceded MAXB." << std::endl;
			ok = false;
		}
		else if(base < MINB) {
			std::cout << "\n[\\] Warning: base below MINB." << std::endl;			
			ok = false;
		}
		
		if(ok) {
			mNumberBase = base;
			mDigits = new char[ s.size() ];
			strncpy( mDigits, s.c_str(), s.size() );
			mLength = s.size();
		}
		else {
			mNumberBase = 0;
			mDigits = 0;
			mLength = 1;
		}
		
		mReDigits = 0;
		mRaws = 0;
		
		for(baset i = 0; i < mLength; i++) 
			std::cout << mDigits[i];
		std::cout << std::endl;
	}
	
	Baseset::Baseset(const Baseset & bs) {
		mLength = bs.length();
		mNumberBase = bs.base();
		strncpy(mDigits, bs.digits(), mLength);
		
		mReDigits = 0;
		mRaws = 0;
	}
	
	// Destructor
	
	Baseset::~Baseset() {
		if(mDigits)
			delete [] mDigits;
		
		if(mReDigits)
			delete [] mReDigits;
		
		if(mRaws)
			delete [] mRaws;
		
		std::cout << "Baseset object destroyed" << std::endl; 
	}
	
	// Modifying Accessors
	
	void Baseset::changeBase(int newBase) {
		if(newBase != mNumberBase) {
			baset d = decimal();
			delete [] mDigits;
			mDigits = numberToBase(d, newBase);
		}
	}
	
	// Const Accessors
	
	const Baseset Baseset::copyToBase(int newBase) const {
		return Baseset(decimal(), newBase);
	}
	
	const baset Baseset::decimal() const {
		baset tot = 0;
		for(baset a = 0; a < mLength; a++) {
			baset exponent = mLength - 1 - a;
			unsigned n = ctoi(mDigits[a]);
			
			tot += n * pow(mNumberBase, exponent);
		}
		return tot;
	}
	
	// Operators
	
	Baseset & Baseset::operator=(const Baseset & b1) {
		if(this == &b1) {
			return *this;
		}
		delete [] mDigits;
		mNumberBase = b1.base();
		mLength = b1.length();
		strncpy(mDigits, b1.digits(), mLength);
		
		mReDigits = 0;
		mRaws = 0;
		
		return *this;
	}
};
