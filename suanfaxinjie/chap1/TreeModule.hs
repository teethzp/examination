-- module TreeModule(Tree(..))

-- 定义二叉树节点结构 Tree
-- = 左端是类型的名称（类型构造器），右端叫值构造器Value Constructor（明确了该类型可能的值）
-- 类型构造器和值构造器的首字母必须大写
-- 值构造器的本质是一个函数，可以返回一个类型的值
-- 这里a是类型参数，表示任意类型 data Tree a 说明Tree这个数据类型只有一个类型参数
-- 有一个以上值构造器的数据类型称为代数数据类型algebraic data type
-- 这里不需要定义Node这个数据类型吗？？
data Tree a = Empty | Node (Tree a) a (Tree a)

-- 插入一个节点
insert Empty k = Node Empty k Empty
insert (Node l x r) k | k < x  = Node (insert l k) x r
                      | otherwise = Node l x (insert r k)
