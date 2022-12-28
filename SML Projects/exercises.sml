(** IT 327 Kendall Carter HW 2_14 **)
fun cube n =
   n * n * n;

fun fourth (a) =
   tl(tl(tl(hd [a])));  

fun cycle1 (a) =
   tl(a) @ [hd(a)];   

fun maxhelper (largest, intList) =
  if null(intList) then largest else 
    if largest> hd(intList) then maxhelper(largest,tl(intList)) else
      maxhelper(hd(intList), tl(intList));

fun max theList = 
  maxhelper (0, theList);
  


