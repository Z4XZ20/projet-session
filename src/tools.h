#ifndef TOOLS_H
#define TOOLS_H
#include <stdlib.h>




// insert CODE here 



void test();
void write_database();
const char* book_inv(int i);
int stringcounter();
void search();
int id_parts(char *look_search);
int reducer( char *text);
int checkfile_lenght();

typedef struct etat_livre{
    char nom_livre[60];
    int disponible;
    char date_retour[20];
} Livre;
#endif