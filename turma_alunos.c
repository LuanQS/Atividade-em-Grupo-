#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 50
#define MAX_NOME 50
#define MAX_EMAIL 100

typedef struct
{
    char nome[MAX_NOME];
    char email[MAX_EMAIL];
    float nota_primeiro_bimestre;
    float nota_segundo_bimestre;
} Estudante;

typedef struct
{
    Estudante alunos[MAX_ALUNOS];
    char disciplina[MAX_NOME];
    int num_alunos;
} Turma;

void adicionarAluno(Estudante *estudante)
{
    printf("Digite o nome do aluno: ");
    fgets(estudante->nome, MAX_NOME, stdin);
    estudante->nome[strcspn(estudante->nome, "\n")] = '\0';

    printf("Digite o email do aluno: ");
    fgets(estudante->email, MAX_EMAIL, stdin);
    estudante->email[strcspn(estudante->email, "\n")] = '\0';

    printf("Digite a nota do aluno para o primeiro bimestre: ");
    scanf("%f", &estudante->nota_primeiro_bimestre);
    while (getchar() != '\n')
        ;

    printf("Digite a nota do aluno para o segundo bimestre: ");
    scanf("%f", &estudante->nota_segundo_bimestre);
    while (getchar() != '\n')
        ;

    printf("Aluno adicionado com sucesso!\n");
}

void exibirAlunos(Turma turma)
{
    printf("Lista de Alunos:\n");
    for (int i = 0; i < turma.num_alunos; i++)
    {
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s\n", turma.alunos[i].nome);
        printf("Email: %s\n", turma.alunos[i].email);
        printf("Nota do primeiro bimestre: %.2f\n", turma.alunos[i].nota_primeiro_bimestre);
        printf("Nota do segundo bimestre: %.2f\n", turma.alunos[i].nota_segundo_bimestre);
        printf("\n");
    }
}

int main()
{
    Turma turma;
    turma.num_alunos = 0;

    strcpy(turma.disciplina, "Algoritmos II");

    int opcao;
    do
    {
        printf("\nMenu:\n");
        printf("1. Adicionar Aluno\n");
        printf("2. Exibir Alunos\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        while (getchar() != '\n')
            ;

        switch (opcao)
        {
        case 1:
        {
            if (turma.num_alunos < MAX_ALUNOS)
            {
                adicionarAluno(&turma.alunos[turma.num_alunos++]);
            }
            else
            {
                printf("Limite de alunos atingido!\n");
            }
            break;
        }
        case 2:
            exibirAlunos(turma);
            break;
        case 3:
            printf("Encerrando o programa...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 3);

    return 0;
}
