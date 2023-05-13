#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Node
{
  int data;
  Node *prev;
  Node *next;
  Node(int data):data(data), prev(nullptr), next(nullptr) {}
};

class List
{ 
  public:
    Node *head, *tail;
    void IH(int val){
      if(head == nullptr){
        head = new Node(val);
        tail = head;
      }else{
        Node* tmp = new Node(val);
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
      }
    }
    void IT(int val){
      if(head == nullptr){
        head = new Node(val);
        tail = head;
      }else{
        Node* tmp = new Node(val);
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
      }
    }
    void RH(){
      if(head == nullptr){
        return;
      }else if(head->next == nullptr){
        delete head;
        head = tail = nullptr;
      }else{
        auto tmp = head->next;
        head->next = nullptr;
        tmp->prev = nullptr;
        delete head;
        head = tmp;
      }
    }
    void RT(){
      if(head == nullptr){
        return;
      }else if(head->next == nullptr){
        delete head;
        head = tail = nullptr;
      }else{
        auto tmp = tail->prev;
        tail->prev = nullptr;
        tmp->next = nullptr;
        delete tail;
        tail = tmp;
      }
    }
    void S(int target){
      if(head == nullptr){ cout << "E\n"; return; }
      else{
        auto it = head;
        while(it != nullptr){
          if(it->data == target){
            cout << "Y\n";
            return;
          }
          it = it->next;
        }
        cout << "N\n";
      }
    }
    void O(){
      if(head == nullptr){ cout << "E\n"; return; }
      else{
        auto it = head;
        while(it){
          cout << it->data;
          if(it->next != nullptr)	cout << " ";
          it = it->next;
        }
      }
      cout << "\n";
    }
    List():head(nullptr) {}
};

int main(){
  int q; cin >> q;
  List *L = new List();
  while(q--){
  	string s;
    cin >> s;
    if(s == "IT"){
      int v; cin >> v;
      L->IT(v);
    }else if(s == "IH"){
      int v; cin >> v;
      L->IH(v);
    }else if(s == "RH"){
      L->RH();         
    }else if(s == "RT"){
      L->RT();
    }else if(s == "O"){
      L->O();
    }else{
      int v; cin >> v;
      L->S(v);
    }
  }
  return 0;
}