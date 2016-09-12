#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

double getRandomNumber(const double min, const double max)
{
	double temp = (double)rand() / (double)RAND_MAX;
	temp = min + (max - min)*temp;

	return temp;
}

bool isInsideDumbel(const double x, const double y)
{
	const double x_c = 0.5;
	const double y_c = 0.5;
	const double r = 0.5;

	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;

	if (f > 0.0) return false;
	else return true;
}

void main()
{
	FILE *of = fopen("Dumbel.txt", "w");
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10000; i++)
	{
		double x = getRandomNumber(0.0, 1.0);
		double y = getRandomNumber(0.0, 1.0);
		double z = getRandomNumber(0.7, 2.0);
		double w = getRandomNumber(0.25, 0.75);

		if (isInsideDumbel(x, y) == true)
		{
			fprintf(of, "%f, %f\n", x, y);
			fprintf(of, "%f, %f\n", x + 1.8, y);
		}
		fprintf(of, "%f, %f\n", z, w);

	}

	fclose(of);

}