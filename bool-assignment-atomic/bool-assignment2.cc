
#include <thread>
#include <cassert>
#include <chrono>
using namespace std;

bool b = false;

void writer() {
  while (true) {
    this_thread::sleep_for(chrono::milliseconds(rand() % 10));
    b = true;
  }
}

void reader() {
  auto last_received = chrono::high_resolution_clock::now();
  while (true) {
    if (b) {
      b = false;
      auto now = chrono::high_resolution_clock::now();
      assert(now - last_received <= chrono::milliseconds(20));
      last_received = now;
    }
  }
}

int main() {
  thread t(&writer);
  reader();
}
