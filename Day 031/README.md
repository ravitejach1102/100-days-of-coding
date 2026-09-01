# Valid Palindrome

## Example

**Input:**

```text
"A man, a plan, a canal: Panama"
```

**Output:**

```text
Palindrome
```

**Explanation:**
Ignore spaces, commas, and other special characters, and compare letters without considering uppercase/lowercase.

The string becomes:

`amanaplanacanalpanama`

It reads the same from both sides, so it is a palindrome.

## Concept

**Two Pointers**

Use one pointer from the beginning and another from the end. Ignore non-alphanumeric characters and compare the remaining characters.

## Approach

1. Set `i` at the beginning of the string.
2. Set `j` at the end of the string.
3. Continue while `i < j`.
4. If `s[i]` is not a letter or number, move `i` forward.
5. If `s[j]` is not a letter or number, move `j` backward.
6. If both characters are valid, convert them to lowercase using `tolower()`.
7. Compare the two characters.
8. If they are different, return `false`.
9. If they are the same, move both pointers toward the center.
10. If all characters match, return `true`.

## Dry Run

**Input:**

`A man, a plan, a canal: Panama`

Start:

`i → A`
`j → a`

Both are alphanumeric.

`tolower('A') == tolower('a')`

So they match.

Move both pointers inward.

---

Next valid characters:

`i → m`
`j → m`

They match.

---

Continue comparing:

`a == a`
`n == n`
`a == a`
`p == p`
`l == l`
`a == a`
`n == n`
`a == a`
`c == c`
`a == a`
`n == n`
`a == a`
`l == l`
`p == p`
`a == a`
`m == m`

Characters such as spaces, `,` and `:` are skipped using `isalnum()`.

All valid characters match.

Therefore, the function returns `true`.

## Complexity

* Time Complexity: **O(n)** — Each character is checked at most once.
* Space Complexity: **O(1)** — Only two pointers and a few variables are used.
