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

void write_database() /*open file and overwrite database at start*/
{   
    int i,temp;
    FILE *fptr;                      
    fptr = fopen("Database.txt","w");
    fprintf(fptr,"\n   nom du livre                                                 |status | Date de retour |\n");
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
    
}

int stringcounter(char *book_name)/*count the full length of a string and return the number*/
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

void search()/*recherche les livres dans la database*/
{   
    const int standard=100;
    char *look;
    char sizelook=0;
    look=malloc(standard * sizeof(char));       /* give standard value before resizing to right size*/
    scanf("%s",look);
    sizelook=stringcounter(look);
    printf("%d %s\n",sizelook,look);
    look=malloc(sizelook+1 * sizeof(char));
    reducer(*look);
}

void reducer( char **look)/*goes trough a string a convert uppercase to lower case*/
{                                 /*to facilitate the search process*/
    printf("1- %s",look);
}


int id_parts()/*dissassemble the different part of the search result string into component and return them in 3 different variable */
{                              /*ex: name | status | date de retour */

}



/*convert ascii letter from upper to lower =+32 on ascii code*/
/*    char book[30];
    printf("nom du livre: ");
    fgets(book,30,stdin);

    printf("book is: %s",book);*/
