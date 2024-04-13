#include <stdio.h>
#include "../src/tools.h"


void main() {


int error_flag=0;
Database database;

/*check if the .txt is empty*/
database.nb_livre=checkfile_lenght();

if(database.nb_livre==0)
{   
    /*if empty then we write database*/
    write_database();
}

    /*putting the database in RAM for easier mpdification*/

database.livre = (Livre*)malloc(database.nb_livre * sizeof(Livre));

if(database.livre == NULL)
{
    printf("error");
    return;
}

//store_data(&database);
add_book(&database);

} 