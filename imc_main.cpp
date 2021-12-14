#include "iostream"
#include "cstdlib"
#include "string"

using namespace std;

const int n = 5;
int linha = 0;

struct pessoa {
    string nome;
    string email;
    string telefone;
    double peso{};
    double altura{};
};

struct pessoa tb1[n];
string lerNome();
string email();
string telefone();
double lerPeso();
double lerAltura();
void adicionarLinha();
void exibirStruct();
void removerLinha(int numeroLinha);
void exibirStruct();
void executar();

int main() {
    setlocale(LC_ALL, "Portuguese");
    executar();
    return 0;
}

string lerNome() {
    string x;
    cout << "Digite o nome: ";
    getline(cin, x);
    return x;
}

string lerEmail() {
    string x;
    cout << "Digite o email: ";
    cin >> x;
    return x;
}

string lerTelefone() {
    string x;
    cout << "Digite o telefone: ";
    cin >> x;
    return x;
}

double lerPeso() {
    double x;
    cout << "Digite o peso: ";
    cin >> x;
    return x;
}

double lerAltura() {
    double x;
    cout << "Digite a altura: ";
    cin >> x;
    return x;
}

void adicionarLinha() {
    linha++;
    cin.ignore();
    string nome_ = lerNome();
    tb1[linha].nome = nome_;
    string email_ = lerEmail();
    tb1[linha].email = email_;
    string telefone_ = lerTelefone();
    tb1[linha].telefone = telefone_;
    double peso = lerPeso();
    tb1[linha].peso = peso;
    double altura = lerAltura();
    tb1[linha].altura = altura;
}

void exibirLinha(int numeroLinha) {
    system("clear");
    cout << "\n----------------INICIO--------------------\n";
    cout << "\n\tNumeroLinha: " << numeroLinha << " | "
    << tb1[numeroLinha].nome << " | "
    << tb1[numeroLinha].email << " | "
    << tb1[numeroLinha].telefone << " | "
    << tb1[numeroLinha].peso << " | "
    << tb1[numeroLinha].altura << "\n";
    cout << "\n----------------FIM-----------------------" << endl;
    system("sleep 3");
}

void removerLinha(int numeroLinha) {
    tb1[numeroLinha].altura = tb1[0].altura;
    tb1[numeroLinha].email = tb1[0].email;
    tb1[numeroLinha].nome = tb1[0].nome;
    tb1[numeroLinha].telefone = tb1[0].telefone;
    tb1[numeroLinha].peso = tb1[0].peso;
}

void exibirStruc() {
    system("clear");
    cout << "\n----------------INICIO--------------------\n";
    for (int i = 1; i <= linha; i++) {
        cout << "\n\t"
        << tb1[i].nome << " | "
        << tb1[i].email << " | "
        << tb1[i].telefone << " | "
        << tb1[i].peso << " | "
        << tb1[i].altura << "\n";
    }
    cout << "\n----------------FIM-----------------------" << endl;
    system("sleep 2");
}

    void executar() {
    int tecla, num, numeroLinha;
    MENU:
    system("clear");
    cout << "\nMENU";
    cout << "\n\n\t1. Adicionar Linha";
    cout << "\n\t2. Exibir Linha";
    cout << "\n\t3. Remover Linha";
    cout << "\n\t4. Exibir Struct";
    cout << "\n\t5. Finalizar programa";
    cout << "\n\titem:";
    cin >> tecla;
    switch (tecla) {
        case 1:
            if (linha > 2) {
                cout << "\nExcedido tamanho = 3";
            } else {
                adicionarLinha();
            }
            break;
        case 2:
            cout << "\nLinha.: ";
            cin>> num;
            if (num == 0) {
            cout << "\nnao encontrada";
            goto MENU;
            }
            num + 1;
            if (num > linha) {
            cout << "\nnao encontrada";
            goto MENU;
            } else {
            exibirLinha(num);
            }
            break;
        case 3:
            cout << "\nLinha.: ";
            cin>> num;
            if (num == 0) {
                cout << "\nnao encontrada";
                goto MENU;
            }
            num + 1;
            if (num > linha) {
                cout << "\nnao encontrada";
            goto MENU;
            } else {
                removerLinha(num);
            }
            break;
        case 4:
            exibirStruc();
            break;
        case 5:
            exit(0);
            break;
    }
    goto MENU;

} 