#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _personagem
{
    int id;
    char apelido[20];
    int idade;

} Personagem;

typedef struct _livro
{
    int id;
    char titulo[30];
    int ano;

    Personagem *personagens[10];
    int numPersonagens;

} Livro;

typedef struct _autor
{
    int id;
    char nome[30];
    char paisNasc[30];

    Livro *livros[15];
    int numLivros;
} Autor;

//DELARAÇÃO DAS FUNÇÕES
void menu();                    //OK
Autor *CadAut();                //OK
void ListAutor();               //OK
Livro *cadLivro();              //OK
void ListLivros();              //OK
Personagem *CadPerso();         //OK
void ListPerso();               //OK
void *CadLivroAutor();          //OK
void *CadPersonagemLivro();     //OK

void menu()
{
    puts("\n\t1 - Inserir novo autor");
    puts("\t2 - Listar autores");
    puts("\t3 - Inserir novo livro");
    puts("\t4 - Listar livros");
    puts("\t5 - Inserir novo personagem");
    puts("\t6 - Listar personagens");
    puts("\t7 - Juntar livro a autor");
    puts("\t8 - Juntar personagem a livro");
    puts("\t9 - Sair");
}

Autor *CadAut(int idAutor) // FUNÇÃO PARA CADASTRAR AUTOR
{
    Autor *NovoAutor = (Autor *)malloc(sizeof(Autor));
    NovoAutor->id = idAutor;

    puts("\n\tNome do autor: ");
    printf("\t");
    scanf(" %[^\n]s", NovoAutor->nome);

    puts("\n\tPais de nascimento do autor: ");
    printf("\t");
    scanf(" %[^\n\t]s", &NovoAutor->paisNasc);

    NovoAutor->numLivros = 0;

    return NovoAutor;
}

void ListAutor(Autor *autor[], int idAut) // FUNÇÃO PARA LISTAR AUTOR   
{
    for (int i = 0; i < idAut; i++)
    {
        printf("\n\t|Id: %d\t |Nome:  %s\t |Pais.Nasc:  %s\t |Num.livros:  %d\n", autor[i]->id, autor[i]->nome, autor[i]->paisNasc, autor[i]->numLivros);
    }
        
}

Livro *cadLivro(int idLiv) // FUNÇÃO PARA CADASTRAR LIVRO
{
    Livro *NovoLivro = (Livro *)malloc(sizeof(Livro));
    NovoLivro->id = idLiv;

    puts("\n\tTitulo do livro: ");
    printf("\t");
    scanf(" %[^\n]s", NovoLivro->titulo);

    puts("\n\tAno do livro: ");
    printf("\t");
    scanf(" %d", &NovoLivro->ano);

    NovoLivro->numPersonagens = 0;

    return NovoLivro;
}

void ListLivros(Livro *livro[], int idLiv) // FUNÇÃO PARA LISTAR LIVROS
{

    for (int i = 0; i < idLiv; i++)
    {
        printf("\n\tId:  %d\t |Titulo:  %s\t |Ano:  %d\t |Num.Personagens:%d \n", livro[i]->id, livro[i]->titulo, livro[i]->ano, livro[i]->numPersonagens);
    }
    puts("\n");
}

Personagem *CadPerso(int idPerso) // FUNÇÃO PARA CADASTRAR PERSONAGENS
{
    Personagem *NovoPerso = (Personagem *)malloc(sizeof(Personagem));
    NovoPerso->id = idPerso;

    puts("\n\tApelido do personagem: ");
    printf("\t");
    scanf(" %[^\n]s", NovoPerso->apelido);

    puts("\n\tIdade do personagem: ");
    printf("\t");
    scanf(" %d", &NovoPerso->idade);

    return NovoPerso;
}

void ListPerso(Personagem *personagens[], int idPerso) // FUNÇÃO PARA LISTAR PERSONAGEM
{

    for (int i = 0; i < idPerso; i++)
    {
        printf("\n\tId:  %d\t | Apelido: %s\t | Idade: %d\t |\n", personagens[i]->id, personagens[i]->apelido, personagens[i]->idade);
    }
    puts("\n");
}

