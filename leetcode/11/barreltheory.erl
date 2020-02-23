#!/usr/bin/env escript

% leetcode 11
% use two pointer can get better answer (only one xunhun)

% 思路：
% 有点像组合，向DFS靠
% 怎么降维，一直降到可以直接得到解（两个元素）
% F[H|T] = max { ~ , F[T] }

% 比较两个数的大小，返回小的
smaller(Num1, Num2) ->
    case Num1 > Num2 of 
        true -> Num2;
        false -> Num1
    end.

% 比较两个数的大小，返回大的
bigger(Num1, Num2) ->
    case Num1 > Num2 of 
        true -> Num1;
        false -> Num2
    end.

% compute函数是找出固定一个点时（该点为第一个参数），可以装的最多的水，第三个参数是为了判断动点相对固定点的位置
% 第一次调用compute时，第三个参数是1
compute(_, [], _) ->
    0;
compute(A1, [B|Remain], Index) ->
    Temp = Index * smaller(A1, B),
    bigger(Temp, compute(A1, Remain, Index +1)). % 这里传入compute的还是A1，因为这次计算，不动的点一直是A1

% 求木桶可以装的最多的水
func([]) ->
    0;
func([_]) -> % 递归退出条件
    0;
func([A|Tail]) ->
    R_Temp = compute(A, Tail, 1),
    R_Temp2 = func(Tail),
    bigger(R_Temp, R_Temp2).

% 测试用例
test() ->
    Result = func([1, 8, 6, 2, 5, 4, 8, 3, 7]),
    io:format("Result:~p ~n", [Result]).

main([]) ->
    test().