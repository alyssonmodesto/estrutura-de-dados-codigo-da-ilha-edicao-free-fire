#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
//#define MaxCadastro 10

typedef struct {
    char NomeItem[50];  
    char TipoItem[30];      
    int Quantidade; 
} ItensCadastro;

ItensCadastro IC[10];

char *DescItemSelecionado[] = {"Sair", "Adicionar item", "Remover item", "Listar itens da mochila"};

int ItemSelecionado = 0;
int itemCadastrado = 0;

 //menu
  int menu(){
	  
	 int selecao = 0; 
	 
	 printf("----------------------------\n"); 
     printf("0. %s\n",DescItemSelecionado[0]);
     printf("1. %s\n",DescItemSelecionado[1]);
     printf("2. %s\n",DescItemSelecionado[2]);
     printf("3. %s\n",DescItemSelecionado[3]);
     printf("----------------------------\n");
     printf("Escolha uma opção\n");
     
     scanf("%d", &selecao);
	 
	 return selecao;
	  
  }
  
  //Listagem	 
  void Listagem(int itemCadastrados) {
	  
	   int contador = 1;
	   
       printf("Nome do Item   Tipo do Item   Quantidade \n");		
     	     	
       for (int i = 0; i < itemCadastrados; i++) {   
	   
          printf("%s", IC[contador].NomeItem);		
          printf("             %s",IC[contador].TipoItem);		
     	  printf("             %i\n", IC[contador].Quantidade);
		  
		  contador++;
       }
	   
     }

 //Cadastro	 
  int cadastro(int itensCadastrados) {
 
       int Contador = itensCadastrados + 1;
		 
       //for (int i = 0; i < 9 - 1; i++) {   
	   
          printf("Nome do Item:\n");		
          scanf(" %[^\n]", IC[Contador].NomeItem);		
     	
          printf("Tipo do Item (ex: Arma, Munição, Cura):\n");		
          scanf(" %[^\n]", IC[Contador].TipoItem);		
     	
          printf("Quantidade:\n");		
          scanf("%d", &IC[Contador].Quantidade);
        	
         // Contador++;	
       //}
	   
	   return Contador; 
     }
	 
    //Remover	 
    void Remover() {   			  
       //void *realloc(void *IC[], 1);     	       	
    }
	 
int main() {
 		
     printf("=====================\n");
     printf("MOCHILA DE SOBREVIVENCIA - CODIGO DA ILHA\n");
     printf("=====================\n");
     
     printf("Itens na mochila: 0/10\n");
	 
	 VoltarMenu:	 
	 ItemSelecionado = menu();            
     printf("%s\n",DescItemSelecionado[ItemSelecionado]);
	 
	 if (ItemSelecionado == 0) {
       return 0;
	}
	 
	if (ItemSelecionado == 1) {
	    itemCadastrado = cadastro(itemCadastrado);
		goto VoltarMenu;
	}
	
	if (ItemSelecionado == 2) {
		        		
	    Remover();
				
		goto VoltarMenu;
	}
	 
     if (ItemSelecionado == 3) {
	    Listagem(itemCadastrado);
		goto VoltarMenu;
	}
	 
            	 
	return 0;
}
