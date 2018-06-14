print(['NO', 'YES'][(lambda s: any(''.join(x) in s for x in __import__('itertools').permutations('ABC')))(input())])
