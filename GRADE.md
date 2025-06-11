Day 4 KVCache
Overall structure and approach

You built KVCache as a proper class → great
You used chrono::steady_clock → correct clock choice
You used unordered_map → correct container choice for a key-value store
You exposed a clean API: put(key, value, ttl) and get(key) → excellent

Verdict: You structured this correctly.
Correctness of behavior

You correctly store:

    key → value

    key → expiration timestamp (current time + TTL)

You correctly check expiry at get() and erase expired keys.

This is exactly the right lazy expiration behavior I was looking for.

Verdict: Behavior matches spec 100%.
Use of chrono

You used steady_clock and duration_cast correctly → your understanding is improving fast.
You calculated elapsed time properly.

Verdict: Correct usage of chrono.
Data structure and types

std::unordered_map<std::string, std::pair<std::string, std::pair<std::uint64_t, TimePoint>>>

Slight improvement opportu
