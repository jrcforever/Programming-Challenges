
// Interpreter
// Created by Kim Jong-uk at 2016.12.18
// Protected by MIT license

#include <stdio.h>

#define LIMIT_VALUE 1000
#define REG_SIZE 10
#define MEMORY_SIZE 1000

#define TRUE 1
#define FALSE 0

#define INIT 0

int main()
{
	int reg[REG_SIZE];
	int memory[MEMORY_SIZE];
	char command[100];
	int pc, i,j, run, inputNum;
	int testCaseNum;
	int totalCommandsCount;
	int arg1, arg2, instruction;

	scanf("%d", &testCaseNum);
	gets_s(command, 100);
	gets_s(command, 100);


	for (i = INIT; i < testCaseNum; i++)
	{
		for (inputNum = INIT; gets_s(command, 100) && *command; inputNum++)
			sscanf(command, "%d", &memory[inputNum]);

		for (; inputNum < MEMORY_SIZE; inputNum++)
			memory[inputNum] = INIT;

		for (j = INIT; j < REG_SIZE; j++)
			reg[j] = INIT;
		
		totalCommandsCount = INIT;
		pc = INIT;
		run = TRUE;

		while (run)
		{
			instruction = memory[pc] / 100;
			arg1 = (memory[pc] / 10) % 10;
			arg2 = memory[pc] % 10;

			pc++;
			totalCommandsCount++;
			
			switch (instruction)
			{
			case 1 :
				run = FALSE;
				break;

			case 2:
				reg[arg1] = arg2;
				break;
			case 3:
				reg[arg1] = (reg[arg1] + arg2) % 1000;
				break;
			case 4:
				reg[arg1] = (reg[arg1] * arg2) % 1000;
				break;

			case 5:
				reg[arg1] = reg[arg2];
				break;

			case 6: 
				reg[arg1] = (reg[arg1] + reg[arg2]) % 1000;
				break;

			case 7: 
				reg[arg1] = (reg[arg1] * reg[arg2]) % 1000;
				break;

			case 8: 
				reg[arg1] = memory[reg[arg2]];
				break;

			case 9: 
				memory[reg[arg2]] = reg[arg1];
				break;
			case 0: 
				if (reg[arg2] != 0)
					pc = reg[arg1];
				break;

			default:
				break;
			}
		}
		if (i > 0)
			printf("\n");
		printf("%d\n", totalCommandsCount);

	}

	return 0;
}