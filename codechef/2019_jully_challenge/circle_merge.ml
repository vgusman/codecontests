(* Computing (x MOD y) inside the deepest loop results in TLE! Using 3 loops instead works. *)

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
    (* Scanf.scanf "\n" (fun _ -> ()); *)
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
  let sums = Array.init 400 (fun _ -> Array.make 400 0L) in
  let p = Array.init 400 (fun _ -> Array.make 400 0L) in
  loop t
    (fun _ ->
      let n = read_int ~endl:() () in
      let a = read_long_array n in
      loop n  
        (fun i ->
          p.(i).(i)<-0L;
          let c = ref 0L in
          loop n
          (fun j ->
            let jj = (i + j) mod n in
            c := !c ++ a.(jj);
            sums.(i).(jj) <- !c            
          )
        );
      loop (n - 1) (fun k ->
          loop n (fun i ->
            let j = i + k + 1 in 
            let jj = j mod n in
            let tmp = ref p.((i+1) mod n).(jj) in
            
            if j < n then begin
              for l = i to j-1 do
                let x = p.(i).(l) ++ p.(l+1).(jj) in
                if x < !tmp then tmp := x;  
              done
            end else if j = n then begin
              for l = i to j-2 do
                let x = p.(i).(l) ++ p.(l+1).(jj) in
                if x < !tmp then tmp := x;  
              done;
              let x = p.(i).(n - 1) ++ p.(0).(jj) in
              if x < !tmp then tmp := x;
            end else begin 
              for l = i to n-2 do
                let x = p.(i).(l) ++ p.(l+1).(jj) in
                if x < !tmp then tmp := x;  
              done;
              let x = p.(i).(n - 1) ++ p.(0).(jj) in
              if x < !tmp then tmp := x;
              for l = 0 to j-1-n do
                let x = p.(i).(l) ++ p.(l+1).(jj) in
                if x < !tmp then tmp := x;  
              done;
            end;
            p.(i).(jj) <- sums.(i).(jj) ++ !tmp;
          )
      );
      let res = ref p.(0).(n-1) in
      loop (n-1) (fun k ->
            if p.(k+1).(k) < !res then res := p.(k+1).(k);
      );
      debug (Long !res);
    )
;;
