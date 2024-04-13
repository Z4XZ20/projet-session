#include "../src/tools.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>



const char* book_inv(int i) /*contains all the book names*/
{                                                    /*taille tableau bookname, default 50*/
    char book_name[60];
    
    switch(i)
    {
        case 1:;
            *book_name= "Don Quixote ,Miguel de Cervantes";
            
    
        break;

        case 2:;
            *book_name= "A Tale of Two Cities ,Charles Dickens";
    
        break;

        case 3:;
            *book_name= "Le Petit Prince ,Antoine de Saint-Exupery";
    
        break;
        case 4:;
            *book_name= "Harry Potter and the Sorcerer's Stone ,J.K. Rowling";
    
        break;
        case 5:;
            *book_name= "And Then There Were None ,Agatha Christie";
    
        break;
        case 6:;
            *book_name= " Dream of the Red Chamber ,Cao Xueqin";
    
        break;
        case 7:;
            *book_name= "The Hobbit ,J.R.R. Tolkien";
    
        break;
        case 8:;
            *book_name= "The Lion, the Witch and the Wardrobe ,C.S. Lewis";
    
        break;
        case 9:;
            *book_name= "She: A History of Adventure ,H. Rider Haggard";
    
        break;
        case 10:;
            *book_name= "Vardi Wala Gunda ,Ved Prakash Sharma";
    
        break;
        case 11:;
            *book_name= "The Da Vinci Code ,Dan Brown";
    
        break;
        case 12:;
            *book_name= "Harry Potter and the Chamber of Secrets ,J.K. Rowling";
    
        break;
        case 13:;
            *book_name= "The Alchemist ,Paulo Coelho";
    
        break;
        case 14:;
            *book_name= "Harry Potter and the Prisoner of Azkaban ,J.K. Rowling";
    
        break;
        case 15:;
            *book_name= "Harry Potter and the Goblet of Fire ,J.K. Rowling";
    
        break;
        case 16:;
            *book_name= "Harry Potter and the Order of the Phoenix ,J.K. Rowling";
    
        break;
        case 17:;
            *book_name= "Harry Potter and the Half-Blood Prince ,J.K. Rowling";
    
        break;
        case 18:;
            *book_name= " Harry Potter and the Deathly Hallows ,J.K. Rowling";
    
        break;
        case 19:;
            *book_name= "The Catcher in the Rye , J.D. Salinger";
    
        break;
        case 20:;
            *book_name= "The Bridges of Madison County ,Robert James Waller";
    
        break;
        case 21:;
            *book_name= "Ben-Hur: A Tale of the Christ ,Lew Wallace";
    
        break;
        case 22:;
            *book_name= "One Hundred Years of Solitude ,Gabriel Garcia Marquez ";
    
        break;
        case 23:;
            *book_name= "Lolita ,Vladimir Nabokov";
    
        break;
        case 24:;
            *book_name= "Heidi ,Johanna Spyri";
    
        break;
        case 25:;
            *book_name= "Anne of Green Gables ,Lucy Maud Montgomery";
    
        break;
        case 26:;
            *book_name= "Black Beauty ,Anna Sewell";
    
        break;
        case 27:;
            *book_name= "The Name of the Rose ,Umberto Eco";
    
        break;
        case 28:;
            *book_name= "The Eagle Has Landed ,Jack Higgins";
    
        break;
        case 29:;
            *book_name= "Watership Down ,Richard Adams";
    
        break;
        case 30:;
            *book_name= "Charlotte's Web ,E.B. White";
    
        break;
        default:;
            *book_name= "error";
    
        break;

        return book_name;
    }


}

void write_database() /*open file and overwrite database at start if database doesnt exist*/
{   
    int i,temp;
    FILE *fptr;                      
    fptr = fopen("Database.txt","w");
    fprintf(fptr,"   nom du livre                                                 |status | Date de retour |\n");
    for(i=1;i<=30;i++)
    {   
       
        fprintf(fptr,"\n%d- %s",i,book_inv(i));
        temp=stringcounter(book_inv(i));
        
        if(i<10){fprintf(fptr," ");}

        for(temp=60-temp;temp>0;temp--)
        {
            fprintf(fptr," ");
        }
        fprintf(fptr,"|   0   |       --       |\n");
    }
    fclose(fptr);
}

int stringcounter(char *book_name)/*count the full length of a string with spaces and return the number*/
{   
    int i,space=0,letter=0,total;


    for(i=0;book_name[i]!='\0';i++)
    {
        if(book_name[i]==' ')
        {
            space++;
        }
        else
        {
            letter++;
        }
    }

    total=letter+space;

    return total;
}

