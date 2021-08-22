/*PLANEJAMENTO:
Ler struct
Ver todo o saiba mais.
pag 10 pag 16
"no máximo, 10 veículos." => for(carros=0;    carros<= 10; carros++) 

Dados:
marca => char
modelo (ano) => inteiro
placa => pLetras = string de letras [2] / pNumeros = string de numeros[3]
			concatenação por meio de strcat    strcat(pLetras,pnumeros);
											   printf("Placa => %s",pLetras)
											   
Sistema:
Listar os veículos cadastrados =>	printf marca , if marca = marca	
Inserir um novo veículo => modificar elementos a string marca
Listar os veículos filtrando-se por ano de fabricação => filtrar modelo
Listar os veículos com o ano de fabricação acima de um certo valor especificado pelo usuário =>	filtrar modelo
Listar os veículos filtrando-se pelo modelo =>	filtrar modelo	
O sistema deverá armazenar os veículos ordenados pelo ano de fabricação => ordem de veiculos baseado em modelo
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Carros {
	char marca[50]; //s
	char modelo[50]; //s
	int ano; //ano diferente de modelo
	int placaN; //d
	char placaL[2];
} Carro;

Carro carro[10];
Carro newCarro[10];
int o = 3;
int novoCarro = 3;
int u = 0;
int troca; 

int ano;
int anoMin;
char modelo[50];
void menu();
void anunciar();
void listagem();

int main()
{	
setlocale(LC_ALL, "Portuguese");

printf("                                      BEM-VINDO A NOSSA CONCESSIONÁRIA! VEJA O QUE DESEJA.                                                 \n");

strcpy(carro[0].marca, "Fiat");
strcpy(carro[0].modelo, "compacto");
carro[0].ano = 1998;
carro[0].placaN = 1743;
strcpy(carro[0].placaL, "AAA");

strcpy(carro[1].marca, "Suzuki");
strcpy(carro[1].modelo, "4x4");
carro[1].ano = 2001;
carro[1].placaN = 3756;
strcpy(carro[1].placaL, "BBB");

strcpy(carro[2].marca, "Ford");
strcpy(carro[2].modelo, "SUV");
carro[2].ano = 1999;
carro[2].placaN = 1206;
strcpy(carro[2].placaL, "CCC");

for(o=3; o <=9; o++) {
    strcpy(carro[o].marca, "Não definida");
    strcpy(carro[o].modelo, "Não especificado");
    carro[o].ano = 0;
    carro[o].placaN = 1000;
    strcpy(carro[o].placaL, "xxx");
}
   menu();
   return 0; 
}

void menu () {
int i;
do{ 	

	printf("Alternativas disponiveis: \n");
	printf("1 para ver os carros que estão a venda!\n");
	printf("2 para anunciar seus carros conosco!\n");
	printf("3 para pesquisar um carro pelo seu ano de fabricação\n");
	printf("4 para pesquisar um carro a partir de um ano específico\n");
	printf("5 para pesquisar por um carro pelo seu modelo\n");
	printf("6 para sair.\n");
	printf("Insira o numero correspondente a alternativa desejada!   "); 
    scanf("%i", &i ); 
    
    switch(i) { 
    	case 1:
			troca = 1;
   			while (troca == 1) {
        		troca = 0;        
        		for (u = 0; u <= 8; u++) { 
            		if (carro[u].ano > carro[u + 1].ano) {
            			Carro tmp;;
               			troca = 1;
                		tmp = carro[u];
                		carro[u] = carro[u + 1];
                		carro[u + 1] = tmp;
            		}
        		}
    		} 
    		
    		imprimir();

    	break;
    	case 2:
    		printf("==================================================================================================\n");
    		if(novoCarro <= 9) {
    		printf("Digite a marca do carro: ");
    		scanf("%s%*c", &carro[novoCarro].marca);
    		printf("Digite o modelo do carro: ");
    		scanf("%s%*c", &carro[novoCarro].modelo);
    		printf("Digite o ano do carro: ");
    		scanf("%d%*c", &carro[novoCarro].ano);
    		printf("Digite as letras da placa do carro: ");
    		scanf("%s%*c", &carro[novoCarro].placaL);
    		printf("Digite os numeros da placa do carro: ");
    		scanf("%d%*c", &carro[novoCarro].placaN);
    		
    		printf("==================================================================================================\n");
    		printf("O catálogo foi atualizado, se houver algum problema entre em contato pelo nosso telefone.\n");
    		printf("==================================================================================================\n");
    		
    		novoCarro = novoCarro + 1;
            } else {
            	printf("==================================================================================================\n");
            	printf(" Infelizmente não há mais vagas! Tente novamente outro dia. \n ");
            	printf("==================================================================================================\n");
			}
    	break;
    	case 3:
    		printf("==================================================================================================\n");
			printf("Digite o ano:   ");
			scanf("%d%*c", &ano);
			int p = 0;
			int x = 0;
			printf("\nCom essas especificações nós ");
			for(p=0; p <= 8; p++) {
    			if(ano == carro[p].ano ) {    
        			printf( "\ntemos um carro da marca %s, fabricado no ano de %d, de modelo %s, com placa %s-%d.", carro[p].marca, carro[p].ano, carro[p].modelo, carro[p].placaL, carro[p].placaN);	
    			} else {
        			x++;
    			}
			}
			
			if(p == x) { 
				printf("infelizmente não temos algum carro que se adeque as suas exigências.");
			} else {}  
		
			printf("\n==================================================================================================\n");	 
    	break;
    	case 4:
    		printf("==================================================================================================\n");
			printf("Digite o ano minimo:   ");
			scanf("%d%*c", &anoMin); 
			int p2 = 0;
			int x2 = 0;
			printf("\nCom essas especificações nós ");
			for(p2=0; p2 <= 8; p2++) {
    			if(anoMin <= carro[p2].ano ) {    
        			printf( "\ntemos um carro da marca %s, fabricado no ano de %d, de modelo %s, com placa %s-%d.", carro[p2].marca, carro[p2].ano, carro[p2].modelo, carro[p2].placaL, carro[p2].placaN);	
    			} else {
        			x2++;
    			}
			}
			
			if(p2 == x2) {
				printf("infelizmente não temos algum carro que se adeque as suas exigências.");
			} else {}  
		
			printf("\n==================================================================================================\n");
    	break;
    	case 5:
    		printf("==================================================================================================\n");
			printf("Digite o modelo:   ");
			scanf("%s%*c", &modelo); //esse modelo deve ter [] na sua criação para poder entrar no strcmp
			int p3 = 0;
			int x3 = 0;
			printf("\nCom essas especificações nós ");
			for(p3=0; p3 <= 8; p3++) {
    			if(strcmp(modelo, carro[p3].modelo) == 0) {
        			printf( "\ntemos um carro da marca %s, fabricado no ano de %d, de modelo %s, com placa %s-%d.", carro[p3].marca, carro[p3].ano, carro[p3].modelo, carro[p3].placaL, carro[p3].placaN);
    			} else {
        			x3++;
    			}
			}
			
			if(p3 == x3) {
				printf("infelizmente não temos algum carro que se adeque as suas exigências.");
			} else {}  
		
			printf("\n==================================================================================================\n");	 
    	break;
    	case 6:
    		printf("==================================================================================================\n");
    		printf("Obrigado por ver nosso produtos, volte sempre, estaremos de portas abertas!");
    	break;
		}	
	}
	while(i!=6);
}

void imprimir() {
    printf("======================================================================================================\n");
    for (u=0; u <= 9; u++) {
    	if(carro[u].ano != 0) {
        printf( "Temos um carro da marca %s, fabricado no ano de %d, de modelo %s, com placa %s-%d.\n", carro[u].marca, carro[u].ano, carro[u].modelo, carro[u].placaL, carro[u].placaN);
		} else {}
    }
    printf("======================================================================================================\n");
}




