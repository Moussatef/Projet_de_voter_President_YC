#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
	
	char list_P[50];
	
}president;

typedef struct {
	
	char CIN[10],
	     Nom_Pr_V[50] ;
	     
}electeur;

typedef struct {
	char Nom_Pr[50];
	int NB_V;
	int prsnt;
	
}count;


president list_Pr[50];
electeur list_E[50];
count list_Coun[50];

int countT = 0;

void presidents(int n){
    int i,j;
while( n < 5 )
    printf("le nombre %i est pas suffisant ",n);
//Remplisage a la table ou list  presidants
for( i = 0 ; i < n ; i++)
	{
        printf("Saisir nom de president numero %i : ",i+1);
        scanf("%s",list_Pr[i].list_P);
    }
    printf("\n");
//Affichage les presidants
    for( i = 0 ; i < n ; i++)
	{
        printf("Le president  %i : %s \n",i+1,list_Pr[i].list_P);
        
    }
}



int Rechercher(char pr[50],int n){
	int i,cmp=0;
	for(i=0 ; i < n - countT ; i++){
		if(strcmp(list_Pr[i].list_P,pr)  == 0){
			cmp++;
		}
	}
	return cmp; 
}


void electeurs(int n){
    int i,t=0;
    char pr[50];
    
while( n < 10 )
    printf("le nombre %i est pas suffisant ",n);

for ( i = 0; i < n; i++)
{
	
    printf("Saisir votre CIN : ");
    scanf("%s",list_E[i].CIN);
    t=0;
    while(t == 0){
    	printf("Entrez le nom du president qui a vote : ");
		scanf("%s",pr);
		if(Rechercher(pr,n) == 1){
			strcpy(list_E[i].Nom_Pr_V,pr);
			t=1;
		}
		else 
		printf("Le president n'est pas sur la liste %i\n",Rechercher(pr,n));
	}
    
}
//Affichage
for ( i = 0; i < n; i++)
{
    printf("Votre CIN : %s  tu vote a la president : %s \n",list_E[i].CIN,list_E[i].Nom_Pr_V);
    
}

}

void vote2(int NbE , int NBP){
    int i,t=0;
    char pr[50];
    
for ( i = 0; i < NbE ; i++)
{
    printf("votre CIN : %s \n",list_E[i].CIN);
    t=0;
    while(t == 0){
    	printf("Entrez le nom du president qui a vote : ");
		scanf("%s",pr);
		if(Rechercher(pr,NBP) != 0){
			strcpy(list_E[i].Nom_Pr_V,pr);
			t=1;
		}
		else 
		printf("Le president n'est pas sur la liste  \n");
    }
}
}
void trier(int n){
	int   i,j, prst , nbv ;
		char pr[50], prv[50] ;
	
	for(i = 0; i < n-countT ; i++){
		for( j = i+1 ; j < n-countT ; j++ )
		if(list_Coun[i].prsnt < list_Coun[j].prsnt){
		
        strcpy( pr,list_Pr[i].list_P );
        strcpy(list_Pr[i].list_P , list_Coun[j].Nom_Pr);
        strcpy(list_Pr[j].list_P , pr);
        
        strcpy( prv,list_Coun[i].Nom_Pr );
        strcpy(list_Coun[i].Nom_Pr , list_Coun[j].Nom_Pr);
        strcpy(list_Coun[j].Nom_Pr , prv);	
        
        
        prst = list_Coun[i].prsnt;
        list_Coun[i].prsnt = list_Coun[j].prsnt;
        list_Coun[j].prsnt = prst ;
        
        
         nbv =list_Coun[i].NB_V;
		 list_Coun[i].NB_V =  list_Coun[j].NB_V;
		 list_Coun[j].NB_V =  nbv;
		}
	}
}

void calcul(int nbPr , int nbE){
	
	int i,j ,cmp1=0 , p=0 , cmp2;
	
	for( i = 0 ; i < nbPr ; i++){
		cmp1=0;
		p=0;
		for( j = 0 ; j < nbE ; j++){
			if(strcmp(list_Pr[i].list_P,list_E[j].Nom_Pr_V )==0){
				cmp1++;
			}
		}
	
		strcpy(list_Coun[i].Nom_Pr,list_Pr[i].list_P);
		list_Coun[i].NB_V = cmp1;
	    p =cmp1*100/nbE;
		list_Coun[i].prsnt = p ;
	}
	
	trier(nbE);

	
	
	//Affichage
	for ( i = 0; i < nbPr - countT ; i++)
	{
	        printf("president : %s  nombre de votes  : %i  porsantage : %i  \n",list_Coun[i].Nom_Pr,list_Coun[i].NB_V,list_Coun[i].prsnt);
	}
	}

