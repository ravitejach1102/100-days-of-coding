# Stock Span

## 1. Problem Statement

Given an array of stock prices, find the **span** for each day.

The span is the number of consecutive days before the current day where the stock price was **less than or equal to** the current price.

Example:

```text
Stock prices: 100 80 60 70 60 85 100
Span:          1  1  1  2  1  5  7
```

## 2. Concept

* Use a **stack** to find the previous greater price.
* In **Code 1**, the stack stores indexes.
* In **Code 2**, the stack stores `{price, span}` pairs.
* Smaller or equal prices are removed because they are included in the current span.

## 3. Logic

### Code 1: Stack of Indexes

The stack stores the **indexes** of useful previous prices.

For every price:

1. Remove indexes whose prices are less than or equal to the current price.
2. If the stack is empty, there is no previous greater price, so:

   ```cpp
   span[i] = i + 1;
   ```
3. Otherwise, the top of the stack is the previous greater price.
4. Calculate:

   ```cpp
   span[i] = i - s.top();
   ```
5. Push the current index.

### Code 2: Stack of `{price, span}`

The stack stores:

```text
{price, span}
```

For every new price:

1. Start with `span = 1`.
2. If the top price is less than or equal to the current price, pop it.
3. Add the popped element's span to the current span.
4. Continue until a greater price is found or the stack becomes empty.
5. Push `{current price, current span}`.

The important line is:

```cpp
span += s.top().second;
```

Instead of counting every previous day again, we use the span that was already calculated.

## 4. Approach

### Code 1: Stack of Indexes

1. Create a stack of integers.
2. Push index `0` and set `span[0] = 1`.
3. For every next index, get the current price.
4. Remove indexes whose prices are less than or equal to the current price.
5. If the stack is empty, set span to `i + 1`.
6. Otherwise, calculate `i - s.top()`.
7. Push the current index.

### Code 2: Stack of `{price, span}`

1. Create a stack of pairs.
2. Start every new stock span with `1`.
3. Remove prices less than or equal to the current price.
4. Add their stored spans to the current span.
5. Push `{price, span}` into the stack.
6. Return the current span.

## 5. Dry Run

Example:

```text
stock = {100, 80, 60, 70, 60, 85, 100}
```

Expected:

```text
1 1 1 2 1 5 7
```

### Code 1: Stack of Indexes

The stack contains **indexes**.

#### Price = 100, index = 0

```text
span = 1
```

Push index `0`.

```text
TOP
 ↓
[0] → 100
```

---

#### Price = 80, index = 1

Check top:

```text
stock[0] = 100
100 <= 80 → false
```

Previous greater index = `0`.

```text
span[1] = 1 - 0 = 1
```

Push `1`.

```text
TOP
 ↓
[1] → 80
[0] → 100
```

---

#### Price = 60, index = 2

```text
80 <= 60 → false
```

So:

```text
span[2] = 2 - 1 = 1
```

Push `2`.

```text
TOP
 ↓
[2] → 60
[1] → 80
[0] → 100
```

---

#### Price = 70, index = 3

Top price:

```text
60 <= 70 → true
```

Pop index `2`.

```text
TOP
 ↓
[1] → 80
[0] → 100
```

Now:

```text
80 <= 70 → false
```

Previous greater index = `1`.

```text
span[3] = 3 - 1 = 2
```

Push `3`.

```text
TOP
 ↓
[3] → 70
[1] → 80
[0] → 100
```

---

#### Price = 60, index = 4

```text
70 <= 60 → false
```

Therefore:

```text
span[4] = 4 - 3 = 1
```

Push `4`.

```text
TOP
 ↓
[4] → 60
[3] → 70
[1] → 80
[0] → 100
```

---

#### Price = 85, index = 5

Check and pop:

```text
60 <= 85 → pop
70 <= 85 → pop
80 <= 85 → pop
```

Stack becomes:

```text
TOP
 ↓
[0] → 100
```

Now:

```text
100 <= 85 → false
```

Previous greater index = `0`.

```text
span[5] = 5 - 0 = 5
```

Push `5`.

```text
TOP
 ↓
[5] → 85
[0] → 100
```

---

#### Price = 100, index = 6

Check:

```text
85 <= 100 → pop
100 <= 100 → pop
```

Stack becomes empty:

```text
TOP
 ↓
EMPTY
```

Therefore:

```text
span[6] = 6 + 1 = 7
```

Final result:

```text
1 1 1 2 1 5 7
```

---

### Code 2: Stack of `{price, span}`

Here the stack stores:

```text
{price, span}
```

#### Price = 100

Start:

```text
span = 1
```

Push:

```text
{100, 1}
```

Stack:

```text
TOP
 ↓
{100, 1}
```

Answer:

```text
1
```

---

#### Price = 80

```text
100 <= 80 → false
```

Push:

```text
{80, 1}
```

Stack:

```text
TOP
 ↓
{80, 1}
{100, 1}
```

Answer:

```text
1
```

---

#### Price = 60

```text
80 <= 60 → false
```

Push:

```text
{60, 1}
```

Stack:

```text
TOP
 ↓
{60, 1}
{80, 1}
{100, 1}
```

Answer:

```text
1
```

---

#### Price = 70

Start:

```text
span = 1
```

Top:

```text
{60, 1}
```

Since:

```text
60 <= 70
```

pop it and add its span:

```text
span = 1 + 1
     = 2
```

Stack:

```text
TOP
 ↓
{80, 1}
{100, 1}
```

Now:

```text
80 <= 70 → false
```

Push:

```text
{70, 2}
```

Stack:

```text
TOP
 ↓
{70, 2}
{80, 1}
{100, 1}
```

Answer:

```text
2
```

---

#### Price = 60

Top:

```text
70 <= 60 → false
```

Push:

```text
{60, 1}
```

Stack:

```text
TOP
 ↓
{60, 1}
{70, 2}
{80, 1}
{100, 1}
```

Answer:

```text
1
```

---

#### Price = 85

Start:

```text
span = 1
```

Pop:

```text
{60, 1}
```

Add its span:

```text
span = 1 + 1 = 2
```

Next:

```text
{70, 2}
```

Pop and add:

```text
span = 2 + 2 = 4
```

Next:

```text
{80, 1}
```

Pop and add:

```text
span = 4 + 1 = 5
```

Now top:

```text
{100, 1}
```

Since:

```text
100 <= 85 → false
```

Stop.

Push:

```text
{85, 5}
```

Stack:

```text
TOP
 ↓
{85, 5}
{100, 1}
```

Answer:

```text
5
```

---

#### Price = 100

Start:

```text
span = 1
```

Top:

```text
{85, 5}
```

Since:

```text
85 <= 100
```

Pop and add:

```text
span = 1 + 5 = 6
```

Next:

```text
{100, 1}
```

Since:

```text
100 <= 100
```

Pop and add:

```text
span = 6 + 1 = 7
```

Stack is now empty.

Push:

```text
{100, 7}
```

Final stack:

```text
TOP
 ↓
{100, 7}
```

Final result:

```text
1 1 1 2 1 5 7
```

## 7. Time Complexity

**O(n)** — Each element is pushed and popped from the stack at most once.

## 8. Space Complexity

**O(n)** — The stack can contain up to `n` elements.
