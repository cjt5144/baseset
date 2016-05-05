// #include "baseset.h"
// #include <cstring>
// 
// namespace ct {
// 	
// 	// Constructors
// 	
// 	Baseset::Baseset(baset number, int base) {
// 		if(base >= MINB && base <= MAXB)
// 			b = base;
// 		else
// 			b = -1;
// 		
// 		dts = new char[1];
// 		dts[0] = 0;
// 	}
// 	
// 	Baseset::Baseset(const char* d, int base) {
// 		if(base >= MINB && base <= MAXB) {
// 			b = base;
// 			
// 			baset a = 0;
// 			while(d[a] != 0)
// 				a++;
// 		
// 			dts = new char[a];
// 			for(baset i = 0; i < a; i++) {
// 				dts[i] = d[i];
// 			}
// 		}
// 		else {
// 			b = -1;
// 		
// 			dts = new char[1];
// 			dts[0] = 0;
// 		}
// 	}
// 	
// 	Baseset::Baseset(const char* d, const baset & a, int base) {
// 		if(base >= MINB && base <= MAXB) {
// 			b = base;
// 		
// 			dts = new char[a];
// 			for(baset i = 0; i < a; i++) {
// 				dts[i] = d[i];
// 			}
// 		}
// 		else {
// 			b = -1;
// 		
// 			dts = new char[1];
// 			dts[0] = 0;
// 		}
// 	}
// 	
// 	Baseset::Baseset(const Baseset & bs) {
// 		Baseset(bs.digits(), bs.length(), bs.base());
// 	}
// 	
// 	// Destructor
// 	
// 	Baseset::~Baseset() {
// 		delete [] dts;
// 	}
// 	
// 	// Accessors
// 	
// 	const char Baseset::at(const baset & i) const {
// 		if(i < l)
// 			return dts[i];
// 		else
// 			return 0;
// 	}
// 	
// 	baset Baseset::decimal() const {
// 		return 0;
// 	}
// };
