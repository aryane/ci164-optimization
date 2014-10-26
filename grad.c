#include "grad.h"

/**
 * @file grad.c
 * @brief Funções criadas para a resolução do trabalho
 * @author Aryane Ast dos Santos
 * @author Kevin Katzer
 */

/**
 * @brief Função principal do método de gradiente
 * @param *A Matriz.
 * @param *x Vetor solução.
 * @param n Dimensão da matriz.
 * @param e Erro máximo permitido.
 * @param it Número máximo de iterações.
 */

double gradSolver(double *A, double *b, double *x, int n, double e,
    int it, double *timeGrad, double *timeError){
    int i = 0, errors = 0;
    double *r = (double *) malloc(n*sizeof(double));
    memset(x,0,n*sizeof(double));
    e = fabs(e);
    *timeGrad = 0.0;
    *timeError = 0.0;

    *timeGrad -= timestamp();

    *timeError -= timestamp();
    residue(A, b, x, r, n);
    double n0 = residualNorm(r, n);
    *timeError += timestamp();
    ++errors;
    calcGrad(A, x, r, n);
    *timeError -= timestamp();
    residue(A, b, x, r, n);
    double n1 = residualNorm(r, n);
    *timeError += timestamp();
    ++errors;

    int ra = 1; //Resíduo atual. Se for 0, n0 é a norma resíduo atual e n1 a do resíduo anterior.
    double relErr = n0 - n1;

    while ((fabs(relErr) > e) && (++i<it)){
        if (ra == 0){
            calcGrad(A, x, r, n);
            ra = 1;
            *timeError -= timestamp();
            residue(A, b, x, r, n);
            n0 = residualNorm(r, n);
            *timeError += timestamp();
            ++errors;
            relErr = n0 - n1;
        }
        if (ra == 1){
            calcGrad(A, x, r, n);
            ra = 0;
            *timeError -= timestamp();
            residue(A, b, x, r, n);
            n1 = residualNorm(r, n);
            *timeError += timestamp();
            ++errors;
            relErr = n1 - n0;
        }
    }
    *timeGrad += timestamp();
    *timeGrad /= i+1; //Contando com a iteração de fora do laço.
    *timeError /= errors;

    if (ra == 0)
        return n0;
    else
        return n1;
}

/**
 * @brief Iterações do método de gradiente
 * @param *A Matriz.
 * @param *x Vetor solução.
 * @param *r Vetor de resíduos.
 * @param n Dimensão da matriz.
 */

void calcGrad(double *A, double *x, double *r, int n){
    double iaux, *aux = (double *)malloc(n*sizeof(double));
    multMat(A, r, aux, n);
    iaux = multVet(r, r, n)/multVet(r, aux, n);
    for (int i = 0; i < n; ++i)
        x[i] = x[i] + iaux * r[i];
}

/**
 * @brief Calcula norma do resíduo.
 * @param *r vetor de resíduo.
 * @param n tamanho do vetor.
 */
double residualNorm(double *r, int n) {
    double norm, sum = 0.0;
    for (int i=0; i<n; ++i)
        sum += r[i] * r[i];
    norm = sqrt(sum);

    return norm;
}

/**
 * @brief Cálculo do vetor de resíduo.
 * @param *A Matriz.
 * @param *b vetor b.
 * @param *x Vetor solução.
 * @param * Vetor de resíduosolução.
 * @param n Dimensão da matriz.
 */
void residue(double *A, double *b, double *x, double *r, int n) {
    for (int i=0; i<n; ++i) {
        r[i] = b[i];
        for (int j=0; j<n; ++j) {
            r[i] -= A[i*n+j]*x[j];
        }
    }
}

/**
 * @brief Multiplica vetores
 * @param *v vetor 1
 * @param *r vetor 2
 * @param n tamanho dos vetores
 * @return resultado
 */
double multVet(double *v, double *r, int n) {
    double sum = 0.0;
    for (int i=0; i<n; ++i) {
        sum += v[i]*r[i];
    }
    return sum;
}

void multMat(double *A, double *v, double *result, int n) {
    for (int i=0; i<n; ++i){
        result[i] = 0.0;
        for (int j=0; j<n; ++j){
            result[i] += v[j]*A[i*n+j];
        }
    }
}

