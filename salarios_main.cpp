/*
Ler o valor correspondente ao salário mensal (variável SM) de um trabalhador e também
o valor do percentual de reajuste (variável PR) a ser atribuído. Apresentar o valor do novo
salário (variável NS).
*/

#include "iostream"
#include "cstdlib"
#include "string"
using namespace std;
const int n = 5;
int linha = 0;
struct registro
{
    double salario;
    double reajuste;
    double salarioCorrigido;
};
struct registro tb1[n];
void Ler_Calcular ();
void executar ();
int
main ()
{
    setlocale (LC_ALL, "Portuguese");
    executar ();
    return 0;
}
void
Ler_Calcular ()
{
    linha++;
    double a, b;
    double salario, reajuste;
    cout << "Digite o salario : ";
    cin >> a;
    tb1[linha].salario = a;
    cout << "Digite o reajuste : ";
    cin >> b;
    tb1[linha].reajuste = b / 100;
    tb1[linha].salarioCorrigido =
    tb1[linha].salario + (tb1[linha].salario * tb1[linha].reajuste);
}
void
mostrarCalculo ()
{
    cout << "salario inicial : R$" << tb1[linha].salario
    << "\nreajuste : " << tb1[linha].reajuste * 100 << "%"
    << "\nsalario corrigido : R$" << tb1[linha].salarioCorrigido << endl;
    system ("sleep 5");
}
void
executar ()
{
    int tecla;
    MENU:
    system ("clear");
    cout << "\n*** Menu ***";
    cout << "\n\n\t1 ler e calcular salario";
    cout << "\n\t2 mostrar salario corrigido";
    cout << "\n\t3 Sair";
    cout << "\n\titem:";
    cin >> tecla;
    switch (tecla)
    {
        case 1:
        Ler_Calcular ();
        break;
        case 2:
        mostrarCalculo ();
        break;
        case 3:
        exit (0);
        break;
    }
    goto MENU;
}