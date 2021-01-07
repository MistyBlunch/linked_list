#include <bits/stdc++.h>
using namespace std;

// Creamos una estrucuta node que tendrá 2 atributos
struct node {
  int value_;
  node* next_ = nullptr;

  /*****************************************************************
  Tendremos 2 constructores, uno que inicializará los atributos con 
  los argumentos que le pasemos a una instancia de node
  ******************************************************************/
  node() = default;
  node(int value_) : value_{value_}, next_{nullptr} { }

  // Creamos 2 métodos
  int value() const { return value_; }
  node* next() const { return next_; }
};


// Creamos una estrucuta linked list que tendrá 3 atributos
class linked_list {
  node* head_;
  node* tail_;
  int size_;

public:
  linked_list() : head_{nullptr}, tail_{nullptr}, size_{0} { }

  // Método para agregar un nodo al final de una linked list
  void push_back(int data) {
    node* tmp = new node(data);
    /*****************************************************************
    también podemos hacer esto, pero como nuestro constructor ya lo 
    hace, no hay necesidad de inicializar cada atributo como lo hace 
    el sig código:

    tmp->value_ = data;
    tmp->next_ = nullptr;
    ******************************************************************/

    /*****************************************************************
    Verificamos si el head es nulo, si es así, entonces quiere decir 
    que aún no hay ningún nodo en la linked list, por lo que el nodo
    que agreguemos será tanto el head como el tail.
    Pero si el head no es nulo, entonces significa que ya hay nodos en 
    la linked list. Por lo que, tenemos que agregar el nodo al final 
    de la linked list, y hacer que el último nodo agregado sea el 
    siguiente nodo de tail.
    ******************************************************************/
    if(head_ == nullptr) {
      head_ = tmp;
      tail_ = tmp;
    } else {
      tail_->next_ = tmp;
      tail_ = tail_->next_;
    }
  }

  void push_front(int data) {
    node* tmp = new node(data);
    /*****************************************************************
    Verificamos si el head es nulo, si es así, entonces quiere decir 
    que aún no hay ningún nodo en la linked list, por lo que el nodo
    que agreguemos será tanto el head como el tail.
    Pero si el head no es nulo, entonces significa que ya hay nodos en 
    la linked list. Por lo que, tenemos que agregar el nodo al inicio 
    de la linked list. Para ello, hacemos que el atributo next del
    nodo apunte al head, una vez hecho esto, hacemos que el head pase
    a puntar al nodo agregado.
    ******************************************************************/
    if(head_ == nullptr) {
      head_ = tmp;
      tail_ = tmp;
    } else {
      tmp->next_ = head_;
      head_ = tmp;
    }
  }

  void print() {
    node* nod = head_;
    while(nod != nullptr) {
      cout << nod->value_ << " -> ";
      nod = nod->next_;
    }
  }
};

int main() {
  cout << "hello" << endl;
  linked_list ll;

  // 43->NULL
  ll.push_front(43);

  // 76->43->NULL
  ll.push_front(76);

  // 76->43->15->NULL
  ll.push_back(15);

  // 76->43->15->44->NULL
  ll.push_back(44);

  // 76->43->15->44->100->NULL
  ll.insert(4, 100);

  // 76->43->15->48->44->100->NULL
  ll.insert(3, 48);

  // 22->76->43->15->48->44->100->NULL
  ll.insert(0, 22);

  ll.print();
}
