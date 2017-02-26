# include <iostream>
# include <string.h>
# include "./src/boy.h"
# include "./src/girl.h"
# include "./src/couple.h"
# include "./src/essential_gift.h"
# include "./src/luxury_gift.h"
# include "./src/utility_gift.h"
# include "./src/reading.h"
# include <vector>
# include <limits.h>
# include <float.h>	

using namespace std;

int main()
{
	vector<class boy> boys_vector;
	vector<class girl> girls_vector;
	vector<class couple> couples_vector;
	vector<class essential_gift> egifts_vector;
	vector<class luxury_gift> lgifts_vector;
	vector<class utility_gift> ugifts_vector;
	vector<class couple>::iterator itr, best_happy, best_compatible;
	float tmp1 = FLT_MIN;
	int tmp2 = INT_MIN;
	

	initialize(&boys_vector, &girls_vector, &egifts_vector, &lgifts_vector, &ugifts_vector);
	make_couple(boys_vector, girls_vector, &couples_vector);
	set_gifts(&couples_vector, egifts_vector, lgifts_vector, ugifts_vector);

	for (itr = couples_vector.begin(); itr != couples_vector.end(); itr++) {
		if (itr->happiness >= tmp1) {
			best_happy = itr;
		}

		if (itr->compatibility >= tmp2) {
			best_compatible = itr;
		}
	}

	cout << "The best happy couple is : " << (best_happy->Boy).name << " " << (best_happy->Girl).name << endl;
	cout << "The best compatible couple is : " << (best_compatible->Boy).name << " " << (best_compatible->Girl).name << endl;

	return 0;
}