/**
 * @brief Imprime os parâmetros possíveis em stdout
 */
void helper() {
    printf("\033[1mUSO\033[0m\n");
    printf("\t./gradSolver [OPÇÕES]\n");
    printf("\033[1mOPÇÕES\033[0m\n");
    printf("\t\033[1m-i\033[0m\n");
    printf("\t\tArquivo de entrada do programa. Se não incluído, a matriz deve ser inserida via stdin.");
    printf("\tgradSolver -i [endereço do arquivo]\n");
    printf("\t\033[1m-o\033[0m\n");
    printf("\t\tArquivo de saída do programa. Se não incluído, a matriz será impressa em stdout.");
    printf("\tgradSolver -o [endereço do arquivo]\n");
    printf("\t\033[1m-r\033[0m\n");
    printf("\t\tDimensão da matriz a ser gerada aleatoriamente. Não deve ser inserido se for fornecido um arquivo de entrada.");
    printf("\tgradSolver -r [dimensão]\n");
    printf("\t\033[1m-k\033[0m\n");
    printf("\t\tNúmero máximo de iterações a serem executadas. (Opcional)");
    printf("\tgradSolver -k [número de iterações]\n");
    printf("\t\033[1m-e\033[0m\n");
    printf("\t\tO maior erro aceitável. (Opcional)\tgradSolver -e [erro]\n");
}

/**
 * @brief Função de leitura da matriz
 * @param *f Stream de entrada (arquivo ou stdin).
 * @param *A Matriz.
 * @param *b Vetor.
 * @param n Dimensão da matriz.
 */

void readInput(char *ivalue, double **A, double **b, int *n){
    FILE *stream;
    double *a, *B;

    /* Pega o arquivo de entrada, se não houver, lê da entrada padrão. */
    if (ivalue != NULL)
        stream = fopen(ivalue, "r");
    else
        stream = stdin;

    /* Lê dimensão da matriz. */
    fscanf(stream, "%d\n", n);
    /* Aloca memória para matriz e vetor b. */
    if ( ! (a = (double *) malloc((*n)*(*n)*sizeof(double))) ) {
        strerror(ENOMEM);
        exit(ENOMEM);
    }
    if ( ! (B = (double *) malloc((*n)*sizeof(double))) ) {
        strerror(ENOMEM);
        exit(ENOMEM);
    }

    /* Lê matriz A */
    for (int i=0; i<*n; ++i) {
        for (int j=0; j<*n; ++j) {
            fscanf(stream, "%lf ", &a[(i*(*n))+j]);
        }
        fscanf(stream, "\n");
    }

    /* Lê vetor b. */
    for (int i=0; i<*n; ++i) {
        fscanf(stream, "%lf ", &B[i]);
    }
    *A = a;
    *b = B;

    if (ivalue != NULL)
        fclose(stream);
}

void printMat(FILE *stream, double *A, int n) {
    fprintf(stream, "%d\n", n);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            fprintf(stream, "%.17g ", A[i*n+j]);
        }
        fprintf(stream, "\n");
    }
}

void printVet(FILE *stream, double *v, int n) {
    for (int j=0; j<n; ++j) {
        fprintf(stream, "%.17g ", v[j]);
    }
    fprintf(stream, "\n");
}

/**
 * @brief Escreve saída em stdout
 * @param *f Stream de saída (arquivo ou stdin).
 * @param n Dimensão da matriz.
 */
void printOut(char *ovalue, double resNorm, double timeGrad, double timeError,
    double *sol, int n){
    FILE *stream;

    if (ovalue != NULL)
        stream = fopen(ovalue, "w");
    else
        stream = stdout;

    fprintf(stream, "#Erro: %.17f\n", resNorm);
    fprintf(stream, "#Tempo Grad: %.17fs\n", timeGrad);
    fprintf(stream, "#Tempo Erro: %.17fs\n", timeError);
    fprintf(stream, "#\n");
    fprintf(stream, "%d\n", n);
    for (int i=0; i<n; ++i)
        fprintf(stream, "%.17g ", sol[i]);

    if (ovalue != NULL)
        fclose(stream);
}
