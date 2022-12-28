rev_filter([],_[]).
rev_filter([E|Tail],E,Result):-
    rev_filter(Tail,E,Result).
rev_filter ([Head|Tail],E,Result) :-
    not(Head=E),
    rev_filter(Tail,E,[Head::TailResult]).

rev_filter([],_[]).
rev_filter([E|Tail],E,Result):-
    rev_filter(Tail,E,Result).
rev_filter ([Head|Tail],E,Result) :-
    not(Head=E),
    rev_filter(Tail,E,TailResult),
    append(TailResult,[Head],Result).

fun halve nil = (nil, nil)
|   halve [a] = ([a], nil) 
|   halve (a :: b :: cs) =
    let
        val (x,y) = halve cs
    in
        (a :: x, b :: y)
    end ;

fun halve thelist=
        let
            fun half (nil, sofar)
|   halve [a] = ([a], nil) 
|   halve (a :: b :: cs) =
    let
        val (x,y) = halve cs
    in
        (a :: x, b :: y)
    end ;

