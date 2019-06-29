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
  loop t (fun _ ->
      let chef = Scanf.scanf "%Ld %Ld %Ld\n" (fun x y k -> Int64.rem ((x ++ y) // k) 2L = 0L) in
      if chef then Printf.printf "Chef\n" else Printf.printf "Paja\n"
    )
;;
