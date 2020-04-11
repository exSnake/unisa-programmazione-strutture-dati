#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "item.h"

FILE *Fopen(const char *path, const char *mode);

int main(int argc, char *argv[]){
	float x, y, d;
	if (argc < 1)
		printf("Passare come argomento il file in ingresso contenente i punti");

	FILE *fp = Fopen(argv[1],"r");
	list l = new_list();
	fscanf(fp, "%f", &d); //distanza
	while(!feof(fp)){
		fscanf(fp,"%f%f",&x, &y);
		item p = new_item(x, y);
		cons_list(p,l);
	}
	fclose(fp);
	list tmp = clone_list(l);
	int m = 0;
	int p1_pos = 0, p2_pos = 0;
	float dist = 0;
	for(int i = 0; i < size_list(l); i++)
		for (int j = i + 1; j < size_list(l); j++){
			float tmpdst = distanza(get_item(l,i), get_item(l,j));
			if (tmpdst < d)
				m++; //numero coppie punti a distanza minore di d
			if (tmpdst > dist){
				p1_pos = i;
				p2_pos = j;
				dist = tmpdst;
			}
		}

	printf("Le coppie di punti a distanza minore di %.2f sono %d\n", d, m);
	printf("La coppia di punti con piu distanza tra di loro (%.2f) e' la seguente:\n",dist);
	output_item(get_item(l, p1_pos));
	output_item(get_item(l, p2_pos));
}

FILE *Fopen(const char *path, const char *mode)
{
	FILE *f = fopen(path, mode);
	if (f == NULL)
	{
		perror(path);
		printf("Impossibile aprire il file\n");
		exit(EXIT_FAILURE);
	}
	return f;
}

/*FILE *fd;
	//apre il file

	int n = 0, m=0;
	float d = 0;
	float ascissa, ordinata;
	item p;
	
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
		p[n] = new_item(ascissa, ordinata);
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
	return 0;*/