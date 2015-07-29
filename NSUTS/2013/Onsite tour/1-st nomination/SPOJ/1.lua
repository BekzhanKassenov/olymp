r = 0;
while (r ~= 42) do
	r = 1*io.read();
	if r == 42 
		then break
	end
	io.write(r .. "\n");
end     