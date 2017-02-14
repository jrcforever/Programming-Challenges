// The Stern-Brocot Number System
// Created by Kim Jong-uk at 2017.02.06
// Protected by MIT license

// m/n

#include <stdio.h>

int main()
{
	int lm, ln, rm, rn;
	int m, n, p, q;

	scanf("%d %d", &p, &q);

	while (p != 1 || q != 1)
	{
		lm = 0; ln = 1; rm = 1; rn = 0; m = 1; n = 1;

		while (p != m || q != n)
		{
			if (n*p < q*m)
			{
				putchar('L');
				rm = m;  rn = n;
				m = lm + rm; n = ln + rn;
			}
			else if (n*p > q*m)
			{
				putchar('R');
				lm = m;  ln = n;
				m = lm+ rm; n = ln+rn;
			}
		}
		putchar('\n');
		scanf("%d %d",&p, &q);
	}

	return 0;
}