#include "baseset.h"
#include <cstring>

namespace ct {

	// Constructors
	
	Baseset::Baseset(baset number, int base) {
		dts = new char[1];
		dts[0] = '0';
		b = base;
	}
	
	Baseset::Baseset(const char* d, const baset & l, int base) {
		dts = new char[l];
		b = base;
		for(baset i = 0; i < l; i++) {
			dts[i] = d[i];
		}
	}
	
	Baseset::Baseset(const Baseset & bs) {
		Baseset(bs.digits(), bs.length(), bs.base());
	}
	
	// Destructor
	
	Baseset::~Baseset() {
		delete [] dts;
	}
	
	// Accessors
	
	const char Baseset::at(const baset & i) const {
		if(i < l)
			return dts[i];
		else
			return 0;
	}
	
	baset Baseset::decimal() const {
		return 0;
	}
};
