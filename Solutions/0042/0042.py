import json

def m():
    def isTriangleNumber(n):
        for i in range(1, 100):
            triangleNum = .5 * i * (i+1)
            if triangleNum > n: return False
            elif triangleNum == n: return True
        return False

    with open('Solutions/0042/words.json', 'r') as file:
        f = file.read()
        file.close()
    words = json.loads(f)

    ans = 0
    for v in words:
        wordSum = 0
        for c in v:
            wordSum += ord(c)-64
        if isTriangleNumber(wordSum):
            ans += 1

    print(ans)


if __name__ == '__main__':
    m()