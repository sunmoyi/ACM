#include<stdio.h>

int main(void)
{
	FILE *fp = fopen("c:\\wps\\bj\\std.dat", "a+");
	char str[] = "I am a student.";
	fprintf(fp, "%s\n", str);
	fclose(fp);
	return 0;
}