gradSolver - Soluciona um Sistema Linear pelo Método do Gradiente
        
Aryane Ast dos Santos GRR20108817
Kevin Katzer GRR20113204
        
generate_input.c: Cria um arquivo de entrada contendo uma matriz positiva definida no formato definido na especificação. 
grad.*: Contém as funções principais para cálculo do gradiente e auxiliares do método, como leitura dos dados, multiplicação de matrizes e vetores, cálculo de resíduo e norma do mesmo, ajuda e resultados finais.
mat_utils.*: Contém as funções definidas pelo professor. No caso a que gera a matriz e uma para calcular o tempo.
main.c: Faz o parsing dos parâmetros com getopt e invoca função que calcula método do gradiente.

Escolhemos representar o sistema linear num vetor unidimensional. A alternativa seria usar uma matriz bidimensional, mas o acesso ficaria mais caro, conforme visto em sala de aula.

Não descobrimos nenhum bug, mas também não testamos o programa à exaustão, o que não diz muito.
