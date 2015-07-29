var s:string; n:longint; 
begin 
assign(input, 'input.txt'); reset(input); 
assign(output, 'output.txt'); rewrite(output); 
readln(s); 
readln(n); 
if (s='School') and (n mod 2=0) then writeln('No'); 
if (s='School') and (n mod 2=1) then writeln('Yes'); 
if (s='Home') and (n mod 2=0) then writeln('Yes'); 
if (s='Home') and (n mod 2=1) then writeln('Yes'); 
end.