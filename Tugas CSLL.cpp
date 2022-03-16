#include <iostream>
using namespace std;

struct Mie{
  string merek, jenis, harga;

  Mie *next;
};

Mie *head, *tail, *newNode, *cur, *del;

void createCircularSingleLinkedList(string dataBaru[4]){

  head = new Mie();
  head->merek = dataBaru[0];
  head->jenis = dataBaru[1];
  head->harga = dataBaru[2];
  tail = head;
  tail->next = head;

}

// add first
void addFirst( string data[3] ){
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    newNode = new Mie();
    newNode->merek = data[0];
    newNode->jenis = data[1];
    newNode->harga = data[2];
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
  }
}

// add Last
void addLast( string data[3] ){
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    newNode = new Mie();
    newNode->merek = data[0];
    newNode->jenis = data[1];
    newNode->harga = data[2];
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
  }
}

// add Middle
void addMiddle(string data[3], int posisi)
{
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    if( posisi == 1 ){
      cout << "Posisi satu bukan posisi tengah!!!" << endl;
    }else{
      newNode = new Mie();
      newNode->merek = data[0];
      newNode->jenis = data[1];
      newNode->harga = data[2];

      // tranversing
      int nomor = 1;
      cur = head;
      while (nomor < posisi - 1)
      {
        cur = cur->next;
        nomor++;
      }
      newNode->next = cur->next;
      cur->next = newNode;
    }
  }
}

// remove First
void removeFirst(){
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    del = head;
    head = head->next;
    tail->next = head;
    delete del;
  }
}

// remove last
void removeLast()
{
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    del = tail;
    cur = head;
    while( cur->next != tail ){
      cur = cur->next;
    }
    tail = cur;
    tail->next = head;
    delete del;
  }
}

// remove middle
void removeMiddle(int posisi)
{
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    // tranversing
    int nomor = 1;
    cur = head;
    while( nomor < posisi - 1 ){
      cur = cur->next;
      nomor++;
    }
    del = cur->next;
    cur->next = del->next;
    delete del;
  }
}


void printCircular()
{
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    cout << " List Mie " << endl;
    cout << "________________________________________________________________" << endl; 
    cout << "| MEREK\t\t| JENIS\t\t| HARGA\t|" << endl;
    cout << "________________________________________________________________" << endl; 
    cur = head;
    while (cur->next != head)
    {
      // print
      cout << "| " << cur->merek << "\t| " << cur->jenis << "\t| " << cur->harga << "\t|" << endl;
      cur = cur->next;
    }
    cout <<   "| " << cur->merek << "\t| " << cur->jenis << "\t| " << cur->harga << "\t|" << endl;
    cout << "_________________________________________________________________" << endl;
  }
}


int main(){
  string dataBaru[3] = {"INDOMIE","GORENG", "3000"};
  createCircularSingleLinkedList(dataBaru);

  printCircular();

  string data[3] = {"SEDAP", "KUAH", "4000"};
  addFirst(data);

  printCircular();

  string data2[3] = {"INTERMI", "KUAH", "2000"};
  addLast(data2);

  printCircular();

  string data3[3] = {"SARIMI", "GORENG", "4000"};
  addMiddle(data3, 5);

  printCircular();

  removeMiddle(6);

  printCircular();

  removeFirst();

  printCircular();

  removeLast();

  printCircular();
}
