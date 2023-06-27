#include <stdio.h>

int cpfD1(const char cpf[11]);
int cpfD2(const char cpf[11]);

int main() {
    //Inicializa as variaveis necessárias
    char cpf[11];
    int dt1;
    int dt2;

    //Recebe do usuário somente os numeros do cpf
    printf("Digite somente os numeros do seu cpf:");
    scanf("%s", cpf);
    
    if (cpf[0] == cpf[1] && cpf[1] == cpf[2] && cpf[2] == cpf[3] && cpf[3] == cpf[4] && cpf[4] == cpf[5] && cpf[5] == cpf[6] && cpf[6] == cpf[7] && cpf[7] == cpf[8] && cpf[8] == cpf[9] && cpf[9] == cpf[10]) {
        printf("CPF invalido");
        return 0;
    } else
    //Verificando se os digitos do CPF não repetem, para que ele seja valido
    //Calcula os dois digitos verificadores
    dt1 = cpfD1(cpf);
    dt2 = cpfD2(cpf);

    //Verifica se o CPF é valido ou não
    if(dt1 == ((int)cpf[9])-48 && dt2 == ((int) cpf[10])-48){
        printf("CPF valido");
        return 0;
    } else{
        printf("CPF invalido");
        return 1;
    }
}

int cpfD1(const char cpf[11]){
    int soma = 0;
    int digito;
    for (int i = 10, j = 0; i >= 2 && j<10; --i, ++j) {
        int c = ((int) cpf[j])-48;
        soma += (c)*i;
    }
    digito = 11 - soma % 11;
    if (digito >= 10) digito = 0;
    return digito;
    //Calculando o primeiro digito
}
int cpfD2(const char cpf[11]){
    int soma = 0;
    int digito;
    for (int i = 11, j = 0; i >= 2 && j<11; --i, ++j) {
        int c = ((int) cpf[j])-48;
        soma += (c)*i;
    }
    digito = 11 - soma % 11;
    if (digito >= 10) digito = 0;
    return digito;
    //Calculando o segundo digito
}