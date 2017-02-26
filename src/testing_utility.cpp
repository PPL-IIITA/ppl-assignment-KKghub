#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{
	int boys_count;
	int girls_count;
	int egifts_count;
	int lgifts_count;
	int ugifts_count;
	int i;
	int j;

	char *string = (char *)malloc(10 * sizeof(char));
	int integer;
	
	cout << "This is testing utility to generate random pool of girls, boys and gifts" << endl;

	cout << "Enter number of boys to generate : ";
	cin >> boys_count;

	cout << "Enter number of girls to generate : ";
	cin >> girls_count;

	cout << "Enter number of essential gifts to generate : ";
	cin >> egifts_count;

	cout << "Enter number of luxury gifts to generate : ";
	cin >> lgifts_count;

	cout << "Enter number of utility gifts to generate : ";
	cin >> ugifts_count;


	FILE *fp;
	fp = fopen("./resources/boys.txt", "w+");
//	string = (char **)malloc(n*sizeof(char *));
	for(i = 0; i < boys_count; i++) {
//		input[i]=(char *)malloc((k+1)*sizeof(char));
		for(j=0;j<3;j++)
			string[j]=(rand()%26)+65;
		string[3]='\0';

		fputs(string, fp);
		fputs(" ", fp);

                integer = (rand() % 3);
                fprintf(fp, "%d", integer);
                fputs(" ", fp);

		integer = (rand() % 100);
		fprintf(fp, "%d", integer);
		fputs(" ", fp);

		integer = (rand() % 100);
		fprintf(fp, "%d", integer);
		fputs(" ", fp);

		integer = (rand() % 100);
		fprintf(fp, "%d", integer);
		fputs(" ", fp);

		integer = (rand() % 100);
		fprintf(fp, "%d", integer);

		if (i != boys_count - 1)
			fputs("\n", fp);
		
	}

	fclose(fp);

	fp = fopen("./resources/girls.txt", "w+");
	for(i = 0; i < girls_count; i++) {
//		input[i]=(char *)malloc((k+1)*sizeof(char));
		for(j=0;j<3;j++)
			string[j]=(rand()%26)+65;
		string[3]='\0';

		fputs(string, fp);
		fputs(" ", fp);

		integer = (rand() % 3);
		fprintf(fp, "%d", integer);
		fputs(" ", fp);

		integer = (rand() % 100);
		fprintf(fp, "%d", integer);
		fputs(" ", fp);

		integer = (rand() % 100);
		fprintf(fp, "%d", integer);
		fputs(" ", fp);

		integer = (rand() % 100);
		fprintf(fp, "%d", integer);
                if (i != girls_count - 1)
                        fputs("\n", fp);
		
	}
	fclose(fp);

	fp = fopen("./resources/egifts.txt", "w+");
	for(i = 0; i < egifts_count; i++) {

		integer = (rand() % 100);
		fprintf(fp, "%d", integer);
		fputs(" ", fp);

		integer = (rand() % 100);
		fprintf(fp, "%d", integer);
                if (i != egifts_count - 1)
              		fputs("\n", fp);
		
	}

	fp = fopen("./resources/lgifts.txt", "w+");
	for(i = 0; i < lgifts_count; i++) {

		integer = (rand() % 100);
		fprintf(fp, "%d", integer);
		fputs(" ", fp);

		integer = (rand() % 100);
		fprintf(fp, "%d", integer);
                fputs(" ", fp);

		integer = (rand() % 100);
		fprintf(fp, "%d", integer);
		fputs(" ", fp);

		integer = (rand() % 100);
		fprintf(fp, "%d", integer);
                if (i != lgifts_count - 1)
                        fputs("\n", fp);
		
	}
	fclose(fp);

	fp = fopen("./resources/ugifts.txt", "w+");
	for(i = 0; i < ugifts_count; i++) {

		integer = (rand() % 100);
		fprintf(fp, "%d", integer);
		fputs(" ", fp);

		integer = (rand() % 100);
		fprintf(fp, "%d", integer);
		fputs(" ", fp);

		integer = (rand() % 100);
		fprintf(fp, "%d", integer);
		fputs(" ", fp);

		integer = (rand() % 100);
		fprintf(fp, "%d", integer);
                if (i != ugifts_count - 1)
                        fputs("\n", fp);
		
	}
	fclose(fp);



	return 0;
}
