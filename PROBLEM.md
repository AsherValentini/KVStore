Expiring Key-Value Store

Paragraph:

You are building an in-memory key-value store (like a cache).
Keys are strings, values are strings.
Each key-value pair has a time-to-live (TTL) in milliseconds — after this time passes, the key is considered expired and no longer exists.

You are asked to build a KVStore module with the following API:

    put(key, value, ttl_ms) → store key with value and TTL.

    get(key) → returns value if key exists and is not expired, else indicates "not found".

    Expired keys should not be returned by get().

    No background thread is required → keys can be lazily cleaned up at get/put time.

    The module should handle multiple puts to the same key → latest put wins.

Example:

put("foo", "bar", 500)  
get("foo") → "bar"  
(wait 600 ms)  
get("foo") → "not found"  

Clarifications:

    You do not need to implement a background expirer thread — just check expiry at get() or put() time.

    You can choose any clean way to represent "not found" in your API.

    Use chrono for time tracking (steady_clock preferred).

    The module should be reusable and clean.

That’s it — design a clean KVStore module.
Class, state, logic — clean and reusable.
