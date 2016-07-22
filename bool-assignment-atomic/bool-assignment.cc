
#include <cstdlib>
#include <thread>
using namespace std;

bool b = false;

void exec() {
  while (true) {
    b = (rand() & 1);
  }
}

int main() {
  thread t(&exec);
  exec();
}
