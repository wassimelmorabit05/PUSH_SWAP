*This project has been created as part of the 42 curriculum by oel-mora.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 Network.  
The goal is to sort a stack of integers using **two stacks (`a` and `b`)** and a **limited set of allowed operations**, while producing the **smallest possible number of instructions**.

This implementation uses an optimized **Chunk sorting strategy** to efficiently handle large inputs.

---

## Objectives

- Understand and apply stack-based sorting techniques
- Write efficient algorithms in C under strict constraints
- Minimize number of operations and analyze complexity
- Respect the 42 Norm and submission requirements

---

## Rules (brief)

Only the following operations are allowed:
`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.

(See full subject for details.)

---

## Algorithm: Chunk Strategy (implemented)

1. **Indexing** — convert values to their sorted ranks (1..n).
2. **Chunking** — split index-space into chunks.
   - chunk size: `<=100 → 18`, `<=500 → 35`, else `size / 12`.
3. **Push phase** — push chunk elements from A → B using minimal rotations.
4. **Rebuild phase** — pop from B → A by always rotating the max to top (choose `rb` vs `rrb` optimally).

This reduces unnecessary rotations and keeps operation count low.

--- 

## Performance

Meets the subject benchmarks (100 and 500 element goals) when tested with randomized inputs and reasonable seeds.

---

## Resources

push_swap subject (42 Network) — official project specifications and benchmarks
Push Swap: The Least Amount of Moves with Two Stacks (Medium)
https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
Google searches: push_swap chunk algorithm, push_swap optimization

---

## Compilation

```bash
make