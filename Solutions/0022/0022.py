def m():
    import json
    
    with open('input.json', 'r') as file:
        f = file.read()
        file.close()
    names = json.loads(f)

    names.sort()

    ans = 0
    for k, v in enumerate(names):
        nameSum = 0
        for c in v:
            nameSum += ord(c)-64
        ans += nameSum * (k+1)
    
    print(ans)


if __name__ == '__main__':
    m()
