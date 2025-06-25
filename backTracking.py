#String Permutations
def stringPermutation(s,ans):
  if len(s) == 0:
    print(ans)
    return
  
  for i in range(len(s)):
    ch = s[i]
    left = s[:i]
    right = s[i+1:]
    rest = left+right
    stringPermutation(rest, ans+ch)


stringPermutation('ABC', '')