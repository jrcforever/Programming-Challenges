#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int main()
{
	long i, j;
	long cycleNum = 0;
	
	while (true)
	{
		cin >> i;
		cin >> j;
		if (j < i)
		{
			long _temp;
			_temp = j;
			j = i;
			i = _temp;
		}

		for (long index = i; index <= j; index++)
		{
			long _result = index;
			long _tempCycleNum = 1;

			while (_result != 1)
			{
				if (_result % 2 == 0)
					_result = _result / 2;
				else
					_result = _result * 3 + 1;

				_tempCycleNum++;
			}

			if (cycleNum <= _tempCycleNum)
				cycleNum = _tempCycleNum;

		}

		cout << i << " " << j << " " << cycleNum<<endl;
	}

	return 0;
}