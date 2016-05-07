#ifndef BASESET_H_
#define BASESET_H_

#include <string>
#include <climits>

namespace ct {
	
	typedef unsigned long baset;
	
	const char itoc(unsigned n);
	const unsigned ctoi(char c);
	const int digitsForBase(baset n, baset base);
	
	class Baseset 
	{
	public:
		// Iterator Typedefs
		typedef char * iterator;
		typedef const char * const_iterator;
		typedef char * reverse_iterator;
		typedef const char * const_reverse_iterator;
		
		// Minimum and Maximum base possible base numbers
		static const baset MAXDEC = UINT_MAX;
		static const baset MAXDLIN = ULONG_MAX-4/2;
		static const int MINB = 2;
		static const int MAXB = 62;
	
	private:
		// Holds character representation for base mNumberBase
		baset mLength;
		char * mDigits; // not null-terminated
		int mNumberBase;
		
		// Private Member Functions
		char * numberToBase(baset number, int base);
		
	public:
		// Constructors
		explicit Baseset(baset number=0, int base=10);
		Baseset(const std::string & d, int base);
		Baseset(const Baseset & bs);
		// Destructors
		~Baseset();
		// Non-Const Iterator Accessors
		iterator begin() {return mDigits;};
		iterator end() {return mDigits + mLength;};
		reverse_iterator rbegin() {return mDigits + mLength;};
		reverse_iterator rend() {return mDigits;};
		// Const Iterator Accessors
		const_iterator cbegin() const {return mDigits;};
		const_iterator cend() const {return mDigits + mLength;};
		const_reverse_iterator crbegin() const {return mDigits + mLength - 1;};
		const_reverse_iterator crend() const {return mDigits - 1;};
		// Static Constant Accessors
		static baset max_dec() {return MAXDEC;};
		static baset max_d_lin() {return MAXDLIN;};
		static int maxbase() {return MAXB;};
		static int minbase() {return MINB;};
		// Modifying Accessors
		void at(const baset & i, const char & c); // Checks input; Leaves unchanged if invalid
		void changeBase(int newBase);
		// Const Accessors
		const char & at(const baset & i) const {return mDigits[i];};
		const std::string d_str() const;
		const std::string reverse_d_str() const;
		baset length() const {return mLength;};
		int base() const {return mNumberBase;};
		const Baseset copyToBase(int newBase) const;
		const baset decimal() const;
		// Operators
		Baseset & operator=(const Baseset & b1);
		const char & operator[](const baset & i) const {return mDigits[i];};
		bool operator==(const Baseset & b1) const;
		bool operator>(const Baseset & b1) const;
		bool operator<(const Baseset & b1) const;
		bool operator>=(const Baseset & b1) const;
		bool operator<=(const Baseset & b1) const;
	};
};

#endif
