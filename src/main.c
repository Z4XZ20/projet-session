#include <stdio.h>
#include "../src/tools.h"


void main() {

int error_flag=0,i;
Database database;
int *match;
char option;
/*check if the .txt is empty*/

database.nb_livre = checkfile_lenght();

if(database.nb_livre<2)
{   
    /*if empty then we write database*/
    write_database();
    database.nb_livre = checkfile_lenght();
}

    /*putting the database in RAM for easier mpdification*/

database.livre = (Livre*)malloc(database.nb_livre * sizeof(Livre));

if(database.livre == NULL)
{
    printf("error");
    return;
}

store_data(&database);

do
{
menu_default();

    scanf("%c", &option);
    
    switch (option)
    {
        case '0':
        printf("overwriting Database");
        write_database();
        database.nb_livre = checkfile_lenght();
        store_data(&database);
        
        break;

        case '1':
        system("clear");
        rechercher_menu();
        match=search_book(&database);
        resultats_recherche(&database,match);
        
        break;

        case '2':
        system("clear");
        ajoutLivre(&database);
        break;

        case '3':
        system("clear");
        match=search_book(&database);
        suppressionLivre(&database,match);
        break;

        case '4':
        system("clear");
        quitter(&database);
        break;

        default :
        system("clear");
        menu_default();
    }

    

}while(1);
//match=search_book(&database);
/*for(i=1;i<=match[0];i++)
{
    printf("%d ",match[i]);
}*/
//add_book(&database);

//remove_book(&database,match);

//rent_a_book(&database,match);

//return_book(&database,match);

//save_change(&database);

} 