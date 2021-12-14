/* 
Em uma eleição sindical concorreram ao cargo de presidente três candidatos (A, B e C).
Durante a apuração dos votos foram computados votos nulos e votos em branco, além dos
votos válidos para cada candidato.
Deve ser criado um programa de computador que efetue a leitura da quantidade de votos
válidos para cada candidato, além de efetuar também a leitura da quantidade de votos nulos
e votos em branco.
Ao final o programa deve apresentar o número total de eleitores, considerando votos
válidos, nulos e em branco; o percentual correspondente de votos válidos em relação à
quantidade de eleitores; o percentual correspondente de votos válidos do candidato A em
relação à quantidade de eleitores; o percentual correspondente de votos válidos do
candidato B em relação à quantidade de eleitores; o percentual correspondente de votos
válidos do candidato C em relação à quantidade de eleitores; o percentual correspondente
de votos nulos em relação à quantidade de eleitores; e por último o percentual
correspondente de votos em branco em relação à quantidade de eleitores
*/

#include "iostream"
#include "cstdlib"
#include "string"
using namespace std;
const int n = 5;
int linha = 0;
int linha2 = 0;
struct eleitores
{
    int votos_validos;
    int votos_nulosEbranco;
};
struct candidato
{
    string nome;
    int votos;
};
struct eleitores tb1[n];
struct candidato tb2[n];
int ler_votos_validos ();
int ler_votos_nulosBrancos ();
string ler_nome ();
int ler_votos ();
void mostrar_dados ();
void executar ();
int main ()
{
    setlocale (LC_ALL, "Portuguese");
    executar ();
    return 0;
}
int
ler_votos_validos ()
{
    int x;
    cout << "Digite os votos_validos : ";
    cin >> x;
    return x;
}
string
ler_nome ()
{
    string x;
    cout << "Digite o nome : ";
    cin >> x;
    return x;
}
int
ler_votos ()
{
    int x;
    cout << "Digite os votos neste candidato : ";
    cin >> x;
    return x;
}
void
eleitores ()
{
    int votos_validos_ = ler_votos_validos ();
    tb1[linha].votos_validos = votos_validos_;
}
void
candidato ()
{
for (int i = 0; i <= 2; i++)
{
    linha++;
    string nome_ = ler_nome ();
    tb2[linha].nome = nome_;
    int votos_ = ler_votos ();
    tb2[linha].votos = votos_;
    tb1[linha2].votos_validos =tb1[linha2].votos_validos - tb2[linha].votos;
}
int n = tb1[linha2].votos_validos;
tb1[linha2].votos_validos = 0;
tb1[linha2].votos_nulosEbranco = n;
}
void
mostrar_dados ()
    {
    system ("clear");
    int contador = 0;
    //relatorio de contagem de eleitores
    for (int i = 1; i <= 3; i++)
    {
        contador += tb2[i].votos;
    }
    double cont = contador;
    //relatorio de votos
    cout << "\n-------------Relatorio---------------\n";
    for (int i = 1; i <= 3; i++)
    {
        cout << "| nome : " << tb2[i].nome << " | votos : " << tb2[i].votos << " | percentual :" <<
        ((tb2[i].votos/cont)*100) <<"% |"<< endl;
    }
    cout << "--------Fim do relatorio---------------" << endl;
    cout << "Obs.: formula calculo percentual ((votos / votos_validos -
    votos_nulosEbranco)*100)";
    cout << "\n* votos totais : " << tb1[linha2].votos_nulosEbranco + contador << endl;
    cout << "** votos declarados : " << contador << endl;
    cout << "*** votos nulos/brancos : " << tb1[linha2].votos_nulosEbranco << endl;
    system ("sleep 10");
}
void
executar ()
    {
    int tecla;
    MENU:
    system ("clear");
    cout << "\n*** Menu ***";
    cout << "\n\n\t1 Ler dados eleitores";
    cout << "\n\t2 Ler dados candidato ";
    cout << "\n\t3 mostrar_dados";
    cout << "\n\t4 Finalizar programa";
    cout << "\n\titem:";
    cin >> tecla;
    switch (tecla)
    {
        case 1:
        eleitores ();
        break;
        case 2:
        candidato ();
        break;
        case 3:
        mostrar_dados ();
        break;
        case 4:
        exit (0);
        break;
    }
    goto MENU;
}