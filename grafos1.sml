(* BUsqueda en Profundidad *)

open Array


val L = fromList [ [],[2],[3,4],[1], [1,3], [6,7], [2], [4,6] ]
val V = fromList [0,0,0,0,0,0,0,0]

fun bpf (i,[]) = 
	if sub(V,i) = 0 then
	   update (V,i,1)
	else ()

| bpf (i, x::xs) =
	(if sub(V,i) = 0 then (
	   	update (V,i,1);
		bpf(x, sub(L,x)))
	else ();
	bpf(i, xs))

fun explora(n)=
let
	val k = ref 1
in
	while !k <= n do (
		if sub(V,!k) = 0 then
			bpf(!k, sub(L, !k))
		else ();
		k:= !k+1)
end

fun muestra ( a , n) =
let
	val k = ref 1
in	
	while !k <= n do (
		print ( makestring (sub (a, !k)) ^ ",");
	 	k := !k +1
	)
end
