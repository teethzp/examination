#!/usr/bin/env escript

% 二叉树前序遍历
preorder({Value, [], []}) ->
    [Value];
preorder({Value, [], R}) ->
    {V2, L2, R2} = R,
    [Value] ++ preorder({V2, L2, R2});
preorder({Value, L, []}) ->
    {V2, L2, R2} = L,
    [Value] ++ preorder({V2, L2, R2});
preorder({Value, L, R}) ->
    {V2, L2, R2} = L,
    {V3, L3, R3} = R,
    [Value] ++ preorder({V2, L2, R2}) ++ preorder({V3, L3, R3}).

test() ->
    L1L = {4, [], []},
    L1R = {5, [], []},
    L1 = {2, L1L, L1R},
    R1 = {3, [], []},
    preorder({1, L1, R1}).

main([]) ->
    R = test(),
    io:format("~p~n", [R]).
