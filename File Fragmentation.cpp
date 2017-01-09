
// File Fragmentation
// Created by Kim Jong-uk at 2017.01.07
// Protected by MIT license

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXIMUM_FILE_NUMBER 144
#define MAXIMUM_FILE_SIZE 128

int compare(const void *fragment1, const void *fragment2) {
	int diff = strlen(*(char**)fragment1) - strlen(*(char**)fragment2);

	if (diff != 0) return diff;

	return strcmp(*(char**)fragment2, *(char**)fragment1);
}

int main()
{
	char line[MAXIMUM_FILE_NUMBER][MAXIMUM_FILE_SIZE + 1];
	char* linepoint[MAXIMUM_FILE_NUMBER];

	char selectorResult[4][MAXIMUM_FILE_SIZE];
	int seletorCheck[4];
	int selector;

	int testCase, i, j, k, l;
	int inputN;
	char compareSmallFrag[2][MAXIMUM_FILE_SIZE], compareBigFrag[2][MAXIMUM_FILE_SIZE];
	char completeFrag[2][MAXIMUM_FILE_SIZE];
	int compareSmallPointA, compareBigPointA, compareSmallPointB, compareBigPointB;
	scanf("%d", &testCase);

	gets(line[0]);
	gets(line[0]);

	for (i = 0; i < testCase; i++) {

		inputN = 0;

		while (gets(line[inputN]) && *line[inputN] && strlen(line[inputN])>0) {
			linepoint[inputN] = line[inputN];
			inputN++;
		}

		qsort(linepoint, inputN, sizeof(char*), compare);

	//	for(j = 0; j < inputN; j++)
		//printf("%s %s\n", linepoint[j], line[j]);

		for (j = 0; j < 2; j++)
		{
			completeFrag[j][0] =
				compareSmallFrag[j][0] =
				compareBigFrag[j][0] = '\0';
		}
		selector = 0;
		compareSmallPointA = 0;

		for (j = 0; j < 4; j++)
			selectorResult[j][0] = '\0';


		for (j = 0; j < inputN; j++) {

			if ((j+1 <inputN &&strlen (linepoint[j]) < strlen(linepoint[j + 1])) || j == inputN -1 )
			{
				//2
				compareBigPointA = j;
				compareSmallPointB = inputN - 1 - compareBigPointA;
				compareBigPointB = inputN - 1 - compareSmallPointA;

				strcpy(compareSmallFrag[0], linepoint[compareSmallPointA]);  //0 1

			//	printf("tt : %s %d \n", compareSmallFrag[0], compareSmallPointA );
				strcpy(compareSmallFrag[1], linepoint[compareBigPointA]);    //1 0
			//	printf("tt : %s %d \n", compareSmallFrag[1], compareBigPointA);

				strcpy(compareBigFrag[0], linepoint[compareSmallPointB]);    // 0 1
			//	printf("tt : %s %d \n", compareBigFrag[0], compareSmallPointB);
				strcpy(compareBigFrag[1], linepoint[compareBigPointB]);      // 1 0

				for (k = 0; k < 4; k++)
					seletorCheck[k] = 0;

				for (k = 0; k <= 1; k++) {
					strcpy(completeFrag[0], compareSmallFrag[k]); //1
					strcat(completeFrag[0], compareBigFrag[1- k]);   //
					strcpy(completeFrag[1], compareSmallFrag[1-k]); // 0
					strcat(completeFrag[1], compareBigFrag[k]);

				//	printf("%s %s\n", completeFrag[0], completeFrag[1]);

					if (!strcmp(completeFrag[0], completeFrag[1])) {
						if (compareSmallPointA == 0)
						{
							//printf("test\n");
							strcpy(selectorResult[selector], completeFrag[0]);
							selector++;
						}
						else
						{
							//check same word
							for (l = 0; l < k; l++)
								if (!strcmp(selectorResult[l], completeFrag[0]))
									seletorCheck[l] = 1;
						}
					}

					strcpy(completeFrag[0], compareBigFrag[k]);
					strcat(completeFrag[0], compareSmallFrag[1-k]);
					
					strcpy(completeFrag[1], compareBigFrag[k]);
					strcat(completeFrag[1], compareSmallFrag[1- k]);
				

				//	printf("%s %s\n", completeFrag[0], completeFrag[1]);

					if (!strcmp(completeFrag[0], completeFrag[1])) {
						if (compareSmallPointA == 0)
						{
						//	printf("test\n");
							strcpy(selectorResult[selector], completeFrag[0]);
							selector++;
						}
						else
						{
							//check same word
							for (l = 0; l < k; l++)
								if (!strcmp(selectorResult[l], completeFrag[0]))
									seletorCheck[l] = 1;
						}
					}
				}

				if (compareSmallPointA > 0) {
					for (l = 0; l < selector; l++)
						if (!seletorCheck[l]) {
					//		printf("%d minus %s\n",l,selectorResult[l]);
							strcpy(selectorResult[l], selectorResult[selector - 1]);
							seletorCheck[l] = seletorCheck[selector - 1];
							l--;
							selector--;
							continue;
						}
				}

				compareSmallPointA = j + 1;
			}
		}

		if (i > 0)
			putchar('\n');

	//	for (k = 0; k < 4; k++)
	//		printf("%d : %s\n", k, selectorResult[k]);

		printf("%s\n", selectorResult[0]);

	}

	return 0;
}