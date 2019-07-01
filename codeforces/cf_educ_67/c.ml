(* Hacked!!! *)
(* 9 5 *)
(* 0 1 2 *)
(* 1 3 4 *)
(* 1 6 8 *)
(* 1 6 9 *)
(* 0 2 3 *)

module Big = struct

  let ( ++ ) = Int64.add
  let ( -- ) = Int64.sub
  let ( ** ) = Int64.mul
  let ( // ) = Int64.div

  let babs = Int64.abs
  let rem = Int64.rem

end

module Helper = struct

  type t_type =
    | Int of int
    | Long of Int64.t

  let read_int ?endl () =
    match endl with
    | None -> Scanf.scanf "%d " (fun x -> x)
    | Some () -> Scanf.scanf "%d\n" (fun x -> x)

  let read_long ?endl () =
    match endl with
    | None -> Scanf.scanf "%Ld " (fun x -> x)
    | Some () -> Scanf.scanf "%Ld\n" (fun x -> x)

  let read_int_array n =
    let res = Array.init n (fun _ -> Scanf.scanf "%d " (fun x -> x)) in
    Scanf.scanf "\n" (fun _ -> ());
    res

  let read_long_array n =
    let res = Array.init n (fun _ -> Scanf.scanf "%Ld " (fun x -> x)) in
    Scanf.scanf "\n" (fun _ -> ());
    res

  let read_char_array n =
    let res = Array.init n (fun _ -> Scanf.scanf "%c" (fun x -> x)) in
    Scanf.scanf "\n" (fun _ -> ());
    res

  let debug = function
    | Int x -> Printf.printf "%d\n" x
    | Long x -> Printf.printf "%Ld\n" x

  type 'a return = { return : 'b . 'a -> 'b }

  (* From Jane Street Tech Blog *)
  let with_return (type t) (f : _ -> t) =
    let module M = struct exception Return of t end in
    let return = { return = (fun x -> raise (M.Return x)); } in
    try f return with M.Return x -> x
    (* with_return (fun r -> do_somthing; if return_condition then r.return (); *)

  let loop n f = for i = 0 to n - 1 do f i; done

  let find_nb f a =
    let res = ref 0 in
    Array.iteri (fun i x -> if f i x then incr res) a;
    !res

end

let () =
  let open Helper in
  let n = read_int () in
  let m = read_int ~endl:() () in
  let a = Array.make (n+1) 1100 in
  let p = Array.make (n+1) false in
  let not_sort = ref [] in
  loop m (fun _ ->
      let t = read_int () in
      let l = read_int () in
      let r = read_int ~endl:() () in
      if t = 1 then
        for i = l to r - 1 do
          p.(i) <- true;
        done
      else
        not_sort := (l, r) :: !not_sort
    );
  let x = ref (n + 2000) in
  let i = ref 1 in
  while (!i <= n) do
    if p.(!i) then begin
      while (!i <= n) && p.(!i) do
        a.(!i) <- !x;
        incr i;
      done;
      a.(!i) <- !x;
    end;
    decr x;
    while (!i <= n) && (not p.(!i)) do incr i done;
  done;
  let ok = ref true in

  List.iter
    (fun (l, r) ->
       let k = ref l in
       while !k < r && p.(!k) do
         incr k;
       done;
       if !k = r then ok := false
       else
         a.(!k) <- a.(!k) + 1;
    ) !not_sort;

  if !ok then begin
    Printf.printf "YES\n";
    for i = 1 to n do Printf.printf "%d " a.(i) done;
  end
  else
    Printf.printf "NO\n"
;;
