#include "../src/tools.h"



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
            *book_name= "Dream of the Red Chamber ,Cao Xueqin";
    
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
            *book_name= "Harry Potter and the Deathly Hallows ,J.K. Rowling";
    
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
        fprintf(fptr,"|   0   |    --    |\n");
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
    for(i=1;i<lenght-2;i++)     /*keep in memory the placement of the different info in the .txt*/
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
                 if(isupper(temp[i]))                /*transform uppercase to lowercase for research function*/
                {
                    nom_recherche[i-3]=temp[i]+32; 
                }
                else
                {
                    nom_recherche[i-3]=temp[i];
                }
                if(book_read>10)
                {
                   nom[i-3]=temp[i+1]; 
                }
                else
                {
                   nom[i-3]=temp[i];  
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
    nb_ligne=(nb_ligne/2);
    free(test);
    fclose(fptr);
    return nb_ligne;
}

void add_book(Database *database)/*add book to RAM storage*/
{
    char *temp,*array_disp,*array_date;
    int length,i;
    
    temp=(char*)malloc(100*sizeof(char*));
    array_disp=(char*)malloc(15*sizeof(char*));
    array_date=(char*)malloc(15*sizeof(char*));
    array_disp="   0   ";
    array_date="    --    ";
    printf("Quel est le nom de livre et nom de l'auteur a ajouter a la base de donnée:");
    scanf(" %[^\n]%*c", temp);
    /*if book name is valid add to database*/

    database->nb_livre++;
    strcpy(database->livre[database->nb_livre].nom,temp);
    strcpy(database->livre[database->nb_livre].disponible,array_disp);
    strcpy(database->livre[database->nb_livre].date_retour,array_date);
    printf("\nLe livre a bien ete ajouter!");

}

void remove_book(Database *database,int* match)/*remove book from RAM storage*/
{
    int select,i;
    for(i=1;i<=match[0];i++)
    {
        printf("%d- %s\n",i,database->livre[match[i]].nom);
    }
    
    printf("Select the book you mean to remove(enter number ,0 to escape):");
    scanf("%d",&select);
    if(select>match[0]||select<=0)             //error
    {
        printf("\nwrong choice");
        return 1;
    }
    /*if book name is valid remove to database*/

    strcpy(database->livre[match[select]].nom,"\0");
    strcpy(database->livre[match[select]].disponible,"\0");
    strcpy(database->livre[match[select]].date_retour,"\0");

    for(i=match[select];i<=database->nb_livre;i++)
    {
            strcpy(database->livre[i].nom,database->livre[i+1].nom);
            strcpy(database->livre[i].disponible,database->livre[i+1].disponible);
            strcpy(database->livre[i].date_retour,database->livre[i+1].date_retour);
    }
    database->nb_livre--;
    printf("\nLe livre a bien ete supprimer!");
}

int* search_book(Database *database)/*search book in RAM storage*/
{
    char *temp;
    int i,length,id;
    int *match;
    temp=(int*)malloc(20*sizeof(int*));
    printf("\n Quel livre rechercher vous? :");
    scanf(" %[^\n]%*c", temp);
    length=strlen(temp);
    if(length<=3)
    {
        printf("\n-----------name too short-----------\n");
        return 1;
    }

    for(i=0;i<length;i++)
    {
        if(isupper(temp[i]))
        {
            temp[i]=temp[i]+32;
        }
    }

    match=compare(database,temp);
        
}

int *compare(Database *database,char *temp)/*compare string*/
{
    int i,u=1,length;
    char *id;
    int *match;
    match=(int*)malloc(5*sizeof(int*));
    for(i=0;i<database->nb_livre+1;i++)
    {
        id=strstr(database->livre[i].nom_recherche,temp);
        if(id == NULL)
        { 
            //nothing happens
        }
        else
        {
            match[u]=i;
        
            u++; 
            if(u>5) 
            {
                match[0]=u-1;
                return match;
            }
        }
    }
    match[0]=u-1;
    length=strlen(temp);
    if(match[0]<=0)
    {   
        temp[length-1] = '\0';
        length--;
        match=compare(database,temp);
    }
    return match;
}

