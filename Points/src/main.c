#include <stdio.h>
#include <stdlib.h>
#include "punto.h"


int main(int argc, char *argv[])
{
	FILE *fd;
	//apre il file

	int n = 0, m=0;
	float d = 0;
	float ascissa, ordinata;
	punto *p;
	
	if(argc < 1)
		printf("Non c'e un file in ingresso");
	
	char* file_name = argv[1];
	fd = fopen(file_name, "r");
	while (!feof(fd))
		n++; //lettura numero punti - 1 perche il primo e' la distanza
	
	fclose(fd);
	p = malloc(sizeof(punto) * (n-1));
	fd = fopen(file_name, "r");
	fscanf(fd, "%f", &d); //distanza
	while(!feof(fd)){
		fscanf(fd,"%f%f",&ascissa, &ordinata);
		p[n] = creapunto(ascissa, ordinata);
		n++;
	}
	fclose(fd);

	for (int i=0; i<n-1; i++){
	  for (int j = i+1; j < n; j++){
		  if(distanza(p[i],p[j]))
			  m++;
	  }
	}

	printf("Le coppie di punti a distanza minore di %f sono %d", d, m);

	system("PAUSE");
	return 0;
}
