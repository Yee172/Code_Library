for x in map(int, __import__('sys').stdin.readlines()):
    if x < 2:
        print(x)
    else:
        print(x - 1 << 1)
