chars ← ⍎⍞
lines ← ⍎⍞
empty ← +/{+/⍞∊'.'} ¨⍳lines

⎕ ← ⊃⊃empty÷(lines×chars)