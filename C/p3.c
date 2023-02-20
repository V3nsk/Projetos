#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
	void *elemento;
	struct _no *prox;
}No;

typedef struct _lista{
	No *primeiro;
	No *ultimo;
	int tamanho;
}Lista;

typedef struct _personagem{
    int id;
    char apelido[20];
    int idade;
} Personagem;

typedef struct _livro
{
    int id;
    char titulo[30];
    int ano;

    Lista *personagens;  
} Livro;

typedef struct _autor
{
    int id;
    char nome[30];
    char paisNasc[30];

    Lista *livros;
} Autor;

void menu();         
void menuOp();       
Lista *criarLista(); 
void ins();          
void *CadAut();      
void ListAutor();    
void *CadLivro();    
void ListLivro();    
void *CadPerso();    
void ListPerso();    
void *buscar();      
int remover();   

//FUNÇÕES
Lista *criarLista(){
	Lista *novaLista = (Lista*) malloc(sizeof(Lista));
	novaLista->primeiro = NULL;
	novaLista->ultimo = NULL;
	novaLista->tamanho = 0;
	return novaLista;
}

void ins(Lista *lista, void *novoElemento){
	No *novoNo = (No *) malloc(sizeof(No));
	novoNo->elemento = novoElemento;
	novoNo->prox = NULL;

	if(lista->tamanho == 0){
		lista->primeiro = novoNo;
		lista->ultimo = novoNo;
		lista->tamanho++;
	}else{
		lista->ultimo->prox = novoNo;
		lista->ultimo = novoNo;
		lista->tamanho++;
	}
}

void *CadAut(Lista *autor, int idAutor) 
{
    Autor *NovoAutor = (Autor *)malloc(sizeof(Autor));
    NovoAutor->id = idAutor;

    puts("\n\tNome do autor: ");
    printf("\t");
    scanf(" %[^\n]s", NovoAutor->nome);
    puts("\n\tPais de nascimento do autor: ");
    printf("\t");
    scanf(" %[^\n\t]s", &NovoAutor->paisNasc);

    NovoAutor->livros = criarLista();

   ins(autor, (void *) NovoAutor);
}

void ListAutor(Lista *autor) {
    No *aux = autor->primeiro;
    Autor *aut;
    while (aux != NULL){
        aut = (Autor*) aux->elemento;
        printf("\tId: %d\t | Nome: %s\t | P.nasc: %s\t | N.livros: %d\t\n",
            aut->id, aut->nome, aut->paisNasc, aut->livros->tamanho);
        aux = aux->prox;
    }
    printf("\n\n");
}

void *CadLivro(Lista *livros ,int idLiv) {
    Livro *NovoLivro = (Livro *)malloc(sizeof(Livro));
    NovoLivro->id = idLiv;

    puts("\n\tTitulo do livro: ");
    printf("\t");
    scanf(" %[^\n]s", NovoLivro->titulo);
    puts("\n\tAno do livro: ");
    printf("\t");
    scanf(" %d", &NovoLivro->ano);

    NovoLivro->personagens = criarLista();

    ins(livros, (void *) NovoLivro);
}

void ListLivro(Lista *livros){
    No *aux = livros->primeiro;
    Livro *livs;
    while (aux != NULL){
        livs = (Livro*) aux->elemento;
        printf("\tId: %d\t | Titulo: %s\t | Ano: %d\t | N.Personagens: %d\n",
            livs->id, livs->titulo, livs->ano, livs->personagens->tamanho);
        aux = aux->prox;
    }
    printf("\n\n");
}

void *CadPerso(Lista *personagens ,int idPerso)
{
    Personagem *NovoPerso = (Personagem *)malloc(sizeof(Personagem));
    NovoPerso->id = idPerso;

    puts("\n\tApelido do personagem: ");
    printf("\t");
    scanf(" %[^\n]s", NovoPerso->apelido);
    puts("\n\tIdade do personagem: ");
    printf("\t");
    scanf(" %d", &NovoPerso->idade);

    ins(personagens, (void *) NovoPerso);
}

void ListPerso(Lista *personagens){
    No *aux = personagens->primeiro;
    Personagem *pers;
    while (aux != NULL){
        pers = (Personagem*) aux->elemento;
        printf("\tId: %d\t | Apelido: %s\t | Idade: %d\t\n",
            pers->id, pers->apelido, pers->idade);
        aux = aux->prox;
    }
    printf("\n\n");
}

