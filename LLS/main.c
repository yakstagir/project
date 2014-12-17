#include <stdio.h>
#include <stdlib.h>
#include <math.h>	


int main(int argc, char* argv[])
{

	int n, m;
	FILE *file, *file1;

	if (argc == 2){
		printf("Enter number of points = \n");
		file1 = fopen("plot", "w+");
	}
	scanf("%d", &n);
	if (argc == 2)
		printf("Enter polynom degree = \n");
scan:
	scanf("%d", &m);
	if (m >= n) {printf("Enter polynom degree < number of ponts\n"); goto scan;}
	double *x, *y;

	int i = 0, j, k;		
	if (((x = (double *)malloc(n*sizeof(double)))==NULL) || ((y = (double*)malloc(n*sizeof(double)))==NULL)){
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}
	while (i<n){
		scanf("%lf", &x[i]);
		scanf("%lf", &y[i]);

	if (argc == 2) fprintf(file1, "%lf %lf\n", x[i], y[i]);
		i++;
	}

	double **a;
	//~ Выделение памяти для матрицы базисных функций	
	if ((a = (double **)malloc((n)*sizeof(double*)))==NULL){
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}
	for (i = 0; i < n; i++)
		if ((a[i] = (double *)malloc((m+1)*sizeof(double)))==NULL){
			printf("Ошибка при распределении памяти\n");
			exit(1);
		}

	//~ Процедура получения матрицы значений базисных функция
	for (i = 0; i < n; i++)
		for (j = 0; j <= m ; j++)
		{
			a[i][j] = pow(x[i], (double)j);
		}	
	

	
	//~ Выделение памяти для траспонированной матрицы А
	//~ double **at;
	//~ if ((at = (double **)malloc((m+1)*sizeof(double*)))==NULL){
		//~ printf("Ошибка при распределении памяти\n");
		//~ exit(1);
	//~ }
	//~ for (i = 0; i <= m; i++)
		//~ if ((at[i] = (double *)malloc((n)*sizeof(double)))==NULL){
			//~ printf("Ошибка при распределении памяти\n");
			//~ exit(1);
		//~ }

	//~ Транспонированная матрица A

	//~ for (i = 0; i <= m; i++)
		//~ for (j = 0; j < n ; j++){
			//~ at[i][j] = a[j][i];
				//~ 
		//~ }
	//~ for (i = 0; i < m+1; i++){
		//~ for (j = 0; j < n ; j++){
			//~ printf("%0.lf\t",at[i][j]);
		//~ }
		//~ printf("\n");
	//~ }
	//~ return 0;			
		
	//~ Выделение памяти для матрицы С
	double **c;
	if ((c = (double **)malloc((n)*sizeof(double*)))==NULL){
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}
	for (i = 0; i < n; i++)
		if ((c[i] = (double *)malloc((n)*sizeof(double)))==NULL){
			printf("Ошибка при распределении памяти\n");
			exit(1);
		}
	//~ В матрице C результат умножения At на A		
	for (i = 0; i <= m; i++)

		for (k = 0; k <=  m ; k++)
		{
			c[i][k]=0;
			for (j = 0; j < n; j++)	
				//~ c[i][k] += at[i][j]*a[j][k];
				c[i][k] += a[j][i]*a[j][k];
		}
	//~ for (i = 0; i <= m; i++){
		//~ for (j = 0; j <= m ; j++){
			//~ printf("%0.lf\t",c[i][j]);
		//~ }
		//~ printf("\n");
	//~ }
	//~ return 0;

	//~ Единичная матрица
	double **crev;
	if ((crev = (double **)malloc((m+1)*sizeof(double*)))==NULL){
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}
	for (i = 0; i < m+1; i++)
		if ((crev[i] = (double *)malloc((n)*sizeof(double)))==NULL){
			printf("Ошибка при распределении памяти\n");
			exit(1);
		}


	for(i=0;i<m+1;i++)
	{
		for(j=0;j<m+1;j++)
			crev[i][j]=0;
		crev[i][i]=1;
	}


	//~ Нахождение треугольной матрицы

	double aa, bb;
	for(i=0;i<m+1;i++)
	{
		aa=c[i][i];
		for(j=i+1;j<m+1;j++)
		{
			bb=c[j][i];
			for(k=0;k<m+1;k++)
			{
				c[j][k]=c[i][k]*bb-c[j][k]*aa;
				crev[j][k]=crev[i][k]*bb-crev[j][k]*aa;
			}
		}
	}
		//~ for (i = 0; i <= m; i++){
		//~ for (j = 0; j <= m ; j++){
			//~ printf("%lf\t",c[i][j]);
		//~ }
		//~ printf("\n");
	//~ }

	//~ Нахождение обратной матрицы Сrev


	double sum;
	for(i=0;i<m+1;i++)
	{
		for(j=m;j>=0;j--)
		{
			sum=0;
			for(k=m;k>j;k--)
				sum+=c[j][k]*crev[k][i];
			if(c[j][j]==0)
			{
				return 0;
			}
			crev[j][i]=(crev[j][i]-sum)/(c[j][j]);
		}
	}

		
		
	for (i = 0; i <= m; i++)
		for (k = 0; k < n ; k++)
		{
			c[i][k]=0;
			for (j = 0; j <= m; j++)	
				c[i][k] += crev[i][j]*a[k][j];	
				//~ c[i][k] += crev[i][j]*at[j][k];	
		}
		


	//~ for (i = 0; i <= m; i++){
		//~ for (j = 0; j < n ; j++){
			//~ printf("%lf\t",c[i][j]);
		//~ }
		//~ printf("\n");
	//~ }



	double* yy;
	if ((yy = (double *)malloc((m+1)*sizeof(double)))==NULL){
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}


	for (i = 0; i <= m; i++){
		yy[i]=0;
		for (k = 0; k <  n ; k++)
			yy[i] += c[i][k]*y[k];	
	}
	
if (argc == 2)	{
  file = fopen("polynom.gnu", "w+");
	fprintf(file, "plot ");
	    fprintf(file, "'plot',");}
else 
  file = fopen("polynom.gnu", "a+");

  	for (i = 0; i <= m; i++)
	{
		if (yy[i] > 0 && i>0){
			fprintf(file, "+");
			printf("+");}
		fprintf(file, "%f*x**%d", yy[i], i);
		printf("%f*x**%d", yy[i], i);
		
	}
	fprintf(file, "\npause -1 ");
	fclose(file);
	if (argc==2) fclose(file1);	
	printf("\n");
	
		
	free(x);
	free(y);
	return 0;
}			


	//~ for (i = 0; i < n; i++){
		//~ for (j = 0; j <= m ; j++){
			//~ printf("%0.lf\t",a[i][j]);
		//~ }
		//~ printf("\n");
	//~ }
