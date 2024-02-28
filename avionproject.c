#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct date{
	int jour,mois,annee;	
}date;

typedef struct avion{
	char num_matricul[20];
	int nbr_place;
	char etat;
	date ddl;
	int nbr_vol;
	struct avion* suivant;
}avion;

int ValidationDate(int jour,int mois,int annee){
    int valide=1;
    if(mois<1 || mois>12){
        valide=0;
    }
    switch(mois){
        case 2:
            if(annee%4==0 && (annee%100!=0 || annee%400==0)){
                if(jour<1 || jour>29){
                    valide=0;
                }
            }else{
                if(jour<1 || jour>28){
                    valide=0;
            	}
            }
            break;
        case 4:
            if(jour<1 || jour>30){
                valide=0;
            }
            break;
		case 6:
            if(jour<1 || jour>30){
                valide=0;
            }
            break;  
		case 9:
            if(jour<1 || jour>30){
                valide=0;
            }
            break;  
        case 11:
            if(jour<1 || jour>30){
                valide=0;
            }
            break;
        default:
            if (jour<1 || jour>31){
                valide=0;
            }
            break;
    }
    if(annee<0 || annee>9999) {
        valide=0;
    }
    return valide;
}

int ValidationMatricule(avion* liste,char* num_matricul){
	avion* p=liste;
	int valide=1;
	if(p->suivant==NULL){
		return valide;
	}else{
		while(p!=NULL){
			if(liste->num_matricul==num_matricul){
				valide=0;
			}
			p=p->suivant;
		}
		return valide;
	}
}

avion* Saisie(){
	avion *liste=(avion*)malloc(sizeof(avion));
	if(liste){
		//do{
			printf("donner le matricule :");fflush(stdin);
			gets(liste->num_matricul);
		//}while(ValidationMatricule(liste,liste->num_matricul)==0);
		do{
			printf("donner le nombre de place :");
			scanf("%d",&liste->nbr_place);
		}while(liste->nbr_place<=0);
		do{
			printf("donner l'etat de l'avion (D/d=Decolle ou A/a=Atterrit ou M/m=Maintenance) :");fflush(stdin);
			scanf("%c",&liste->etat);
			//	D/d=Decolle    A/a=Atterrit    M/m=Maintenance
		}while(liste->etat!='D' && liste->etat!='d' && liste->etat!='a' && liste->etat!='A' && liste->etat!='M' && liste->etat!='m');	
		do{
			printf("donner la date de lise en service :\n");
			scanf("%d%d%d",&liste->ddl.jour,&liste->ddl.mois,&liste->ddl.annee);
		}while(ValidationDate(liste->ddl.jour,liste->ddl.mois,liste->ddl.annee)!=1);
		do{
			printf("donner le nombre de vols :");
			scanf("%d",&liste->nbr_vol);
		}while(liste->nbr_vol<=0);
		return liste;	
	}else{
		printf("problem d'allocation\n");
	}	
}

avion* AjoutDebut(avion* liste){
	avion* tmp;
	tmp=(avion*)malloc(sizeof(avion));
	if(tmp){
		tmp=Saisie();
		tmp->suivant=liste;
		liste=tmp;
		return liste;
	}else{
		printf("problem d'allocation\n");
	}
}

avion* AjoutFin(avion *liste){
	avion* tmp,*p=liste;
	if(p==NULL){
		AjoutDebut(liste);
	}else{
		tmp=(avion*)malloc(sizeof(avion));
		if(tmp){
			tmp=Saisie();
			while(p->suivant!=NULL){	
				p=p->suivant;
			}
			p->suivant=tmp;
			tmp->suivant=NULL;
			return liste;	
		}else{
			printf("problem d'allocation\n");
		}	
	}	
}

void Affichage(avion* liste){
	avion* p=liste;
	int i=0;
	while(p!=NULL){
		printf("pour l'avion %d :\n",i+1);i++;
		printf("le matricule est : %s\n",p->num_matricul);
		printf("le nombre de place : %d\n",p->nbr_place);
		if(p->etat=='D' || p->etat=='d'){
			printf("l'etat de l'avion est : Decolle\n");
		}else if(p->etat=='A' || p->etat=='a'){
			printf("l'etat de l'avion : Atterrit\n");
		}else{
			printf("l'etat de l'avion : Maintenance\n");
		}
		printf("la date de lise en service est : (%d/%d/%d)\n",p->ddl.jour,p->ddl.mois,p->ddl.annee);
		printf("le nombre de vols est : %d\n",p->nbr_vol);	
		p=p->suivant;
	}	
}

