#ifndef TOOLS_H
#define TOOLS_H
#include <stdlib.h>




// insert CODE here 

struct etat_livre{
    char nom[60];
    char disponible[60];
    char date_retour[60];
    int lenght;
};
typedef struct etat_livre Livre;

struct database{
   
    int nb_livre;
    Livre *livre;

};
typedef struct database Database;



void write_database();
const char* book_inv(int i);
int stringcounter();
void search();
void store_data(Database *database);
void id_parts(Database *database,char *temp,int book_read);
int reducer( char *text);
int checkfile_lenght();



#endif