void rent_a_book(Database *database,int* match)/*rent a specified book for 1 week*/
{
    int i,select;
    char id=0;
    time_t current_time = time(NULL);
    struct tm *timeStruct = localtime(&current_time);
    timeStruct->tm_mday += 7;
    time_t modifiedTime = mktime(timeStruct);
    char return_time[20];
    strftime(return_time, sizeof(return_time), "%Y-%m-%d", timeStruct);

    printf("\nselectionnez le livre a emprunter(entrez le numero ,0 pour quitter ce menu):");
    scanf("%d",&select);
    if(select>match[0]||select<=0)             //error
    {
        printf("\nwrong choice");
        if(select==0)
        {return;}
    }

    printf("\n- %s\n",database->livre[match[select]].nom);
    
    for(i=0;i<7;i++)
    {
        if(database->livre[match[select]].disponible[i]=='1')
        {
            id++;
        }
    }

    if(id>0)
    {
        printf("\nle livre est emprunter jusqu'aux: %s\n",database->livre[match[select]].date_retour);
        
    }
    else
    {
        printf("\nlivre empunter avec succès! date de retour: %s", return_time);
        
        
        strcpy(database->livre[match[select]].disponible,"   1   ");
        
        
        strcpy(database->livre[match[select]].date_retour,return_time);

    }

}

void return_book(Database *database,int* match)/*return a rented book and id if return late*/
{
    char date[25];
    time_t current_time = time(NULL);
    strftime(date, 25, "%Y-%m-%d", localtime(&current_time));
    int current_day,current_month,book_month,book_day,i,length,select,id=0;
    printf("selectionnez le livre a retourner(entrez le numero ,0 pour quitter ce menu):");
    scanf("%d",&select);
    if(select>match[0]||select<=0)             //error
    {
        printf("\nwrong choice");
        if(select==0)
        {return;}
    }
    
    for(i=0;i<7;i++)
    {
        if(database->livre[match[select]].disponible[i]=='0')
        {
            id++;
        }
    }

    if(id>0)
    {
        printf("\nle livre n'est pas emprunter ");

        return;
    }
    //extract the return date month day and put them in decimal for actual date
    length=strlen(date);
    for(i=0;i<=length;i++)
    {
            if(i==5)
            {
                current_month = (date[i]-48) *10;
            }
            if(i==6)
            {
                current_month = current_month + (date[i]-48);
            }

            if(i==8)
            {
                current_day = (date[i]-48) *10;
            }
            if(i==9)
            {
                current_day = current_day + (date[i]-48);
            }
    }
    //extract the return date month day and put them in decimal for selected book
    length=strlen(database->livre[match[select]].date_retour);
    for(i=0;i<=length;i++)
    {
            if(i==5)
            {
                book_month = (database->livre[match[select]].date_retour[i]-48) *10;
            }
            if(i==6)
            {
                book_month = book_month + (database->livre[match[select]].date_retour[i]-48);
            }

            if(i==8)
            {
                book_day = (database->livre[match[select]].date_retour[i]-48) *10;
            }
            if(i==9)
            {
                book_day = book_day + (database->livre[match[select]].date_retour[i]-48);
            }
    }

        printf("\nLivre retouner avec succes!");

    strcpy(database->livre[match[select]].disponible,"   0   ");

    strcpy(database->livre[match[select]].date_retour,"    --    ");

    if(book_month==current_month)
    {
        if(current_day>book_day)
        {
            printf("\nretour de livre en retard, penalité appliquer");
        }
    }
    else
    {
        if(current_month>book_month)
        {
            printf("\nretour de livre en retard, penalité appliquer");
        }
    }

}

void save_change(Database *database)/*save change in database .txt file*/
{   
    int i,temp;
    FILE *fptr;  
    fptr = fopen("Database.txt","w");
    fprintf(fptr,"   nom du livre                                                 |status | Date de retour |\n");
    for(i=2;i<=database->nb_livre;i++)
    {   
        fprintf(fptr,"\n%d- %s",i-1,database->livre[i].nom);
        temp=strlen(database->livre[i].nom);
        for(temp=60-temp;temp>0;temp--)
        {
            fprintf(fptr," ");
        }
        fprintf(fptr,"|%s|",database->livre[i].disponible);
        fprintf(fptr,"%s|\n",database->livre[i].date_retour);
        
    }
    fclose(fptr);
}

