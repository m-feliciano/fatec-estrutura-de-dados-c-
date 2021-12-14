/*
Elaborar um programa de computador que efetue a leitura de quatro valores inteiros
(variáveis A, B, C e D).
Ao final o programa deve apresentar o resultado do produto (variável P) do primeiro com o
terceiro valor, e o resultado da soma (variável S) do segundo com o quarto valor.
*/

#include "iostream" 
#include "cstdlib" 
#include "string"
using namespace std;
const int n = 5;
int linha = 0;
struct registro
{
    int A;
    int B;
    int C;
    int D;
    int varProduto;
    int varSoma;
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
    int a, b, c, d;
    linha++;
    cout << "Digite o A:"; cin >> a;
    tb1[linha].A = a;
    cout << "Digite o B:"; cin >> b;
    tb1[linha].B = b;
    cout << "Digite o C:"; cin >> c;
    tb1[linha].C = c;
    cout << "Digite o D:"; cin >> d;
    tb1[linha].D = d;
    tb1[linha].varProduto = tb1[linha].A * tb1[linha].C;
    tb1[linha].varSoma = tb1[linha].B + tb1[linha].D;
}
void
mostrarCalculo ()
{
    cout << "A : " << tb1[linha].A
    << "\nB : " << tb1[linha].B
    << "\nC : " << tb1[linha].C
    << "\nD : " << tb1[linha].D << endl;
    cout << "\nProduto de " << tb1[linha].A<<" com "<<tb1[linha].C<<" = " <<
    tb1[linha].varProduto
    << "\nSoma de "<<tb1[linha].B<<" com "<<tb1[linha].D<<" = " << tb1[linha].varSoma <<
    endl;
    system ("sleep 10");
}
void
executar ()
{
    int tecla;
    MENU:
    system ("clear");
    cout << "\n*** Menu ***";
    cout << "\n\n\t1 ler_calculo";
    cout << "\n\t2 mostrar calculo";
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