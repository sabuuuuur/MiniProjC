//les bibliotheques
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//les structures
typedef struct{
    int jour,mois,annee;
}date;

//structure client
typedef struct{
    char CIN[15];
    char nom[15];
    char ville[15];
    char prenom[15];
    int num_permis;
    int num_tel;
    date date_naissance;
}client;

//stucture voiture
typedef struct{
    int num_matricule;
    char marque[20];
    char type[20];
    float prix;
    date DateMiseCirculation;
}voiture;

//structure location
typedef struct{
    char CIN[15];
    int num_matricule;
    date date_location;
    int duree;
}location;

//prototype des fonctions client
//la saisie
void RemplissageC(client*,int);
void AffichageC(client*,int);
void AfficheC(client c);
void AffichageCC(client*,int,char*);
void AffichageVC(client*,int,char*);
void AffichageLC(client*,int,char);
void AjoutC(client*,int*);
void AjoutPosC(client*,int*,int);
void SuppressionC(client*,int*,char*);
int comptageC(location*,int,client*,int,char*);

//prototype des fonctions voiture
void RemplissageV(voiture*,int);
void AffichageV(voiture*,int);
void AfficheV(voiture v);
void AffichageMV(voiture*,int,char*);
void AffichageTV(voiture*,int,char*);
void AjoutV(voiture*,int*);
void AjoutPosV(voiture*,int*,int);
void SuppressionV(voiture*,int*,int);

//prototypes des fonctions location
void RemplissageL(location *,int ,voiture* ,int ,client* ,int);
void AfficheL(location l);
void AffichageL(location*,int);
void AffichageCL(location*,int,client*,int,char*);
void AffichageVL(location*,int,int);
void AffichageDL(location*,int,int);
void AffichageDLL(location *l,int nl,date);
void AjoutL(location*,int*);
void AjoutPosL(location*,int*,int);
void SuppressionL(location*,int*,client*,int*,char*);
int RechercheC(client* ,int ,char *);
int RechercheM(voiture *v,int nv,int);

//prototype des nouveau tableau
void LocationCD(location*,int*,char*);
void LocationVD(location *,int* ,int );

//prototype de chiffre d'afaire
float CAV(location*,int,voiture*,int,int);
void AfficheVCA(location*,int,voiture*,int);

