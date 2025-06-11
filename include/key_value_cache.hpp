#pragma once
#include <iostream>
#include <chrono>
#include <unordered_map>
#include <string>
#include <utility>
#include <cstdint>
#include <optional>

class KVCache {

  using TimePoint = std::chrono::steady_clock::time_point;

public:
  KVCache() { std::cout << "[KVCache] created" << std::endl; }

  void put(std::string key, std::string value, std::uint64_t exp) {

    TimePoint now = std::chrono::steady_clock::now();

    cache_[key] = {value, {exp, now}}; // not sure if i should be using move semantics here
  }

  std::optional<std::string> get(std::string key) {
    auto it = cache_.find(key);
    if (it != cache_.end()) {

      auto elapsed = std::chrono::steady_clock::now() - it->second.second.second;

      if (elapsed >= std::chrono::milliseconds(it->second.second.first)) {
        cache_.erase(key);
        return std::nullopt;
      } else {
        return it->second.first;
      }
    } else {
      return std::nullopt;
    }
  }

private:
  std::unordered_map<std::string, std::pair<std::string, std::pair<std::uint64_t, TimePoint>>>
      cache_;
};