avion* AjoutPosition(avion* liste,int pos){
	int i=0;
	avion* tmp=liste,*p;
	if(pos==1){
		liste=AjoutDebut(liste);
	}else{
		while(tmp->suivant!=NULL){
			i++;
			if(i==pos-1) break;
			tmp=tmp->suivant;	
		}
		if(tmp==NULL){
			printf("position non trouvable\n");
			printf("tapez une touche pour sortir :");	
			getch();
			return liste;	
		}
		p=(avion*)malloc(sizeof(avion));
		if(p){
			p=Saisie();
			p->suivant=tmp->suivant;
			tmp->suivant=p;
			return liste;
		}else{
			printf("problem d'allocation\n");
		}
	}
}

avion* TrieDecroissant(avion* liste){//x
	avion* p=liste,*tmp;
	int i=0;
	tmp=(avion*)malloc(sizeof(avion));
	tmp=Saisie();
	if(tmp){
		while(p!=NULL){
			if(tmp->nbr_place<=liste->nbr_place){
				liste=AjoutPosition(liste,i+2);
				break;
			}
			p=p->suivant;
			i++;
		}
		return liste;
	}else{
		printf("problem d'allocation\n");
	}

}

avion* SuppressionDebut(avion* liste){
	avion* p=liste;
	if(p==NULL){
		printf("liste vide\n");
		printf("tapez une touche pour sortir :");
		getch();
		return liste;
	}
	liste=p->suivant;
	free(p);
	return liste;
}

avion* SuppressionFin(avion*liste){
	avion* p=liste,*tmp;
	if(p==NULL){
		printf("liste vide\n");
		printf("tapez une touche pour sortir :");
		getch();
		return liste;
	}
	if(p->suivant==NULL){
		free(liste);
		return NULL;
	}
	while(p->suivant->suivant!=NULL){
		p=p->suivant;
	}
	tmp=p->suivant;
	free(tmp);
	p->suivant=NULL;
	return liste;
}

avion* SuppressionPos(avion* liste,int pos){
	avion* p=liste,*tmp;
	int i=0;
	if(liste==NULL){
		printf("liste vide\n");
		printf("tapez une touche pour sortir :");
		getch();
		return liste;
	}	
	if(pos==1){
		return SuppressionDebut(liste);
	}
	while(p!=NULL){
		i++;
		if(pos-1==i)break;
		p=p->suivant;
	}
	if(p==NULL){
		puts("Position indisponible\n");
		return liste;
	}
	tmp=p->suivant;
	p->suivant=p->suivant->suivant;
	free(tmp);
	return liste;
}

avion* SuppressionMatricule(avion *liste,char* num_matricul){
    avion* p=liste;
    int i=0;
    while (p!=NULL){
        if(strcmp(p->num_matricul,num_matricul)==0){
            break;
        }
        p=p->suivant;
        i++;
    }
    return SuppressionPos(liste,i+1);
}

//question 6

void VerifierAvion(avion* liste){
	avion* p=liste;
	while(p!=NULL){
		if(p->etat=='d' || p->etat=='D'){
			printf("l'avion du matricule %s n'est pas dans l'aeroport (-1)\n",p->num_matricul);
		}else if(p->etat=='a' || p->etat=='A' || p->etat=='m' || p->etat=='M'){
			printf("l'avion du matricule %s est dans l'aeroport\n",p->num_matricul);
		}
		p=p->suivant;
	}
}

//question 7

avion* SuppressionMaintenance20(avion* liste,date ddl){//x
	avion* p=liste;
	int i=0;
	while(p!=NULL){
		if(((ddl.annee)-(p->ddl.annee))>=20 && (p->etat=='m' || p->etat=='M')){
			SuppressionPos(liste,i+1);
		}
		i++;
		p=p->suivant;
	}
	return liste;
}

//question 8

int NbrAvion(avion* liste){
	avion* p=liste;
	int i=0;
	while(p!=NULL){
		p=p->suivant;
		i++;
	}
	//printf("le nombre total d'avions est :%d",i);
	return i;
}

//question 9

void AvionAtterrit(avion* liste,date ddl){
	avion* p=liste;
	int i=0;
	while(p!=NULL){
		if(p->ddl.jour==ddl.jour && p->ddl.mois==ddl.mois && p->ddl.annee==ddl.annee && (p->etat=='A' || p->etat=='a')){
			i++;
		}
		p=p->suivant;
	}
	printf("le nombre total d'avions atterrit a t=(%d/%d/%d) est :%d",ddl.jour,ddl.mois,ddl.annee,i);
}

