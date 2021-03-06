#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <bits/stdc++.h>
using namespace std;

namespace mb {
  // Creamos una estrucuta node que tendrá 2 atributos
  template <typename T>
  struct node {
    T value_;
    node<T>* next_ = nullptr;

    /*****************************************************************
    Tendremos 2 constructores, uno que inicializará los atributos con 
    los argumentos que le pasemos a una instancia de node
    ******************************************************************/
    node() = default;
    node(T value_) : value_{value_}, next_{nullptr} { }

    // Creamos 2 métodos
    T value() const { return value_; };
    node<T>* next() const { return next_; };
  };

  // Creamos una estrucuta linked list que tendrá 3 atributos
  template <typename T>
  class linked_list {
    node<T>* head_;
    node<T>* tail_;
    size_t size_;

  public:
    linked_list() : head_{nullptr}, tail_{nullptr}, size_{0} { }

    linked_list(initializer_list<int> l) : head_{nullptr}, tail_{nullptr}, size_{0} {
      for(auto v:l) 
        push_back(v);
    }

    // Método para agregar un nodo al final de una linked list
    void push_back(T data) {
      node<T>* tmp = new node<T>(data);
      /*****************************************************************
      También podemos hacer esto, pero como nuestro constructor ya lo 
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

      size_++;
    }

    // Método para agregar un nodo al inicio de una linked list
    void push_front(T data) {
      node<T>* tmp = new node<T>(data);
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

      size_++;
    }

    // Método para agregar un nodo en la posición que se especifique en la linked list
    void insert(size_t index, T data) {
      node<T>* tmp = new node<T>(data);
      /*****************************************************************
      Verificamos si el index es menor que 0 o si es mayor que el tamaño
      de la linked list, si es así, entonces no retornamos nada.
      Si el index es 0, significa que se hará una inserción al inicio de
      la linked list, por eso un push_front().
      Si el index es el mismo que el tamaño de la linked list, significa 
      que se hará una inserción al final de la linked list, por eso un 
      push_back().
      Y si no es ninguna de las condiciones previstas anteriormente, 
      entonces creamos dos nodos, que actúen como el nodo previo y 
      posterior, a continuación explicaré la lógica que consideré.
        1. Recorreremos la linked list hasta llegar una posición antes
        de la posición deseada, esto tiene por ebjetivo que los 2 nodos, 
        tanto el previo como el posterior avancen.
        2. Al finalizar el loop el nodo previo debería ser el nodo que 
        se encuentra una posición antes del nodo de la posición que se 
        especificó y el nodo posterior debería ser el mismo nodo que el
        nodo previo.
        3. Sin embargo, una vez fuera del loop el nodo posterior será el 
        le sigue, con esto, habremo conseguido las direcciones que 
        necesitamos.
        4. Finalizamos el algoritmo con nuestro nodo tmp(creado al inicio)
        apuntando al nodo posterior y con el nodo previo apuntando al nodo
        tmp.
      ******************************************************************/
      if(index < 0 || index > size_) 
        return;
      if(index == 0) {
        push_front(data);
        return;
      }
      if(index == size_) {
        push_back(data);
        return;
      }

      node<T>* prevNode = head_;
      node<T>* posNode = head_;

      for(size_t i = 0; i < index-1; i++) {
        prevNode = prevNode->next_;
        posNode = posNode->next_;
      }
      posNode = posNode->next_;

      tmp->next_ = posNode;
      prevNode->next_ = tmp;

      size_++;
    }

    // Método para borrar el primer nodo de la linked list
    void pop_front() {
      /*****************************************************************
      Para este método crearemos 1 nodo, este será el head. Luego 
      haremos que el head apunte al nodo siguiente del head. Hecho esto, 
      ya podemos eliminar el nodo que guardaba al antiguo head.
      ******************************************************************/
      if(size_ == 0) return;
      node<T>* node = head_;

      head_ = node->next_;
      delete node;

      size_--;
    }

    // Método para borrar el último nodo de la linked list
    void pop_back() {
      /*****************************************************************
      Para este método crearemos 1 nodo, este será el head. Luego 
      haremos que el nodo sea el penúltimo. Con esto ya podemos eliminar
      el nodo siguiente y hacer que el tail apunte al penúltimo nodo.
      ******************************************************************/
      if(size_ == 0) return;
      if(size_ == 1) {
        pop_front();
        return;
      }

      node<T>* node = head_;

      for(size_t i = 0; i < size_-1; ++i) {
        node = node->next_;
      }

      delete node->next_;
      tail_ = node;

      size_--;
    }

    // Método para borrar el nodo de posición especificada en el método
    void erase(size_t index) {
      /*****************************************************************
      Verificamos si el index es menor que 0 o si es mayor que el tamaño
      de la linked list, si es así, entonces no retornamos nada.
      Si el size es igual a cero, significa que no hay ningún nodo el la 
      linked list, por lo que, no se hará nada.
      Sin embargo el index es 0, significa que se elminará al inicio de
      la linked list, por eso un pop_front().
      Si el index es el mismo que el tamaño de la linked list, significa 
      que se eliminará el último nodo de  la linked list, por eso un 
      pop_back().
      Y si no es ninguna de las condiciones previstas anteriormente, 
      entonces primero creamos un nodo, que actúen como el nodo previo,
      a continuación explicaré la lógica que consideré.
        1. Recorreremos la linked list hasta llegar una posición antes
        de la posición deseada, esto tiene por ebjetivo que el nodo 
        previo sea el nodo anterior al nodo que se quiere borrar.
        2. Al finalizar el loop el nodo previo debería ser el nodo que 
        se encuentra una posición antes del nodo de la posición que se 
        especificó.
        3. Después creamos un nuevo nodo(posNode) el cuál será el 
        siguiente nodo del nodo previo.
        4. A su vez creamos otro nodo que sera el siguiente(nxtNode) del
        nodo posterior.
        5. Lo siguiente tendrá por objetivo hacer que el nodo previo 
        apunte al nodo siguiente del posterior y después eliminará el nodo 
        posterior creado.
      ******************************************************************/
      if(index < 0 || index > size_) return;
      if(size_ == 0) return;
      if(index == 0) {
        pop_front();
        return;
      }
      if(index == size_) {
        pop_back();
        return;
      }

      node<T>* prevNode = head_;

      for(size_t i = 0; i < index-1; ++i) {
        prevNode = prevNode->next_;
      }
      node<T>* posNode = prevNode->next_;
      node<T>* nxtNode = posNode->next_;

      prevNode->next_ = nxtNode;
      delete posNode;
      
      size_--;
    }

    // Método para retornar el valor de una posición en la linked list
    node<T>* get(size_t index) {
      if(index < 0 || index > size_) return nullptr;

      node<T>* tmp = head_;
      for(size_t i=0; i<index; ++i) {
        tmp = tmp->next_;
      }
      return tmp;
    }

    // Método para retornar el indice del valor que le pasamos al método
    T search(T data) {
      node<T>* tmp = head_;
      for(size_t i=0; i<size_; ++i) {
        if(tmp->value_ == data)
          return i;
        tmp = tmp->next_;
      }
      return -1;
    }

    // Método para retornar el tamaño de la linked list
    size_t size() {
      return size_;
    }
    
    // Método para retornar el puntero head de la linked list
    node<T>* begin() {
      return head_;
    }

    // Método para retornar el puntero tail de la linked list
    node<T>* end() {
      return tail_;
    }

    // Método para imprimir la linked list
    void print() {
      node<T>* nod = head_;
      while(nod != nullptr) {
        cout << nod->value_ << " -> ";
        nod = nod->next_;
      }
    }
  };
}

#endif