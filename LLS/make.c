#include <stdio.h>
int main(){
	int d;
	printf("Enter 1 for 1st test degree = 1\nEnter 2 for 2nd test degree = 2\nor 3 for keyboard input\n");
	scanf("%d", &d);
	if (d == 3){

		system("gcc main.c -lm && ./a.out key");
		system("gnuplot polynom.gnu");
	}
	else
		if (d == 2){
			system("gcc parabola.c -lm && ./a.out < parab");	
			system("gcc main.c -lm && ./a.out < test");
			system("gnuplot polynom.gnu");}
		else if (d == 1){
			system("gcc generator.c -lm && ./a.out < gener");
			system("gcc main.c -lm && ./a.out < test");
			system("gnuplot polynom.gnu");}
		else if	(d == 4){
			system("gcc generator.c -lm && ./a.out < gener");
			system("gcc main.c -lm && ./a.out < пример");
			system("gnuplot test.gnu");}
		else
			printf("ERROR");
	return 0;
}
