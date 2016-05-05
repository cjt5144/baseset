#ifndef BASESET_H_
#define BASESET_H_

#include <string>

typedef unsigned long baset;

namespace ct {
	class Baseset {
		private:
			// Minimum and Maximum base possible base numbers
			static const int minb = 2;
			static const int maxb = 62;
			
			// Holds character representation for base b
			char* dts;
			int b;
			baset l;
		
		public:
			// Constructors
			Baseset(baset number=0, int base=2);
			Baseset(const char* d, const baset & l, int base=2);
// 			Baseset(const std::string & s, baset & l, int base=2);
			Baseset(const Baseset & bs);
			// Destructors
			~Baseset();
			// Accessors
			const char at(const baset & i) const;
			const char* digits() const {return dts;};
			baset length() const {return l;};
			int base() const {return b;};
			baset decimal() const;
	};
};

#endif