#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int y, x0, xl;
	int k, b, e;
    scanf("%d", &k);
    scanf("%d", &b);
    scanf("%d", &e);
    scanf("%d", &x0);
    scanf("%d", &xl);
    srand(time(NULL));


    FILE *file = fopen("test", "w+");
    FILE *file1 = fopen("plot", "w+");	
    FILE *file2 = fopen("polynom.gnu", "w+");
        	
    fprintf(file2, "plot %d*x+%d,", k, b);
    fprintf(file2, "%d*x+%d,", k, b+e);
    fprintf(file2, "%d*x+%d,", k, b-e);
    fprintf(file2, "'plot',");
	fprintf(file, "%d\n1\n", xl-x0);
    for (; x0 <= xl ; x0++)
	{
		
		y = k*x0+b-e;
		y = y + rand()%(2*e);
		fprintf(file, "%d %d\n", x0, y);
		fprintf(file1, "%d %d\n", x0, y);
	}

    
fclose(file);
fclose(file1);
fclose(file2);
	
	return 0;
}
