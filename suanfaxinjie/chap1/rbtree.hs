data Color = R | B

data RBTree a = Empty 
            | Node Color (RBTree a) a (RBTree a)

-- 插入操作
-- 先做一般的二叉搜索树的插入insert，然后如果不满足红黑树条件（4种情况）则做balance操作使之平衡，最后将根节点变成黑色makeBlack
-- 刚插入节点一律染成红色（除非是根节点），则可能会出现需要balance的情况，这种情况一定是因为父子节点出现了2个红色（因为其他四个条件都没有被破坏所以一定满足）
-- 而父子节点出现2个红色只有四种情况：两个红色在左子树或两个红色在右子树再分别是左儿子或右儿子，因此是2*2四种可能
-- 这四种可能又都可以统一变换成一种形式 a x b y c z d的一种组合（中序遍历）（传统的红黑树不是将4种情况转换成统一的形式）
insert t x = makeBlack $ ins t where  -- 公式：insert(T, k) = makeBlack(ins(T,k))其中T是红黑树根节点，k是被插入的值，insert函数分两步：插入操作和将根节点涂黑操作
    ins Empty = Node R Empty x Empty -- 补充解释函数ins：根节点为空节点的情况
    ins (Node color l k r)  -- where补充解释函数ins：根节点非空的情况，k是根节点的值
        | x < k = balance color (ins l) k r -- 插入到左子树
        | otherwise = balance color l k (ins r) -- 插入到右子树 ins操作是二叉搜索树插入操作加上balance操作
    makeBlack(Node _ l k r) = Node B l k r -- where补充解释makeBlack函数：不管这个节点是什么颜色，最后都涂成黑色

balance B (Node R (Node R a x b) y c) z d = -- 需要balance：两个红色节点是左子树父亲和左儿子
    Node R (Node B a x b) y (Node B c z d)

balance B (Node R a x (Node R b y c)) z d = -- 需要balance：两个红色节点是左子树父亲和右儿子
    Node R (Node B a x b) y (Node B c z d)

balance B a x (Node R b y (Node R c z d)) = -- 需要balance：两个红色节点是右子树父亲和右儿子
    Node R (Node B a x b) y (Node B c z d)

balance B a x(Node R (Node R b y c) z d) = -- 需要balance：两个红色节点是右子树和左儿子
    Node R (Node B a x b) y (Node B c z d)

balance color l k r = Node color l k r -- 其他情况下不需要做任何变化