int main(){
	client *c;
	voiture *v;
	location *l;
	int nc,nv,nl;//les taille des tableau
    int p,i;//p:la position dans le tableau c;i:un compteur dans les boucles
    char CIN[15],ville[20],caractere,type[20],marque[15],nom[20];
    int num_matricule;
    date DLocation;
    int duree,cmp;//cmp est un compteur.
	int nbr,choix,cm1=0,cm2=0,cm3=0;//variable utiliser dans le menu
	
	do{	
	//menu principale:
	here:
	system("cls");
	printf("\n                            \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                            \xb3 Agence de Location \xb3");
	printf("\n                            \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	
	printf("\n\n");
	
	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    Gestion clients.......................1   \xba");
	printf("\n               \xba    Gestion voitures......................2   \xba");
	printf("\n               \xba    Location..............................3   \xba");
	printf("\n               \xba    Statistique...........................4   \xba");
	printf("\n               \xba    Quitter...............................5   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");

    
    do{
    	scanf("%d",&choix);
    	if(choix!=1 &&choix!=2 &&choix!=3 &&choix!=4 &&choix!=5)
    		goto here;
    }while(choix!=1 &&choix!=2 &&choix!=3 &&choix!=4 &&choix!=5);
    system("cls");
    switch(choix){	
		case 1:
			//menu getion client
			here1:
			system("cls");
			printf("\n                              \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
			printf("\n                              \xb3 Gestion client \xb3");
			printf("\n                              \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
			
			printf("\n\n");
			
			printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
			printf("\n               \xba                                              \xba");
			printf("\n               \xba    Initialisation........................1   \xba");
			printf("\n               \xba    Ajouter client........................2   \xba");
			printf("\n               \xba    Afficher client.......................3   \xba");
			printf("\n               \xba    Supprimer client......................4   \xba");
			printf("\n               \xba    Retour................................0   \xba");
			printf("\n               \xba                                              \xba");
			printf("\n               \xba                                              \xba");
			printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
			printf("\n\n                                Votre choix  :  ");
			do{
	    		scanf("%d",&choix);
	    		if(choix!=1 &&choix!=2 &&choix!=3 &&choix!=4 &&choix!=0)
	    			goto here1;
	    	}while(choix!=1 &&choix!=2 &&choix!=3 &&choix!=4 &&choix!=0);
	    	system("cls");
			switch(choix){
				case 1:
					if(cm1==0){
   					cm1=1;
   					//saisie du nombre de case pour le tableau de client.
   					do{
        				printf("donner le nombre de client de base :");
        				scanf("%d",&nc);
    				}while(nc<1);
    				system("cls");
    				//creation du tableau dans la memoire
    				c=(client*)malloc(nc*sizeof(client));
    				//traitement des fonctions clients
    				if(c){
    					//fonction
    					RemplissageC(c,nc);
    				}else{
        				printf("la memoire ne support pas cette taille!!\n");
    				}
					}else{
    					printf("vous avez deja initialiser le tableau des clients\n");
					}
					break;
				case 2:
					//menu affichage client
					here12:
					system("cls");
					printf("\n                              \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
					printf("\n                              \xb3 Gestion client \xb3");
					printf("\n                              \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
					
					printf("\n\n");
					
					printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
					printf("\n               \xba                                              \xba");
					printf("\n               \xba    Vers La Fin...........................1   \xba");
					printf("\n               \xba    Par Position..........................2   \xba");
					printf("\n               \xba    Retour................................0   \xba");
					printf("\n               \xba                                              \xba");
					printf("\n               \xba                                              \xba");
					printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
					printf("\n\n                                Votre choix  :  ");
					do{
			    		scanf("%d",&choix);
			    		if(choix!=1 &&choix!=2&&choix!=0)
			    			goto here12;
			    	}while(choix!=1 &&choix!=2&&choix!=0);
			    	system("cls");
					switch(choix){
						case 1:
							//fonction
							AjoutC(c,&nc);
							break;
						case 2:
							do{
        						printf("donner une position dans le tableau des clients :");
        						scanf("%d",&p);
    						}while(p<1||p>nc);
							//fonction
							AjoutPosC(c,&nc,p);
							break;
						case 0:
							goto here1;
							break;
					}
					break;
				case 3:
					//menu ajout client
					here13:
					system("cls");
					printf("\n                              \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
					printf("\n                              \xb3 Gestion client \xb3");
					printf("\n                              \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
					
					printf("\n\n");
					
					printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
					printf("\n               \xba                                              \xba");
					printf("\n               \xba    Tout Les Clients......................1   \xba");
					printf("\n               \xba    Par CIN...............................2   \xba");
					printf("\n               \xba    Par Ville.............................3   \xba");
					printf("\n               \xba    Par Caractere.........................4   \xba");
					printf("\n               \xba    Retour................................0   \xba");
					printf("\n               \xba                                              \xba");
					printf("\n               \xba                                              \xba");
					printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
					printf("\n\n                                Votre choix  :  ");
					do{
			    		scanf("%d",&choix);
			    		if(choix!=1 &&choix!=2&&choix!=3&&choix!=4&&choix!=0)
			    			goto here13;
			    	}while(choix!=1 &&choix!=2&&choix!=3&&choix!=4&&choix!=0);
			    	system("cls");
					switch(choix){
						case 1:
							//fonction
   							AffichageC(c,nc);
							break;
						case 2:
							fflush(stdin);
							printf("donner un CIN :");
	    					gets(CIN);
	    					//fonction
							AffichageCC(c,nc,CIN);
							break;
						case 3:
							fflush(stdin);
							printf("donner une ville :");
	    					gets(ville);
							//fonction
							AffichageVC(c,nc,ville);
							break;
						case 4:
							printf("donner un caractere :");
							fflush(stdin);
							scanf("%c",&caractere);
							//fonction
							AffichageLC(c,nc,caractere);
							break;
						case 0:
							goto here1;
							break;
					}
					printf("tapez pour retourner au menu principale.");
					getch();
					break;
				case 4:
					fflush(stdin);
					printf("donner un CIN d'un client a supprimer:");
        			gets(CIN);
        			//fonction
					SuppressionC(c,&nc,CIN);
					break;
				case 0:
					goto here;
					break;
			}	
			break;
    	case 2:
    		//menu Gestion voiture
    		here2:
			system("cls");
    		printf("\n                              \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
			printf("\n                              \xb3 Gestion voiture \xb3");
			printf("\n                              \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
			
			printf("\n\n");
			
			printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
			printf("\n               \xba                                              \xba");
			printf("\n               \xba    Initialisation........................1   \xba");
			printf("\n               \xba    Ajouter voiture.......................2   \xba");
			printf("\n               \xba    Afficher voiture......................3   \xba");
			printf("\n               \xba    Supprimer voiture.....................4   \xba");
			printf("\n               \xba    Retour................................0   \xba");
			printf("\n               \xba                                              \xba");
			printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
			printf("\n\n                                Votre choix  :  ");
			do{
	    		scanf("%d",&choix);
	    		if(choix!=1 &&choix!=2 &&choix!=3 &&choix!=4 &&choix!=0)
	    			goto here2;
	    	}while(choix!=1 &&choix!=2 &&choix!=3 &&choix!=4 &&choix!=0);
	    	system("cls");
			switch(choix){
				case 1:
					if(cm2==0){
   					cm2=1;
					//saisie du nombre de case pour le tableau de voiture.
    				do{
        				printf("donner le nombre de voiture de base :");
        				scanf("%d",&nv);
    				}while(nv<1);
    				system("cls");
    				//creation du tableau dans la memoire
    				v=(voiture*)malloc(nv*sizeof(voiture));
    				//traitement des fonctions voiture
    				if(v){
    					//fonction
    					RemplissageV(v,nv);
    				}else{
        				printf("la memoire ne support pas cette taille!!\n");
    				}
    				}else{
    					printf("vous avez deja initialiser le tableau des voitures\n");
					}
					break;
				case 2:
					//menu affichage voiture
					here22:
					system("cls");
		    		printf("\n                              \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
					printf("\n                              \xb3 Gestion voiture \xb3");
					printf("\n                              \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
					
					printf("\n\n");
					
					printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
					printf("\n               \xba                                              \xba");
					printf("\n               \xba    Vers La Fin...........................1   \xba");
					printf("\n               \xba    Par Position..........................2   \xba");
					printf("\n               \xba    Retour................................0   \xba");
					printf("\n               \xba                                              \xba");
					printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
					printf("\n\n                                Votre choix  :  ");
					do{
			    		scanf("%d",&choix);
			    		if(choix!=1 &&choix!=2&&choix!=0)
			    			goto here22;
			    	}while(choix!=1 &&choix!=2&&choix!=0);
			    	system("cls");
					switch(choix){
						case 1:
							//fonction
   							AjoutV(v,&nv);
							break;
						case 2:
							do{
								printf("donner une position dans le tableau des voitures :");
        						scanf("%d",&p);
    						}while(p<1||p>nv);
    						//fonction
    						AjoutPosV(v,&nv,p);
							break;
						case 0:
							goto here22;
							break;
					}
					break;	
				case 3:
					//menu ajout voiture
					here23:
					system("cls");
		    		printf("\n                              \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
					printf("\n                              \xb3 Gestion voiture \xb3");
					printf("\n                              \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
					
					printf("\n\n");
					
					printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
					printf("\n               \xba                                              \xba");
					printf("\n               \xba    Tous Les Voitures.....................1   \xba");
					printf("\n               \xba    Par Marque............................2   \xba");
					printf("\n               \xba    Par Type..............................3   \xba");
					printf("\n               \xba    Retour................................0   \xba");
					printf("\n               \xba                                              \xba");
					printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
					printf("\n\n                                Votre choix  :  ");
					do{
			    		scanf("%d",&choix);
			    		if(choix!=1 &&choix!=2&&choix!=3&&choix!=0)
			    			goto here23;
			    	}while(choix!=1 &&choix!=2&&choix!=3&&choix!=0);
			    	system("cls");
					switch(choix){
						case 1:
							//fonction
   							AffichageV(v,nv);
							break;
						case 2:
							fflush(stdin);
							printf("donner la marque d'une voiture a afficher :");
        					gets(marque);	
							//fonction
							AffichageMV(v,nv,marque);
							break;
						case 3:
							do{
		 						
        						printf("donner un type de voiture(touristique/commerciale):");
								fflush(stdin);
								scanf("%s",type);
							}while(!(strcmp(type,"touristique")==0 || strcmp(type,"TOURISTIQUE")==0 || strcmp(type,"commerciale")==0 || strcmp(type,"COMMERCIALE")==0));
							//fonction
							AffichageTV(v,nv,type);
							break;
						case 0:
							goto here2;
							break;
					}
					printf("tapez pour retourner au menu principale.");
					getch();
					break;
				case 4:
					printf("donner un num_matricule d'une voiture a supprimer:");
        			scanf("%d",&num_matricule);
					//fonction
					SuppressionV(v,&nv,num_matricule);
					break;
				case 0:
					goto here;
					break;	
			}
    		break;
    	case 3:
    		//menu location
    		here3:
			system("cls");
			printf("\n                                 \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
			printf("\n                                 \xb3 Location \xb3");
			printf("\n                                 \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
			
			printf("\n\n");
			
			printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
			printf("\n               \xba                                              \xba");
			printf("\n               \xba    Initialisation........................1   \xba");
			printf("\n               \xba    Ajouter Location......................2   \xba");
			printf("\n               \xba    Afficher Location.....................3   \xba");
			printf("\n               \xba    Supprimer location....................4   \xba");
			printf("\n               \xba    Retour................................0   \xba");
			printf("\n               \xba                                              \xba");
			printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
			printf("\n\n                                Votre choix  :  ");
			do{
	    		scanf("%d",&choix);
	    		if(choix!=1 &&choix!=2 &&choix!=3 &&choix!=4 &&choix!=0)
	    			goto here3;
	    	}while(choix!=1 &&choix!=2 &&choix!=3 &&choix!=4 &&choix!=0);
	    	system("cls");
			switch(choix){
				case 1:
					if(cm3==0){
   					cm3=1;
   					//saisie du nombre de case pour le tableau de location.
    				do{
        				printf("donner le nombre de location de base :");
        				scanf("%d",&nl);
    				}while(nl<1);
   					system("cls");
    				//creation du tableau dans la memoire
   					l=(location*)malloc(nl*sizeof(location));
   					//traitement des fonctions locations
   					if(l){
   						//fonction
						RemplissageL(l,nl,v,nv,c,nc);
					}else{
						printf("la taille est trop grand!!\n");
					} 	
					}else{
    					printf("vous avez deja initialiser le tableau des locations\n");
					}
					break;
				case 2:
					//menu affichage location
					here32:
					system("cls");
					printf("\n                                 \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
					printf("\n                                 \xb3 Location \xb3");
					printf("\n                                 \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
					
					printf("\n\n");
					
					printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
					printf("\n               \xba                                              \xba");
					printf("\n               \xba    Vers La Fin...........................1   \xba");
					printf("\n               \xba    Par Position..........................2   \xba");
					printf("\n               \xba    Retour................................0   \xba");
					printf("\n               \xba                                              \xba");
					printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
					printf("\n\n                                Votre choix  :  ");
					do{
			    		scanf("%d",&choix);
			    		if(choix!=1 &&choix!=2 &&choix!=0)
			    			goto here32;
			    	}while(choix!=1 &&choix!=2 &&choix!=0);
			    	system("cls");
					switch(choix){
						case 1:
							//fonction
   							AjoutL(l,&nl);
							break;
						case 2:
							do{
								printf("donner une position dans le tableau des locations :");
        						scanf("%d",&p);
    						}while(p<1||p>nl);
   							//fonction
   							AjoutPosL(l,&nl,p);
							break;
						case 0:
							goto here3;
							break;
					}
					break;	
				case 3:
					//menu ajout location
					here33:
					system("cls");
					printf("\n                                 \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
					printf("\n                                 \xb3 Location \xb3");
					printf("\n                                 \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
					
					printf("\n\n");
					
					printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
					printf("\n               \xba                                              \xba");
					printf("\n               \xba    Par Client(Nom).......................1   \xba");
					printf("\n               \xba    Par Voiture(Immatriculation)..........2   \xba");
					printf("\n               \xba    Par Duree.............................3   \xba");
					printf("\n               \xba    Par Date De Location..................4   \xba");
					printf("\n               \xba    Retour................................0   \xba");
					printf("\n               \xba                                              \xba");
					printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
					printf("\n\n                                Votre choix  :  ");
					do{
			    		scanf("%d",&choix);
			    		if(choix!=1 &&choix!=2&&choix!=3&&choix!=4&&choix!=0)
			    			goto here33;
			    	}while(choix!=1 &&choix!=2&&choix!=3&&choix!=4&&choix!=0);
			    	system("cls");
					switch(choix){
						case 1:
							fflush(stdin);
							printf("donner un nom :");
							gets(nom);
							//fonction
							AffichageCL(l,nl,c,nc,nom);
							break;
						case 2:
        					printf("donner un numero de matriculate a chercher dans les location :");
    						scanf("%d",&num_matricule);
    						//fonction
    						AffichageVL(l,nl,num_matricule);
							break;
						case 3:
							printf("donner une duree a chercher dans les locations :");
							scanf("%d",&duree);
							AffichageDL(l,nl,duree);
							break;
						case 4:
							printf("donner une date de location :\n");
        					scanf("%d%d%d",&DLocation.jour,&DLocation.mois,&DLocation.annee);
        					AffichageDLL(l,nl,DLocation);
							break;
						case 0:
							goto here3;
							break;
					}
					printf("tapez pour retourner au menu principale.");
					getch();
					break;
				case 4:
					fflush(stdin);
					printf("donner une ville :");
					gets(ville);
					//fonction
					SuppressionL(l,&nl,c,&nc,ville);
					break;
				case 0:
					goto here;
					break;	
			}
			break;
    	case 4:
    		//menu statistique
    		here4:
			system("cls");
    		printf("\n                                        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
			printf("\n                                        \xb3 Statistique \xb3");
			printf("\n                                        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
			
			printf("\n\n");
			
			printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
			printf("\n               \xba                                                            \xba");
			printf("\n               \xba    Nombre De Contact D'une Ville.......................1   \xba");
			printf("\n               \xba    Le Chiffre Realiser Par Une Voiture.................2   \xba");
			printf("\n               \xba    La Voiture Qui a Realise Le Chiffre Le Plus Eleve...3   \xba");
			printf("\n               \xba    Les Location D'un Client Ou Voiture.................4   \xba");
			printf("\n               \xba    Retour..............................................0   \xba");
			printf("\n               \xba                                                            \xba");
			printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
			printf("\n\n                                Votre choix  :  ");
			do{
	    		scanf("%d",&choix);
	    		if(choix!=1 &&choix!=2 &&choix!=3 &&choix!=4 &&choix!=0)
	    			goto here4;
	    	}while(choix!=1 &&choix!=2 &&choix!=3 &&choix!=4 &&choix!=0);
	    	system("cls");
			switch(choix){
				case 1:
					fflush(stdin);
					printf("donner une ville :");
					gets(ville);
					nbr=comptageC(l,nl,c,nc,ville);
					printf("Le Nombre De Contact :%d\n",nbr);
					printf("tapez pour retourner au menu principale.");
					getch();
					break;
				case 2:
                    fflush(stdin);
                    printf("donner le matricule :");
                    scanf("%d",&num_matricule);
                    nbr=CAV(l,nl,v,nv,num_matricule);
                    printf("Le CA de Voiture :%.2f\n",nbr);
                    printf("tapez pour retourner au menu principale.");
					getch();
					break;	
				case 3:
                    fflush(stdin);
                    AfficheVCA(l,nl,v,nv);
					break;
				case 4:
					system("cls");
		    		printf("\n                                \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
					printf("\n                                \xb3 Statistique \xb3");
					printf("\n                                \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
					
					printf("\n\n");
					
					printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
					printf("\n               \xba                                              \xba");
					printf("\n               \xba    Les Location D'un Client..............1   \xba");
					printf("\n               \xba    Les Location D'une Voiture............2   \xba");
					printf("\n               \xba    Retour................................0   \xba");
					printf("\n               \xba                                              \xba");
					printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
					printf("\n\n                                Votre choix  :  ");
					do{
			    		scanf("%d",&choix);
			    		if(choix!=1 &&choix!=2 &&choix!=0)
			    			goto here4;
			    	}while(choix!=1 &&choix!=2 &&choix!=0);
			    	system("cls");
					switch(choix){
						case 1:
							LocationCD(l,&nl,CIN);
							printf("tapez pour retourner au menu principale.");
							getch();
							break;
						case 2:
							LocationVD(l,&nl,num_matricule);
							printf("tapez pour retourner au menu principale.");
							getch();
							break;
						case 0:
							goto here4;
							break;
					}
					break;
				case 0:
					goto here;
					break;	
			}
			break;
		case 5:
			//menu quitter
			goto fin;
			break;
	}	
	}while(choix!=5);
	getch();
	fin:
	free(c);
	free(v);
	free(l);
	return 0;
}

/*
=>les fonctions par rapport aux clients
-la saisie
-l'ajout(dans une position / a la fin du tableau)
-l'affichage(tous les clients/par CIN/par ville/par caractere)
-suppression
*/
//saisie:
void RemplissageC(client *c, int nc){
    int i;
    for(i=0;i<nc;i++){
        printf("pour la client %d\n",i+1);
        printf("donner son nom :");
        scanf("%s",(c+i)->nom);
        printf("donner son prenom :");
        scanf("%s",(c+i)->prenom);
        fflush(stdin);
        printf("donner sa ville :");
        gets((c+i)->ville);
        printf("donner son numero du permis :");
        scanf("%d",&(c+i)->num_permis);
        printf("donner son numero de telephone :");
        scanf("%d",&(c+i)->num_tel);
        printf("donner sa date de naissance (jour/mois/annee) :\n");
        do{
            printf("    ->le jour de naissance : ");
            scanf("%d",&(c+i)->date_naissance.jour);
        }while((c+i)->date_naissance.jour>31);         
        do{
            printf("    ->le mois  de naissance est : ");
            scanf("%d",&(c+i)->date_naissance.mois);
        }while(((c+i)->date_naissance.mois<1)||((c+i)->date_naissance.mois>12));             
        printf("    ->lannee de naissance est :  ");
        scanf("%d",&(c+i)->date_naissance.annee);                
        fflush(stdin);
		printf("donner son CIN :");
        gets((c+i)->CIN);
        system("cls");
    }
}
//affichage(tous les clients):
void AffichageC(client *c, int nc){
    int i;
    for(i=0;i<nc;i++){
        printf("pour la client %d\n",i+1);
        printf("nom : %s\t\tprenom : %s\n",(c+i)->nom,(c+i)->prenom);   
        printf("ville : %s\n",(c+i)->ville);
        printf("numero du permis : %d\n",(c+i)->num_permis);
        printf("numero de telephone : 0%d\n",(c+i)->num_tel);
        printf("la date de naissance : (%d/%d/%d)\n",(c+i)->date_naissance.jour,(c+i)->date_naissance.mois,(c+i)->date_naissance.annee);
		printf("CIN : %s\n",(c+i)->CIN);
    }
}
//fonction affichage generale:
/*Affichage Client*/
void AfficheC(client c){
    printf(" le CIN du client est:");
    printf("%s\n",c.CIN);
    printf(" le nom du client est :");
    printf("%s\n",c.nom);
    printf(" le prenom du client est :");
    printf("%s\n",c.prenom);
    printf(" la ville du client est :");
    printf("%s\n",c.ville);
    printf(" le nnum de permis du client est :");
    printf("%d\n",c.num_permis);
    printf(" le numero du client num est : 0");
    printf("%d\n",c.num_tel);
    printf(" la date de naissance du client est :");
    printf("(%d/%d/%d)\n",c.date_naissance.jour,c.date_naissance.mois,c.date_naissance.annee);
}

//affichage(par CIN):
void AffichageCC(client *c, int nc, char* CIN){
    int i,cmp=0;
    for (i=0;i<nc;i++) {
        if (strcmp((c+i)->CIN,CIN)==0){
            AfficheC(*(c+i));
            cmp++;
        }
    }
    if(cmp==0)
    	printf("ce CIN n'existe pas.\n");
}
//affichage(par ville):
void AffichageVC(client *c, int nc, char* ville){
    int i,cmp=0;
    for (i=0; i<nc; i++) {
        if (strcmp((c+i)->ville,ville)==0){
            AfficheC(*(c+i));
            cmp++;
        }
    }
    if(cmp==0)
    	printf("cette ville n'existe pas.\n");
}
//affichage(par caractere):
void AffichageLC(client *c, int nc, char A){
    int i,tmp=0;
    for (i=0; i<nc; i++) {
        if ((c+i)->nom[0]==A){
            tmp++;
            AfficheC(*(c+i));
        }
    }
    if (tmp==0) {
        printf("Lettre non trouvee.\n");
    }
}

//ajout(a la fin du tableau):
void AjoutC(client* c,int* nc){
    c=(client*)realloc(c,(*nc+1)*sizeof(client));
    if(c){
    	(*nc)++;
        printf("pour la client %d\n",*nc);
        printf("donner son nom :");
        scanf("%s",(c+*nc-1)->nom);
        printf("donner son prenom :");
        scanf("%s",(c+*nc-1)->prenom);
        fflush(stdin);
        printf("donner sa ville :");
        gets((c+*nc-1)->ville);
        printf("donner son numero du permis :");
        scanf("%d",&(c+*nc-1)->num_permis);
        printf("donner son numero de telephone :");
        scanf("%d",&(c+*nc-1)->num_tel);
        printf("donner sa date de naissance (jour/mois/annee) :\n");
        do{
            printf("    ->le jour de naissance : ");
            scanf("%d",&(c+*nc-1)->date_naissance.jour);
        }while((c+*nc-1)->date_naissance.jour>31);         
        do{
            printf("    ->le mois  de naissance est : ");
            scanf("%d",&(c+*nc-1)->date_naissance.mois);
        }while(((c+*nc-1)->date_naissance.mois<1)||((c+*nc-1)->date_naissance.mois>12));             
        printf("    ->lannee de naissance est :  ");
        scanf("%d",&(c+*nc-1)->date_naissance.annee);
		fflush(stdin);
		printf("donner son CIN :");
        gets((c+*nc-1)->CIN);
    }else{
   		printf("la memoire ne support pas cette taille!!\n");	
	}
}
//ajout(dans une position):
void AjoutPosC(client* c,int* nc,int p){
	int i;
    c=(client*)realloc(c,(*nc+1)*sizeof(client));
    if(c){
    	(*nc)++;
    	for(i=*nc-1;i>=p;i--){
    		*(c+i)=*(c+i-1);
    		/*strcpy((c+i)->nom,(c+i-1)->nom);
        	strcpy((c+i)->prenom,(c+i-1)->prenom);
    	    strcpy((c+i)->ville,(c+i-1)->ville);
    	    (c+i)->num_permis=(c+i-1)->num_permis;
    	    (c+i)->num_tel=(c+i-1)->num_tel;
    	    (c+i)->date_naissance.jour=(c+i-1)->date_naissance.jour;
    	    (c+i)->date_naissance.mois=(c+i-1)->date_naissance.mois;
    	    (c+i)->date_naissance.annee=(c+i-1)->date_naissance.annee;
    	    strcpy((c+i)->CIN,(c+i-1)->CIN);*/
		}
			printf("pour le client %d\n",p);
    	    printf("donner son nom :");
    	    scanf("%s",(c+p-1)->nom);
    	    printf("donner son prenom :");
    	    scanf("%s",(c+p-1)->prenom);
    	    fflush(stdin);
    	    printf("donner sa ville :");
    	    gets((c+p-1)->ville);
    	    printf("donner son numero du permis :");
    	    scanf("%d",&(c+p-1)->num_permis);
    	    printf("donner son numero de telephone :");
    	    scanf("%d",&(c+p-1)->num_tel);
    	    printf("donner sa date de naissance (jour/mois/annee) :\n");
    	    scanf("%d%d%d",&(c+p-1)->date_naissance.jour,&(c+i)->date_naissance.mois,&(c+i)->date_naissance.annee);
    	    printf("donner sa date de naissance (jour/mois/annee) :\n");
        	do{
        	    printf("    ->le jour de naissance : ");
				scanf("%d",&(c+*nc-1)->date_naissance.jour);
        	}while((c+*nc-1)->date_naissance.jour>31);         
        	do{
        	    printf("    ->le mois  de naissance est : ");
        	    scanf("%d",&(c+*nc-1)->date_naissance.mois);
        	}while(((c+*nc-1)->date_naissance.mois<1)||((c+*nc-1)->date_naissance.mois>12));             
        	printf("    ->lannee de naissance est :  ");
        	scanf("%d",&(c+*nc-1)->date_naissance.annee);
			fflush(stdin);
			printf("donner son CIN :");
    	    gets((c+p-1)->CIN);
	}else{
   		printf("la memoire ne support pas cette taille!!\n");	
	}
}
//suppression:
void  SuppressionC(client *c,int* nc, char* CIN) {
    int i,pos;
    for (i=0;i<*nc;i++) {
        if (strcmp((c+i)->CIN,CIN)==0){
            pos=i;
        }
        
    }
    for (i=pos;i<(*nc-1);i++) {
        strcpy((c+i)->CIN,(c+i+1)->CIN);
        strcpy((c+i)->nom,(c+i+1)->nom);
        strcpy((c+i)->prenom,(c+i+1)->prenom);
        strcpy((c+i)->ville,(c+i+1)->ville);
        (c+i)->num_permis=(c+i+1)->num_permis;
        (c+i)->num_tel=(c+i+1)->num_tel;
        (c+i)->date_naissance.jour=(c+i+1)->date_naissance.jour;
        (c+i)->date_naissance.mois=(c+i+1)->date_naissance.mois;
        (c+i)->date_naissance.annee=(c+i+1)->date_naissance.annee;
        
    }
	
    c=(client*)realloc(c,(*nc-1)*sizeof(client));
    (*nc)--;
}

/*
=>les fonctions par rapport aux voitures
-la saisie
-l'ajout(dans une position / a la fin du tableau)
-l'affichage(tous les voitures/par marque/par type)
-suppression
*/
//saisie:
void RemplissageV(voiture *v,int nv){
	int i;
    for(i=0;i<nv;i++){
        printf("pour la voiture %d:\n",i+1);
        fflush(stdin);
        printf("donner le numero de matricule de la voiture :");
        scanf("%d",&(v+i)->num_matricule);
        fflush(stdin);
        printf("donner sa marque :");
        gets((v+i)->marque);
        do{
        	fflush(stdin);
        	printf("donner son type(touristique/commerciale):");
        	scanf("%s",(v+i)->type);
		}while(!(strcmp((v+i)->type,"touristique")==0 || strcmp((v+i)->type,"TOURISTIQUE")==0 || strcmp((v+i)->type,"commerciale")==0 || strcmp((v+i)->type,"COMMERCIALE")==0));
        printf("donner le prix :");
        scanf("%f",&(v+i)->prix);
        printf("donner sa date de mise en circulation (jour/mois/annee) :\n");
        do{
        	printf("    ->le jour de mise circuilation : ");
            scanf("%d",&(v+i)->DateMiseCirculation.jour);
    	}while((v+i)->DateMiseCirculation.jour>31);
        do{
    		printf("    ->le mois  de mise circuilation : ");
            scanf("%d",&(v+i)->DateMiseCirculation.mois);
        }while(((v+i)->DateMiseCirculation.mois<1)||((v+i)->DateMiseCirculation.mois>12));
        printf("    ->lannee de mise circulation : ");
        scanf("%d",&(v+i)->DateMiseCirculation.annee);
        system("cls");
	}
}

//affichage(tous les voitures):
void AffichageV(voiture *v,int nv){
	int i;
    for(i=0;i<nv;i++){
        printf("pour la voiture %d:\n",i+1);       
        printf("le num_matricule de la voiture : %d\n",(v+i)->num_matricule);       
        printf("sa marque : %s\n",(v+i)->marque);       
        printf("son type est : %s\n",(v+i)->type);     
        printf("le prix : %.2f\n",(v+i)->prix);       
        printf("sa date de mise en circulation : (%d/%d/%d)\n",(v+i)->DateMiseCirculation.jour,(v+i)->DateMiseCirculation.mois,(v+i)->DateMiseCirculation.annee);
	}
}
//fonction d'affichage generale :
/*Affichage Voiture*/
void AfficheV(voiture v){
        printf("le numero d'immatriculation du voiture est:");
        printf("%d\n",v.num_matricule);
        printf("la marque du voiture est:");
        printf("%s\n",v.marque);
        printf("le type du voiture est:");
        printf("%s\n",v.type);
        printf("la date de mise en circulation du voiture est:");
        printf("(%d/%d/%d)\n",v.DateMiseCirculation.jour,v.DateMiseCirculation.mois,v.DateMiseCirculation.annee);
    }
//affichage(par marque):
void AffichageMV(voiture *v,int nv,char* marque){
    int i,tmp=0;
    for (i=0;i<nv;i++) {
        if (strcmp((v+i)->marque,marque)==0){
            tmp++;
            AfficheV(*(v+i));
        }
    }
    if (tmp==0) {
        printf("Marque non trouvée\n");
    }
}
//affichage(par type):
void AffichageTV(voiture *v,int nv,char* type){
    int i, tmp=0;
    for (i=0;i<nv;i++) 
	{
        if (strcmp((v+i)->type,type)==0)
		{
            tmp++;
            AfficheV(*(v+i));
        }
    }
    if (tmp==0) {
        printf("Type non trouvé\n");
    }
}
//ajout(a la fin du tableau):
void AjoutV(voiture* v,int* nv){
    v=(voiture*)realloc(v,(*nv+1)*sizeof(voiture));
    if(v){
    	(*nv)++;
    	fflush(stdin);
        printf("donner le numero de matricule de la voiture :");
        scanf("%d",&(v+*nv-1)->num_matricule);
        fflush(stdin);
        printf("donner sa marque :");
        gets((v+*nv-1)->marque);
        do{
        	fflush(stdin);
        	printf("donner son type(touristique/commerciale):");
        	scanf("%s",(v+*nv-1)->type);
		}while(!(strcmp((v+*nv-1)->type,"touristique")==0 || strcmp((v+*nv-1)->type,"TOURISTIQUE")==0 || strcmp((v+*nv-1)->type,"commerciale")==0 || strcmp((v+*nv-1)->type,"COMMERCIALE")==0));
        printf("donner le prix :");
        scanf("%f",&(v+*nv-1)->prix);
        printf("donner sa date de mise en circulation (jour/mois/annee) :\n");
        scanf("%d%d%d",&(v+*nv-1)->DateMiseCirculation.jour,&(v+*nv-1)->DateMiseCirculation.mois,&(v+*nv-1)->DateMiseCirculation.annee);
    	printf("donner sa date de mise en circulation (jour/mois/annee) :\n");
        do{
        	printf("    ->le jour de mise circuilation : ");
            scanf("%d",&(v+*nv-1)->DateMiseCirculation.jour);
    	}while((v+*nv-1)->DateMiseCirculation.jour>31);
        do{
    		printf("    ->le mois  de mise circuilation : ");
            scanf("%d",&(v+*nv-1)->DateMiseCirculation.mois);
        }while(((v+*nv-1)->DateMiseCirculation.mois<1)||((v+*nv-1)->DateMiseCirculation.mois>12));
        printf("    ->lannee de mise circulation : ");
        scanf("%d",&(v+*nv-1)->DateMiseCirculation.annee);
	}else{
   		printf("la memoire ne support pas cette taille!!\n");	
	}
}

//ajout(dans une position):
void AjoutPosV(voiture* v,int* nv,int p){
	int i;       
    v=(voiture*)realloc(v,(*nv+1)*sizeof(voiture));
    if(v){
    	(*nv)++;
    	for(i=*nv-1;i>=p;i--){
    		(v+i)->DateMiseCirculation.jour=(v+i-1)->DateMiseCirculation.jour;
    	    (v+i)->DateMiseCirculation.mois=(v+i-1)->DateMiseCirculation.mois;
    	    (v+i)->DateMiseCirculation.annee=(v+i-1)->DateMiseCirculation.annee;
    	    (v+i)->prix=(v+i-1)->prix;
    	    strcpy((v+i)->type,(v+i-1)->type);   	    
    	    strcpy((v+i)->marque,(v+i-1)->marque);
    	    (v+i)->num_matricule=(v+i-1)->num_matricule;
		}
    	printf("pour la voiture %d:\n",p);
        fflush(stdin);
        printf("donner le numero de matricule de la voiture :");
        scanf("%d",&(v+p-1)->num_matricule);
        fflush(stdin);
        printf("donner sa marque :");
        gets((v+p-1)->marque);
        do{
        	fflush(stdin);
        	printf("donner son type(touristique/commerciale):");
        	scanf("%s",(v+p-1)->type);
		}while(!(strcmp((v+p-1)->type,"touristique")==0 || strcmp((v+p-1)->type,"TOURISTIQUE")==0 || strcmp((v+p-1)->type,"commerciale")==0 || strcmp((v+p-1)->type,"COMMERCIALE")==0));
        printf("donner le prix :");
        scanf("%f",&(v+p-1)->prix);
        printf("donner sa date de mise en circulation (jour/mois/annee) :\n");
        do{
        	printf("    ->le jour de mise circuilation : ");
            scanf("%d",&(v+p-1)->DateMiseCirculation.jour);
    	}while((v+p-1)->DateMiseCirculation.jour>31);
        do{
    		printf("    ->le mois  de mise circuilation : ");
            scanf("%d",&(v+p-1)->DateMiseCirculation.mois);
        }while(((v+p-1)->DateMiseCirculation.mois<1)||((v+p-1)->DateMiseCirculation.mois>12));
        printf("    ->lannee de mise circulation : ");
        scanf("%d",&(v+p-1)->DateMiseCirculation.annee);
	}else{
   		printf("la memoire ne support pas cette taille!!\n");	
	}	
}

//suppression:
void SuppressionV(voiture *v,int* nv,int num_matricule){
    int i, pos=0;
    for (i=0;i<*nv;i++) {
        if (((v+i)->num_matricule)==num_matricule) {
            pos=i;
        }
    }
    for (i=pos;i<(*nv-1);i++) {
        (v+i)->num_matricule=(v+i+1)->num_matricule;
        strcpy((v+i)->marque,(v+i+1)->marque);
        strcpy((v+i)->type,(v+i+1)->type);
        (v+i)->prix=(v+i+1)->prix;
        (v+i)->DateMiseCirculation.jour=(v+i+1)->DateMiseCirculation.jour;
        (v+i)->DateMiseCirculation.mois=(v+i+1)->DateMiseCirculation.mois;
        (v+i)->DateMiseCirculation.annee=(v+i+1)->DateMiseCirculation.annee;
    }
    v=(voiture*)realloc(v,(*nv-1)*sizeof(voiture));
    (*nv)--;
}

/*
=>les fonctions par rapport a la locations
-la saisie
-l'ajout(dans une position / a la fin du tableau)
-l'affichage
-suppression
*/
//recherch de client par CIN

int RechercheC(client* c,int nc,char* CIN){
        int i;
        //reponse de recherche
        //si return -1 => CIN n'existe pas
        //si return i CIN existe et sa position est i
        for(i=0;i<nc;i++){
            if(strcmp((c+i)->CIN,CIN)==0){
                return i;
            }
        }
        return -1;
}

//recherche de voiture par matricule
int RechercheM(voiture *v,int nv,int num_matricule){
    int i;
    for(i=0;i<nv;i++){
        if((v+i)->num_matricule == num_matricule){
            return i;
        }
    }
    return -1;
}

//saisie:
void RemplissageL(location *l,int nl,voiture* v,int nv,client* c,int nc){
	int i;
	char CIN[15];
    for(i=0;i<nl;i++){
    	printf("pour la location %d:\n",i+1);
        printf("donner le numero de matricule de la voiture : ");
        scanf("%d",&(l+i)->num_matricule);
        if (RechercheM(v,nv,(l+i)->num_matricule)==-1){
            printf("La voiture n'existe pas:\n");
            break;
        }
        printf("donner sa date de location (jour/mois/annee) : \n");
        do{
            printf("    ->le jour de location : ");fflush(stdin);
            scanf("%d",&(l+i)->date_location.jour);
        }while((l+i)->date_location.jour>31);
        do{
            printf("    ->le mois  de location est : ");fflush(stdin);
            scanf("%d",&(l+i)->date_location.mois);
        }while(((l+i)->date_location.mois<1)||((l+i)->date_location.mois>12));
        printf("    ->l'annee de location est : ");fflush(stdin);
        scanf("%d",&(l+i)->date_location.annee);
        fflush(stdin);
		printf("donner le CIN du client :");
        gets((l+i)->CIN);
        if (RechercheC(c,nc,(l+i)->CIN)==-1) {
            printf("Le client n'existe pas: \n");
            break;
        }
        printf("donner la duree de location :");
        scanf("%d",&(l+i)->duree);
        system("cls");
    }
}
//fonction affichage generale des location
/*Affichage Location*/
void AfficheL(location l){
        printf(" le CIN du client de location  est :");
        printf("%s\n",l.CIN);
        printf(" le numero d'immatriculation du location est :");
        printf("%d\n",l.num_matricule);
        printf(" la duree de location est :");
        printf("%d\n",l.duree);
        printf("la date de location est :");
        printf("(%d/%d/%d)\n",l.date_location.jour,l.date_location.mois,l.date_location.annee);
}

//affichage(par client[nom]):
void AffichageCL(location *l,int nl,client* c,int nc,char* CIN){
    int i,j;
    char T[10];
    for(i=0;i<nc;i++){
        if(strcmp((c+i)->nom,CIN)==0){
            strcpy(T,(c+i)->CIN);
            break;
        }
    }
    for(j=0;j<nl;j++) {
        if(strcmp(T,(l+j)->CIN)==0){
            AfficheL(*(l+j));
        }
    }   
}

//affichage(par voiture[immatriculation]):
void AffichageVL(location *l,int nl,int num_matricule){
    int i;
    for (i=0; i<nl; i++) {
        if (((l+i)->num_matricule)==num_matricule) {
            AfficheL(*(l+i));
        }
        }
    }

//affichage(par duree):
void AffichageDL(location *l,int nl,int duree){
    int i;
    for (i=0; i<nl; i++) {
        if (((l+i)->duree)==duree) {
            AfficheL(*(l+i));
        }
        }
    }
//affichage(par date de location):
void AffichageDLL(location *l,int nl,date date_location){
    int i;
    for (i=0;i<nl; i++) {
        if (((l+i)->date_location.jour)==date_location.jour && ((l+i)->date_location.mois)==date_location.mois &&((l+i)->date_location.annee)==date_location.annee){
            AfficheL(*(l+i));
        }
    }
}

//ajout(a la fin du tableau):
void AjoutL(location* l,int* nl){
    l=(location*)realloc(l,(*nl+1)*sizeof(location));
    if(l){
    	(*nl)++;
    	printf("pour la location %d:\n",*nl);
        printf("donner le numero de matricule de la voiture :");
        scanf("%d",&(l+*nl-1)->num_matricule);
        printf("donner sa date de location (jour/mois/annee) :\n");
        scanf("%d%d%d",&(l+*nl-1)->date_location.jour,&(l+*nl-1)->date_location.mois,&(l+*nl-1)->date_location.annee);
        fflush(stdin);
		printf("donner le CIN du client :");
        gets((l+*nl-1)->CIN);
        printf("donner la duree de location :");
        scanf("%d",&(l+*nl-1)->duree);
    }else{
   		printf("la memoire ne support pas cette taille!!\n");	
	}
}

//ajout(dans une position):
void AjoutPosL(location* l,int* nl,int p){
	int i;
    l=(location*)realloc(l,(*nl+1)*sizeof(location));
    if(l){
    	(*nl)++;
    	for(i=*nl-1;i>=p;i--){
    		(l+i)->num_matricule=(l+i-1)->num_matricule;
    		(l+i)->date_location.jour=(l+i-1)->date_location.jour;
    	    (l+i)->date_location.mois=(l+i-1)->date_location.mois;
    	    (l+i)->date_location.annee=(l+i-1)->date_location.annee;
    	    strcpy((l+i)->CIN,(l+i-1)->CIN);
    	    (l+i)->duree=(l+i-1)->duree;
		}
    	printf("pour la location %d:\n",p);
        fflush(stdin);
        printf("donner le numero de matricule de la voiture :");
        scanf("%d",&(l+p-1)->num_matricule);
        printf("donner sa date de location (jour/mois/annee) : \n");
        do{
            printf("    ->le jour de location : ");fflush(stdin);
            scanf("%d",&(l+p-1)->date_location.jour);
        }while((l+p-1)->date_location.jour>31);
        do{
            printf("    ->le mois  de location est : ");fflush(stdin);
            scanf("%d",&(l+p-1)->date_location.mois);
        }while(((l+p-1)->date_location.mois<1)||((l+p-1)->date_location.mois>12));
        printf("    ->l'annee de location est : ");fflush(stdin);
        scanf("%d",&(l+p-1)->date_location.annee);
		fflush(stdin);
		printf("donner le CIN du client :");
        gets((l+p-1)->CIN);
        printf("donner la duree de location :");
        scanf("%d",&(l+p-1)->duree);
    }else{
   		printf("la memoire ne support pas cette taille!!\n");	
	}
}

//suppression:
void SuppressionL(location *l, int* nl,client* c,int* nc,char* ville){
    int i,j,pos,k;
    char T[20];
    for(i=0;i<*nc;i++){
        if(strcmp((c+i)->ville,ville)==0){
            strcpy(T,(c+i)->CIN);
        }
        for(j=0;j<*nl;j++){
            if(strcmp(T,(l+j)->CIN)==0){
            for(k=j;k<(*nl-1);k++) {
                strcpy((l+k)->CIN,(l+k+1)->CIN);
                (l+k)->num_matricule=(l+k+1)->num_matricule;
                (l+k)->duree=(l+k+1)->duree;
                (l+k)->date_location.jour=(l+k+1)->date_location.jour;
                (l+k)->date_location.mois=(l+k+1)->date_location.mois;
                (l+k)->date_location.annee=(l+k+1)->date_location.annee;
            }
            l=(location*)realloc(l,(*nl-1)*sizeof(location));
            (*nl)--;
            }
        }
    }
}
/////////////////////////////////////////
//Creer tab de loca pour un client donnée
void LocationCD(location* l,int* nl,char* CIN){
    int i,cpt=0,k=0;
    location* tnl;
    for (i=0;i<*nl;i++) {
        if (strcmp((l+i)->CIN,CIN)==0){
            cpt++;
        }
    }
    tnl=(location*)malloc(cpt*sizeof(location));
    if(tnl){
        for (i=0;i<*nl;i++) {
            if (strcmp((l+i)->CIN,CIN)==0){
                *(tnl+k) = *(l+i);
                k++;
            }
        }
        
        AfficheL(*tnl);
    }
        else {
            printf("Erreur d'allocation!!");
        }
}
//Creer tab de loca pour une voiture donnée
void LocationVD(location *l,int* nl,int num_matricule){
    int i,  cpt=0, k=0;
    location* tnv;
    for (i=0; i<*nl; i++) {
        if ((l+i)->num_matricule==num_matricule){
            cpt++;
        }
    }
    tnv=(location*)malloc(cpt*sizeof(location));
    if(tnv){
        for (i=0;i<*nl;i++) {
            if ((l+i)->num_matricule==num_matricule){
                *(tnv+k)=*(l+i);
                k++;
            }
        }
        AfficheL(*tnv);
    }
        else {
            printf("Erreur d'allocation!!");
        }
}

//Calculer  CA d'une voiture
float CAV(location *l,int nl,voiture* v,int nv,int num_matricule){
    int i,nbre=0;
    float CA=0;
    for (i=0;i<nl;i++){
        if((l+i)->num_matricule==num_matricule){
            nbre=nbre+(l+i)->duree;
        }
    }
    for (i=0;i<nv;i++) {
        if(((v+i)->num_matricule)==num_matricule) {
            CA=nbre*(v+i)->prix;
        }
        return CA;
    }
}
//Afficher VCA
void AfficheVCA(location *l, int nl, voiture *v, int  nv){
    int i,j,nbre=0,pos=0;
    float prix,max;
    for (i=0; i<nl; i++) {
        if ((v+0)->num_matricule==(l+i)->num_matricule) {
            nbre+=(l+i)->duree;
        }
    }
    max=nbre*(v+0)->prix;
    for(i=1;i<nv;i++) {
        nbre=0;
        for (j=0; j<nl; j++) {
            if ((v+i)->num_matricule == (l+j)->num_matricule) {
                nbre+=(l+i)->duree;
            }
        }
        prix=nbre*(v+i)->prix;
        if (prix>max) {
            max=prix;
            pos=i;
        }
    }
    AfficheV(*(v+pos));
}
//comtage
int comptageC(location *l,int nl,client* c,int nc,char* ville){
    int i,j,cpt=0;
    char T[10];
    for(i=0;i<nc;i++) {
        if(strcmp((c+i)->ville,ville)==0){
            strcpy(T,(c+i)->CIN);
        }
        for(j=i;j<nl;j++) {
            if(strcmp(T,(l+j)->CIN)==0){
                cpt++;
            }
        }
    }
    return cpt+1;
}
