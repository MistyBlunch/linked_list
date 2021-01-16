#include <iostream>
#include "linked_list.h"

using namespace std;
using namespace mb;

int main() {
  linked_list<int> ll;

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

  cout << '\n' << ll.size() << '\n';

  cout << endl;

  // Get value of the second index
  // It should be 43
  cout << "Get value of the second index:" << endl;
  node<int>* get = ll.get(2);
  if(get != NULL)
    cout << get->value_;
  else
    cout << "not found";
  cout << endl << endl;

  // Find the position of value 15
  // It must be 3
  cout << "The position of value 15:" << endl;
  int srch = ll.search(15);
  cout << srch << endl << endl;

  // Remove first element
  cout << "Remove the first element:" << endl;
  ll.erase(0);
  // 76->43->15->48->44->100->NULL
  ll.print();
  cout << endl;

  // Remove fifth element
  cout << "Remove the fifth element:" << endl;
  ll.erase(4);
  // 76->43->15->48->100->NULL
  ll.print();
  cout << endl;

  // Remove tenth element
  cout << "Remove the tenth element:" << endl;
  ll.erase(9);
  // Nothing happen
  // 76->43->15->48->100->NULL
  ll.print();
  cout << endl;


  // Test 1
  linked_list<int> ll2;
  for (size_t i = 0; i < 10; ++i) {
    ll2.push_back(i);
  }
  if(ll2.size() == 10) cout << "owo\n";

  linked_list<int> list1 = {3, 24, 13, 64, 25};

  linked_list<int> result;

  auto iter = end(list1)->value();

  for(auto it = list1.begin(); it != list1.end(); it+=2) {
    result.push_back(it->value());
  }
  result.push_back(iter);

  result.print();
  cout << "\n size: \t" << result.size() << "\n";
}