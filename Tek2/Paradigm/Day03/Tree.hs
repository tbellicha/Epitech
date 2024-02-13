data Tree a = Empty | Node (Tree a) a (Tree a)
    deriving (Show)

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree x Empty = Node Empty x Empty
addInTree x (Node t1 v t2)
    | v == x = Node t1 v t2
    | v  < x = Node t1 v (addInTree x t2)
    | v  > x = Node (addInTree x t1) v t2

instance Functor Tree where
    fmap f Empty = Empty
    fmap f (Node t1 x t2) = Node (fmap f t1) (f x) (fmap f t2)

listToTree :: Ord a => [a] -> Tree a
listToTree list = foldr addInTree Empty list

treeToList :: Tree a -> [a]
treeToList Empty = []
treeToList (Node t1 x t2) = x : a ++ b
    where   a = (treeToList t1)
            b = (treeToList t2)