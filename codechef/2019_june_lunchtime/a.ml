(* TIME LIMIT EXCEEDED! *)

module Big = struct

  let ( ++ ) = Int64.add
  let ( -- ) = Int64.sub
  let ( ** ) = Int64.mul
  let ( // ) = Int64.div

end

module Helper = struct

  let read_int () = Scanf.scanf "%d\n" (fun x -> x)
  let read_int_array n = Array.init n (fun _ -> Scanf.scanf "%d " (fun x -> x))
  let read_char_array n =
    let res = Array.init n (fun _ -> Scanf.scanf "%c" (fun x -> x)) in
    Scanf.scanf "\n" (fun _ -> ());
    res

  type debug_type =
    | Int of int
    | LInt of Int64.t

  let debug = function
    | Int x -> Printf.printf "%d\n" x
    | LInt x -> Printf.printf "%Ld\n" x

  type 'a return = { return : 'b . 'a -> 'b }

  let with_return (type t) (f : _ -> t) =
    let module M = struct exception Return of t end in
    let return = { return = (fun x -> raise (M.Return x)); } in
    try f return with M.Return x -> x
    (* with_return (fun r -> do_somthing; if return_condition then r.return (); *)

  let loop n f =
    for i = 0 to n - 1 do
      f i;
    done

  let find_nb f a =
    let res = ref 0 in
    Array.iteri (fun i x -> if f i x then incr res) a;
    !res

end

let () =
  let open Helper in
  let open Big in
  let t = read_int () in
  let zeros = Hashtbl.create 8 in
  loop t
    (fun _ ->
       let n, q = Scanf.scanf "%Ld %d\n" (fun n q -> n, q) in
       let s = ref 0L in
       Hashtbl.clear zeros;
       loop q
         (fun _ ->
            let tp = Scanf.scanf "%d " (fun x -> x) in
            if tp = 1 then begin
              let j = Scanf.scanf "%Ld\n" (fun x -> x ++ !s) in
              Hashtbl.add zeros j ();
            end
            else
              let l, r = Scanf.scanf "%Ld %Ld\n" (fun x y -> x ++ !s, y ++ !s) in
              let c = ref r in
              while (!c >= l && Hashtbl.mem zeros !c) do
                c:= !c -- 1L;
              done;
              if !c < l then debug (Int 0) else
                begin
                  debug (LInt !c);
                  s := Int64.rem (!s ++ !c) n;
                end
         )
    )
;;


(* let () = *)
(*   let open Helper in *)
(*   let open Big in *)
(*   let t = read_int () in *)
(*   loop t *)
(*     (fun _ -> *)
(*        let n, q = Scanf.scanf "%Ld %d\n" (fun n q -> n, q) in *)
(*        let s = ref 0L in *)
(*        let zeros = Array.make (Int64.to_int n + 1) 0 in *)
(*        loop q *)
(*          (fun _ -> *)
(*             let tp = Scanf.scanf "%d " (fun x -> x) in *)
(*             if tp = 1 then begin *)
(*               let j = Scanf.scanf "%Ld\n" (fun x -> x ++ !s) in *)
(*               let ji = Int64.to_int j in *)
(*               zeros.(ji) <- max 1 zeros.(ji); *)
(*               let k = ref (ji + 1) in *)
(*               if (Int64.of_int !k <= n) then begin *)
(*                 while (Int64.of_int !k <= n && zeros.(!k) <> 0) do *)
(*                   zeros.(!k) <- zeros.(!k) + 1; *)
(*                   incr k; *)
(*                 done; *)
(*               end *)
(*             end *)
(*             else *)
(*               let l, r = Scanf.scanf "%Ld %Ld\n" (fun x y -> x ++ !s, y ++ !s) in *)
(*               let yy = r -- Int64.of_int zeros.(Int64.to_int r) in *)
(*               if yy < l then debug (Int 0) else *)
(*                 begin *)
(*                   debug (LInt yy); *)
(*                   s := Int64.rem (!s ++ yy) n; *)
(*                 end *)
(*          ) *)
(*     ) *)
(* ;; *)
