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
	
using namespace std;

int main()
{
	vector<class boy> boys_vector;
	vector<class girl> girls_vector;
	vector<class couple> couples_vector;
	vector<class essential_gift> egifts_vector;
	vector<class luxury_gift> lgifts_vector;
	vector<class utility_gift> ugifts_vector;
	vector<class couple>::iterator itr;

	initialize(&boys_vector, &girls_vector, &egifts_vector, &lgifts_vector, &ugifts_vector);
	make_couple(boys_vector, girls_vector, &couples_vector);

	for (itr = couples_vector.begin(); itr != couples_vector.end(); itr++) {
		cout << (itr->Boy).name << " " << (itr->Girl).name << endl;
	}
	return 0;
}