//question 10

void AvionDecolle(avion* liste,date ddl){
	avion* p=liste;
	int i=0;
	while(p!=NULL){
		if(p->ddl.jour==ddl.jour && p->ddl.mois==ddl.mois && p->ddl.annee==ddl.annee && (p->etat=='D' || p->etat=='d')){
			i++;
		}
		p=p->suivant;
	}
	printf("le nombre total d'avions decolle a t=(%d/%d/%d) est :%d",ddl.jour,ddl.mois,ddl.annee,i);
}

//question 11

void AvionMaintenance(avion* liste,date ddl){
	avion* p=liste;
	int i=0;
	while(p!=NULL){
		if(p->ddl.jour==ddl.jour && p->ddl.mois==ddl.mois && p->ddl.annee==ddl.annee && (p->etat=='M' || p->etat=='m')){
			i++;
		}
		p=p->suivant;
	}
	printf("le nombre total d'avions en maintenance a t=(%d/%d/%d) est :%d",ddl.jour,ddl.mois,ddl.annee,i);
}

//question 12

void PourcentageAvion(avion* liste){
	avion* p=liste;
	int total=NbrAvion(liste);
	float d=0,a=0,m=0;
	while(p!=NULL){
		if(p->etat=='M' || p->etat=='m'){
			m++;
		}else if(p->etat=='D' || p->etat=='d'){
			d++;
		}else{
			a++;
		}
		p=p->suivant;
	}
	printf("les pourcentages sont :\n");
	printf("Decolle :%.2f %\t",(d/total)*100);
	printf("Atterrit :%.2f %\t",(a/total)*100);
	printf("En Maintenance :%.2f %\n",(m/total)*100);
}

//question 13

void MaxVol(avion* liste,date ddl){
	avion* p=liste;
	char num_matricul[20];
	int max=liste->nbr_vol,i=0;
	while(p!=NULL){
		if(((p->ddl.annee)-(ddl.annee))>10){
			goto finfct;
		}else if((p->ddl.annee)-(ddl.annee)==10){
			if((p->ddl.mois)>(ddl.mois)){
				goto finfct;
			}else if((p->ddl.mois)==(ddl.mois)){
				if((p->ddl.jour)>=(ddl.jour)){
					goto finfct;
				}else{
					if(max<=p->nbr_vol){
						max=p->nbr_vol;
						strcpy(num_matricul,liste->num_matricul);
					}
					goto affichagefct;
				}
			}else{
				if(max<=p->nbr_vol){
					max=p->nbr_vol;
					strcpy(num_matricul,liste->num_matricul);
				}
				goto affichagefct;
			}
		}else{
			affichagefct:
			if(max<=p->nbr_vol){
				max=p->nbr_vol;
				strcpy(num_matricul,liste->num_matricul);
			}
		}
		finfct:
		p=p->suivant;
	}
	p=liste;
	while(p!=NULL){
		if(strcmp(num_matricul,liste->num_matricul)==0){
		printf("voici l'avion age moins de 10ans avec un nombre de vols maximal :\n");
		printf("le matricule est : %s\n",p->num_matricul);
		printf("le nombre de place : %d\n",p->nbr_place);
		if(p->etat=='D' || p->etat=='d'){
		printf("l'etat de l'avion est : Decolle\n");
		}else if(p->etat=='A' || p->etat=='a'){
			printf("l'etat de l'avion : Atterrit\n");
		}else{
			printf("l'etat de l'avion : Maintenance\n");
		}
		printf("la date de lise en service est : (%d/%d/%d)\n",p->ddl.jour,p->ddl.mois,p->ddl.annee);
		printf("le nombre de vols est : %d\n",p->nbr_vol);
		i++;
		break;
		}
		p=p->suivant;
	}
	if(i==0){
		printf("auqu'une avion est age moins de 10ans avec un nombre de vols maximal :\n");
	}
}

//question 14

