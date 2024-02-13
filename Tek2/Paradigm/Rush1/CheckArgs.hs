{-# OPTIONS_GHC -Wno-overlapping-patterns #-}
module CheckArgs where

import Data.Char ( isDigit )
import Data.Maybe ( isJust )
import SwitchList (PSList (PSList))

readInt :: String -> Maybe Int
readInt [] = Nothing
readInt (x:xs) = if x == '-' && all isDigit  xs
    || all isDigit (x:xs) then Just (read (x:xs) :: Int) else Nothing

isSorted :: (Ord a) => [a] -> Bool
isSorted [] = True
isSorted [x] = True
isSorted (x:y:xs) = x <= y && isSorted (y:xs)

isSortedPSL :: PSList -> Bool
isSortedPSL (PSList a b) = isSorted a

diRes :: Bool -> IO ()
diRes True = putStrLn "OK"
diRes False  = putStrLn "KO"

checkArgsType :: [String] -> Bool
checkArgsType [] = True
checkArgsType (x:xs) 
    | isJust (readInt x) && checkArgsType xs = True
    | otherwise = False

argsToInt :: [String] -> [Int]
argsToInt = map read

checkOperations :: [String] -> Bool
checkOperations [] = True
checkOperations (x:xs) 
    | validSign x && checkOperations xs = True 
    | otherwise = False

validSign :: String -> Bool
validSign x = x `elem` 
    ["sa", "sb", "sc", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"]
validSign _ = False