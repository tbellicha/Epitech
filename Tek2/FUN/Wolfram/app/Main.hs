--
-- EPITECH PROJECT, 2022
-- Project
-- File description:
-- Main
--

module Main where
import System.Environment
import System.Exit

main :: IO()
main = do
    args <- getArgs
    if null args then
        putStrLn "You must at least enter an argument." >>
        exitWith (ExitFailure 84)
    else
        if length args `mod` 2 == 1 then
            putStrLn "Incomplete param." >> exitWith (ExitFailure 84)
        else
            checkArgsAndCompute args

errorInOptions :: [String] -> Int
errorInOptions (a:b:cx)
    | a /= "--rule" && a /= "--start" && a /= "--lines" &&
        a /= "--window" && a /= "--move" = 1
    | a == "--start" && read b < 0 = 1
    | a == "--lines" && read b < 0 = 1
    | a == "--window" && read b < 0 = 1
    | null cx = 0
errorInOptions (a:b:cx) = errorInOptions cx

getOption :: [String] -> String -> Int -> Int
getOption (a:b:cx) option default_val
    | a == option = read b
    | null cx = default_val
getOption (a:b:cx) option default_val = getOption cx option default_val

checkArgsAndCompute :: [String] -> IO()
checkArgsAndCompute args = do
    let rule = getOption args "--rule" (-1)
        start = getOption args "--start" 0
        line = getOption args "--lines" 80000
        window = getOption args "--window" 80
        move = getOption args "--move" 0
    if errorInOptions args == 1 then
        putStr "Invalid option entered." >>
        exitWith (ExitFailure 84)
    else computeProg rule start line window move

computeProg :: Int -> Int -> Int -> Int -> Int -> IO()
computeProg rule start line window move
    | rule == 30 = exec_30 start line window move
    | rule == 90 = exec_90 start line window move
    | rule == 110 = exec_110 start line window move
    | otherwise =
        putStrLn "Invalid rule parameter (must be 30, 90 or 110)." >>
        exitWith (ExitFailure 84)

printLine :: Int -> Int -> [Char] -> IO()
printLine num start line
    | start <= 1 && num >= 1 = putStrLn line
    | otherwise = putStr ""

----------------------------------- RULE 30 -----------------------------------

exec_30 :: Int -> Int -> Int -> Int -> IO()
exec_30 start line window move = do
    let bef = replicate (window `div` 2) ' '
        aft = replicate (window `div` 2 - (1 - window `mod` 2)) ' '
        first = bef ++ "*" ++ aft
    printLine (line + start - 1) start first
    print30 (first++" ") (line + start - 1) start window

print30 :: [Char] -> Int -> Int -> Int -> IO()
print30 line num start window = do
    let new = " " ++ newLine30 line num window ++ " "
    printLine num start new
    until_no_remaining30 num start (new ++ " ") window

until_no_remaining30 :: Int -> Int -> [Char] -> Int -> IO()
until_no_remaining30 line_remaining start new win
    | line_remaining >= 1 = print30 new (line_remaining - 1) (start - 1) win
    | otherwise = putStr ""

newLine30 :: [Char] -> Int -> Int -> [Char]
newLine30 [] n_ln win = []
newLine30 (a:b:c:dx) n_ln win
    | null dx = ln
    | a == '*' && b == '*' && c == '*' = ln++" "++newLine30 (b:c:dx) n_ln win
    | a == '*' && b == '*' && c == ' ' = ln++" "++newLine30 (b:c:dx) n_ln win
    | a == '*' && b == ' ' && c == '*' = ln++" "++newLine30 (b:c:dx) n_ln win
    | a == '*' && b == ' ' && c == ' ' = ln++"*"++newLine30 (b:c:dx) n_ln win
    | otherwise = newLine302 (a:b:c:dx) n_ln win
    where
        ln = []

newLine302 :: [Char] -> Int -> Int -> [Char]
newLine302 [] n_ln win = []
newLine302 (a:b:c:dx) n_ln win
    | null dx = ln
    | a == ' ' && b == '*' && c == '*' = ln++"*"++newLine30 (b:c:dx) n_ln win
    | a == ' ' && b == '*' && c == ' ' = ln++"*"++newLine30 (b:c:dx) n_ln win
    | a == ' ' && b == ' ' && c == '*' = ln++"*"++newLine30 (b:c:dx) n_ln win
    | a == ' ' && b == ' ' && c == ' ' = ln++" "++newLine30 (b:c:dx) n_ln win
    where
        ln = []

----------------------------------- RULE 90 -----------------------------------

