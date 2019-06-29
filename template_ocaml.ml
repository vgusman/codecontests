module Big = struct

  let ( ++ ) = Int64.add
  let ( -- ) = Int64.sub
  let ( ** ) = Int64.mul
  let ( // ) = Int64.div

end

module Helper = struct

  let read_array () =
    let n = Scanf.scanf "%d\n" (fun x -> x) in
    n, Array.init n (fun _ -> Scanf.scanf "%d " (fun x -> x))

  type debug_type =
    | Int of int

  let debug = function
    | Int x -> Printf.printf "%d " x

end

let () =
  let open Helper in
  ()
;;
