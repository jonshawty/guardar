#include <stdio.h>
#include <stdlib.h>

struct stCurso;
typedef struct stCurso{
    char NomeAluno[30];
    long CpfAluno;
    char TurnoAluno[30];
    int CodigoAluno;
    struct stCurso * Prox;
} Curso;

typedef struct st_Descritor{
    int NumElem;
    Curso * Primeiro;
} Descritor;


int main()
{

    Descritor Lista;
    Lista.NumElem = 0;
    Lista.Primeiro = NULL;

    Curso * Aux;
    int opcao = 0;

    while(opcao < 4){
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Ordenar Alunos\n");
        printf("4 - Sair\n");
        scanf("%d", &opcao);

        if(opcao == 1){
            Aux = (Curso *) calloc(1, sizeof(Curso));
            printf("Digite o nome do Aluno: ");
            scanf("%s", Aux->NomeAluno);

            printf("Digite o Codigo do Aluno: ");
            scanf("%d", &Aux->CodigoAluno);

            printf("Digite o Turno em que o Aluno estuda: ");
            scanf("%s", Aux->TurnoAluno);

            printf("Digite o CPF do aluno: ");
            scanf("%d", &Aux->CpfAluno);

            Aux->Prox = Lista.Primeiro;
            Lista.Primeiro = Aux;
            Lista.NumElem++;

            }

        if(opcao == 2){
            Aux = Lista.Primeiro;
            while(Aux != NULL){
            printf("Nome: %s\n", Aux->NomeAluno);
            printf("Id: %d\n", Aux->CodigoAluno);
            printf("Turno: %s\n", Aux->TurnoAluno);
            printf("CPF Aluno: %d\n", Aux->CpfAluno);
            printf("\n\n");
            Aux = Aux->Prox;
            }
            printf("\n");
            }

        if(opcao == 3){
        int submenu;
        Curso * Aux, * E1, * E2;

        printf("Selecione com qual dado você quer fazer a ordenação:\n");
        printf("1 - Codigo do Aluno\n");
        printf("2 - Cpf do Aluno\n");
        scanf("%d", &submenu);

        if(submenu == 1){
            int troca = 1;
            int OrdIni = 0;
            while(troca == 1){
                troca = 0;
                E1 = Lista.Primeiro;
                E2 = E1->Prox;
                if(E1->CodigoAluno > E2->CodigoAluno){
                    Lista.Primeiro = E2;
                    E1->Prox = E2->Prox;
                    E2->Prox = E1;
                    troca = 1;
                    OrdIni = 1;
                }
                Aux = Lista.Primeiro;
                for(int cont=0; cont < Lista.NumElem-2; cont++){
                    E1 = Aux->Prox;
                    E2 = E1->Prox;
                    if(E1->CodigoAluno > E2->CodigoAluno){
                        Aux->Prox = E2;
                        E1->Prox = E2->Prox;
                        E2->Prox = E1;
                        troca = 1;
                        OrdIni = 1;
                    }
                    Aux = Aux->Prox;
                }
            }
        }
        if(submenu == 2){

        int troca = 1;
            int OrdIni = 0;
            while(troca == 1){
                troca = 0;
                E1 = Lista.Primeiro;
                E2 = E1->Prox;
                if(E1->CpfAluno > E2->CpfAluno){
                    Lista.Primeiro = E2;
                    E1->Prox = E2->Prox;
                    E2->Prox = E1;
                    troca = 1;
                    OrdIni = 1;
                }
                Aux = Lista.Primeiro;
                for(int cont=0; cont < Lista.NumElem-2; cont++){
                    E1 = Aux->Prox;
                    E2 = E1->Prox;
                    if(E1->CpfAluno > E2->CpfAluno){
                        Aux->Prox = E2;
                        E1->Prox = E2->Prox;
                        E2->Prox = E1;
                        troca = 1;
                        OrdIni = 1;
                    }
                    Aux = Aux->Prox;
                }
            }
        }

    }
    }
    return 0;
}
