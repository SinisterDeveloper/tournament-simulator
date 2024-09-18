#include <iostream>
using namespace std;

int main()
{
	enum Team {
		RCB,
		CSK,
		MI,
		GT,
		LSG,
		PBKS,
		SRH,
		KKR,
		DC,
		RR 
	};

	struct match {
		enum Team t1;
		enum Team t2;
	};

	match m1 = { RCB, GT };
	match m2 = { PBKS, CSK };
	match m3 = { LSG, KKR };
	match m4 = { MI, SRH };
	match m5 = { DC, RR };
	match m6 = { SRH, LSG };
	match m7 = { PBKS, RCB };
	match m8 = { GT, CSK };
	match m9 = { KKR, MI };
	match m10 = { CSK, RR };
	match m11 = { RCB, DC };
	match m12 = { GT, KKR };
	match m13 = { DC, LSG };
	match m14 = { RR, PBKS };
	match m15 = { SRH, GT };
	match m16 = { MI, LSG };
	match m17 = { RCB, CSK };
	match m18 = { SRH, PBKS };
	match m19 = { RR, KKR };

	match matches[30] = { m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19 };

	for (int i = 0; i < 19; ++i) {
		cout << "Match " << i + 1 << ": Team " << matches[i].t1 << " vs Team " << matches[i].t2 << endl;
	}

	return 0;
}
