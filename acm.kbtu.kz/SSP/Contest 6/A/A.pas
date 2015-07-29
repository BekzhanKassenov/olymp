var d: array[-2000..2000,-2000..2000] of longint;
s: string;
i,j,n:longint;
begin
    read(s);
    
    n := length(s);
    d[0][0]:=1;
    
    if (n mod 2 = 1) then
        begin
            writeln(0);
            exit;
        end;
    
    for i:=0 to n do
        begin
            for j:=0 to n do
                begin
                    if (s[i]='(') then
                        d[i,j] := d[i-1,j-1];
                    if (s[i]=')') then
                        d[i,j] := d[i-1,j+1];
                    if (s[i]='?') then
                        d[i,j] := (d[i-1,j+1] + d[i-1,j-1]) mod 301907;
                end;
       end;
    writeln(d[n][0]);

end.
