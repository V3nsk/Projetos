#include <stdio.h>
#include <stdlib.h>

typedef struct _personagem
{
    int id;
    char nome[20];
    int idade;

} Personagem;


typedef struct _livro
{
    int id;
    char titulo[20];
    int anoLivro;

    Personagem pesonagens[10];
    int numPerso;

} Livro;

typedef struct _autor
{
    int id;
    char nome[20];
    char pais[20];
    int anoNasc;

    Livro livros[10];
    int numLivro;

} Autor;


void menu()
{
    puts("1 - Inserir novo autor");
    puts("2 - Listar autores");
    puts("3 - Inserir novo livro");
    puts("4 - Listar livros");
    puts("5 - Inserir novo personagem");
    puts("6 - Listar personagens");
    puts("0 - Sair");
}

Autor cadastrarAutor(int idAut)
{
    Autor NovoAut;
    NovoAut.id = idAut;

    puts("Nome do Autor: ");
    scanf(" %[^\n]s", NovoAut.nome);
    puts("Pais de nascimento do Autor: ");
    scanf(" %[^\n]s", NovoAut.pais);
    puts("Ano que o Autor nasceu: ");
    scanf(" %d", &NovoAut.anoNasc);

    NovoAut.numLivro = 0;

    return NovoAut;
}


void ListAutor(Autor autores[], int idAut)
{
    puts("ID\tNOME\tPAIS\tAno de Nascimento\n");
    for (int i = 0; i < idAut; i++)
    {
        printf("%d\t%s\t%s\t%d\n", autores[i].id, autores[i].nome, autores[i].pais, autores[i].anoNasc);
    }
    puts("\n");
}


Livro CadLivro(int idliv)
{
    Livro NovoLivro;
    NovoLivro.id = idliv;

    puts("Nome do livro: ");
    scanf(" %[^\n]s", NovoLivro.titulo);
    puts("Ano do livro: ");
    scanf(" %d", &NovoLivro.anoLivro);

    NovoLivro.numPerso = 0;

    return NovoLivro;
}

void ListarLivro(Livro livros[], int idLiv)
{
    puts("ID\tTitulo\tAno de Criação\n");
    for (int i = 0; i < idLiv; i++)
    {
        printf("%d\t%s\t%d\n", livros[i].id, livros[i].titulo, livros[i].anoLivro);
    }
    puts("\n");
}


Personagem CadPerso(int idPerso)
{
    Personagem NovoPerso;
    NovoPerso.id = idPerso;

    puts("Nome do personagem: ");
    scanf(" %[^\n]s", NovoPerso.nome);
    puts("Idade do Personagem: ");
    scanf(" %d", &NovoPerso.idade);

    return NovoPerso;
}


void ListPerso(Personagem Personagens[], int idPerso)
{
    puts("ID\tNOME\tIDADE\n");
    for (int i = 0; i < idPerso; i++)
    {
        printf("%d\t%s\t%d", Personagens[i].id, Personagens[i].nome, Personagens[i].idade);
    }
    puts("\n");
}



void main()
{
    
    Autor autores[10];
    Livro livros[10];
    Personagem personagens[10];
    int idAut = 0, idLiv = 0, idPerso = 0;
    int aut, liv;
    int op;

    while (op != 7)
    {
        menu();
        scanf("%d", &op);

        switch (op)
        {
        case 1: 
            
            autores[idAut] = cadastrarAutor(idAut);
            idAut++;

            puts("\nOperacao concluida com sucesso!\n\n\n");
            system("pause");
            
            break;

        case 2: 

            if (idAut == 0)
            {
                puts("Nenhum autor cadastrado!");
            }
            else
            {
                ListAutor(autores, idAut);
               
                system("pause");
            }
            break;

        case 3: 

            if (idAut == 0)
            {
                puts("Nenhum autor cadastrado!");
            }
            else
            {
                
                ListAutor(autores, idAut);
                puts("Escreva o ID do criador do livro que vai ser cadastrado: ");
                scanf("%d", &aut);

                idLiv = autores[aut].numLivro;
                autores[aut].livros[idLiv] = CadLivro(idLiv);
                autores[aut].numLivro++;
                idLiv++;

                puts("\nOperacao foi concluida com sucesso!\n\n\n");
               
                system("pause");
            }
            break;

        case 4: 

            if (idAut == 0)
            {
                puts("Nenhum autor cadastrado!");
            }
            else
            {
                
                ListAutor(autores, idAut);
                puts("De qual autor voce deseja listar os livros: ");
                scanf("%d", &aut);

                if (autores[aut].numLivro == 0)
                {
                    system("cls");
                    puts("Este autor nao tem nenhum livro cadastrado");
                }
                else
                {
                    ListarLivro(autores[aut].livros, idLiv);
                    system("pause"); 
                }
            }
            break;

        case 5: 
            if (idAut == 0)
            {
                puts("Nenhum autor cadastrado!");
            }
            else
            {
                ListAutor(autores, idAut);
                puts("Escreva o ID do criador do livro que vai ser cadastrado: ");
                scanf("%d", &aut);

                if (autores[aut].numLivro == 0)
                {
                    puts("Este autor nao tem nenhum livro cadastrado");
                }
                else
                {
                    ListarLivro(autores[aut].livros, idLiv);
                    puts("Escreva o ID do livro em que o personagem vai ser adicionado: ");
                    scanf("%d", &liv);

                    idPerso = autores[aut].livros[liv].numPerso;
                    autores[aut].livros[liv].pesonagens[idPerso] = CadPerso(idPerso);
                    autores[aut].livros[liv].numPerso++;
                    idPerso++;
                    puts("\nOperacao concluida com sucesso!\n\n\n");
                    system("pause");
                }
            }
            break;

        case 6: 

            if (idAut == 0)
            {
                puts("Nenhum autor cadastrado!");
            }
            else
            {
                
                ListAutor(autores, idAut);
                puts("De qual autor voce deseja listar os livros: ");
                scanf("%d", &aut);

                if (autores[aut].numLivro == 0)
                {
                  
                    puts("Este autor nao tem nenhum livro cadastrado");
                }
                else
                {
                    ListarLivro(autores[aut].livros, idLiv);
                    puts("De qual livro voce deseja listar os personagens: ");
                    scanf("%d", &liv);

                    if (autores[aut].livros[liv].numPerso == 0)
                    {
                        puts("Nenhum personagem cadastrado nesse livro");
                    }
                    else
                    {
                        ListPerso(autores[aut].livros[liv].pesonagens, idPerso);
                    system("pause");
                        
                    }
                }
            }

            break;

        default:

            puts(" Nao foi possivel realizar pois a Operacao esta Invalida!\nEscolhas Apenas uma das opcoes listadas acima.\n");
            break;
        }
    }
}