exec_90 :: Int -> Int -> Int -> Int -> IO()
exec_90 start line window move = do
    let bef = replicate (window `div` 2 - (1 - window `mod` 2)) ' '
        aft = replicate (window `div` 2) ' '
        first = bef ++ "*" ++ aft
    printLine (line + start - 1) start first
    print90 (first++" ") (line + start - 1) start window

print90 :: [Char] -> Int -> Int -> Int -> IO()
print90 line num start win = do
    let new = " " ++ newLine90 line num win ++ " "
    printLine num start new
    until_no_remaining90 num start (new ++ " ") win

until_no_remaining90 :: Int -> Int -> [Char] -> Int -> IO()
until_no_remaining90 num start new win
    | num >= 1 = print90 new (num - 1) (start - 1) win
    | otherwise = putStr ""

newLine90 :: [Char] -> Int -> Int -> [Char]
newLine90 [] n_ln win = []
newLine90 (a:b:c:dx) n_ln win
    | null dx = ln
    | a == '*' && b == '*' && c == '*' = ln++" "++newLine90 (b:c:dx) n_ln win
    | a == '*' && b == '*' && c == ' ' = ln++"*"++newLine90 (b:c:dx) n_ln win
    | a == '*' && b == ' ' && c == '*' = ln++" "++newLine90 (b:c:dx) n_ln win
    | a == '*' && b == ' ' && c == ' ' = ln++"*"++newLine90 (b:c:dx) n_ln win
    | otherwise = newLine902 (a:b:c:dx) n_ln win
    where
        ln = []

newLine902 :: [Char] -> Int -> Int -> [Char]
newLine902 [] n_ln win = []
newLine902 (a:b:c:dx) n_ln win
    | null dx = ln
    | a == ' ' && b == '*' && c == '*' = ln++"*"++newLine90 (b:c:dx) n_ln win
    | a == ' ' && b == '*' && c == ' ' = ln++" "++newLine90 (b:c:dx) n_ln win
    | a == ' ' && b == ' ' && c == '*' = ln++"*"++newLine90 (b:c:dx) n_ln win
    | a == ' ' && b == ' ' && c == ' ' = ln++" "++newLine90 (b:c:dx) n_ln win
    where
        ln = []

---------------------------------- RULE 110 -----------------------------------

exec_110 :: Int -> Int -> Int -> Int -> IO()
exec_110 start line window move = do
    let bef = replicate (window `div` 2 - (1 - window `mod` 2)) ' '
        aft = replicate (window `div` 2) ' '
        first = bef ++ "*" ++ aft
    printLine (line + start - 1) start first
    print110 (first++" ") (line + start - 1) start window

print110 :: [Char] -> Int -> Int -> Int -> IO()
print110 line num start win = do
    let new = " " ++ newLine110 line num win ++ " "
    printLine num start new
    until_no_remaining110 num start (new ++ " ") win

until_no_remaining110 :: Int -> Int -> [Char] -> Int -> IO()
until_no_remaining110 num start new win
    | num >= 1 = print110 new (num - 1) (start - 1) win
    | otherwise = putStr ""

newLine110 :: [Char] -> Int -> Int -> [Char]
newLine110 [] n_ln win = []
newLine110 (a:b:c:dx) n_ln win
    | null dx = ln
    | a == '*' && b == '*' && c == '*' = ln++" "++newLine110 (b:c:dx) n_ln win
    | a == '*' && b == '*' && c == ' ' = ln++"*"++newLine110 (b:c:dx) n_ln win
    | a == '*' && b == ' ' && c == '*' = ln++"*"++newLine110 (b:c:dx) n_ln win
    | a == '*' && b == ' ' && c == ' ' = ln++" "++newLine110 (b:c:dx) n_ln win
    | otherwise = newLine1102 (a:b:c:dx) n_ln win
    where
        ln = []

newLine1102 :: [Char] -> Int -> Int -> [Char]
newLine1102 [] n_ln win = []
newLine1102 (a:b:c:dx) n_ln win
    | null dx = ln
    | a == ' ' && b == '*' && c == '*' = ln++"*"++newLine110 (b:c:dx) n_ln win
    | a == ' ' && b == '*' && c == ' ' = ln++"*"++newLine110 (b:c:dx) n_ln win
    | a == ' ' && b == ' ' && c == '*' = ln++"*"++newLine110 (b:c:dx) n_ln win
    | a == ' ' && b == ' ' && c == ' ' = ln++" "++newLine110 (b:c:dx) n_ln win
    where
        ln = []