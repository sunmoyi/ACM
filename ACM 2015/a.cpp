#include<cstdio>

using namespace std;

int main(void)
{
	int A, B, C, D, E, F;
	for(A = 0; A <= 1; A++)
		for (B = 0; B <= 1; B++)
			for (C = 0; C <= 1; C++)
				for (D = 0; D <= 1; D++)
					for (E = 0; E <= 1; E++)
						for (F = 0; F <= 1; F++)
						{
							if (A + B >= 1
								&& (A + D <= 1)
								&& (A + E + F == 2)
								&& (B + C == 2 || B + C == 0)
								&& C + D == 1
								&& ((D == 0 && E == 0) || (D == 1)))
							{
								if (A)
									printf("A,");
								if (B)
									printf("B,");
								if (C)
									printf("C,");
								if (D)
									printf("D,");
								if (E)
									printf("E,");
								if (F)
									printf("F,");
								printf("\n");
							}
						}
	return 0;
}