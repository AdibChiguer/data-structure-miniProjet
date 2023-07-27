#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

//1-
//definition des structures bigen
typedef struct Livre{
   int ISBN;
   char titre[MAX];
   int Stock;
   struct Livre *next;
}Livre;
typedef struct LSC{
   Livre *debut;
}LSC;
//definition des structures end
//2-
void initialise(LSC * liste){

    liste->debut = NULL;
}
//3-
void remplir(Livre* newLivre ,int ISBN, char* Titre, int Stock ){

    int i = 0 ;

    newLivre->ISBN = ISBN;
    newLivre->Stock = Stock;
    while(*(Titre + i) != '\0'){
            newLivre->titre[i] = *( Titre + i);
        i++;
    }
    newLivre->titre[i] = '\0';
}
//4-
void afficher(Livre * livre){
    int i = 0;
    printf("le titre de livre est : ");
    while( livre->titre[i] != '\0' ){
    printf("%c",livre->titre[i]);
    i++;
    }
    printf("\nle isbn de cette livre est : %d",livre->ISBN);
    printf("\nla quantite de cette livre est : %d \n",livre->Stock);
    printf("--------------------------------------------------\n");

}
//5-
void afficherListe(LSC *l){
    Livre *tmp = l->debut;
    if (tmp == NULL)
        return;
    while (tmp != NULL)
    {
        afficher(tmp);
        tmp = tmp->next;
    }
}
//6-
Livre * chercher(LSC * liste , int ISBN){
    Livre * tmp ;
    tmp = liste->debut;

    if(liste->debut == NULL){
      return NULL;
    } else {
      while(tmp != NULL && tmp->ISBN != ISBN){
        tmp = tmp->next;
      }
      if(tmp != NULL && tmp->ISBN == ISBN){
        return tmp;
      }
    }
    return NULL;
}
//7-
int position(LSC * liste , int ISBN){
    Livre * tmp ;
    tmp = liste->debut;

     if(liste->debut == NULL){
       printf("la list est vide !");
       return -1 ;
     }else{
         int i = 0;
       while(tmp->ISBN != ISBN && tmp != NULL){
         tmp = tmp->next;
         i++;
       }
       if(tmp->ISBN == ISBN){
        return i;
       }else{
        return -1;
        // if he return -1 that mean the isbn doesn't exist
       }
     }
}
//8-
int quanite(LSC * liste , int ISBN){
    Livre * tmp ;
    tmp = liste->debut;

     if(liste->debut == NULL){
       printf("la list est vide !");
       return -1;
     }else{
       while(tmp->ISBN != ISBN && tmp != NULL){
        tmp = tmp->next;
       }
       if(tmp->ISBN == ISBN){
        return tmp->Stock;
       }else{
        return -1;
        // s'il retourne -1 cela signifie que l'isbn n'existe pas
       }
     }
}
//9-
void ajouter_debut(LSC *l, Livre *new_liv)
{
    new_liv->next = l->debut;
    l->debut = new_liv;
}
void ajouter_fin(LSC *l, Livre *newliv)
{
    Livre *ptr = l->debut;
    if (ptr == NULL)
    {
        l->debut = newliv;
        newliv->next = NULL;
        return;
    }

    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newliv;
    newliv->next=NULL;
}
void ajouterLivre(LSC *liste, Livre *newLivre)
{
    if (chercher(liste, newLivre->ISBN) != NULL)
        chercher(liste, newLivre->ISBN)->Stock += newLivre->Stock;
    else if (newLivre->Stock <= 1)
        ajouter_debut(liste, newLivre);
    else
        ajouter_fin(liste, newLivre);
}
//11-
void supprimerLivre(LSC * liste , Livre * livre){
    Livre * tmp = liste->debut;

    if( liste->debut == livre ){
        //le cas ou le livre est le premier element de la liste
        liste->debut = livre->next;
    }
    else{
        while(tmp->next != livre){
            tmp = tmp->next;
        }
        tmp->next = livre->next;
    }

    free(livre);
}
//10-
void vendre(LSC * liste , int ISBN){
   Livre * cr ;
   cr = liste->debut ;
   while(cr != NULL && cr->ISBN != ISBN){
    cr = cr->next;}
   if(cr == NULL){
    printf("il faut modifier le ISBN");}
   else{
     cr->Stock--;
     if(!(cr->Stock > 0)){
        supprimerLivre(liste , cr);}}
}
//12-
void supprimerToutVide(LSC * liste){
    Livre * cr ;
    cr = liste->debut;
    if(cr == NULL){
        printf("la liste est vide !");
        return;
    } else {
        while(cr->next != NULL){
            if(cr->next->Stock == 0){
                supprimerLivre(liste, cr->next);
            } else {
                cr = cr->next;
            }
        }
        if(liste->debut->Stock == 0){
            supprimerLivre(liste,liste->debut);
        }
    }
}