void *buscar (Lista *lista, int pos){
    if (pos < 0 || pos>= lista->tamanho){
        return NULL;
    } else {
        No *aux = lista->primeiro;
        for (int i = 0; i < pos; i++){
            aux = aux->prox;
        }
        return aux->elemento;
    }
}

int remover(Lista *lista, int pos){
    if (pos < 0 || pos >= lista->tamanho){
        return -1;
    }
    if (lista->tamanho == 1) {
        lista->primeiro = NULL;
        lista->ultimo  = NULL;
        lista->tamanho--;
        return 0;
    }

    if (pos == 0) {
        lista->primeiro = lista->primeiro->prox;
        lista->tamanho--;
        return 0;
    }

    No *aux = lista->primeiro;
    for (int i = 0; i < pos-1; i++) {
        aux = aux->prox;       
    }
    aux->prox = aux->prox->prox;

    if (lista->tamanho-1 == pos) {
        lista->ultimo = aux;
    }
    lista->tamanho--;
    return 0;
}


int main()
{
    Lista  *personagens = criarLista();
    Lista  *livros = criarLista();
    Lista  *autor = criarLista ();
    Autor *aut;
    Livro *livs;
    Personagem *pers;
    int idAutor = 0, idLiv = 0, idPerso = 0, op;
    int pos;
    
    while (op != 0)
    {
        menu();
        scanf("%d", &op);

        switch (op) 
        {
        case 1: 
            system("cls");
            puts("\tO que voce quer cadastrar:\n");
            menuOp();
            scanf("\t %d", &op);

            switch (op) {
            case 1: 
                system("cls");
                CadAut(autor, idAutor);
                idAutor++;
                puts("\n\tOperacao realizada com sucesso\n\n\n\t");
                system("pause");
                system("cls");
                break;

            case 2: 
                system("cls");
                CadLivro(livros, idLiv);
                idLiv++;
                puts("\n\tOperacao realizada com sucesso\n\n\n\t");
                system("pause");
                system("cls");
                break;

            case 3: 
                system("cls");
                CadPerso(personagens, idPerso);
                idLiv++;
                puts("\n\tOperacao realizada com sucesso\n\n\n\t");
                system("pause");
                system("cls");
            break;

            default:
                system("cls");
                puts("\n\tOperacao invalida\n Escolha apenas uma das opcoes listadas.");
                break;
            }
            break;

        case 2: 
            system("cls");
            puts("\tO que voce quer listar:\n");
            menuOp();
            scanf("\t %d", &op);

            switch (op) {
            case 1: 
                if (autor->tamanho != 0){
                    system("cls");
                    ListAutor(autor);
                    system("pause");
                    system("cls");
                } else {
                    system("cls");
                    puts("\tNenhum autor cadastrado\n");
                }
                break;

            case 2: 
                if (livros->tamanho !=0){
                    system("cls");
                    ListLivro(livros);
                    system("pause");
                    system("cls");
                } else {
                    system("cls"); 
                    puts("\tNenhum livro cadastrado no sistema\n");
            }
            break;
        
            case 3:
                if(personagens->tamanho != 0){
                    system("cls");
                    ListPerso(personagens);
                    system("pause");
                    system("cls");
                } else {
                    system("cls"); 
                    puts("\tNenhum personagem cadastrado no sistema\n");
                }     
            }
            break;
                     
        case 3: 
            if (autor->tamanho != 0 || livros->tamanho !=0 || personagens->tamanho !=0){
                system("cls");
                puts("\t1 - Associar livro a autor:");
                puts("\t2 - Associar personagem a livro:");
                puts("");
                scanf("\t %d", &op);

                switch (op) {
                case 1: 
                    if (autor->tamanho != 0 && livros->tamanho !=0){
                        system("cls");
                        ListLivro(livros);
                        puts("\tQual livro deseja associar");
                        scanf("\t %d", &pos);

                        livs = buscar(livros, pos);
                        puts("");

                        ListAutor(autor);
                        puts("\n\t Em qual autor o livro sera associado:");
                        scanf("\t %d", &pos);

                        aut = buscar(autor, pos);

                        if (livs != NULL && aut != NULL) {
                            ins(aut->livros, livs);
                            puts("\tOperacao concluida com sucesso\n\n");
                            system("pause");
                            system("cls");

                        } else {
                            system("cls");
                            puts("\n\tId do autor ou do livro invalido\n Tente novamente");
                            system("pause");
                            system("cls");
                        }
                    } else {
                        system("cls");
                        puts("\tNenhum autor ou livro cadastrado");
                    }
                    break;
                
                case 2: 
                    if (livros->tamanho != 0 && personagens->tamanho != 0){
                        system("cls");
                        ListPerso(personagens);
                        puts("\tQual personagem deseja associar:");
                        scanf("\t %d", &pos);
                        
                        pers = buscar(personagens, pos);
                        puts("");

                        ListLivro(livros);
                        puts("\n\tEm qual personagem sera associado:");
                        scanf("\t %d", &pos);

                        livs = buscar(livros, pos);

                        if (pers != NULL && aut != NULL){
                            ins(livs->personagens, pers);
                            puts("\n\tOperacao realizada com sucesso\n\n");
                            system("pause");
                            system("cls");

                        } else {
                            system("cls");
                            puts("\tId do livro ou do personagem invalido\n Tente novamente");
                            system("pause");
                            system("cls");

                        }
                    } else {
                        system("cls");
                        puts("\tNenhum livro ou personagem cadastrado:");
                    }
                    break;

                    default:
                    system("cls");
                    puts("\n\tOperacao invalida\n Escolha apenas uma das opcoes listadas.\n\n");
                    break;
                }
            } else {
                system("cls");
                puts("\tNenhuma informacao cadastrada no sistema");
            }  
            break;

        case 4: 
            if (autor->tamanho != 0 || livros->tamanho != 0 || personagens->tamanho != 0) {
                system("cls");
                puts("\t1 - Desassociar livro de autor");
                puts("\t2 - Desassociar persoganegm de livro");
                puts("");
                scanf("\t %d", &op);

                switch (op) {
                case 1: 
                    if (autor->tamanho != 0 && livros->tamanho != 0) {
                        system("cls");
                        ListAutor(autor);
                        puts("\tDe qual livro o autor sera desassociado: ");
                        scanf("\t %d", &pos);

                        aut = buscar(autor, pos);

                        if (aut != NULL && aut->livros->tamanho != 0) {
                            puts("");
                            ListLivro(aut->livros);
                            puts(" \tQual livro sera desassociado: ");
                            scanf("\t %d", &pos);

                            remover(aut->livros, pos);
                            puts("\n\tOPERACAO REALIZADA COM SUCESSO!\n\n\n");
                            system("pause");
                            system("cls");
                        } else {
                            system("cls");
                            puts("\tId do autor invalido\nTENTE NOVAMENTE.\n");
                        }
                    } else {
                        system("cls");
                        puts("\tNenhuma informacao cadastrada no sistema.\n");
                    }
                    break;

                case 2:
                    if (livros->tamanho != 0 && personagens->tamanho != 0) {
                        system("cls");
                        ListLivro(livros);
                        puts("\tDe qual livro o personagem sera desassociado: ");
                        scanf("\t %d", &pos);

                        livs = buscar(livros, pos);

                        if (livs != NULL && livs->personagens->tamanho != 0) {
                            puts("");
                            ListPerso(livs->personagens);
                            puts("\tQual personagem sera desassociado: ");
                            scanf("\t %d", &pos);

                            remover(livs->personagens, pos);
                            puts("\n\tOperacao realizada com sucesso!\n\n\n");
                            system("pause");
                            system("cls");
                        } else {
                            system("cls");
                            puts("\tId do livro invalido\nTente novamente.\n");
                        }
                    } else {
                        system("cls");
                        puts("\tNenhuma informacao cadastrada no sistema.\n");
                    }
                    break;
                }
            } 
            break; 
            
        default:
            system("cls");
            puts("\n\tOPERACAO INVALIDA!\nESCOLHA APENAS UMA DAS OPCOES LISTADA.\n\n");
            break;
                  
        }
    }
}

void menu() {
    puts("\n\tQual operacao gostaria de realizar");
    puts("\t0 - Sair");
    puts("\t1 - Cadastrar");
    puts("\t2 - Listar");
    puts("\t3 - Associar entidade existente");
    puts("\t4 - Remover entidade existente");
    puts("");
}

void menuOp() {
    puts("\t1 - Autor");
    puts("\t2 - Livro");
    puts("\t3 - Personagens");
    puts("");
}