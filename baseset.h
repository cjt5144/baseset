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
			static const baset MAXDEC = UINT_MAX;
			static const baset MAXDLIN = ULONG_MAX-4/2;
			static const int MINB = 2;
			static const int MAXB = 62;
			
			// Holds character representation for base mNumberBase
			baset mLength;
			char* mDigits; // not null-terminated
			int* mRaws;
			int mNumberBase;
			
			// Private Member Functions
			char* numberToBase(baset number, int base);
			int* baseArrayToRaw(const char* ca, baset l);
			
		public:
			// Constructors
			explicit Baseset(baset number=0, int base=10);
			Baseset(const std::string & d, int base);
			Baseset(const Baseset & bs);
			// Destructors
			~Baseset();
			// Static Constant Accessors
			static baset max_dec() {return MAXDEC;};
			static baset max_d_lin() {return MAXDLIN;};
			static int maxbase() {return MAXB;};
			static int minbase() {return MINB;};
			// Modifying Accessors
			void changeBase(int newBase);
			// Const Accessors
			const char & at(const baset & i) const {return mDigits[i];};
			const int & r_at(const baset & i) const {return mRaws[i];};
			const char* digits() const {return mDigits;}; // Not null-terminated
			const std::string d_str() const;
			int* rawDigits() const {return mRaws;};
			baset length() const {return mLength;};
			int base() const {return mNumberBase;};
			const Baseset copyToBase(int newBase) const;
			const baset decimal() const;
			// Operators
			Baseset & operator=(const Baseset & b1);
			bool operator==(const Baseset & b1) const;
			bool operator>(const Baseset & b1) const;
			bool operator<(const Baseset & b1) const;
			bool operator>=(const Baseset & b1) const;
			bool operator<=(const Baseset & b1) const;
	};
};

#endif
