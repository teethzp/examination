-- module TreeModule(Tree(..))

-- 定义二叉树节点结构 Tree
-- = 左端是类型的名称（类型构造器），右端叫值构造器Value Constructor（明确了该类型可能的值）
-- 类型构造器和值构造器的首字母必须大写
-- 值构造器的本质是一个函数，可以返回一个类型的值
-- 这里a是类型参数，表示任意类型 data Tree a 说明Tree这个数据类型只有一个类型参数
-- 有一个以上值构造器的数据类型称为代数数据类型algebraic data type
-- Node是构造函数
data Tree a = Empty | Node (Tree a) a (Tree a) -- data Tree a中Tree是想定义的数据类型，a是任意一种现有的数据类型；Node是构造函数；Node后面是构造函数的参数，构造函数的返回值类型就是定义的数据类型

-- 插入一个节点 通过insert函数可以构建一个二叉搜索树
insertToBST Empty k = Node Empty k Empty
insertToBST (Node l x r) k | k < x  = Node (insertToBST l k) x r
                      | otherwise = Node l x (insertToBST r k)

-- 遍历树：中序遍历一个二叉搜索树为一个List，得到从小到大排序的序列
bstToList Empty = []
bstToList (Node l x r) = bstToList l ++ [x] ++ bstToList r -- 函数入参是Tree。Node是构造函数，l x r是构造函数的三个入参

-- 树排序
-- 先根据无序的序列生成一棵二叉搜索树，再遍历
-- sort(X)=bToList(formList(X))
-- formList(X)=foldL(insert, Empty, X) 即 formList = foldL insert Empty   ：partial application形式
-- formList xs = foldL(insertToBST, Empty, xs)

-- 搜索
bstLookup Empty _ = Empty
bstLookup t@(Node l x r) k | k == x = t
                           | k < x = bstLookup l k
                           | otherwise = bstLookup r k

-- 最小值：左子树为空时，这个节点就是最小值
bstMin (Node Empty x _) = x
bstMin (Node l x _) = bstMin l