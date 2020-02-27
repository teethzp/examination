-- Int是平衡因子
data AVLTree a = Empty
                | Br (AVLTree a) a (AVLTree a) Int