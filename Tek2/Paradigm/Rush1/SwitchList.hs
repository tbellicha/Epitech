module SwitchList where
import Distribution.Compat.Lens (_1)

data PSList = PSList {
    lA :: [Int],
    lB :: [Int]
} deriving (Show)

swapFirst :: [a] -> [a]
swapFirst (x:y:xs) = y:x:xs
swapFirst a = a

rotateList :: [a] -> [a]
rotateList [] = []
rotateList xs | length xs < 2 = xs
    | otherwise = drop 1 xs ++ [head xs]

rotateRightList :: [a] -> [a]
rotateRightList [] = []
rotateRightList xs | length xs < 2 = xs
    | otherwise = last xs : take (length xs - 1) xs

swapBoth :: PSList -> PSList
swapBoth (PSList a b)  = PSList (swapFirst a) (swapFirst b)

rotateBoth :: PSList -> PSList
rotateBoth (PSList a b)  = PSList (rotateList a) (rotateList b)

rotateRightBoth :: PSList -> PSList
rotateRightBoth (PSList a b)  = PSList (rotateRightList a) (rotateRightList b)

putA :: PSList -> PSList
putA (PSList a []) = PSList a []
putA (PSList a b) = PSList  (head b:a) (tail b)

putB :: PSList -> PSList
putB (PSList [] b) = PSList [] b
putB (PSList a b) = PSList (tail a) (head a:b)
