#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main()
{
	int y, x0, xl;
	int a, b, c, e;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &e);
    scanf("%d", &x0);
    scanf("%d", &xl);
    srand(time(NULL));


    FILE *file = fopen("test", "w+");
    FILE *file1 = fopen("plot", "w+");	
    FILE *file2 = fopen("polynom.gnu", "w+");
        	
    fprintf(file2, "plot %d*x**2+%d*x+%d,", a, b, c);
    fprintf(file2, "%d*x**2+%d*x+%d,", a, b, c+e);
    fprintf(file2, "%d*x**2+%d*x+%d,", a, b, c-e);
    fprintf(file2, "'plot',");
	fprintf(file, "%d\n2\n", xl-x0);
    for (; x0 <= xl ; x0++)
	{
		
		y = a*pow(x0,2)+b*x0+c-e;
		y = y + rand()%(2*e);
		fprintf(file, "%d %d\n", x0, y);
		fprintf(file1, "%d %d\n", x0, y);
	}

    
fclose(file);
fclose(file1);
fclose(file2);
	
	return 0;
}
