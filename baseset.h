#ifndef BASESET_H_
#define BASESET_H_

#include <string>
#include <climits>

namespace ct {

	typedef unsigned long baset;
	
	class Baseset {
		private:
			// Minimum and Maximum base possible base numbers
			static const int MINB = 2;
			static const int MAXB = 62;
			static const baset MAXDLIN = ULONG_MAX-4 / 2; //ULONG_MAX 4 more than string::max_size
			
			// Holds character representation for base mNumberBase
			char* mDigits;
			int mNumberBase;
			baset mLength;
		public:
			// Constructors
			Baseset(baset number=0, int base=10);
			Baseset(unsigned number); // unsigned int conversion
			Baseset(std::string d, int base);
			Baseset(const Baseset & bs);
			// Destructors
			~Baseset();
			// Modifying Accessors
			char & at(const baset & i);
			void changeBase(int newBase);
			// Const Accessors
			const char at(const baset & i) const;
			const char* digits() const {return mDigits;}; // Not null-terminated
			const char* digitsNT() const; // null-terminated
			const char* reDigits() const; // Not null-terminated reverse
			const char* reDigitsNT() const; // null-terminated reverse
			const baset & length() const {return mLength;};
			int base() const {return mNumberBase;};
			const Baseset copyToBase(int newBase);
			// Operators
			void operator=(const Baseset & B1);
			bool operator==(const Baseset & B1) const;
			bool operator>(const Baseset & B1) const;
			bool operator<(const Baseset & B1) const;
			bool operator>=(const Baseset & B1) const;
			bool operator<=(const Baseset & B1) const;
	};
};

#endif
