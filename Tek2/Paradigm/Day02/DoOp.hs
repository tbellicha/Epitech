import My
import Data.Char
import Control.Monad.State

----------------------------------------------------------------------------------

myElem :: Eq a => a -> [a] -> Bool
myElem n [] = False
myElem n (x:xs)
    | x == n = True
    | otherwise = myElem n xs

----------------------------------------------------------------------------------

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv num divider = Just (num `div` divider)

----------------------------------------------------------------------------------

safeNth :: [ a ] -> Int -> Maybe a
safeNth [] n = Nothing
safeNth (x:xs) 0 = Just x
safeNth (x:xs) n | n < 0 = Nothing
                 | n > length (x:xs) = Nothing
                 | otherwise = Just (myNth xs (n - 1))

----------------------------------------------------------------------------------

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc n = fmap succ n

----------------------------------------------------------------------------------

myLookup :: Eq a => a -> [( a , b ) ] -> Maybe b
myLookup n [] = Nothing
myLookup n (x:xs) | n == myFst x = Just (mySnd x)
                  | otherwise = myLookup n xs

----------------------------------------------------------------------------------

maybeDo :: ( a -> b -> c ) -> Maybe a -> Maybe b -> Maybe c
maybeDo _ Nothing Nothing = Nothing
maybeDo function a b = Just(function) <*> a <*> b

----------------------------------------------------------------------------------

myIsDigit :: Char -> Bool
myIsDigit x | x `elem` "0123456789-" = True
            | otherwise = False

readInt :: [ Char ] -> Maybe Int
readInt [] = Nothing
readInt cs = case all myIsDigit cs of
    True -> Just (read cs::Int)
    False -> Nothing

----------------------------------------------------------------------------------

getLineLength :: IO Int
getLineLength = fmap length getLine

----------------------------------------------------------------------------------

printAndGetLength :: String -> IO Int
printAndGetLength xs =
    putStrLn xs >>
    return (length xs)

----------------------------------------------------------------------------------

printBox :: Int -> IO ()
printBox x  | x <= 0 = return () 
            | otherwise = computeBox x

computeBox :: Int -> IO ()
computeBox x =
    printTopBot x >>
    printMiddleLines (fillLineTab ((x-1)*2) ((x-1)*2)) >>
    printTopBot x

printTopBot :: Int -> IO ()
printTopBot 0 = return ()
printTopBot x =
    putStr ("+") >> 
    putStr (replicate ((x-1)*2) '-') >> 
    putStrLn ("+")

printMiddleLines :: [String] -> IO ()
printMiddleLines [] = return ()
printMiddleLines (x:xs) =
    putStr x >>
    putStrLn ("|") >>
    printMiddleLines xs

fillLineTab :: Int -> Int ->[String]
fillLineTab 0 _ = []
fillLineTab x y | x <= 0 = []
                | otherwise = ('|':(replicate y ' ')):fillLineTab (x - 1) y

----------------------------------------------------------------------------------

concatLines :: Int -> IO String
concatLines iterations = concat <$> replicateM iterations getLine

----------------------------------------------------------------------------------