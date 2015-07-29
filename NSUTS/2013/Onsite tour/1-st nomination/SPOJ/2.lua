primes = {};  
primesSize = 0;
sieve = {};


function fillSieve(n) 
    for i = 2, n do
        sieve[i] = true
    end
    sieve[1] = false;
    for i = 2, n do                          
        if sieve[i] == true then
            primes[primesSize] = i;
            primesSize = primesSize + 1;
            j = i * i
            while j <= n do
                sieve[j] = false;
                j = j + i

            end
        end
        
    end
end

MAXN = 1000000

fillSieve(MAXN);


function prime(n)
    if (n <= MAXN) then
        return sieve[n]
    end
    
    for i = 0, primesSize - 1 do
        local tmp = primes[i];
        if tmp*tmp > n then return true end
        if n % tmp == 0 then return false; 
        end
    end
    
    return true
     
end

t = io.read("*n");

          
while t > 0 do
    n, m = io.read("*n", "*n");
    t = t - 1;
    
    if 2 >= n and 2 <= m then
        io.write("2\n");  
    end

    if n % 2 == 0 then
        n = n + 1;
    end

    while n <= m  do                
        if prime(n) then
            io.write(n .. "\n");
        end
        n = n + 2;
    end
    io.write("\n");
end