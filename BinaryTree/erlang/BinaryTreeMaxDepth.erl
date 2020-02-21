#!/usr/bin/env escript

% 求二叉树的最大深度
binary_tree_depth({[], []}, {[], []}) ->
    1;
binary_tree_depth(L, {[], []}) ->
    {LL, LR} = L,
    1 + binary_tree_depth(LL, LR);
binary_tree_depth({[], []}, R) ->
    {RL, RR} = R,
    1 + binary_tree_depth(RL, RR);
binary_tree_depth(L, R) ->
    {LL, LR} = L,
    {RL, RR} = R,
    D_L = binary_tree_depth(LL, LR),
    D_R = binary_tree_depth(RL, RR),
    case D_L > D_R of
        true -> 1 + D_L;
        false -> 1 + D_R
    end.

test() ->
    N4 = {{[], []}, {[], []}},
    N2 = {N4, {[], []}},
    N3 = {{[], []}, {[], []}},
    Result = binary_tree_depth(N2, N3),
    io:format("~p~n", [Result]).

main([]) ->
    test().