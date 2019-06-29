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
  loop t
    (fun _ ->
       let a0, b0, c0, a1, b1, c1 = Scanf.scanf "%Ld %Ld %Ld %Ld %Ld %Ld\n" (fun q w e r t y -> q, w, e, r, t, y) in
       if a0 = a1 && b0 = b1 && c0 = c1 then debug (Int 0)
       else
         let all_zeros = a0 = 0L && b0 = 0L && c0 = 0L in
         let all_goal_zeros = a1 = 0L && b1 = 0L && c1 = 0L in
         let x, y, z = Int64.abs (a0 -- a1), Int64.abs (b0 -- b1), Int64.abs (c0 -- c1) in
         let p1, p2, p3 = Int64.rem x 2L = 0L, Int64.rem y 2L = 0L, Int64.rem z 2L = 0L in
         let res =
           if all_zeros then
             if (p1 && p2 && p3) || (not (p1 || p2 || p3)) then 2 else 1
           else
           if all_goal_zeros then
             if (p1 && p2 && p3) || (not (p1 || p2 || p3)) then 2 else 1
           else
           if (p1 && p2 && p3) || (not (p1 || p2 || p3)) then 0 else 1
         in
         debug (Int res)
    )
;;
