# Operações:

HEX  COD    OP
00   NOP    NOP
01   MOV    Copie     [EE] para o AC
02   CP     Copie     [AC] para a posição de endereço em EE
03   SUM    Some      [EE] com [AC] e guarde o resultado em AC
04   SUB    Subtraia  [EE] de  [AC] e guarde o resultado em AC
07   READ   Leia um número e guarde-o na posição de endereço [EE]
08   PRINT  Imprima   [EE]
09   STOP   Pare
0A   JP     Desvie para [EE] 
0B   JPB    Desvie para EE se AC > 0
0D   JPZ    Desvie para EE se AC = 0

EE significa o conteúdo na posição de endereço EE na RAM
AC significa o conteúdo do AC
Note que o AC tem 8 bits enquanto uma posição na RAM tem 16 bits

# Exemplo

Seja o programa:

    READ  A1
    READ  A2
    MOV   A1 
    SUM   A2
    CP    A3
    PRINT A3
    STOP

Que lê um valor, guarda esse valor na posição de memória A1.
Depois lê outro valor, e guarda este em A2.
Move o valor de A1 para o acumulador.
Soma o valor que está em A2 com o do acumulador.
Copia o valor do acumulador para a posição A3.
E imprime o valor da posição em A3.
E para.

Queremos o seguinte formato para carregar no logisim:

v2.0 raw
07a1 07a2 01a1 03a2 02a3 08a3 0900

# TODO

- Fix string comparison, JP == JPB problem
- Fix character shift
- Make a way to subtract 1 without user input
