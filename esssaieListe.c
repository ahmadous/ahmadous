#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<windows.h>
struct etudiant
{
    int Identifiant;
    char Nom[20];
    char Prenom[30];
    char Adresse[30];
    int numero[9];
    char mail[30];
    int niveau;
    struct etudiant *suiv;
};
typedef struct etudiant etudiant;
struct formation{
	char Nom[20];
	int identifiant;
	int niveau[3];
	struct formation *suiv;
};
typedef struct formation formation;
struct list1{
    etudiant *tete;
    etudiant *queue;
};
typedef struct list1 listEtudiant;
struct list2{
	formation  *tete;
	formation *queue;
};
typedef struct list2 list2;
etudiant *createNode(int Identifiant,char Nom[20],char Prenom[30],char Adresse[30],int numero[9],char mail[30],int niveau){
	int i;   
    etudiant *new=(etudiant*)malloc(sizeof(etudiant));
    new->Identifiant=Identifiant;
    strcpy(new->Nom,Nom);
    strcpy(new->Prenom,Prenom);
    strcpy(new->Adresse,Adresse);
    for(i=0;i<9;i++){
    	new->numero[i]=numero[i];
	}
    strcpy(new->mail,mail);
    new->niveau=niveau;
    new->suiv=NULL;
    return new;
}
formation *noeud(char Nom[20],int identifiant,int niveau[3]){
	formation *new=(formation*)malloc(sizeof(formation));
	int i;
	strcpy(new->Nom,Nom);
	new->identifiant=identifiant;
	for(i=0;i<3;i++){
		new->niveau[i]=niveau[i];
	}
	new->suiv=NULL;
	return new;
}
listEtudiant *videList(){
    listEtudiant *liste=(listEtudiant*)malloc(sizeof(listEtudiant));
    liste->tete=NULL;
    liste->queue=NULL;
    return liste;
}
list2 *Vide(){
	list2 *liste=(list2*)malloc(sizeof(list2));
	liste->tete=NULL;
    liste->queue=NULL;
    return liste;
}
listEtudiant *ajoutEtudiant(listEtudiant *li,int Identifiant,char Nom[20],char Prenom[30],char Adresse[30],int numero[9],char mail[30],int niveau){
    etudiant *new=createNode(Identifiant,Nom,Prenom,Adresse,numero,mail,niveau);
    if (li->tete==NULL)
    {
        li->tete=new;
        li->queue=new;
    }
    else{
    	new->suiv=li->tete;
    	li->tete=new;
    }
    return li;
}
list2 *ajoutFormation(list2 *li,char Nom[20],int identifiant,int niveau[3]){
	formation *new=noeud(Nom,identifiant,niveau);
	if (li->tete==NULL)
    {
        li->tete=new;
        li->queue=new;
    }
    else{
    	new->suiv=li->tete;
    	li->tete=new;
    }
    return li;
}
listEtudiant *newEtudiant(listEtudiant *liste){
	int Identifiant,i,a;
    char Nom[20];
    char Prenom[30];
    char Adresse[30];
    int numero[9];
    char mail[30];
    int niveau;
    printf("identifiant:\t");
    scanf("%d",&Identifiant);
    printf("Nom:\t");
    scanf("%s",Nom);
    printf("prenom:\t");
    scanf("%s",Prenom);
    printf("Adresse:\t");
    scanf("%s",Adresse);
    printf("numero:\t");
    for(i=0;i<9;i++){
        scanf("%d",&a);
        while(a<0 ||a>9){
            scanf("%d",&a);
        }
        numero[i]=a;
    }
    printf("mail:\t");
    scanf("%s",mail);
    printf("niveau:\t");
    scanf("%d",&niveau);
    return ajoutEtudiant(liste,Identifiant,Nom,Prenom,Adresse,numero,mail,niveau);
}
list2 *newFormation(list2 *liste){
	char Nom[20];
	int identifiant;
	int niveau[3];
	int i;
	printf("Nom:\t");
	scanf("%s",Nom);
	printf("identifiant:\t");
	scanf("%d",&identifiant);
	for(i=0;i<3;i++){
		printf("entrer niveau[%d]",i+1);
		scanf("%d",&niveau[i]);
	}
	return ajoutFormation(liste,Nom,identifiant,niveau);
}
void afficheEtudiant(etudiant *p){
	while(p!=NULL){
		printf("\nAffichage de la liste des etudiants par ordre alphabetique\n");
		printf("Prenom:%s\tNom:%s\n",p->Prenom,p->Nom);
		p=p->suiv;
	}
}
void afficheFormation(formation *p){
		while(p!=NULL){
		printf("\nAffichage de la liste des formation");
		printf("tNom:%s\n",p->Nom);
		p=p->suiv;
	}
}
int main(void){
		int i,a;
		char c;
    listEtudiant *liste=videList();
    list2 *list2=Vide();
    int Identifiant;
    int identifiant;
    char NomF[20];
    char Nom[20];
    char Prenom[30];
    char Adresse[30];
    int numero[9];
    char mail[30];
    int niveau;
    int Niveau[3];
    int choix;
    do{
	    printf("faites votre choix:\n1:Gestion des etudiant\n2:Gestion des formation\n3:Gestion des étudiants par classe\n4:Quitter le programme");
	    scanf("%d",&choix);
	    switch (choix)
	    {
	    case 1:
	    	do{
	    		printf("faites votre choix:\n1:Ajouter un etudiant\n2:modifier un etudiant\n3:supprimer un etudiant\n4:Afficher la liste des etudiants par ordre alphabetique");
		        scanf("%d",&choix);
		        switch (choix)
		        {
		        case 1:
		            liste=newEtudiant(liste);
		            break;
		        case 2:
		        	if(liste==NULL){
		        		printf("la liste est vide");
					}
					else{
						etudiant *p=liste->tete;
						if(liste->tete!=NULL){
							printf("liste n'est pas null");
							printf("entrer l'identifiant a modiier:\t");
							scanf("%d",&Identifiant);
							while(p!=NULL && p->Identifiant !=Identifiant){
								p=p->suiv;
							}
							if(p!=NULL){
								printf("identifiant:\t");
							    scanf("%d",&p->Identifiant);
							    printf("Nom:\t");
							    scanf("%s",p->Nom);
							    printf("prenom:\t");
							    scanf("%s",p->Prenom);
							    printf("Adresse:\t");
							    scanf("%s",p->Adresse);
							    printf("numero:\t");
							    for(i=0;i<9;i++){
							        scanf("%d",&a);
							        while(a<0 ||a>9){
							            scanf("%d",&a);
							        }
							        p->numero[i]=a;
							    }
							    printf("mail:\t");
							    scanf("%s",p->mail);
							    printf("reussi");
							}
							
						}
						else{
							printf("liste est null");
						}
					}
		        	break;
		        case 3:
					printf("\n3:Gestion des étudiants par classe\n");
					if(liste==NULL){
						printf("liste vide");
					}
					else{
						printf("liste non vide");
						etudiant *p=liste->tete;
						printf("\nentrer l'identiant de l'etudiant a modifier");
						scanf("%d",&Identifiant);
						if(liste->tete->Identifiant==Identifiant && liste->tete->suiv==NULL){
							free(liste);
							liste=NULL;
							printf("supprimer !");
						}
						else if(p->Identifiant==Identifiant && p->suiv!=NULL){
							liste->tete=liste->tete->suiv;
							free(p);
							p=NULL;	
							printf("\nsupprimer avec success (: !");
						}
						else{
							etudiant *q=liste->tete;
							while(p!=NULL && p->Identifiant!=Identifiant){
								q=p;
								p=p->suiv;
							}
							if(p!=NULL){
								q->suiv=NULL;
								p->suiv=NULL;
								free(p);
								p=NULL;
								printf("\nsupprimer avec success :) !");
							}
						}
					}
				break;
				case 4: 
					printf("affichage par ordre alphabetique\n");
					etudiant *p=liste->tete;
					etudiant *q=liste->tete;
					while(p->suiv!=NULL){
						printf("j'essaie");
						if(liste->tete->Prenom[1]<liste->tete->suiv->Prenom[1]){
							p=p->suiv;
							q->suiv=p;
							p->suiv=q;
							liste->tete=p;
							printf("\nechange reussi");
						}
						printf("\nhfshbgbsd");
						if(p->Prenom[1]<p->suiv->Prenom[1]){
							p=p->suiv;
							q->suiv=p;
							p->suiv=q;
							printf("\nechange reussi");
						}
						else{
							p=p->suiv;
							q=p;
							printf("\non avancee");
						}
					}
					etudiant *j = liste->tete;
					afficheEtudiant(j);
				break;
		        default:
		            break;
		        }	
		        printf("voulez vous continuer si oui tapez 0 sinon autre\t");
		        scanf("%d",&a);
			}
			while(a==0);
	    	break;
	    case 2: 
			do{
				printf("faites votre choix:\n1:Ajouter une formation\n2:modifier une formation\n3:supprimer une formation\n4:Afficher la liste des formation par ordre alphabetique");
		        scanf("%d",&choix);
		        switch(choix){
		        	case 1:
						list2=newFormation(list2);
					break;
					case 2:
						if(list2==NULL){
							printf("la liste est vide");
						}
						else{
							formation *p=list2->tete;
							if(list2->tete!=NULL){
							printf("liste n'est pas null");
							printf("entrer l'identifiant a modiier:\t");
							scanf("%d",&identifiant);
							while(p!=NULL && p->identifiant !=identifiant){
								p=p->suiv;
							}
							if(p!=NULL){
								printf("identifiant:\t");
							    scanf("%d",&p->identifiant);
							    printf("Nom:\t");
							    scanf("%s",p->Nom);
							    printf("niveau:\t");
							    for(i=0;i<3;i++){
							        scanf("%d",&a);
							        while(a<0 ||a>3){
							            scanf("%d",&a);
							        }
							        p->niveau[i]=a;
							    }
							    printf("reussi");
							}
							
						}
						else{
							printf("liste est null");
						}
						}
						break;
					case 3:
						if(list2==NULL){
						printf("liste vide");
						}
						else{
							printf("liste non vide");
							formation *p=list2->tete;
							printf("\nentrer l'identiant de l'etudiant a modifier");
							scanf("%d",&identifiant);
							if(list2->tete->identifiant==identifiant && list2->tete->suiv==NULL){
								free(list2);
								list2=NULL;
								printf("supprimer !");
							}
							else if(p->identifiant==identifiant && p->suiv!=NULL){
								list2->tete=list2->tete->suiv;
								free(p);
								p=NULL;	
								printf("\nsupprimer avec success (: !");
							}
							else{
								formation *q=list2->tete;
								while(p!=NULL && p->identifiant!=identifiant){
									q=p;
									p=p->suiv;
								}
								if(p!=NULL)
								{
									q->suiv=NULL;
									p->suiv=NULL;
									free(p);
									p=NULL;
									printf("\nsupprimer avec success :) !");
								}
							}
						}
						break;
					case 4:
							 
							afficheFormation(list2->tete);
						break;
					default:
		            break;
				}
				printf("voulez vous continuer si oui tapez 0 sinon autre\t");
		        scanf("%d",&a);
			}
			while(a==0);
		break;
		case 3:
			do{
				printf("faites votre choix:\n1:affichage liste d'etudiant par formation\n2:affichage des etudiant d'un niveau donnee:\n");
				scanf("%d",&choix);
				switch(choix){
					case 1:
						printf(":affichage liste d'etudiant par formation\n");
						etudiant *p=liste->tete;
						formation *q=list2->tete;
						while(p!=NULL){
							for(i=0;i<3;i++){
								if(p->niveau==q->niveau[i]){
									printf("niveau:\t%d\t\tNom:\t%d :\t",p->niveau,p->Nom);
									p=p->suiv;
								}
								else{
									p=p->suiv;
								}
							}
						}
					break;
					case 2:
						printf("affichage d'etudiant d'un niveau donnee");
						etudiant *s = liste->tete;
						printf("entrer le niveau");
						scanf("%d",&niveau);
						while(s!=NULL){
							if(niveau==s->niveau){
								printf("niveau:\t%d\t\tNom:\t%d :\n",s->niveau,s->Nom);
								p=p->suiv;
							}
							else{
								p=p->suiv;
							}
						}
					break;
					default:break;
				}
				printf("voulez vous continuer si oui tapez 0 sinon autre\t");
		        scanf("%d",&a);
			}
			while(a==0);	
			
			break;
		case 4:
			exit;
	    default:
	        break;
	    }	
	    system("cls");
    	printf("voulez vous continuer si oui tapez 0 sinon autre\t");
	    scanf("%d",&a);
	    
	}
    while(a==0);
    return 0;
}
