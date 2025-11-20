#include <stdio.h>
int main(void)
{
	const float CHARGE_E = -1.602177e-19f;
	printf("Electron: q = %f C\n", CHARGE_E);
	printf("Electron: q = %e C\n", CHARGE_E);
	printf("Electron: q = %.1e C\n", CHARGE_E);
	getchar();
	return 0;
}