void menu_default()  /*main menu and call next page*/
{
    char option;
    system("clear");
    printf("┌───────────────────────────────────────────┐\n");
    printf("│                                           │\n");
    printf("│       ╔═══════════════════════════╗       │\n");
    printf("│       ║    BIENVENUE À LA         ║       │\n");
    printf("│       ║    BIBLIOTHÈQUE UQTR      ║       │\n");
    printf("│       ╚═══════════════════════════╝       │\n");
    printf("│                                           │\n");
    printf("│  ╔═══════════════════════════════════╗    │\n");
    printf("│  ║ 1. Rechercher                     ║    │\n");
    printf("│  ╟───────────────────────────────────╢    │\n");
    printf("│  ║ 2. Ajout de livre                 ║    │\n");
    printf("│  ╟───────────────────────────────────╢    │\n");
    printf("│  ║ 3. Suppresion de livre            ║    │\n");
    printf("│  ╟───────────────────────────────────╢    │\n");
    printf("│  ║ 4. Quitter                        ║    │\n");
    printf("│  ╚═══════════════════════════════════╝    │\n");
    printf("└───────────────────────────────────────────┘\n");
    printf("appuyer sur '0' en cas d'erreur avec la base de données\n");
    printf("Veuillez selectionner l'une des quatres options suivantes :\n");
    
}

void rechercher_menu()
{
    system("clear");
    printf("┌───────────────────────────────────────────┐\n");
    printf("│                                           │\n");
    printf("│       ╔═══════════════════════════╗       │\n");
    printf("│       ║        RECHERCHER         ║       │\n");
    printf("│       ╚═══════════════════════════╝       │\n");
    printf("│                                           │\n");
    printf("└───────────────────────────────────────────┘\n");

}

void resultats_recherche(Database *database,int *match)
{
    int spaces,i,choice=0,out=0;
    system("clear");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│                                                            │\n");
    printf("│               ╔═══════════════════════════╗                │\n");
    printf("│               ║   5 meilleurs résultats   ║                │\n");
    printf("│               ╚═══════════════════════════╝                │\n");

    if(match[0]>0)
    {   
        for(i=1;match[0]>=i;i++)
        {
            printf("│%d-%s",i,database->livre[match[i]].nom);   
            spaces=stringcounter(database->livre[match[i]].nom);
            while(spaces<58)
            {
                printf(" ");
                spaces++;
            }
            printf("│\n");
        }
    }
    else
    {
    printf("│       -------------aucun livre trouver-------------        │\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    }

    printf("│                                                            │\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("Quel action voulez vous effectuer (1=louer livre) (2=retourner livre) :");
 
    do
    {
        scanf("%d",&choice);
        if(choice==1||choice==2)
        {
            out++;
        }
        else
        {
        printf("\nValeur non valide, entrez a nouveau:");
        }
    }
    while(out==0);
    
    if(choice==1)
    {
        rent_a_book(database,match);
        printf("\nEntrer une valeur pour continuer(ex: 1-9):");
        scanf("%d",&out);
    }
    if(choice==2)
    {
        return_book(database,match);
        printf("\nEntrer une valeur pour continuer(ex: 1-9):");
        scanf("%d",&out);
    }
}

void ajoutLivre(Database *database)
{
    int wait;
    printf("┌────────────────────────────────────────────────┐\n");
    printf("│                                                │\n");
    printf("│         ╔═══════════════════════════╗          │\n");
    printf("│         ║     Ajouter un livre      ║          │\n");
    printf("│         ╚═══════════════════════════╝          │\n");
    printf("│                                                │\n");
    printf("└────────────────────────────────────────────────┘\n");
    add_book(database);
    printf("\nEntrer une valeur pour continuer(ex: 1-9):");
    scanf("%d",&wait);
}

void suppressionLivre(Database *database,int *match)
{
    int wait;
    printf("┌────────────────────────────────────────────────┐\n");
    printf("│                                                │\n");
    printf("│         ╔═══════════════════════════╗          │\n");
    printf("│         ║    Suppresion de livre    ║          │\n");
    printf("│         ╚═══════════════════════════╝          │\n");
    printf("│                                                │\n");
    printf("└────────────────────────────────────────────────┘\n");
    remove_book(database,match);
    printf("\nEntrer une valeur pour continuer(ex: 1-9):");
    scanf("%d",&wait);
}

void quitter(Database *database)
{
    save_change(database);
    printf("\nMerci d'avoir utilisé la bibliotheque UQTR\n");
    exit(0);
}