void *CadLivroAutor( Autor *autor, Livro *livros) // CADASTRAR LIVRO PARA AUTOR
{
    autor->livros[autor->numLivros] = livros;
    autor-> numLivros++;

}

void *CadPersonagemLivro(Livro *livros, Personagem *personagens) // ADICIONAR PERSONAGEM PARA LIVRO
{
    livros->personagens[livros->numPersonagens] = personagens;
    livros->numPersonagens++;
}

int main()
{
    //VARIAVEIS
    Personagem *personagens[50];
    Livro *livros[50];
    Autor *autor[50];
    int idAutor = 0, idLiv = 0, idPerso = 0;
    int posAutor, posLivro, posPersonagem;
    int op;
    
    while (op != 9)
    {
        menu();
        scanf("%d", &op);

        switch (op)
        {
        case 1: // CADASTRA AUTOR

            system("cls");
            autor[idAutor] = CadAut(idAutor);
            idAutor++;
            puts("\n\tOperacao realizada com sucesso\n\n\n\t");
            system("pause");
            system("cls");
            break;

        case 2: // LISTAR AUTOR
            if (idAutor == 0)
            {
                system("cls");
                puts("\nNenhuma empresa cadastrada no sistema.\n\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                ListAutor(autor, idAutor);
                system("pause");
                system("cls");
            }
            break;

        case 3: // CADASTRAR LIVRO

            system("cls");
            livros[idLiv] = cadLivro(idLiv);
            idLiv++;

            puts("\n\tOperacao foi concluida com sucesso!\n\n\n\t");
            system("pause");
            system("cls");
            break;

        case 4: //LISTAR LIVRO
            if (idLiv == 0)
            {
                system("cls");
                puts("\nNenhum livro cadastrado no sistema.\n\n\n");
                system("pause");
                system("cls");  
            }
            else
            {
                system("cls");
                ListLivros(livros, idLiv);
                system("pause");
                system("cls");
            }
            break;

        case 5: //CADASTRAR PERSONAGENS

            system("cls");
            personagens[idPerso] = CadPerso(idPerso);
            idPerso++;

            puts("\n\tOperacao foi concluida com sucesso!\n\n\n\t");
            system("pause");
            system("cls");
            break;
        
        case 6: //LISTAR PERSONAGENS
            if (idPerso == 0)
            {
                system("cls");
                puts("\nNenhum personagem cadastrado no sistema.\n\n\n");
                system("pause");
                system("cls");
            }
            else   
            {
                system("cls");
                ListPerso(personagens, idPerso);
                system("pause");
                system("cls");
            }
            break;
           
        case 7: //JUNTAR LIVRO A AUTOR
            system("cls");
            ListAutor(autor , idAutor);
            puts("Digite o id do autor que o livro vai ser conectado");
            scanf("%d", &posAutor);

            ListLivros(livros, idLiv);
            puts("\nDigite o id do livro");
            scanf("%d", &posLivro);

            CadLivroAutor(autor[posAutor], livros[posLivro]);
            puts("\nOperacao concluida com sucesso!\n\n\n");
            system("pause");
            system("cls");
            break;

        case 8: //JUNTAR PERSONAGEM A LIVRO
            system("cls");
            ListLivros(livros , idLiv);
            puts("Digite o id do personagem que o livro vai ser conectado");
            scanf("%d", &posLivro);

            ListPerso(personagens, idPerso);
            puts("\nDigite o id do Personagem");
            scanf("%d", &posPersonagem);

            CadPersonagemLivro(livros[posLivro], personagens[posPersonagem]);
            puts("\nOperacao concluida com sucesso!\n\n\n");
            system("pause");
            system("cls");
            break;

        default:
            system("cls");
            puts("\nOperacao Invalida!\nEscolha somente alguma das opcoes listadas.\n\n");
            break;

        }
    }
}