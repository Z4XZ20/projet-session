#include <stdio.h>
#include "../src/tools.h"


void main() {

int nb_ligne=0;
int error_flag=0;

/*check if the .txt is empty*/
nb_ligne=checkfile_lenght();

if(nb_ligne==0)
{   
    /*if empty then we write database*/
    write_database();
}

    /*putting the database in RAM for easier mpdification*/

Database *livre = (Database*)malloc(nb_ligne * sizeof(Database));

if(livre == NULL)
{
    printf("error");
}

store_data(livre,nb_ligne);



} 