void MinVol(avion* liste,date ddl){
	avion* p=liste;
	char num_matricul[20];
	int min=liste->nbr_vol,i=0;
	while(p!=NULL){
		if(((p->ddl.annee)-(ddl.annee))>10){
			goto finfct;
		}else if((p->ddl.annee)-(ddl.annee)==10){
			if((p->ddl.mois)>(ddl.mois)){
				goto finfct;
			}else if((p->ddl.mois)==(ddl.mois)){
				if((p->ddl.jour)>=(ddl.jour)){
					goto finfct;
				}else{
					if(min>=p->nbr_vol){
						min=p->nbr_vol;
						strcpy(num_matricul,liste->num_matricul);
					}
					goto affichagefct;
				}
			}else{
				if(min>=p->nbr_vol){
					min=p->nbr_vol;
					strcpy(num_matricul,liste->num_matricul);
				}
				goto affichagefct;
			}
		}else{
			affichagefct:
			if(min>=p->nbr_vol){
				min=p->nbr_vol;
				strcpy(num_matricul,liste->num_matricul);
			}
		}
		finfct:
		p=p->suivant;
	}
	p=liste;
	while(p!=NULL){
		if(strcmp(num_matricul,liste->num_matricul)==0){
			printf("voici l'avion age moins de 10ans avec un nombre de vols minimal :\n");
			printf("le matricule est : %s\n",p->num_matricul);
			printf("le nombre de place : %d\n",p->nbr_place);
			if(p->etat=='D' || p->etat=='d'){
			printf("l'etat de l'avion est : Decolle\n");
			}else if(p->etat=='A' || p->etat=='a'){
				printf("l'etat de l'avion : Atterrit\n");
			}else{
				printf("l'etat de l'avion : Maintenance\n");
			}
			printf("la date de lise en service est : (%d/%d/%d)\n",p->ddl.jour,p->ddl.mois,p->ddl.annee);
			printf("le nombre de vols est : %d\n",p->nbr_vol);
			i++;
			break;
		}
		p=p->suivant;
	}
	if(i==0){
		printf("auqu'une avion est age moins de 10ans avec un nombre de vols minimal :\n");
	}
}

