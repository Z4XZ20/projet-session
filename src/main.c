#include <stdio.h>
#include "../src/tools.h"


void main() {

int nb_ligne=0;

nb_ligne=checkfile_lenght();
if(nb_ligne=0)
{
    write_database();
}


} 