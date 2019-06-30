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
  let open Big in
  let t = read_int ~endl:() () in
  loop t (fun _ ->
      let n = read_long () in
      let s = read_long () in
      let t = read_long () in
      let x = s ++ t -- n in
      let s = s -- x in
      let t = t -- x in
      debug (Long ((max s t)++1L))
    )
;;
