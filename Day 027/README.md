# Valid Parentheses

## Example

**Input:** `([{}])`
**Output:** `true`

**Explanation:** Each opening bracket has the correct closing bracket in the proper order.

## Concept

**Stack** — Store opening brackets and match them with closing brackets using the top of the stack.

## Approach

1. Traverse the string character by character.
2. If the character is an opening bracket, push it into the stack.
3. If it is a closing bracket:

   * If the stack is empty, return `false`.
   * Check whether it matches the top opening bracket.
   * If it matches, pop the top element.
   * Otherwise, return `false`.
4. After traversing the string, return `true` only if the stack is empty.

## Dry Run

**Input:** `([{}])`

* `(` → push
* `[` → push
* `{` → push
* `}` → matches `{` → pop
* `]` → matches `[` → pop
* `)` → matches `(` → pop
* Stack is empty → **Valid**

## Complexity

* Time Complexity: O(n)
* Space Complexity: O(n)
