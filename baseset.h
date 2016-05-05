#ifndef BASESET_H_
#define BASESET_H_

#include <string>
#include <climits>

namespace ct {
	
	typedef unsigned long baset;
	
	const char itoc(unsigned n);
	const unsigned ctoi(char c);
	const int digitsForBase(baset n, baset base);
	
	class Baseset {
		private:
			// Minimum and Maximum base possible base numbers
			static const int MINB = 2;
			static const int MAXB = 62;
			static const baset MAXDEC = UINT_MAX;
			static const baset MAXDLIN = ULONG_MAX-4/2;
			
			// Holds character representation for base mNumberBase
			char* mDigits; // not null-terminated
			char* mReDigits;
			int* mRaws;
			int mNumberBase;
			baset mLength;
			// Private Member Functions
			char* numberToBase(baset number, int base);
			
		public:
			// Constructors
			explicit Baseset(baset number=0, int base=10);
			Baseset(const std::string & d, int base);
			Baseset(const Baseset & bs);
			// Destructors
			~Baseset();
			// Modifying Accessors
			char & at(const baset & i) {return mDigits[i];}; // May set invalid number for base
			void changeBase(int newBase);
			// Const Accessors
			const char & at(const baset & i) const {return mDigits[i];};
			const char* digits() const {return mDigits;}; // Not null-terminated
// 			const std::string d_str() const;
// 			const char* reDigits() const; // Not null-terminated reverse
// 			const std::string red_str() const; // reverse
// 			int* rawDigits() const;
			baset length() const {return mLength;};
			int base() const {return mNumberBase;};
			const Baseset copyToBase(int newBase) const;
			const baset decimal() const;
			// Operators
			Baseset & operator=(const Baseset & B1);
// 			bool operator==(const Baseset & B1) const;
// 			bool operator>(const Baseset & B1) const;
// 			bool operator<(const Baseset & B1) const;
// 			bool operator>=(const Baseset & B1) const;
// 			bool operator<=(const Baseset & B1) const;
	};
};

#endif
