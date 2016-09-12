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

bool isInsideEllipse(const double x, const double y)
{
	const double x_c = 0.5;
	const double y_c = 0.5;
	const double r = 0.5;
	const double z = 0.25;

	const double f = (x - x_c)*(x - x_c) / (r*r) + (y - y_c)*(y - y_c) / (z*z);

	if (f > 1.0) return false;
	else return true;
}

void main()
{
	FILE *of = fopen("Ellipse.txt", "w");
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10000; i++)
	{
		double x = getRandomNumber(0.0, 1.0);
		double y = getRandomNumber(0.0, 0.8);

		if (isInsideEllipse(x, y) == true)
			fprintf(of, "%f, %f\n", x, y);
	}

	fclose(of);

}