⍝ For a reason I'm not sure, it has a runtime error for some testcases

f ← ⍞
s ← ⍞

p ← ' '(≠⊆⊢)s
n ← {1∊f∊⊃p[⍵]}¨⍳⍴p
{(⊃p[⍵])[⍳(n[⍵]=1) × (⍴⊃p[⍵])] ← '*'} ¨⍳⍴p
⎕ ← ⊃⍪/p,¨' '