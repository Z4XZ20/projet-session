#ifndef TOOLS_H
#define TOOLS_H
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct etat_livre{
    char nom[60];
    char nom_recherche[60];
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
void store_data(Database *database);
void id_parts(Database *database,char *temp,int book_read);
const char* book_inv(int i);
int stringcounter();
int checkfile_lenght();
int *compare(Database *database,char *temp);
int *search_book(Database *database);
void rent_a_book(Database *database,int* match);
void return_book(Database *database,int* match);
void add_book(Database *database);
void remove_book(Database *database,int* match);


#endif