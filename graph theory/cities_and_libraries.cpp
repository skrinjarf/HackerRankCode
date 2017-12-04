#include <iostream>
#include <stdexcept>
#include <cstdlib>
	
using namespace std;

class Vertex
{
private:
	
	bool knjiznica;		//da li je izgradena bolnica ili nije
	int broj;			//redni broj grada(cvora)

public:

	Vertex(int i){ 
		knjiznica=false; 
		broj=i;
	}
	
	bool library(void) {return knjiznica;}
	int index(void) {return broj;}				
};


class Graph
{
private: 
		int **edges;						//edges od I i J su 0 ako nema ceste izmedu vrhova I i J a 1 ako ima     
		int dim;
public:

		Graph(int _dim){
			dim=_dim;
			
			edges=(int **)malloc (dim*sizeof(int*));
			for(int i=0;i<dim;++i) edges[i]=(int*) malloc (dim*sizeof(int));			//alokacija matrice
			
			for(int i=0;i<dim;++i) for(int j=0;j<dim;++j) edges[i][j]=0;  		//postavljanje elemenata na nulu
		}
		
		~Graph(){
			for(int i=0;i<dim;++i) free(edges[i]);
			free(edges);													//dealokacija prvo redci pa zavrsni
		}	
		
		
		bool cesta(int i, int j)					//postoji li cesta izmedu vrha 'i' i 'j'
				{
					if((i>dim)||(j>dim)) throw runtime_error("indexi su izvan dimenzije"); 
					if(edges[i][j]==1) return true;
					return false;
				}
		int dimenzija(void) {return dim;}  
					
};

	
int main()
{
	
return 0;		
}
