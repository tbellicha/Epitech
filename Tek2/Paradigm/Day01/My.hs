module My where

mySucc :: Integer -> Integer
mySucc x = x + 1

myIsNeg :: Integer -> Bool
myIsNeg x = x < 0

myAbs :: Int -> Int
myAbs x | x >= 0    = x
        | otherwise = -x

myMin :: Int -> Int -> Int
myMin a b | a > b    = b
        | otherwise  = a

myMax :: Int -> Int -> Int
myMax a b | a < b    = b
        | otherwise  = a

myTuple :: a -> b -> (a , b )
myTuple a b = (a, b)


myTruple :: a -> b -> c -> (a , b, c)
myTruple a b c = (a, b, c)

myFst :: (a , b ) -> a
myFst (a, b) = a

mySnd :: (a , b ) -> b
mySnd (a, b) = b

mySwap :: (a , b ) -> (b , a )
mySwap (a, b) = (b, a)

myHead :: [ a ] -> a
myHead (a:_) = a
myHead [] = error "Empty list."

myTail :: [ a ] -> [ a ]
myTail (x:xs) = xs
myTail [] = error "Empty list."

myLength :: [a] -> Int
myLength [] = 0
myLength (_:xs) = 1 + myLength xs

myNth :: [ a ] -> Int -> a
myNth [] _ = error "Empty list."
myNth (x:xs) y  | y <= 0 = x
                | otherwise = myNth xs (y-1)

myTake :: Int -> [ a ] -> [ a ]
myTake _ [] = error "Empty list."
myTake 0 _ = []
myTake y (x:xs) | myLength (x:xs) < y = (x:xs)
                | y <= 0 = error "Negative index"
                | otherwise = x : myTake (y-1) xs

myDrop :: Int -> [ a ] -> [ a ]
myDrop n [] = []
myDrop 0 xs = xs
myDrop y (x:xs)  | y <= 1 = xs
                 | otherwise = myDrop (y-1) xs

myAppend :: [ a ] -> [ a ] -> [ a ]
myAppend (x:xs) y = x : myAppend xs y
myAppend[] x = x

myReverse :: [ a ] -> [ a ]
myReverse [] = []
myReverse (x:xs) = myAppend(myReverse xs) [x]

myInit :: [ a ] -> [ a ]
myInit [] = error "Empty list."
myInit (x:xs) = myReverse (myTail (myReverse (x:xs)))

myLast :: [ a ] -> a
myLast [] = error "Empty list."
myLast (x:xs) = myHead (myReverse (x:xs))

myZip :: [ a ] -> [ b ] -> [( a , b ) ]
myZip _ [] = []
myZip [] _ = []
myZip (x:xs) (y:ys) = (x, y) : myZip xs ys

myUnzip :: [( a , b ) ] -> ([ a ] , [ b ])
myUnzip x = res [] [] x
    where
        res :: [a] -> [b] -> [(a,b)] -> ([a], [b])
        res a b [] = (a, b)
        res a b (x:xs) = res (myAppend a [myFst(x)]) (myAppend b [mySnd(x)]) xs

myMap :: ( a -> b ) -> [ a ] -> [ b ]
myMap _ [] = []
myMap function (x:xs) = function (x) : myMap function (xs)

myFilter :: ( a -> Bool ) -> [ a ] -> [ a ]
myFilter _ [] = []
myFilter function (x:xs) | function x = x : myFilter function xs
                         | otherwise = myFilter function xs

myFoldl :: ( b -> a -> b ) -> b -> [ a ] -> b
myFoldl _ b [] = b
myFoldl function b (x:xs) = myFoldl function (function b x) xs

myFoldr :: ( a -> b -> b ) -> b -> [ a ] -> b
myFoldr _ b [] = b
myFoldr function b x = myFoldr function (function (myLast x) b) (myInit x)

myPartition :: ( a -> Bool ) -> [ a ] -> ([ a ] , [ a ])
myPartition function [] = ([], [])
myPartition function xs = (myFilter function xs, myFilter (myNot function) xs)

myNot :: (a -> Bool) -> a -> Bool
myNot function a | function a = False
                 | otherwise = True

myQuickSort :: ( a -> a -> Bool ) -> [ a ] -> [ a ]
myQuickSort function [] = []
myQuickSort function (x:xs) = myAppend higher $ myAppend [x] lower
        where
                compare = function x
                lower = myQuickSort function (myFilter compare xs)
                higher = myQuickSort function (myFilter (myNot compare) xs)