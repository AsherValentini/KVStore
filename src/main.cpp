#include <iostream>
#include <memory>
#include <random>
#include <thread>
#include <unordered_map>

#include "key_value_cache.hpp"

void helper(std::unique_ptr<KVCache> cache,
            std::unordered_map<std::string, std::pair<std::string, std::uint64_t>> cacheMap) {

  std::random_device rd;                              // seed
  std::mt19937 gen(rd());                             // Mersenne Twister RNG
  std::uniform_int_distribution<> distrib(100, 1000); // random between 100 and 1000 ms

  for (auto entry : cacheMap) {

    auto interval_ms = distrib(gen);
    cache->put(entry.first, entry.second.first, entry.second.second);
    std::this_thread::sleep_for(std::chrono::milliseconds(interval_ms));

    auto getResult = cache->get(entry.first);
    if (getResult.has_value()) {
      std::cout << "Got key with value: " << getResult.value() << "\n";

    } else {
      std::cout << "Key expired" << std::endl;
    }
  }
}

int main() {

  auto keyValueStore = std::make_unique<KVCache>();

  std::unordered_map<std::string, std::pair<std::string, std::uint64_t>> keyMap{
      {"key1", {"value1", 150}}, {"key2", {"value2", 500}}, {"key3", {"value3", 600}}};

  std::thread tester([&]() { helper(std::move(keyValueStore), keyMap); });

  tester.join();

  return 0;
}

