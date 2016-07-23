
#include <cstdlib>
#include <thread>
#include <vector>
using namespace std;

bool b = false;

void exec() {
  while (true) {
    b = (rand() & 1);
    bool v = b;
  }
}

int main() {
  vector<thread> threads;
  for (int i = 0; i < 9; i++) {
    threads.emplace_back(&exec);
  }
  exec();
}
