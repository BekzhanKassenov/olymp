import itertools;

def main():
    a = int(input());
    b = int(input());
    c = int(input());

    arr = sorted([a, b, c]);
    signs = ['+', '-', '*']

    ans = None;
    for perm in itertools.permutations(arr):
        for sign1 in signs:
            for sign2 in signs:
                s = str(perm[0]) + sign1 + str(perm[1]) + sign2 + str(perm[2]);
                val = eval(s);
                if ans == None or val < ans:
                    ans = val;

    print(ans);

main();