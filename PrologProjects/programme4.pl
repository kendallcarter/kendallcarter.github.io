% ####################################################################
% Program 4 
%
% IT 327 Mary Elaine Califf
%
% Kendall Carter
% 
% #########################################################

lastName(blum).
lastName(brown).
lastName(steel).
lastName(jones).

hotel(star).
hotel(moon).
hotel(sun).

show(hill).
show(moon)).
show(nero).
show(star).

couple(charles,grace,brown).

ordered([]).
ordered([_]).
ordered([First,Second|Rest]):-First=>Second,ordered([Second|Rest]).

solve(Blum,Brown,Steel,Jones):-
    all_members([H],L2) :- member(H,L2).
    all_members([H|T],L2) :- member(H,L2), all_members(T, L2).
    %Setting up each couple
    Blum=[Blum_male, Blum_female, Blum_hotel, Blum_show],
    Brown=[Brown_male, Brown_female, Brown_hotel, Brown_show],
    Steel=[Steel_male, Steel_female, Steel_hotel, Steel_show],
    Jones=[Jones_male, Jones_female, Jones_hotel, Jones_show],
    %Hint 
    all_members([1,2,3,4], [Eilen_place, Ada_place, Vera_place, Jenny_place]),

    

countOdd/2([TheList],NumOddValues):-
    length(TheList, Count),
    Count>=0->
    {
        Count is Count+1,
        Count2 is mod(Count,2),
        Count2=\=0->


    }
    

countOddTR([],numOddValues):-
    male(X).

member(X, [X|_]).
member(X, [_|L]) :- member(X, L).
