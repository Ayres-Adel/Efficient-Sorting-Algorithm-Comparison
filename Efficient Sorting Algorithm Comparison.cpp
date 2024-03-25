#include<stdio.h>
#include<stdlib.h>
#include <time.h>
                    //___________________________________________Welcome(:__________________________________________________//	
                    
//___________________________________________________________________________________________//
void remplirTableauAvecEntiersAleatoires(int *tab,int taille,int valeurMax)
{
	for(int i=0;i<taille;i++)                                                                           
	{                                                                                                                                  //exo01                                                                       
		tab[i]=rand()%valeurMax;
	}
}
//___________________________________________________________________________________________//
void triselction(int *tab,int max)
{
	int i,j,ind_min,temp;
	i=0;
	while(i<max)
	{
		ind_min=i;
		for(j=i+1;j<max;j++)
		{
			if(tab[j]<tab[ind_min])                                                                                                    //exo03 
			{
				ind_min=j;
			}
		}
		temp=tab[i];
		tab[i]=tab[ind_min];
		tab[ind_min]=temp;
		i++;
	}
}
//___________________________________________________________________________________________//
void triinsertion(int *tab,int max)
{
	int i,temp,pos;
	for(i=1;i<max;i++)
	{
		temp=tab[i];
		pos=i;
		while((pos > 0) && (tab[pos-1] > temp))                                                                                        //exo04  
		{
			tab[pos]=tab[pos-1];
			pos=pos-1;
		}
		tab[pos]=temp;
	}
}
//___________________________________________________________________________________________//	
int main()
{
	int size,ask,i,max;
	max=1000000;
    double executionTime[2];
	printf("                                               <<input a size of the table>>\n");
	printf("the size of the table is: ");
	scanf("%d",&size);
	int A[size];
	for(int k=0; k<2; k++){
        remplirTableauAvecEntiersAleatoires(A,size,max);
        printf("\n                                                       <<Table>>\n\n");
            for (int i=0;i<size;i++)
            {
                printf("  %d ",A[i]);
            }
        printf("\n\n                                  <<press 0 for tri selcetion and 1 for tri insertion>>\n");
        printf("the number is: ");
        scanf("%d",&ask);
        clock_t debut = clock();
        if(ask==0)
        {
            printf("\n                                           <<Array sorted by selection>>\n");
            triselction(A,size);
            
        }
        else if(ask==1)
        {
            printf("\n                                              <<Array sorted by insertion>>\n");
            triinsertion(A,size);
        }
        else
        {
            printf("\n                                              <<invalid algorithm>>\n");
        }
        clock_t fin = clock(); 
        double tempsExecution = (double)(fin - debut) / CLOCKS_PER_SEC;
        executionTime[ask] = tempsExecution;
    }
        
        printf("\n                                                       <<Table>>\n\n");
        for (int i=0;i<size;i++) {
            printf("  %d ", A[i]);
        }
        printf("\n\n                               <<Temps d'exécution de tri par selection: %f secondes>>\n", executionTime[0]);
        printf("\n                               <<Temps d'exécution de tri par insertion: %f secondes>>\n", executionTime[1]);
        if(executionTime[0] < executionTime [1])
            printf("\n                             <<Temps d'exécution de tri par selection est plus court que tri par insertion>>\n");
        else
            printf("\n                           <<Temps d'exécution de tri par insertion est plus court que tri par selection>>\n");

}
                      //______________________________________have a nice day (:__________________________________________________//
