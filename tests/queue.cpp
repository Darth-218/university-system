#include "../include/queue.h"

using namespace std;

int main() {
  Queue<int> q;

  q.enqueue(23);
  q.enqueue(24);
  q.enqueue(25);
  q.enqueue(26);
  q.peek();

  q.dequeue();
  q.peek();
}
