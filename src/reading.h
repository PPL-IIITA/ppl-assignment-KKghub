# include <stdio.h>
# include <iostream>
# include <stdlib.h>
# include <fstream>
# include <string>
# include <vector>
# include <algorithm>

using namespace std;


bool egift_cmp(class essential_gift egift1, class essential_gift egift2)
{
	if (egift1.price < egift2.price) {
		return true;
	} else {
		return false;
	}
}

bool lgift_cmp(class luxury_gift lgift1, class luxury_gift lgift2)
{
        if (lgift1.price < lgift2.price) {
                return true;
        } else {
                return false;
        }
}
bool ugift_cmp(class utility_gift ugift1, class utility_gift ugift2)
{
        if (ugift1.price < ugift2.price) {
                return true;
        } else {
                return false;
        }
}

void initialize(vector<class boy> *B_vector, vector<class girl> *G_vector, vector<class essential_gift> *egift_vector, vector<class luxury_gift> *lgift_vector, vector<class utility_gift> *ugift_vector)
{
	class boy *B;
	class girl *G;
	class essential_gift *egift;
	class luxury_gift *lgift;
	class utility_gift *ugift;

	int i;
	int j;
	int k;
	char name[100];
	int type;
	int attr;
	int buget;
	int intel;
	int min_attr;
	
	int integer;
	char c;

	fstream fp;
	fp.open("./resources/girls.txt", ios::in);

	while (!fp.eof()) {
		G = (class girl *)malloc(sizeof(class girl));
		fp >> G->name >> G->type >> G->attr >> G->budget >> G->intel;
		fp.get(c);
//		cout << G->name << " " << G->type << " " << G->attr << " " << G->budget << " " << G->intel << endl;
		(*G_vector).push_back(*G);
	}
	fp.close();


        fp.open("./resources/boys.txt", ios::in);
        while (!fp.eof()) {
		B = (class boy *)malloc(sizeof(class boy));
                fp >> B->name >> B->type >> B->attr >> B->budget >> B->intel >> B->min_attr;
		fp.get(c);
//                cout << name << " " << type << " " << attr << " " << buget << " " << min_attr << endl;
		(*B_vector).push_back(*B);
        }
        fp.close();

	fp.open("./resources/egifts.txt", ios::in);
	while (!fp.eof()) {
		egift = (class essential_gift *)malloc(sizeof(class essential_gift));
		fp >> egift->price >> egift->value;
		(*egift_vector).push_back(*egift);
	}
	sort((*egift_vector).begin(), (*egift_vector).end(), egift_cmp);
	fp.close();


        fp.open("./resources/lgifts.txt", ios::in);
        while (!fp.eof()) {
                lgift = (class luxury_gift *)malloc(sizeof(class luxury_gift));
                fp >> lgift->price >> lgift->value >> lgift->rating >> lgift->difficulty;
                (*lgift_vector).push_back(*lgift);
        }
        sort((*lgift_vector).begin(), (*lgift_vector).end(), lgift_cmp);
        fp.close();

        fp.open("./resources/ugifts.txt", ios::in);
        while (!fp.eof()) {
                ugift = (class utility_gift *)malloc(sizeof(class utility_gift));
                fp >> ugift->price >> ugift->value >> ugift->utility_value >> ugift->utility_class;
                (*ugift_vector).push_back(*ugift);
        }
        sort((*ugift_vector).begin(), (*ugift_vector).end(), ugift_cmp);
        fp.close();
}


void make_couple(vector<class boy> B_vector, vector<class girl> G_vector, vector<class couple> *C_vector)
{
	vector<class girl>::iterator gitr;
	vector<class boy>::iterator bitr;
	class couple *C;
	for (gitr = G_vector.begin(); gitr != G_vector.end(); gitr++) {
		for (bitr = B_vector.begin(); bitr != B_vector.end(); bitr++) {
			if (bitr->budget >= gitr->budget && gitr->attr > bitr->min_attr) {
				C = (class couple *)malloc(sizeof(class couple));
				C->Boy = (*bitr);
				C->Girl = (*gitr);
				(*C_vector).push_back(*C);
				B_vector.erase(bitr);
				break;
			}
		}
	}
}

void set_gifts(vector<class couple> *C_vector, vector<class essential_gift> egift_vector, vector<class luxury_gift> lgift_vector, vector<class utility_gift> ugift_vector)
{
	vector<class couple>::iterator itr;
	vector<class essential_gift>::iterator egift_itr;
	vector<class luxury_gift>::iterator lgift_itr;
	vector<class utiliy_gift>::iterator ugift_itr;
	vector<class essential_gift>::reverse_iterator egift_itr2;
	int g_value;

	for (itr = (*C_vector).begin(); itr != (*C_vector).end(); itr++) {
		if ((*itr).Boy.type == 0) {
			g_value = 0;
			for (egift_itr = egift_vector.begin(); egift_itr != egift_vector.end(); egift_itr++) {
//				printf("label\n");
				g_value = g_value + (*egift_itr).price;
//				cout << g_value << endl;
				if (g_value >= (*itr).Girl.budget) {
					break;
				}
			}
		} else if ((*itr).Boy.type == 1) {
			g_value = 0;
			for (egift_itr2 = egift_vector.rbegin(); egift_itr2 != egift_vector.rend(); egift_itr2++) {
//				cout << "label 2" << endl;
				g_value = g_value + (*egift_itr2).price;
//				cout << g_value << endl;
			}
		} else {
			g_value = 0;
			for (egift_itr = egift_vector.begin(); egift_itr != egift_vector.end(); egift_itr++) {
//				cout << "label 3" << endl;
                                g_value = g_value + (*egift_itr).price;
//				cout << g_value << endl;
                                if (g_value >= (*itr).Girl.budget) {
                                        break;
                                }
                        }
			lgift_itr = lgift_vector.begin();
			g_value = g_value + (*lgift_itr).price;
		}

		(*itr).set_state(g_value);
//		cout << (*itr).gift_cost << endl;
/*	        gift_cost = g_cost;


        	switch(Girl.type) {
                	case 0 : Girl.happiness = log(gift_cost / Girl.budget);
                        	break;
                	case 1 : Girl.happiness = gift_cost / Girl.budget;
                        	break;
                	case 2 : Girl.happiness = exp(gift_cost / Girl.budget);
                        	break;
        	}

        	switch(Boy.type) {
                	case 0 : Boy.happiness = Boy.budget - gift_cost;
                        	break;
                	case 1 : Boy.happiness = Girl.happiness;
                        	break;
                	case 2 : Boy.happiness = Girl.intel;
                        	break;
        	}

        	(*itr).happiness = (*itr).Boy.happiness + (*itr).Girl.happiness;
        	(*itr).compatibility = ((*itr).Boy.budget - (*itr).Girl.budget) + abs((*itr).Boy.attr - (*itr).Girl.attr);// + abs(Boy.intel - Girl.intel);              
*/
	}
}
