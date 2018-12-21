(*Algoritmo de Floyd*)

load "Array2";
open Array2;

val c=fromList [[0,0,0,0],[0,0,8,5],[0,3,0,1000000],[0,1000000,2,0]];

fun floyd()=
let
	val i=ref 1
	val j=ref 1
	val k=ref 1
in
	while !k <= 3 do(
		i:=1;
		while !i <= 3 do(
			j:=1;
			while !j <= 3 do(
				if sub(c,!i,!j) > (sub(c,!i,!k) + sub(c,!k,!j)) then
					update(c,!i,!j, sub(c,!i,!k) + sub(c,!k,!j))
				else();
				j:= !j+1
			);
			i:= !i+1
		);
		k:= !k+1
	)
end

fun muestra()=
let
	val i=ref 1
	val j=ref 1
in
	while !j <= 3 do(
		i:=1;
		while !i <= 3 do(
			print(makestring(sub(c,!j,!i))^",");
			i:= !i+1
		);
		print "\n";
		j:= !j+1
	)
end
