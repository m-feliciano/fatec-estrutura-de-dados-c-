#include <cstdlib>
#include <iostream>
using namespace std;

// declaracoes 

void construtor ();
int lerValor ();
void push ();
void pop ();
void exibir ();
void destrutor ();
bool vazia ();


typedef struct Nopilha pilha;

struct Nopilha
{
  int valor;
  pilha *ant;
};

int cont;			// qtde de elementos da pilha 
pilha *topo;

int
main ()
{
  setlocale (LC_ALL, "portuguese");
  int tecla;

MENU:
  cout << "\n1. Constructor"
    "\n2. push"
    "\n3. exibir" "\n4. pop" "\n5. destrutor " "\n6. finaliza" "\nItem:  ";
  cin >> tecla;
  if (tecla == 1)
    {
      construtor ();
      system ("sleep 1");
      goto MENU;
    }

  if (tecla == 2)
    {
      push ();
      //push(); 
      system ("sleep 1");
      goto MENU;
    }

  if (tecla == 3)
    {
      exibir ();
      system ("sleep 1");
      goto MENU;
    }

  if (tecla == 4)
    {
      pop ();
      system ("sleep 1");
      goto MENU;
    }



  if (tecla == 5)
    {
      destrutor ();
      system ("sleep 1");
      goto MENU;
    }
    
  if (tecla == 6)
    {
      cout << "\nPrograma finalizado!\n";
      return 0;
      exit (0);
    }

  /* 
     construtor(); 
     push(); 
     push(); 
     exibir(); 
     pop(); 
     exibir(); 
     destrutor(); 
     return 0; 
   */

}
void
construtor ()
{
  cont = 0;
  topo = NULL;
}

// empilhar  
int
lerValor ()
{
  int v;
  cout << " Digite o valor:";
  cin >> v;
  return v;
}



void
push ()
{
  pilha *newPilha;
  newPilha = (pilha *) malloc (sizeof (pilha));
  if (newPilha == NULL)
    {
      cout << "Falha de alocacao!" << endl;
      system ("sleep 3");
      return;			// sai do void sem fazer nada.  
    }

  // configurar atributos internos de newpilha 
  cont++;
  newPilha->valor = lerValor ();
  // O ponteiro interno ant* do novo struct newPilha 
  // devera conter o endereco de memoria  
  // do topo anterior 
  newPilha->ant = topo;
  // o novo topo tera o endereco de memoria 
  // do newPilha que acabou de ser alocado 
  topo = newPilha;
}

void
pop ()
{
  pilha *temp;
  temp = topo;
  topo = temp->ant;		// altera o endereco do topo para o topo anterior 
  free (temp);
  cont--;
}

void
exibir ()
{
  pilha *temp;
  temp = topo;
  while (temp != NULL)
    {
      cout << temp->valor << "  ";
      temp = temp->ant;
    }
  free (temp);
}

void
destrutor ()
{
  pilha *temp;
  temp = topo;
  while (temp != NULL)
    {
      free (temp);		// apagando a memoria 
      temp = temp->ant;
    }
  free (temp);
  free (topo);
}



bool
vazia ()
{
  if (cont == 0)
    return true;
  else
    return false;
}
