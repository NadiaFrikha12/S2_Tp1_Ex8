//Ecrire un programme qui duplique un fichier. Le nom de la copie sera formé à
//partir du nom du premier auquel on ajoute 2 avant l’extension. Par exemple de «
//fichier.ext » aura pour nom « fichier2.ext ».

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	
	FILE *fp1; //le fichier a ouvrir
	FILE *fp2; //le fichier dupliqué
	char nom[10]; //le nom du fichier à ouvrir
	char nom2[11]; //le nom du nouveau fichier 
	char ligne[100]; //pour désignier les lignes du fichier
	int i=0,j=0; //compteurs
	
	//lire le nom du fichier à dupliquer
	printf("donner le nom du fichier a dupliquer : ");
	gets(nom);
	

	//ouvrir le fichier en mode read
	fp1=fopen(nom,"r");
	
	//verifier si le pointeur du fichier est valide
	if (fp1 == NULL){
		printf("le fichier n'a pas pu etre ouvert");
		return 0;
	}
	
	// Construire le nom du nouveau fichier
	strcpy(nom2, nom);
	int len = strlen(nom2);

	// Trouver l'index du point avant l'extension
	int index = len - 1;
	while (index >= 0 && nom2[index] != '.'){
		index--;
	}

	// Ajouter "2" avant l'extension
	strcpy(nom2 + index, "2"); //copie la chaîne "2" à partir de l'index du dernier point trouvé dans nom2
	strcat(nom2, nom + index); //ajouter '.txt' à la fin 
	
	
	//ouvrir un nouveau fichier en mode write 
	fp2=fopen(nom2,"w");
	
	//verifier si le pointeur du fichier est valide
	if (fp2 == NULL){
		printf("le nouveau fichier n'a pas pu etre dupliquer");
		return 0;
	}
	
	//dupliquer le ficher
	while ((fgets(ligne,sizeof(ligne),fp1)) != NULL){
		fprintf(fp2,"%s",ligne);
	}
	
	printf("fichier duplique !");
	//fermuture des fichier 
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}
	
