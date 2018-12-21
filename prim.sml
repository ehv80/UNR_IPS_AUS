open Array2
open Array

val INF = 1000000000
val C = Array2.fromList [
                   [0,0,0,0,0,0,0],
		   [INF, 0,6,1,5,INF,INF],
		   [INF, 6, 0, 5,INF,3, INF],
		   [INF, 1, 5, 0, 5, 6, 4],
		   [INF, 5, INF, 5, 0, INF, 2],
		   [INF, INF, 3, 6, INF, 0, 6],
		   [INF, INF, INF, 4, 2, 6, 0] ]
val Mcercano = Array.fromList [0, 0, 1, 1, 1, 1, 1, 1]
val Mcosto   = Array.fromList [INF,INF, 6, 1, 5, INF, INF]

val k = ref 0
val n = Array.length(Mcosto) -1 ;

		   
fun minimo_costo () = 
	let 
		val min = ref INF;
		val i = ref 2;
	in
	while !i <= n do (
		if Array.sub(Mcercano, !i) <> 0 andalso Array.sub(Mcosto, !i) < !min then (
			min := Array.sub(Mcosto, !i);
			k   := !i )
		else ();
		i := !i + 1
	)
	end
			
fun prim() =
let 
	val j = ref 2;
	val m = ref 2 
	
in
	while !j <= n do (
		minimo_costo ();
		print ("(" ^ makestring(!k) ^ "," ^
			makestring(Array.sub(Mcercano, !k)) ^ ")  --> " ^
			makestring (Array.sub(Mcosto, !k)) ^ "\n");
		Array.update(Mcosto, !k, INF);
		Array.update(Mcercano, !k, 0);
		m := 2;
		while !m <= n do ( 
			if Array2.sub(C, !k, !m) < Array.sub(Mcosto, !m) andalso Array.sub(Mcercano, !m) <> 0 then (
				Array.update(Mcosto, !m, Array2.sub(C, !k, !m));
				Array.update(Mcercano, !m , !k) )
			else ();
			m := !m + 1
		);
		j := !j + 1
	)
end