void id_parts(Database* database,char *temp,int book_read)/*dissassemble the different part of the search result string into component and return them in 3 different variable */
{                              /*ex: name | status | date de retour */
    int lenght=0;
    int pos1=0,pos2=0,i=0,u=0,t=0;
    char *nom,*nom_recherche,*disponible,*date;
    char c={'|'};
    char *interim;
    nom=(char*)malloc(60*sizeof(char*));
    disponible=(char*)malloc(60*sizeof(char*));
    date=(char*)malloc(60*sizeof(char*));
    nom_recherche=(char*)malloc(60*sizeof(char*));
    lenght=strlen(temp);
    if(lenght<=20)
    {
        return;
    }
    book_read++;
    for(i=1;i<lenght-2;i++)     /*keep in memory the placement of the differrent info in the .txt*/
    {
        if(temp[i]==c)
        {   
            if(pos1==0)
            {
                pos1=i;
            }
            pos2=i;
        }
    }
    for(i=3;i<lenght-2;i++)     /*put the different character in the right array for RAM storage and remove useless empty space*/
    {
        if(temp[i]!="" && temp[i+1]!="")
        {
            
            if(i<pos1-5)
            {   
                
                nom[i-3]=temp[i];
                if(isupper(temp[i]))                /*transform uppercase to lowercase for research function*/
                {
                    nom_recherche[i-3]=nom[i-3]+32;   
                }
                else
                {
                    nom_recherche[i-3]=temp[i];
                }
            }

            if(i>pos1 && i<pos2)
            {
                disponible[u]=temp[i];
                u++;
            }
            if(i>pos2)
            {
                date[t]=temp[i];
                t++;
            }
        }
    }  
    strcpy(database->livre[book_read].nom,nom);
    strcpy(database->livre[book_read].disponible,disponible);
    strcpy(database->livre[book_read].date_retour,date);
    strcpy(database->livre[book_read].nom_recherche,nom_recherche);
    free(nom);
    free(nom_recherche);
    free(disponible);
    free(date);
    
    return;

}

void store_data(Database *database)/*store data in the struct for easier modification and add*/
{
    FILE *fptr;
    char *temp;
    int book_read=0;
    int error=0,i,lenght;
    temp=(char*)malloc(250*sizeof(char*));
    
    fptr = fopen("Database.txt","r");
    if(fptr == NULL)
    {
        return 0;
    }

    while(fgets(temp,300,fptr)!=NULL)
    {   
        id_parts(database,temp,book_read);                                           /*send the current text string to being processed and stored*/
        lenght=strlen(temp);
        if(lenght>5)
        {
            book_read++;
        }
    }
    free(temp);
    fclose(fptr);
}

int checkfile_lenght()/*open file check for number of line and close*/
{
    int nb_ligne=1;
    FILE *fptr;
    char *test;
    test=(char*)malloc(250*sizeof(char*));
    fptr = fopen("Database.txt","r");
    if(fptr == NULL)
    {
        return 0;
    }
    while(fgets(test,300,fptr)!=NULL)
    {
        nb_ligne++;
    }
    nb_ligne=(nb_ligne/2)-1;
    free(test);
    fclose(fptr);
    return nb_ligne;
}

void add_book(Database *database)
{
    char *temp;
    int lenght,i;
    temp=(char*)malloc(100*sizeof(char*));
    printf("Quel est le nom de livre et nom de l'auteur a ajouter a la base de donnée?");
    scanf("%s",temp);
    if(strlen(temp)>65)
    {
        printf("Nom trop long");
        return;
    }
    /*if book name is valid add to database*/
    
    database->nb_livre++;
    database->livre = (Livre*)realloc(database->nb_livre * sizeof(Livre));
    
    if(database->livre == NULL)
    {
        printf("error");
        return;
    }
    
    for(i=0;database->nb_livre>=i;i++)
    {
        printf("%s",database->livre[i].nom);
    }
    lenght=strlen(temp);
    free(temp);
}
/*
void search()/*recherche les livres dans la database*//*
{   
    const int standard=100;
    char *look;
    char sizelook=0;
    look=malloc(standard * sizeof(char));       /* give standard value before resizing to right size*//*
    scanf("%s",look);
    sizelook=stringcounter(look);
    printf("%d %s\n",sizelook,look);
    look=malloc(sizelook+1 * sizeof(char));
    reducer(*look);
}
*/