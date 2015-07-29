var a,N,i,min: longint;
begin
readln(n);
min := 2000000000;
for i := 1 to n do 
begin
	read(a);
	if min > a then 
		min := a; 
end;
write(min);
end.