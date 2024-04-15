#include <stdio.h>
#include "../src/tools.h"


void main() {

int error_flag=0,i;
Database database;
int *match;
/*check if the .txt is empty*/

database.nb_livre = checkfile_lenght();

if(database.nb_livre<5)
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

match=search_book(&database);
for(i=1;i<=match[0];i++)
{
    printf("%d ",match[i]);
}
//add_book(&database);

//remove_book(&database,match);

//rent_a_book(&database,match);

//return_book(&database,match);

save_change(&database);

} 