int main(){
	int choix,pos,i;
	avion* liste=NULL;
	char num_matricul[20];
	date ddl;
	
	here1:
	system("cls");
	printf("\t\t                          Menu\n");
	printf("\t                            .--------------.  \n\n");
	printf("\n\t                    \xc9\xcd                            \xcd\xbb");
	printf("\n\t\t                    1-Ajouter Avion");
	printf("\n\t\t                    2-Afficher Avion");
	printf("\n\t\t                    3-Supprimer Avion");
	printf("\n\t\t                    4-Autre Question");
	printf("\n\t\t                    5-Quitter");
	printf("\n\t                    \xc8\xcd                            \xcd\xbc");
	printf("\n\n\t\t                     Votre Choix :");
	do{
		scanf("%d",&choix);
	}while(choix!=1 && choix!=2 && choix!=3 && choix!=4 && choix!=5);
	system("cls");
	switch(choix){
		case 1:
			system("cls");
			printf("\t\t                          Menu\n");
			printf("\t                            .--------------.  \n\n");
			printf("\n\t                    \xc9\xcd                            \xcd\xbb");
			printf("\n\t\t                    1-Ajout Debut");
			printf("\n\t\t                    2-Ajout Fin");
			printf("\n\t\t                    3-Ajout Position");
			printf("\n\t\t                    4-Ajout Par Nombre \n\t\t\t\t      de Place (trie)");
			printf("\n\t\t                    5-retourner");
			printf("\n\t                    \xc8\xcd                            \xcd\xbc");
			printf("\n\n\t\t                     Votre Choix :");
			do{
				scanf("%d",&choix);
			}while(choix!=1 && choix!=2 && choix!=3 && choix!=4 && choix!=5);
			system("cls");
			switch(choix){
				case 1:
					liste=AjoutDebut(liste);
					break;
				case 2:
					liste=AjoutFin(liste);
					break;
				case 3:
					do{
						printf("donner une position :");
						scanf("%d",&pos);	
					}while(pos<=0);
					liste=AjoutPosition(liste,pos);
					break;
				case 4:
					liste=TrieDecroissant(liste);
					break;
				case 5:
					goto here1;
					break;
			}
			break;
		case 2:
			Affichage(liste);
			printf("\n\n");
			printf("tapez une touche pour sortir :");
			getch();
			break;
		case 3:
			system("cls");
			printf("\t\t                          Menu\n");
			printf("\t                            .--------------.  \n\n");
			printf("\n\t                    \xc9\xcd                              \xcd\xbb");
			printf("\n\t\t                    1-Suppression Debut");
			printf("\n\t\t                    2-Suppression Fin");
			printf("\n\t\t                    3-Suppression Position");
			printf("\n\t\t                    4-Suppression Par\n \t\t\t\t      Numero Matricul");
			printf("\n\t\t                    5-retourner");
			printf("\n\t                    \xc8\xcd                              \xcd\xbc");
			printf("\n\n\t\t                     Votre Choix :");
			do{
				scanf("%d",&choix);
			}while(choix!=1 && choix!=2 && choix!=3 && choix!=4 && choix!=5);
			system("cls");
			switch(choix){
				case 1:
					liste=SuppressionDebut(liste);
					break;
				case 2:
					liste=SuppressionFin(liste);
					break;
				case 3:
					do{
						printf("donner une position :");
						scanf("%d",&pos);	
					}while(pos<=0);
					liste=SuppressionPos(liste,pos);
					break;
				case 4:
					//do{
						printf("donner un matricul :");fflush(stdin);
						gets(num_matricul);	
					//}while(validationMatricul(liste,num_maltricul)!=0);
					liste=SuppressionMatricule(liste,num_matricul);
					break;
				case 5:
					goto here1;
					break;
			}
			break;
		case 4:
			system("cls");
			printf("\t\t                          Menu\n");
			printf("\t                            .--------------.  \n\n");
			printf("\n\t                    \xc9\xcd                            \xcd\xbb");
			printf("\n\t\t                      1-Question 6");
			printf("\n\t\t                      2-Question 7");
			printf("\n\t\t                      3-Question 8");
			printf("\n\t\t                      4-Question 9");
			printf("\n\t\t                      5-Question 10");
			printf("\n\t\t                      6-Question 11");
			printf("\n\t\t                      7-Question 12");
			printf("\n\t\t                      8-Question 13");
			printf("\n\t\t                      9-Question 14");
			printf("\n\t\t                      10-retourner");
			printf("\n\t                    \xc8\xcd                            \xcd\xbc");
			printf("\n\n\t\t                     Votre Choix :");
			do{
				scanf("%d",&choix);
			}while(choix!=1 && choix!=2 && choix!=3 && choix!=4 && choix!=5 && choix!=6 && choix!=7 && choix!=8 && choix!=9 && choix!=10);
			system("cls");
			switch(choix){
				case 1:
					VerifierAvion(liste);
					break;
				case 2:
					do{
						printf("donner une date :\n");
						scanf("%d%d%d",&ddl.jour,&ddl.mois,&ddl.annee);	
					}while(ValidationDate(liste->ddl.jour,liste->ddl.mois,liste->ddl.annee)!=1);
					liste=SuppressionMaintenance20(liste,ddl);
					break;
				case 3:
					i=NbrAvion(liste);
					printf("le nombre total d'avions est :%d",i);
					break;
				case 4:
					do{
						printf("donner une date :\n");
						scanf("%d%d%d",&ddl.jour,&ddl.mois,&ddl.annee);	
					}while(ValidationDate(liste->ddl.jour,liste->ddl.mois,liste->ddl.annee)!=1);
					AvionAtterrit(liste,ddl);
					break;
				case 5:
					do{
						printf("donner une date :\n");
						scanf("%d%d%d",&ddl.jour,&ddl.mois,&ddl.annee);	
					}while(ValidationDate(liste->ddl.jour,liste->ddl.mois,liste->ddl.annee)!=1);
					AvionDecolle(liste,ddl);
					break;
				case 6:
					do{
						printf("donner une date :\n");
						scanf("%d%d%d",&ddl.jour,&ddl.mois,&ddl.annee);	
					}while(ValidationDate(liste->ddl.jour,liste->ddl.mois,liste->ddl.annee)!=1);
					AvionMaintenance(liste,ddl);
					break;
				case 7:
					PourcentageAvion(liste);
					break;
				case 8:
					do{
						printf("donner une date :\n");
						scanf("%d%d%d",&ddl.jour,&ddl.mois,&ddl.annee);	
					}while(ValidationDate(liste->ddl.jour,liste->ddl.mois,liste->ddl.annee)!=1);
					MaxVol(liste,ddl);
					break;
				case 9:
					do{
						printf("donner une date :\n");
						scanf("%d%d%d",&ddl.jour,&ddl.mois,&ddl.annee);	
					}while(ValidationDate(liste->ddl.jour,liste->ddl.mois,liste->ddl.annee)!=1);
					MinVol(liste,ddl);
					break;
				case 10:
					goto here1;
					break;
			}
			printf("\n\n");
			printf("tapez une touche pour sortir :");
			getch();
			break;
		case 5:
			goto fin;
			break;
	}
	goto here1;
	fin:
	printf("Fin programme\n");
	return 0;
}
