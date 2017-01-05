
// Crypt Kicker
// Created by Kim Jong-uk at 2016.12.28
// Protected by MIT license

#include <stdio.h>
#include <string.h>

#define MAXIMUM_WORD_LENGTH 16
#define MAXIMUM_LINE_LENGTH 80
#define MAXIMUM_DICTIONALY 1000

static char dictionalyWord[MAXIMUM_DICTIONALY][MAXIMUM_WORD_LENGTH + 1];

int check(int lineLength, char* line, int startPosition, char* map, char* inverseMap, int directionLength)
{
	char _word[MAXIMUM_WORD_LENGTH + 1];
	char _map['z' + 1];
	char _inverseMap['z' + 1];
	int i, j, index_word, z;

	if (line[startPosition] == ' ')
		startPosition++;

	if (startPosition >= lineLength)
	{
		for (i = 0; i < lineLength; i++)
			putchar(line[i] == ' ' ? ' ' : map[line[i]]);
		putchar('\n');
		return 0;
	}

	for (index_word = 0; line[index_word + startPosition] >= 'a' && line[index_word + startPosition] <= 'z'; index_word++)
	{
		_word[index_word] = line[index_word + startPosition];
	}
	_word[index_word] = '\0';

	for (i = 0; i < directionLength; i++)
		if (index_word == strlen(dictionalyWord[i]))
		{
			for (z = 'a'; z <= 'z'; z++) {
				_map[z] = map[z];
				_inverseMap[z] = inverseMap[z];
			}

			for (j = 0; j < index_word; j++)
			{

				if (_map[_word[j]] && _map[_word[j]] != dictionalyWord[i][j]
					|| _inverseMap[dictionalyWord[i][j]] && _inverseMap[dictionalyWord[i][j]] != _word[j])
					goto endfunc;
				else
				{
					_map[_word[j]] = dictionalyWord[i][j];
					_inverseMap[dictionalyWord[i][j]] = _word[j];
				}
			}

			if (0 == check(lineLength, line, startPosition + index_word, _map, _inverseMap, directionLength))
				return 0;
		endfunc:;
		}

	return 1;
}

int main()
{
	int dictionalyTotalWordNumber;
	char line[MAXIMUM_LINE_LENGTH + 1];
	int i;
	int lineLength;
	char map['z' + 1];
	char inverseMap['z' + 1];

	scanf("%d", &dictionalyTotalWordNumber);
	gets(line);
	for (i = 0; i < dictionalyTotalWordNumber; i++)
		gets(dictionalyWord[i]);

	while (gets(line) && *line) {
		lineLength = strlen(line);

		for (i = 'a'; i <= 'z'; i++)
		{
			map[i] = '\0';
			inverseMap[i] = '\0';
		}

		if (check(lineLength, line, 0, map, inverseMap, dictionalyTotalWordNumber)) {
			for (i = 0; i < lineLength; i++)
				putchar(line[i] == ' ' ? ' ' : '*');
			putchar('\n');
		}

	}

	return 0;
}