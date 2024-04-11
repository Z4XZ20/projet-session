#ifndef TOOLS_H
#define TOOLS_H
#include <stdlib.h>




// insert CODE here 

typedef struct etat_livre{
    char nom_livre[60];
    int disponible;
    char date_retour[20];
} Database;


void write_database();
const char* book_inv(int i);
int stringcounter();
void search();
int id_parts(char *temp,struct etat_livre *Livre,int book_read);
int reducer( char *text);
int checkfile_lenght();
int store_data(struct etat_livre *Livre,int nb_ligne);



#endif