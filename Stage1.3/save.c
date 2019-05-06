#include "jouer.h"
int saveGame(char nomfichier[],Player *hero1 ,Player *hero2, Ennemi *Mob  , background *b ,int nbsave , int verif_input , int nbsave){
	FILE *f=NULL;

	f=fopen(nomfichier,"a");

	
   	
fprintf (f , "\n %d %d %d %d %d %d %d " , hero1->pos_perso.x, hero1->pos_perso.y, hero1->pos_perso.w , hero1->pos_perso.h , hero1->nbm_mv , hero1->nmb_health , verif_input) ;
fprintf (f , "\n %d %d %d %d %d %d %d" , hero2->pos_perso.x, hero2->pos_perso.y, hero2->pos_perso.w , hero2->pos_perso.h , hero2->nbm_mv , hero2->nmb_health  , verif_input) ;

fprintf (f , "\n %d %d %d %d" , Mob->pos_Ennemi.x , Mob->pos_Ennemi.y , Mob->pos_Ennemi.w , Mob->pos_Ennemi.h ) ;
fprintf ("\n %d %d %d %d %d %d %d %d " , b->positionecran.x , b->positionecran.y , b->positionecran.h , b->positionecran.w , b->camera.x , b->camera.y , b->camera.h , b->camera.w  ) ;

	saveN+=1;
	fclose(f);
	
	return nbsave;
}
int numberSave(char nomfichier[],int nbsave)
{ 
	FILE *f=NULL;
	int c;
	nbsave=0;

	f=fopen(nomfichier,"r");

	while((c=fgetc(f)) != EOF)
	{
		if(c=='\n')
			nbsave++;
	}

	fclose(f);
	return nbsave;
}

/*void int_load(,char nomfichier[],player *hero1 ,player *hero2, Ennemi *Mob , EO *obj , background *b , int lineNumber , int verif_input)
{
	FILE *f=NULL;

	f=fopen(nomfichier,"r");
	int i=0;

    if(f==NULL)
    {
    	fprintf(stderr,"Le fichier ne s'est pas ouvert correctement.\n");
    	exit(EXIT_FAILURE);
    }
    else
    {
    	while(!feof(f)){
            if(lineNumber==0){
fscanf (f , "\n %d %d %d %d %d %d " , hero1->pos_perso.x, hero1->pos_perso.y, hero1->pos_perso.w , hero1->pos_perso.h , hero1->nbm_mv , hero1->nmb_health ) ;
fscanf (f , "\n %d %d %d %d %d %d " , hero2->pos_perso.x, hero2->pos_perso.y, hero2->pos_perso.w , hero2->pos_perso.h , hero2->nbm_mv , hero2->nmb_health , verif_input) ;

fscanf (f , "\n %d %d %d %d" , Mob->pos_Ennemi.x , Mob->pos_Ennemi.y , Mob->pos_Ennemi.w , Mob->pos_Ennemi.h ) ;
fscanf("\n %d %d %d %d %d %d %d %d " , b->positionecran.x , b->positionecran.y , b->positionecran.h , b->positionecran.w , b->camera.x , b->camera.y , b->camera.h , b->camera.w  ) ;

              
                break;         
            }
    		if(lineNumber!=0){
    			for(i=0;i<lineNumber;i++)
    				fscanf(f,"\n");
    		}
    		fscanf (f , "\n %d %d %d %d %d %d " , hero1->pos_perso.x, hero1->pos_perso.y, hero1->pos_perso.w , hero1->pos_perso.h , hero1->nbm_mv , hero1->nmb_health ) ;
fscanf (f , "\n %d %d %d %d %d %d " , hero2->pos_perso.x, hero2->pos_perso.y, hero2->pos_perso.w , hero2->pos_perso.h , hero2->nbm_mv , hero2->nmb_health ) ;

fscanf (f , "\n %d %d %d %d" , Mob->pos_Ennemi.x , Mob->pos_Ennemi.y , Mob->pos_Ennemi.w , Mob->pos_Ennemi.h ) ;
fscanf("\n %d %d %d %d %d %d %d %d " , b->positionecran.x , b->positionecran.y , b->positionecran.h , b->positionecran.w , b->camera.x , b->camera.y , b->camera.h , b->camera.w  ) ;
    	}
    }

	fclose(f);

}*/
