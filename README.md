<b>NOME</b>
        gradSolver - Soluciona um Sistema Linear pelo Método do Gradiente
<b>SINOPSE</b>
        ./gradSolver [OPTION]...
<b>DESCRIÇÃO</b>
        Resolve um sistema linear a partir de uma matriz quadrada definida, positiva e simétrica.
        Parâmetros possíveis:
        -i
                Arquivo de entrada do programa. Se não incluído, a matriz deve ser inserida via stdin.  gradSolver -i [endereço do arquivo]
        -o
                Arquivo de saída do programa. Se não incluído, a matriz será impressa em stdout.        gradSolver -o [endereço do arquivo]
        -r
                Dimensão da matriz a ser gerada aleatoriamente. Não deve ser inserido se for fornecido um arquivo de entrada.   gradSolver -r [dimensão]
        -k
                Número máximo de iterações a serem executadas. (Opcional)       gradSolver -k [número de iterações]
        -e
                O maior erro aceitável. (Opcional)      gradSolver -e [erro]
