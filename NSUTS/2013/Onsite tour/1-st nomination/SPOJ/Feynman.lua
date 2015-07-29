while true do
    n = io.read("*n"); 
    if 1 * n == 0 then
        break;
    end
    ans = 0;
    for i = 1, n do
        ans = ans + (n - i + 1) * (n - i + 1);
    end
    print(ans);
end