int main()
{

  // la declaration des livres
  Livre * lv1;
  Livre * lv2;
  Livre * lv3;
  Livre * lv4;
  Livre * lv6;
  Livre * lv7;
  Livre * lv8;
  Livre * lv9;
  Livre * lv10;
  // la declaration d'une liste
  LSC * liste;

  char tab1[] = "Le Dernier Jour d'un Condamne";
  char tab2[] = "Harry Potter";
  char tab3[] = "The Psychology of Money";
  char tab4[] = "La Boite a merveilles";
  char tab6[] = "Atomic Habits";
  char tab7[] = "Il etait une fois un vieux couple heureux";
  char tab8[] = "The Old Man and the Sea";
  char tab9[] = "The one Page Marketing Plan";
  char tab10[] = "One Piece Vol 1";


  // l'allocation

  lv1 = malloc(sizeof(Livre));
  lv2 = malloc(sizeof(Livre));
  lv3 = malloc(sizeof(Livre));
  lv4 = malloc(sizeof(Livre));
  lv6 = malloc(sizeof(Livre));
  lv7 = malloc(sizeof(Livre));
  lv8 = malloc(sizeof(Livre));
  lv9 = malloc(sizeof(Livre));
  lv10 = malloc(sizeof(Livre));
  liste = malloc(sizeof(LSC));

  //initialisation d'une liste
  initialise(liste);

  // replissage
  remplir(lv1,220,tab1,0);
  remplir(lv2,12,tab2,9);
  remplir(lv3,44,tab3,0);
  remplir(lv4,99,tab4,1);
  remplir(lv6,14,tab6,3);
  remplir(lv7,9,tab7,9);
  remplir(lv8,7,tab8,44);
  remplir(lv9,80,tab9,1);
  remplir(lv10,223,tab10,1);

//  affichage des livres
  printf(" ************ affichage des livres *********** \n ");
  afficher(lv1);
  printf("------------------ \n");
  afficher(lv3);
  printf("------------------ \n");
  afficher(lv7);
  printf("------------------ \n");
  afficher(lv10);
  printf("------------------ \n");

  //ajouter des au liste
  ajouterLivre(liste,lv1);
  ajouterLivre(liste,lv2);
  ajouterLivre(liste,lv3);
  ajouterLivre(liste,lv4);
  ajouterLivre(liste,lv6);
  ajouterLivre(liste,lv7);
  ajouterLivre(liste,lv8);
  ajouterLivre(liste,lv9);
  ajouterLivre(liste,lv10);
  printf(" \n \n \n ************ affichage *********** \n ");
  // l'affichage du liste
  afficherListe(liste);


  printf(" \n \n \n ************ vendre *********** \n ");
  // vendre

  vendre(liste,99);
  vendre(liste,7);
  vendre(liste,9);
  afficherListe(liste);


  printf(" \n \n \n *********** supp si vide ! ************** \n ");
  //suppretion
  supprimerToutVide(liste);
  afficherListe(liste);

  printf(" \n \n \n ********** stock ************* \n");
  printf("la qantite en stock est : %d",quanite(liste,12));

  free(lv1);
  free(lv2);
  free(lv3);
  free(lv4);
  free(lv6);
  free(lv7);
  free(lv8);
  free(lv9);
  free(lv10);

}
