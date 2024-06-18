#include <stdio.h>
#include <string.h>

// Definição da enumeração Genero
enum Genero { FICCAO, NAO_FICCAO, CIENCIA, HISTORIA, BIOGRAFIA };

// Definição da estrutura Livro
struct Livro {
    char titulo[100];
    char autor[100];
    int ano;
    enum Genero genero;
};

// Função para adicionar um novo livro ao array de livros
void adicionarLivro(struct Livro livros[], int *contador) {
    printf("Digite o titulo do livro: ");
    scanf(" %[^\n]", livros[*contador].titulo);
    printf("Digite o autor do livro: ");
    scanf(" %[^\n]", livros[*contador].autor);
    printf("Digite o ano do livro: ");
    scanf("%d", &livros[*contador].ano);
    printf("Escolha o genero do livro:\n");
    printf("0 - FICCAO\n1 - NAO_FICCAO\n2 - CIENCIA\n3 - HISTORIA\n4 - BIOGRAFIA\n");
    int opcao;
    scanf("%d", &opcao);
    livros[*contador].genero = opcao;
    (*contador)++;
}

// Função para listar todos os livros armazenados
void listarLivros(struct Livro livros[], int contador) {
    printf("Lista de livros:\n");
    int i;

  for (i = 0; i <= contador; i++) {
        printf("Titulo: %s\nAutor: %s\nAno: %d\nGenero: ", livros[i].titulo, livros[i].autor, livros[i].ano);
        switch (livros[i].genero) {
            case FICCAO:
                printf("FICCAO\n");
                break;
            case NAO_FICCAO:
                printf("NAO_FICCAO\n");
                break;
            case CIENCIA:
                printf("CIENCIA\n");
                break;
            case HISTORIA:
                printf("HISTORIA\n");
                break;
            case BIOGRAFIA:
                printf("BIOGRAFIA\n");
                break;
        }
        printf("\n");
    }
}

// Função para buscar um livro pelo título
void buscarLivroPorTitulo(struct Livro livros[], int contador, char titulo[]) {
    int i;

  for (i = 0; i <= contador; i++) {
        if (strcmp(livros[i].titulo, titulo) == 0) {
            printf("Livro encontrado:\n");
            printf("Titulo: %s\nAutor: %s\nAno: %d\nGenero: ", livros[i].titulo, livros[i].autor, livros[i].ano);
            switch (livros[i].genero) {
                case FICCAO:
                    printf("FICCAO\n");
                    break;
                case NAO_FICCAO:
                    printf("NAO_FICCAO\n");
                    break;
                case CIENCIA:
                    printf("CIENCIA\n");
                    break;
                case HISTORIA:
                    printf("HISTORIA\n");
                    break;
                case BIOGRAFIA:
                    printf("BIOGRAFIA\n");
                    break;
            }
            return;
        }
    }
    printf("Livro nao encontrado.\n");
}

// Função para remover um livro pelo título
void removerLivroPorTitulo(struct Livro livros[], int *contador, char titulo[]) {
    int i;

    for (i = 0; i < *contador; i++) { // Corrigi a condição do loop
        if (strcmp(livros[i].titulo, titulo) == 0) {
            for (int j = i; j < *contador - 1; j++) {
                livros[j] = livros[j + 1];
            }
            (*contador)--;
            printf("Livro removido com sucesso.\n");
            return;
        }
    }
    printf("Livro não encontrado.\n"); // Adicionei uma mensagem caso o livro não seja encontrado
}



int main() {
    struct Livro livros[100];
    int contador = 0;
    int opcao;

    do {
        printf("\nMenu de Opcoes:\n");
        printf("1 - Adicionar um novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("3 - Buscar um livro pelo titulo\n");
        printf("4 - Remover um livro pelo titulo\n");
        printf("5 - Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarLivro(livros, &contador);
                break;
            case 2:
                listarLivros(livros, contador);
                break;
            case 3: {
                char tituloBusca[100];
                printf("Digite o titulo do livro a buscar: ");
                scanf(" %[^\n]", tituloBusca);
                buscarLivroPorTitulo(livros, contador, tituloBusca);
                break;
            }
            case 4: {
                char tituloRemocao[100];
                printf("Digite o titulo do livro a remover: ");
                scanf(" %[^\n]", tituloRemocao);
                removerLivroPorTitulo(livros, &contador, tituloRemocao);
                break;
            }
            case 5:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}