void vedier(int nbPr , int nbE){
	int i;
	for ( i = 0; i < nbE ; i++)
	{
		 memset(list_E[i].Nom_Pr_V,  0, sizeof(list_E[i].Nom_Pr_V));
	}	 
	for ( i = 0; i < nbPr ; i++)
	{
		 memset(list_E[i].Nom_Pr_V,  0, sizeof(list_E[i].Nom_Pr_V));
		 list_Coun[i].prsnt=  0;
		 list_Coun[i].NB_V =  0;
		 memset(list_Coun[i].Nom_Pr, 0, sizeof(list_Coun[i].Nom_Pr));
    }
}

void tour1(int n)
{
	int i   =0,
	    cmp =0,
		colm=n;
	
	while( i < n && valider1(n) == 0){
		
		if(list_Coun[i].prsnt > 15){
		strcpy(list_Pr[cmp].list_P , list_Coun[i].Nom_Pr);
		cmp++;
		colm--;
		countT=colm;
		}
		i++;
	}
	
	
    
}

void tour2(int n)
{
	int i = 0,  j , colm= 0;
	trier(n);
	
//	for ( i = 0; i < n - countT ; i++)
//{
//    printf("president : %s  nombre de votes  : %i  porsantage : %i  \n",list_Coun[i].Nom_Pr,list_Coun[i].NB_V,list_Coun[i].prsnt);
//}

	for(i=n-countT-1; i>0 ;  i--){
		if(list_Coun[i].prsnt < list_Coun[i-1].prsnt)
		{
			colm++;
			i=0;
		}
		
		else{
			if(list_Coun[i].prsnt == list_Coun[i-1].prsnt){
				colm++;
			}
			
		} 
	}
	
	   
    countT += colm;
}

int valider1(int nbPr){
	int colm=0,i;
	for(i=nbPr-countT-1; i>0 ;  i--){
		
		if(list_Coun[i].prsnt == list_Coun[i-1].prsnt){
			colm++;
		}
			
	} 
//
	if(colm == nbPr-countT || colm == nbPr-countT-1 )
	   return 1;
	   else
	
	
	return 0;
}

int valider2(int nbPr){
	int colm=0,i;
	for ( i = 0; i < nbPr - countT ; i++)
	{
		if(list_Coun[i].prsnt==list_Coun[i+1].prsnt)
		colm++;
		else
		break;
	}

	if(colm == nbPr-countT )
	   return 1;
	   else
	return 0;
}

void  main() 
 {
 
 	
	int i ,Nb_President,NB_Electeurs;
	
	printf("Saisir nombre des presidents (N >= 5 )! : ");
	scanf("%i",&Nb_President);
	presidents(Nb_President);
	printf("Saisir nombre des electeurs (N >= 10 )! : ");
	scanf("%i",&NB_Electeurs);
	
	
	electeurs(NB_Electeurs);
	calcul(Nb_President,NB_Electeurs);
	tour1(Nb_President);
	while(valider1(Nb_President) == 1 || valider2(Nb_President) == 1){
		vote2(NB_Electeurs,Nb_President);
		calcul(Nb_President,NB_Electeurs);
		tour1(Nb_President);
	}
	
	printf("return valider1=  %i , return valider2 = %i ",valider1(Nb_President),valider2(Nb_President));
	
	
    for ( i = 0 ; i < Nb_President - countT ; i++)
	{
    //Affichage les president passe souivant Deuxieme tour
     printf("president passe souivant Deuxieme tour : %s  \n", list_Pr[i].list_P);
    
	}
	
	vedier(Nb_President,NB_Electeurs);
	vote2(NB_Electeurs,Nb_President);
	calcul(Nb_President,NB_Electeurs);
	
//	while(rt==0){
//		vote2(NB_Electeurs,Nb_President);
//		calcul(Nb_President,NB_Electeurs);
//		
//	}
	
	tour2(Nb_President);

    for ( i = 0 ; i < Nb_President - countT ; i++)
	{
    //Affichage les president passe souivant Troisieme tour :
     printf("president passe souivant Troisieme tour : %s  \n", list_Pr[i].list_P);
     
	 }
	 
	 vedier(Nb_President,NB_Electeurs);
	 vote2(NB_Electeurs,Nb_President);
 	 calcul(Nb_President,NB_Electeurs);
 	 
//	 while(rt == 0){
//		vote2(NB_Electeurs,Nb_President);
//		calcul(Nb_President,NB_Electeurs);
//		
//	}
	
	
	
	
	 tour2(Nb_President);
	  for ( i = 0 ; i < Nb_President - countT ; i++)
	  {
	  //Affichage les president reussit :
	   printf("Le president reussit a voter : %s  \n", list_Pr[i].list_P);
	 
	 }

 

}
